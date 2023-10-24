#include "control_light.h"

const aqua::CVector3 CControlLight::m_position = aqua::CVector3(0.0f,1500.0f,0.0f);
const float CControlLight::m_range = 2300.0f;
const float CControlLight::m_attenuation = 0.0f;
const float CControlLight::m_attenuation_proportion = 0.00065f;
const float CControlLight::m_attenuation_squaring = 0.0f;

//コンストラクタ
CControlLight::CControlLight(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"ControlLight")
{
}

//初期化
void CControlLight::Initialize(aqua::CLight* light)
{
	m_Light = light;
	
	//ポイントライトに変更
	m_Light->ChangeTypePoint(m_position, m_range, m_attenuation, m_attenuation_proportion, m_attenuation_squaring);

	m_Light->Initialize();
}

//更新
void CControlLight::Update(void)
{
	m_Light->Update();
}
