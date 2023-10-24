/*
	@file CLight.cpp
	@ライトクラス
*/

#include"light.h"
#include "../../mathematics/mathematics.h"

/*
	aqua名前空間
*/
namespace aqua
{
	const CVector3 CLight::m_default_direction = aqua::CVector3(0.0f, -1.0f, 0.0f);
	const CVector3 CLight::m_default_position = aqua::CVector3(0.0f,1000.0f,0.0f);
	const float CLight::m_default_range = 2000.0f;
	const float CLight::m_default_attenuation = 0.0f;
	const float CLight::m_default_attenuation_proportion = 0.0f;
	const float CLight::m_default_attenuation_squaring = 0.0f;

	/*
		コンストラクタ
	*/
	CLight::
	CLight(void)
		: m_Direction(m_default_direction)
		, m_Position(m_default_position)
		, m_Range(m_default_range)
		, m_Attenuation(m_default_attenuation)
		,m_AttenuationProportion(m_default_attenuation_proportion)
		,m_AttenuationSquaring(m_default_attenuation_squaring)
	{
	}

	void
	CLight::
	Initialize(void)
	{
		//標準ライトの方向を設定する
		SetLightDirection(m_Direction);

		//標準ライトの位置を設定する
		SetLightPosition(m_Position);

		//標準ライトの有効距離と距離減衰パラメータを設定する
		SetLightRangeAtten(m_Range, m_Attenuation, m_AttenuationProportion, m_AttenuationSquaring);
	}

	/*
		更新
	*/
	void
	CLight::
	Update(void)
	{
		//標準ライトの方向を設定する
		SetLightDirection(m_Direction);

		//標準ライトの位置を設定する
		SetLightPosition(m_Position);

		//標準ライトの有効距離と距離減衰パラメータを設定する
		SetLightRangeAtten(m_Range, m_Attenuation, m_AttenuationProportion, m_AttenuationSquaring);
	}

	/*
		標準ライトのタイプをディレクショナルライトにする
	*/
	void 
	CLight::
	ChangeTypeDir(const aqua::CVector3& direction)
	{
		m_Direction = direction;
		ChangeLightTypeDir(m_Direction);
	}

	/*
		標準ライトのタイプをポイントライトにする
	*/
	void 
	CLight::
	ChangeTypePoint(const aqua::CVector3& position, float range, float attenuation, float attenuation_proportion, float attenuation_squaring)
	{
		m_Position = position;
		m_Range = range;
		m_Attenuation = attenuation;
		m_AttenuationProportion = attenuation_proportion;
		m_AttenuationSquaring = attenuation_squaring;
		
		ChangeLightTypePoint(m_Position, m_Range, m_Attenuation, m_AttenuationProportion, m_AttenuationSquaring);
	}
}