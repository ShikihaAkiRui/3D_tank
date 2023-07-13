#include "control_camera.h"
#include"../stage/stage.h"

const aqua::CVector3 CControlCamera::m_camera_length = aqua::CVector3(0.0f, 40.0f, -100.0f);
const aqua::CVector2 CControlCamera::m_angle_variation = aqua::CVector2(0.1f, 0.1f);
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

//�J�����̈ʒu���擾
aqua::CVector3 CControlCamera::GetPosition(void)
{
	return m_Camera->m_Position;
}

//�����Ă���p�x���擾
aqua::CVector3 CControlCamera::GetAngle(void)
{
	aqua::CVector3 angle = aqua::CVector3::ZERO;
	aqua::CVector3 distance = m_Camera->m_TargetPosition - m_Camera->m_Position;
	angle.y = aqua::RadToDeg(atan2(distance.x, distance.z));

	aqua::CVector3 floor = distance;
	floor.y = 0.0f;
	float x_angle = 0.0f;
	x_angle = acos(aqua::CVector3::Dot(floor.Normalize(), distance.Normalize()));
	
	x_angle *= distance.y < 0 ? 1.0f : -1.0f;
	angle.x = aqua::RadToDeg(x_angle);

	return angle;
}
