#include "bullet.h"
#include"../../unit_manager/unit_manager.h"

const aqua::CVector3 CBullet::m_direction = aqua::CVector3(0.0f, 0.0f, 1.0f);
const float CBullet::m_move_speed = 100.0f;
const float CBullet::m_radius = 4.0f;

//コンストラクタ
CBullet::CBullet(aqua::IGameObject* parent)
	:IUnit(parent,"Bullet")
	,m_Position(aqua::CVector3::ZERO)
	,m_Velocity(aqua::CVector3::ZERO)
{
}

//初期化
void CBullet::Initialize(const aqua::CVector3& position)
{
	IUnit::Initialize("data/ball.mv1");

	m_Position = position;

	m_Velocity = m_direction * m_move_speed * aqua::GetDeltaTime();

	m_Model->position = m_Position;
}

//更新
void CBullet::Update(void)
{
	IUnit::Update();

	m_Position += m_Velocity;
	m_Model->position = m_Position;

	
	CUnitManager* unit_manager = (CUnitManager*)aqua::FindGameObject("UnitManager");
	if (!unit_manager)return;
	if (unit_manager->EnemyCheckHitBullet(m_Position, m_radius))
		DeleteObject();
	
}

//中心位置取得
aqua::CVector3 CBullet::GetCenterPosition(void)
{
	return m_Position;
}

//半径取得
float CBullet::GetRadius(void)
{
	return m_radius;
}
