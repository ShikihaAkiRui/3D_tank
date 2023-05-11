#include "bullet.h"

const float CBullet::m_move_speed = 30.0f;
const float CBullet::m_radius = 10.0f;

//コンストラクタ
CBullet::CBullet(aqua::IGameObject* parent)
	:IUnit(parent,"Bullet")
	,m_Position(aqua::CVector3::ZERO)
	,m_Velocity(aqua::CVector3::ZERO)
{
}

//初期化
void CBullet::Initialize(const aqua::CVector3& position, float direction)
{
	IUnit::Initialize("data/boxt.mv1");

	m_Position = position;
	m_Velocity.x = sin(aqua::DegToRad(direction)) * m_move_speed * aqua::GetDeltaTime();
	m_Velocity.z = cos(aqua::DegToRad(direction)) * m_move_speed * aqua::GetDeltaTime();

	m_Model->position = m_Position;
}

//更新
void CBullet::Update(void)
{
	IUnit::Update();

	m_Position += m_Velocity;
	m_Model->position = m_Position;

}
