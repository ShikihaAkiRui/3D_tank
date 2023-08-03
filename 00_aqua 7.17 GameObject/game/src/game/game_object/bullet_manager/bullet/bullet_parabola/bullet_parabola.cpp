#include "bullet_parabola.h"

const float CBulletParabola::m_move_angle = 60.0f;
const float CBulletParabola::m_move_speed = 100.0f;

//コンストラクタ
CBulletParabola::CBulletParabola(aqua::IGameObject* parent)
	:IBullet(parent,"BulletParabola")
	,m_ImpactPosition(aqua::CVector3::ZERO)
{
}

//初期化
void CBulletParabola::Initialize(UNIT_CATEGORY unit_category, const aqua::CVector3& position, const aqua::CVector3& impact_position)
{
	m_UnitCategory = unit_category;
	m_Position = position;
	m_ImpactPosition = m_ImpactPosition;

	IBullet::Initialize("data/ball.mv1");


	m_Model.position = m_Position;
}

//更新
void CBulletParabola::Update(void)
{
	//移動方向設定
	SetVelocity();

	IBullet::Update();
}

//移動方向設定
void CBulletParabola::SetVelocity(void)
{
	aqua::CVector3 vector = m_Position - m_ImpactPosition;
	float length = vector.Length();

	float t1 = tan(aqua::DegToRad(m_move_angle));
	float t2 = (m_ImpactPosition.y - t1 * length) / (length * length);

	//移動
	m_Velocity.x += m_move_speed;

	float y = t2 * m_Velocity.x * m_Velocity.x + t1 * m_Velocity.x;

	m_Velocity = aqua::CVector3(m_Velocity.x, y, 0);
}
