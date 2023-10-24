#include "enemy_fly.h"
#include"../../../unit_manager/unit_manager.h"
#include"../../../bullet_manager/bullet_manager.h"
#include"../../../game_sound_manager/game_sound_manager.h"

const aqua::CVector3 CEnemyFly::m_scale = aqua::CVector3(-0.8f, 0.8f, -0.8f);
const float CEnemyFly::m_graund_ray_langth = -15.0f;
const int CEnemyFly::m_life = 1;
const float CEnemyFly::m_move_speed = 40.0f;
const float CEnemyFly::m_stop_distance = 350.0f;
const float CEnemyFly::m_back_distance = 300.0f;
const float CEnemyFly::m_shot_length = 700.0f;
const float CEnemyFly::m_shot_time = 6.0f;
const float CEnemyFly::m_max_fly_height = 100.0f;
const float CEnemyFly::m_fly_speed = 10.0f;
const float CEnemyFly::m_max_front_angle = 15.0f;
const float CEnemyFly::m_max_back_angle = -10.0f;
const float CEnemyFly::m_move_angle_speed = 30.0f;
const float CEnemyFly::m_propeller_angle_speed = 10.0f;
const float CEnemyFly::m_main_propeller_angle = 90.0f;
const aqua::CVector3 CEnemyFly::m_main_propeller_position = aqua::CVector3(0.0f, 35.4f, 0.0f);
const int CEnemyFly::m_main_propeller_frame = 6;
const aqua::CVector3 CEnemyFly::m_back_propeller_position = aqua::CVector3(-4.8f, 13.7f, 73.5f);
const int CEnemyFly::m_back_propeller_frame = 1;

//コンストラクタ
CEnemyFly::CEnemyFly(aqua::IGameObject* parent)
	:IEnemy(parent, "EnemyFly")
	, m_PlayerDistance(aqua::CVector3::ZERO)
	, m_BulletAngle(aqua::CVector3::ZERO)
	, m_DefaultPositionY(0.0f)
	, m_MoveAngle(0.0f)
	, m_HoveringFlag(false)
	, m_PropellerAngle(0.0f)
{
}

//初期化
void CEnemyFly::Initialize(const aqua::CVector3& position)
{
	IEnemy::Initialize("data/model/helicopter/PoliceHelicopter-fbx.mv1", position, m_graund_ray_langth, m_life);

	m_Model->scale = m_scale;

	//向きを設定
	m_Player = CUnitManager::GetInstance().GetPlayer();

	//向く方向の角度を求める
	aqua::CVector3 distance = m_Player->GetModel()->position - m_Position;
	aqua::CVector2 move_direction = aqua::CVector2::ZERO;
	m_Rotation.y = aqua::RadToDeg(atan2(distance.x, distance.z));

	m_DefaultPositionY = m_Position.y;
	m_Model->rotation = m_Rotation;
	m_BulletAngle = m_Rotation;

	//コリジョンの位置修正
	RefreshCollInfo();

	m_ShotTimer.Setup(m_shot_time);
	m_FlyTimer.Setup(m_fly_speed);
}

//更新
void CEnemyFly::Update(void)
{
	//移動
	Move();

	//機体の傾き
	MoveRotation();

	//プロペラを回転
	PropellerRotation();

	//弾を撃つ
	Shot();

	//弾の判定
	if (CheckHitBullet())
		HitAttack();

	//アイテムの判定
	if (CheckHitItem())
		HitItem();

	IUnit::Update();
}

