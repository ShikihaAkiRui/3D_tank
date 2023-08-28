#include "bullet_parabola.h"
#include"../../../stage/stage.h"

const float CBulletParabola::m_move_speed = 5.0f;
const float CBulletParabola::m_fall_speed = 0.05f;
const float CBulletParabola::m_max_lenght_angle = 45.0f;
const float CBulletParabola::m_radius = 4.0f;

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
	m_Radius = m_radius;

	IBullet::Initialize("data/model/Sphere.mv1");

	m_Model.position = m_Position;
	aqua::CVector3 vector = m_Position - m_ImpactPosition;

	float target_length = vector.Length();

	//�ʒu���˒������m�F
	float bullet_length = (m_move_speed * m_move_speed * sin(2 * aqua::DegToRad(m_max_lenght_angle))) / m_fall_speed;

	//�^�[�Q�b�g���͈͊O�Ȃ����
	if (target_length > bullet_length)
		DeleteObject();

	//�p�x�����߂�
	float angle = asinf((target_length * m_fall_speed) / (m_move_speed * m_move_speed)) / 2;

	m_Velocity.y = cos(angle) * m_move_speed;
	m_Velocity.z = sin(angle) * m_move_speed;

	aqua::CMatrix matrix = aqua::CMatrix::Ident();
	
	//Y������]
	float angle_y = aqua::RadToDeg(atan2(vector.x, vector.z));
	//0���ȏ�ɂ���
	angle_y += 180.0f;
	matrix.RotY(aqua::DegToRad(angle_y));
	
	m_Velocity.Transform(matrix);
}

//�X�V
void CBulletParabola::Update(void)
{
	//�d�͂̒l��������
	m_Velocity.y -= m_fall_speed;

	IBullet::Update();
}