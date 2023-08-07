#include "bullet_parabola.h"
#include"../../../stage/stage.h"

const float CBulletParabola::m_move_speed = 30.0f;
const float CBulletParabola::m_fall_speed = 4.0f;
const float CBulletParabola::m_max_lenght_angle = 45.0f;

//�R���X�g���N�^
CBulletParabola::CBulletParabola(aqua::IGameObject* parent)
	:IBullet(parent,"BulletParabola")
	,m_ImpactPosition(aqua::CVector3::ZERO)
{
}

//������
void CBulletParabola::Initialize(UNIT_CATEGORY unit_category, const aqua::CVector3& position, const aqua::CVector3& impact_position)
{
	m_UnitCategory = unit_category;
	m_Position = position;
	m_ImpactPosition = impact_position;

	IBullet::Initialize("data/ball.mv1");

	m_Model.position = m_Position;
	aqua::CVector2 vector = aqua::CVector2(m_Position.x, m_Position.z) - aqua::CVector2(m_ImpactPosition.x, m_ImpactPosition.z);

	float target_length = vector.Length();

	//�ʒu���˒������m�F
	float bullet_length = (m_move_speed * m_move_speed * sin(2 * aqua::DegToRad(m_max_lenght_angle))) / m_fall_speed;

	//�^�[�Q�b�g���͈͊O�Ȃ����
	if (target_length > bullet_length)
		DeleteObject();

	//�p�x�����߂�
	float angle = asinf((target_length * m_fall_speed) / (m_move_speed * m_move_speed)) / 2;

	m_Velocity.y = cos(angle) * m_move_speed * aqua::GetDeltaTime();
	m_Velocity.z = sin(angle) * m_move_speed * aqua::GetDeltaTime();
	
}

//�X�V
void CBulletParabola::Update(void)
{
	m_Velocity.y -= m_fall_speed * aqua::GetDeltaTime();

	IBullet::Update();
}