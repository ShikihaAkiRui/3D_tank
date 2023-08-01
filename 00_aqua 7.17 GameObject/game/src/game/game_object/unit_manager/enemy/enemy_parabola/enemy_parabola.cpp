#include "enemy_parabola.h"
#include"../../../bullet_manager/bullet_manager.h"
#include"../../unit_manager.h"

const float CEnemyParabola::m_graund_ray_langth = -15.0f;
const int CEnemyParabola::m_life = 1;
const float CEnemyParabola::m_move_speed = 10.0f;
const float CEnemyParabola::m_stop_distance = 300.0f;
const float CEnemyParabola::m_shot_time = 3.0f;

//コンストラクタ
CEnemyParabola::CEnemyParabola(aqua::IGameObject* parent)
	:IEnemy(parent, "EnemyNormal")
	, m_ShotFlag(false)
{
}

//初期化
void CEnemyParabola::Initialize(const aqua::CVector3& position)
{
	IEnemy::Initialize("data/boxt.mv1", position, m_graund_ray_langth, m_life);

	//向き設定
	m_Player = CUnitManager::GetInstance().GetPlayer();
	if (!m_Player)return;

	//向く方向の角度を求める
	aqua::CVector3 distance = m_Player->GetModel()->position - m_Position;
	aqua::CVector2 move_direction = aqua::CVector2::ZERO;
	m_Rotation.y = aqua::RadToDeg(atan2(distance.x, distance.z));

	m_Model->rotation = m_Rotation;

	m_ShotTimer.Setup(m_shot_time);

}

//更新
void CEnemyParabola::Update(void)
{
	IEnemy::Update();

	//移動
	Move();

	//フラグがtrueのとき攻撃
	if (m_ShotFlag)
		Shot();

}

//移動
void CEnemyParabola::Move(void)
{
	m_Velocity = aqua::CVector3(0.0f, 0.0f, 1.0f);

	//向きを変える
	aqua::CVector3 distance = m_Player->GetModel()->position - m_Position;
	m_Rotation.y = aqua::RadToDeg(atan2(distance.x, distance.z));

	aqua::CVector3 floor = distance;
	floor.y = 0.0f;
	float x_angle = 0.0f;
	x_angle = acos(aqua::CVector3::Dot(floor.Normalize(), distance.Normalize()));

	//プレイヤーが下なら回転方向を変える
	x_angle *= distance.y < 0 ? 1.0f : -1.0f;

	m_Rotation.x = aqua::RadToDeg(x_angle);

	//移動方向を変える
	aqua::CMatrix matrix = aqua::CMatrix::Ident();
	matrix.RotY(aqua::DegToRad(m_Rotation.y));
	m_Velocity.Transform(matrix);

	IEnemy::Move();

	//止まる距離より遠いとき
	if (distance.Length() > m_stop_distance)
	{
		m_Position += m_Velocity * m_move_speed * aqua::GetDeltaTime();
		m_ShotFlag = false;

	}
	//下がる位置内のとき
	else
	{
		m_Position -= m_Velocity * m_move_speed * aqua::GetDeltaTime();
		m_ShotFlag = true;
	}

	m_Model->rotation = m_Rotation;
	m_Model->position = m_Position;

}

//弾を撃つ
void CEnemyParabola::Shot(void)
{
	m_ShotTimer.Update();

	if (m_ShotTimer.Finished())
	{
		m_ShotTimer.Reset();

		//CBulletManager& bullet_manager = CBulletManager::GetInstance();

		//bullet_manager.Create(m_UnitCategory, m_Position, m_Rotation);
	}

}
