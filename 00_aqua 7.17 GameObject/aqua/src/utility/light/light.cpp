/*
	@file CLight.cpp
	@���C�g�N���X
*/

#include"light.h"
#include "../../mathematics/mathematics.h"

/*
	aqua���O���
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
		�R���X�g���N�^
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
		//�W�����C�g�̕�����ݒ肷��
		SetLightDirection(m_Direction);

		//�W�����C�g�̈ʒu��ݒ肷��
		SetLightPosition(m_Position);

		//�W�����C�g�̗L�������Ƌ��������p�����[�^��ݒ肷��
		SetLightRangeAtten(m_Range, m_Attenuation, m_AttenuationProportion, m_AttenuationSquaring);
	}

	/*
		�X�V
	*/
	void
	CLight::
	Update(void)
	{
		//�W�����C�g�̕�����ݒ肷��
		SetLightDirection(m_Direction);

		//�W�����C�g�̈ʒu��ݒ肷��
		SetLightPosition(m_Position);

		//�W�����C�g�̗L�������Ƌ��������p�����[�^��ݒ肷��
		SetLightRangeAtten(m_Range, m_Attenuation, m_AttenuationProportion, m_AttenuationSquaring);
	}

	/*
		�W�����C�g�̃^�C�v���f�B���N�V���i�����C�g�ɂ���
	*/
	void 
	CLight::
	ChangeTypeDir(const aqua::CVector3& direction)
	{
		m_Direction = direction;
		ChangeLightTypeDir(m_Direction);
	}

	/*
		�W�����C�g�̃^�C�v���|�C���g���C�g�ɂ���
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