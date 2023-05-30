#include "control_camera.h"
#include"../stage/stage.h"

const aqua::CVector3 CControlCamera::m_camera_length = aqua::CVector3(0.0f, 30.0f, -100.0f);
const aqua::CVector2 CControlCamera::m_angle_variation = aqua::CVector2(0.1, 0.1f);

//コンストラクタ
CControlCamera::CControlCamera(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"ControlCamera")
	,m_Camera(nullptr)
	,m_Unit(nullptr)
	,m_Angle(aqua::CVector2::ZERO)
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
	aqua::CMatrix matrix = aqua::CMatrix::Ident();
	
	/*
	matrix.RotY(aqua::DegToRad(m_Unit->GetModel()->rotation.y));
	m_Camera->m_Position = m_Unit->GetModel()->position + aqua::CVector3(m_camera_length).Transform(matrix);
	m_Camera->m_TargetPosition = m_Unit->GetModel()->position;
	m_Camera->Update();
	*/


	aqua::CPoint mouse = aqua::mouse::GetCursorMovement();

	m_Angle.x += mouse.x * m_angle_variation.x;
	m_Angle.y += mouse.y * m_angle_variation.y;

	matrix.RotX(aqua::DegToRad(m_Angle.y));
	matrix.RotY(aqua::DegToRad(m_Angle.x));


	CStage* stage = (CStage*)aqua::FindGameObject("Stage");
	if (!stage)return;

	m_Camera->m_Position = m_Unit->GetModel()->position + aqua::CVector3(m_camera_length).Transform(matrix);

	//床と当たってたら
	if (stage->CollCheckLine(-1, m_Camera->m_Position, m_Camera->m_Position + aqua::CVector3(0.0f,10.0f,0.0f)))
	{
		aqua::CVector3 hit_position;

		hit_position = stage->GetCollCheckLineHitPosition(-1, m_Camera->m_Position, m_Camera->m_Position + aqua::CVector3(0.0f, 10.0f, 0.0f));

		m_Camera->m_Position.y = hit_position.y - 10.0f;
	}


	m_Camera->m_TargetPosition = m_Unit->GetModel()->position;
	m_Camera->Update();
}