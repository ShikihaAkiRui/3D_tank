#pragma once

#include<DxLib.h>
#include"../../mathematics/vector/vector.h"

/*
	aqua���O���
*/
namespace aqua
{
	/*
		@class CLight

		@brief ���C�g�N���X
	*/

	class CLight
	{
	public:
		//!����
		CVector3 m_Direction;
		//!�ʒu
		CVector3 m_Position;
		//!�L������
		float m_Range;
		//!��������
		float m_Attenuation;
		//!��������(���)
		float m_AttenuationProportion;
		//!��������(���)
		float m_AttenuationSquaring;

		/*
			@brief	�R���X�g���N�^
		*/
		CLight(void);

		/*
			@brief	�f�X�g���N�^
		*/
		~CLight(void) = default;

		void	Initialize(void);

		/*
			@brief	�X�V
		*/
		void	Update(void);

		/*
			@brief	�W�����C�g�̃^�C�v���f�B���N�V���i�����C�g�ɂ���

			@param[in]	direction	����
		*/
		void ChangeTypeDir(const aqua::CVector3& direction);
		
		/*
			@brief	�W�����C�g�̃^�C�v���|�C���g���C�g�ɂ���

			@param[in]	position	�ʒu
			@param[in]	range	�L������
			@param[in]	attenuation	��������
			@param[in]	attenuation_proportion	��������(���)
			@param[in]	attenuation_squaring	��������(���)
		*/
		void	ChangeTypePoint(const aqua::CVector3& position, float range, float attenuation, float attenuation_proportion, float attenuation_squaring);

	private:

		//!�����̏����l
		static const CVector3 m_default_direction;
		//!�ʒu�̏����l
		static const CVector3 m_default_position;
		//!�L�������̏����l
		static const float m_default_range;
		//!���������̏����l
		static const float m_default_attenuation;
		//!��������(���)�̏����l
		static const float m_default_attenuation_proportion;
		//!��������(���)�̏����l
		static const float m_default_attenuation_squaring;
	};

}