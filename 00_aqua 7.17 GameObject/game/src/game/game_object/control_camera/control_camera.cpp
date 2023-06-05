#include "control_camera.h"
#include"../stage/stage.h"

const aqua::CVector3 CControlCamera::m_camera_length = aqua::CVector3(0.0f, 40.0f, -100.0f);
const aqua::CVector2 CControlCamera::m_angle_variation = aqua::CVector2(0.1, 0.1f);
const float CControlCamera::m_max_x_angle = 60.0f;
const float CControlCamera::m_min_x_angle = -90.0f;
const aqua::CVector3 CControlCamera::m_target_position = aqua::CVector3(0.0f, 30.0f, 0.0f);

//�R���X�g���N�^
CControlCamera::CControlCamera(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"ControlCamera")
	,m_Camera(nullptr)
	,m_Unit(nullptr)
	,m_Angle(aqua::CVector3::ZERO)
{
}

//������
void CControlCamera::Initialize(aqua::CCamera* camera,IUnit* unit)
{
	m_Camera = camera;
	m_Unit = unit;

	m_Camera->m_Position = m_Unit->GetModel()->position + m_camera_length;
	m_Camera->m_TargetPosition = m_Unit->GetModel()->position + m_target_position;

	m_Camera->Initialize();
}

//�X�V
void CControlCamera::Update(void)
{
	aqua::CMatrix matrix = aqua::CMatrix::Ident();

	aqua::CPoint mouse = aqua::mouse::GetCursorMovement();

	//�p�x�ɕϊ�
	m_Angle.x += mouse.y * m_angle_variation.x;
	m_Angle.y += mouse.x * m_angle_variation.y;

	if (m_Angle.y >= 360.0f)
		m_Angle.y -= 360.0f;
	if (m_Angle.y <= 0.0f)
		m_Angle.y += 360.0f;

	//�㉺�̕������
	if (m_Angle.x >= m_max_x_angle)
		m_Angle.x = m_max_x_angle;
	if (m_Angle.x <= m_min_x_angle)
		m_Angle.x = m_min_x_angle;
	
	matrix.RotX(aqua::DegToRad(m_Angle.x));
	matrix.RotY(aqua::DegToRad(m_Angle.y));

	m_Camera->m_Position = m_Unit->GetModel()->position + aqua::CVector3(m_camera_length).Transform(matrix);

	m_Camera->m_TargetPosition = m_Unit->GetModel()->position + m_target_position;
	
	m_Camera->Update();
}

//�����Ă���p�x���擾
aqua::CVector3 CControlCamera::GetAngle(void)
{
	return m_Angle;
}
