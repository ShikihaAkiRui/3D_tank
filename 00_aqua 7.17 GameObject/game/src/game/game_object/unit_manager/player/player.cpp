#include "player.h"
#include"../unit_manager.h"
#include"../../bullet_manager/bullet_manager.h"

const float CPlayer::m_move_speed = 10.0f;
const float CPlayer::m_ray_langth = 15.0f;
const float CPlayer::m_rotation_speed = 90.0f;

//コンストラクタ
CPlayer::CPlayer(aqua::IGameObject* parent)
	:IUnit(parent,"Player")
	,m_Position(aqua::CVector3::ZERO)
	,m_Velocity(aqua::CVector3::ZERO)
	,m_Angle(0)
	,m_Rotation(aqua::CVector3::ZERO)
	, m_Matrix(aqua::CMatrix::Ident())
{
}

//初期化
void CPlayer::Initialize(void)
{
	IUnit::Initialize("data/boxt.mv1");
	
	m_Position = aqua::CVector3(0.0f, 0.0f,30.0f);
	m_Model->position = m_Position;

}

//更新
void CPlayer::Update(void)
{
	IUnit::Update();



	Move();

	CUnitManager* unit_manager = (CUnitManager*)aqua::FindGameObject("UnitManager");

	if (unit_manager->CheckHitUnit("Enemy", m_Position, m_Position + m_Velocity *  m_ray_langth))
		m_Position = aqua::CVector3(-20.0f, 0.0f, 30.0f);

	Shot();

}

//描画
void CPlayer::Draw(void)
{
	IUnit::Draw();

	DrawLine3D(m_Position, m_Position + m_Velocity * m_ray_langth, 0xffff00ff);
}

//移動
void CPlayer::Move(void)
{
	m_Velocity = aqua::CVector3::ZERO;
	m_Matrix = aqua::CMatrix::Ident();

	//左右方向変更
	if (aqua::keyboard::Button(aqua::keyboard::KEY_ID::LEFT))
	{
		m_Angle -= m_rotation_speed * aqua::GetDeltaTime();

		if (m_Angle >= 360.0f)
			m_Angle -= 360.0f;
	}
	if (aqua::keyboard::Button(aqua::keyboard::KEY_ID::RIGHT))
	{
		m_Angle += m_rotation_speed * aqua::GetDeltaTime();

		if (m_Angle <= 0)
			m_Angle += 360.0f;
	}
	//上下移動
	if (aqua::keyboard::Button(aqua::keyboard::KEY_ID::UP))
		m_Velocity.z = 1.0f;
	if (aqua::keyboard::Button(aqua::keyboard::KEY_ID::DOWN))
		m_Velocity.z = -1.0f;

	//行列で方向変更
	m_Rotation.y = m_Angle;
	m_Matrix.RotY(aqua::DegToRad(m_Rotation.y));
	m_Velocity.Transform(m_Matrix);

	m_Position += m_Velocity * m_move_speed * aqua::GetDeltaTime();

	m_Model->rotation = m_Rotation;
	m_Model->position = m_Position;
}

//弾で攻撃
void CPlayer::Shot(void)
{
	CBulletManager* bullet_manager = (CBulletManager*)aqua::FindGameObject("BulletManager");
	if (!bullet_manager)return;

	//弾を出す
	if (aqua::mouse::Trigger(aqua::mouse::BUTTON_ID::LEFT))
	{
		bullet_manager->Create(m_Position, m_Matrix);
	}

}
