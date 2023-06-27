#include "enemy.h"
#include"../../bullet_manager/bullet_manager.h"
#include"../player/player.h"
#include"../../item_manager/item_manager.h"

const aqua::CVector3 CEnemy::m_graund_ray_langth = aqua::CVector3(0.0f, -10.0f, 0.0f);
const int CEnemy::m_life = 1;
const float CEnemy::m_move_speed = 30.0f;
const float CEnemy::m_stop_distance = 250.0f;
const float CEnemy::m_back_distance = 230.0f;
const float CEnemy::m_shot_time = 2.0f;

//コンストラクタ
CEnemy::CEnemy(aqua::IGameObject* parent)
	:ICharacter(parent,"Enemy")
	,m_Player(nullptr)
	,m_ShotFlag(false)
{
}

//初期化
void CEnemy::Initialize(const aqua::CVector3& position)
{
	ICharacter::Initialize("data/boxt.mv1");

	m_Position = position;

	CheckGround();

	m_UnitCategory = UNIT_CATEGORY::ENMEY;
	m_Life = m_life;
	m_GraundRayLength = m_graund_ray_langth;

	//向き設定
	m_Player = (CPlayer*)aqua::FindGameObject("Player");
	if (!m_Player)return;
	//向く方向の角度を求める
	aqua::CVector3 distance = m_Player->GetModel()->position - m_Position;
	aqua::CVector2 move_direction = aqua::CVector2::ZERO;
	m_Rotation.y = aqua::RadToDeg(atan2(distance.x, distance.z));

	m_Model->rotation = m_Rotation;
	m_Model->position = m_Position;

	m_ShotTimer.Setup(m_shot_time);

}

//更新
void CEnemy::Update(void)
{
	//移動
	Move();

	//フラグがtrueのとき攻撃
	if (m_ShotFlag)
		Shot();

	ICharacter::Update();
}

//移動
void CEnemy::Move(void)
{
	m_Velocity = aqua::CVector3(0.0f,0.0f,1.0f);

	//向きを変える
	aqua::CVector3 distance = m_Player->GetModel()->position - m_Position;
	m_Rotation.y = aqua::RadToDeg(atan2(distance.x, distance.z));
	
	aqua::CVector3 floor = distance;
	floor.y = 0.0f;
	float x_angle = 0.0f;
	x_angle = acos(aqua::CVector3::Dot(floor.Normalize(), distance.Normalize()));

//#define TEST
#ifdef TEST

	
	//現在向いている方向
	aqua::CVector3 current_dir;
	current_dir.x = 0.0f;
	current_dir.y = sin(aqua::DegToRad(m_Rotation.x));
	current_dir.z = cos(aqua::DegToRad(m_Rotation.x));

	//回転方向を設定
	aqua::CVector3 dis = distance;
	dis.x = 0.0f;
	aqua::CVector3 cross = aqua::CVector3::Cross(current_dir.Normalize(),dis.Normalize());
	if (cross.y != 0.0f)cross = aqua::CVector3(1.0f, 0.0f, 0.0f);

	if (cross.x > 0)
		m_Rotation.x = aqua::RadToDeg(x_angle);
	else
		m_Rotation.x = aqua::RadToDeg(-x_angle);
	

#else

	//m_Rotation.x = aqua::RadToDeg(-x_angle);

	//プレイヤーがしたなら回転方向を変える
	x_angle *= distance.y < 0 ? 1.0f : -1.0f;
	
	m_Rotation.x = aqua::RadToDeg(x_angle);

#endif

	//移動方向を変える
	aqua::CMatrix matrix = aqua::CMatrix::Ident();
	matrix.RotY(aqua::DegToRad(m_Rotation.y));
	m_Velocity.Transform(matrix);

	ICharacter::Move();

	//止まる距離より遠いとき
	if (distance.Length() > m_stop_distance)
	{
		m_Position += m_Velocity * m_move_speed * aqua::GetDeltaTime();
		m_ShotFlag = false;

	}
	//下がる位置内のとき
	else if(distance.Length() < m_back_distance)
	{
		m_Position -= m_Velocity * m_move_speed * aqua::GetDeltaTime();
		m_ShotFlag = true;
	}
	//近づかず、下がらないとき
	else
	{
		m_ShotFlag = true;
	}

	m_Model->rotation = m_Rotation;
	m_Model->position = m_Position;
}

//倒された
void CEnemy::Dead(void)
{
	CItemManager* item_manager = (CItemManager*)aqua::FindGameObject("ItemManager");
	if (!item_manager)return;

	item_manager->Create(m_Position);

	ICharacter::Dead();
}

//弾を撃つ
void CEnemy::Shot(void)
{
	m_ShotTimer.Update();

	if (m_ShotTimer.Finished())
	{
		CBulletManager* bullet_manager = (CBulletManager*)aqua::FindGameObject("BulletManager");
		if (!bullet_manager)return;

		bullet_manager->Create(m_UnitCategory, m_Position, m_Rotation);

		m_ShotTimer.Reset();
	}
}