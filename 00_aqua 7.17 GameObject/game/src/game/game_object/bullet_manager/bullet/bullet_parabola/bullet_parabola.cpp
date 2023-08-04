#include "bullet_parabola.h"
#include"../../../stage/stage.h"

const float CBulletParabola::m_move_angle = 45.0f;
const float CBulletParabola::m_move_speed = 10.0f;
const float CBulletParabola::m_accelerate = 0.98f;

//コンストラクタ
CBulletParabola::CBulletParabola(aqua::IGameObject* parent)
	:IBullet(parent,"BulletParabola")
	,m_ImpactPosition(aqua::CVector3::ZERO)
	,m_Accelerate(aqua::CVector3::ZERO)
	,m_Lenght(0.0f)
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
	aqua::CVector2 vector = aqua::CVector2(m_Position.x, m_Position.z) - aqua::CVector2(m_ImpactPosition.x, m_ImpactPosition.z);

	m_Lenght = vector.Length();


	//角度


}

//更新
void CBulletParabola::Update(void)
{
	CStage* stage = (CStage*)aqua::FindGameObject("Stage");

	m_Accelerate.y += stage->GetGravity();

	m_Velocity += m_Accelerate;

	IBullet::Update();

	m_Velocity *= m_accelerate;

	m_Accelerate = aqua::CVector3::ZERO;
}