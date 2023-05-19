#include "control_camera.h"

const aqua::CVector3 CControlCamera::m_camera_length = aqua::CVector3(0.0f,0.0f,-50.0f);

//コンストラクタ
CControlCamera::CControlCamera(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"ControlCamera")
	,m_Camera(nullptr)
	,m_Unit(nullptr)
{
}

//初期化
void CControlCamera::Initialize(void)
{
}

//初期化
void CControlCamera::Initialize(aqua::CCamera* camera,IUnit* unit)
{
	m_Camera = camera;
	m_Unit = unit;

	m_Camera->m_Position = m_Unit->GetModel()->position + m_camera_length;
	m_Camera->m_TargetPosition = m_Unit->GetModel()->position;

	m_Camera->Initialize();
}

//更新
void CControlCamera::Update(void)
{
	m_Camera->Update();
}
