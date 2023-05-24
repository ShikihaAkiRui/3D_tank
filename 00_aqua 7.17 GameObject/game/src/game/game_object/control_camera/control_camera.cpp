#include "control_camera.h"

const aqua::CVector3 CControlCamera::m_camera_length = aqua::CVector3(0.0f, 30.0f, -80.0f);

//�R���X�g���N�^
CControlCamera::CControlCamera(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"ControlCamera")
	,m_Camera(nullptr)
	,m_Unit(nullptr)
{
}

//������
void CControlCamera::Initialize(void)
{
}

//������
void CControlCamera::Initialize(aqua::CCamera* camera,IUnit* unit)
{
	m_Camera = camera;
	m_Unit = unit;

	m_Camera->m_Position = m_Unit->GetModel()->position + m_camera_length;
	m_Camera->m_TargetPosition = m_Unit->GetModel()->position;

	m_Camera->Initialize();
}

//�X�V
void CControlCamera::Update(void)
{
	aqua::CMatrix matrix = aqua::CMatrix::Ident();

	matrix.RotY(aqua::DegToRad(m_Unit->GetModel()->rotation.y));
	m_Camera->m_Position = m_Unit->GetModel()->position + aqua::CVector3(m_camera_length).Transform(matrix);
	m_Camera->m_TargetPosition = m_Unit->GetModel()->position;
	m_Camera->Update();
}