//移動
void CEnemyFly::Move(void)
{
	m_Velocity = aqua::CVector3(0.0f, 0.0f, 1.0f);

	//向きを変える
	m_PlayerDistance = m_Player->GetModel()->position - m_Position;
	m_Rotation.y = aqua::RadToDeg(atan2(m_PlayerDistance.x, m_PlayerDistance.z));

	//移動方向を変える
	aqua::CMatrix matrix = aqua::CMatrix::Ident();
	matrix.RotY(aqua::DegToRad(m_Rotation.y));
	m_Velocity.Transform(matrix);

	bool max_fly_flag = false;
	float move_height = 0.0f;

	//上昇させる
	if (m_Position.y < m_max_fly_height)
	{
		m_FlyTimer.Update();

		if (!m_FlyTimer.Finished())
			move_height = aqua::easing::OutQuintic(m_FlyTimer.GetTime(), m_FlyTimer.GetLimit(), m_DefaultPositionY, m_max_fly_height);
		else
			move_height = m_max_fly_height;
	}
	else
	{
		m_Position.y = m_max_fly_height;
		max_fly_flag = true;
	}
	
	CheckWall();

	//止まる距離より遠いとき
	if (m_PlayerDistance.Length() > m_stop_distance)
	{
		m_Position += m_Velocity * m_move_speed * aqua::GetDeltaTime();
		m_MoveAngle = m_move_angle_speed;
		m_HoveringFlag = false;
	}
	//下がる位置内のとき
	else if (m_PlayerDistance.Length() < m_back_distance)
	{
		m_Position -= m_Velocity * m_move_speed * aqua::GetDeltaTime();
		m_MoveAngle = -m_move_angle_speed;
		m_HoveringFlag = false;
	}
	else
	{
		m_HoveringFlag = true;
	}
	//上に上昇
	if (!max_fly_flag)
	{
		m_Position.y = move_height;
	}

	m_Model->rotation.y = m_Rotation.y;
	m_Model->position = m_Position;
}

//弾を撃つ角度を決める
void CEnemyFly::ShotAngle(void)
{
	//y軸は敵の方向にする
	m_BulletAngle = m_Rotation;
	
	//x軸の角度を求める
	aqua::CVector3 floor = m_PlayerDistance;
	floor.y = 0.0f;
	float x_angle = 0.0f;
	x_angle = acos(aqua::CVector3::Dot(floor.Normalize(), m_PlayerDistance.Normalize()));

	//プレイヤーが下なら回転方向を変える
	x_angle *= m_PlayerDistance.y < 0 ? 1.0f : -1.0f;

	m_BulletAngle.x = aqua::RadToDeg(x_angle);
}

//プロペラを回転
void CEnemyFly::PropellerRotation(void)
{
	//メインのプロペラ
	aqua::CMatrix main_matrix = aqua::CMatrix::Ident();

	m_PropellerAngle += m_propeller_angle_speed;

	main_matrix.RotX(aqua::DegToRad(m_main_propeller_angle));
	main_matrix.RotY(aqua::DegToRad(m_PropellerAngle));
	main_matrix.Translate(m_main_propeller_position);

	aqua::CAnimationModel::SetFrameUserLocalMatrix(m_Model, m_main_propeller_frame, main_matrix);

	//後ろのプロペラ
	aqua::CMatrix back_matrix = aqua::CMatrix::Ident();
	
	back_matrix.RotX(aqua::DegToRad(-m_PropellerAngle));
	back_matrix.Translate(m_back_propeller_position);

	aqua::CAnimationModel::SetFrameUserLocalMatrix(m_Model, m_back_propeller_frame, back_matrix);
}

//機体の傾き
void CEnemyFly::MoveRotation(void)
{
	//ホバリングする
	if (m_HoveringFlag)
	{
		//角度が0以上
		if (m_Rotation.x > 0)
		{
			m_MoveAngle = -m_move_angle_speed;
			m_Rotation.x += m_MoveAngle * aqua::GetDeltaTime();

			//0未満になったら0
			if (m_Rotation.x <= 0)
				m_Rotation.x = 0;
		}
		else
		{
			m_MoveAngle = m_move_angle_speed;
			m_Rotation.x += m_MoveAngle * aqua::GetDeltaTime();

			//0超えたらになったら0
			if (m_Rotation.x >= 0)
				m_Rotation.x = 0;
		}
	}
	else
	{
		m_Rotation.x += m_MoveAngle * aqua::GetDeltaTime();

		//最大最小角度を超えたら戻す
		if (m_Rotation.x > m_max_front_angle)
			m_Rotation.x = m_max_front_angle;
		if (m_Rotation.x < m_max_back_angle)
			m_Rotation.x = m_max_back_angle;
	}

	m_Model->rotation.x = m_Rotation.x;
	m_MoveAngle = 0.0f;
}

//弾を撃つ
void CEnemyFly::Shot(void)
{
	m_ShotTimer.Update();

	if (m_ShotTimer.Finished())
	{
		m_ShotTimer.Reset();

		//弾を飛ばす方向を設定
		ShotAngle();

		CBulletManager& bullet_manager = CBulletManager::GetInstance();
		bullet_manager.Create(BULLET_ID::NORMAL, m_UnitCategory, m_Position, m_BulletAngle);

		CGameSoundManager::GetInstance().Play(SOUND_ID::SHOT);
	}
}