#pragma once

#include<DxLib.h>
#include"../../mathematics/vector/vector.h"

/*
	aqua���O���
*/
namespace aqua
{
	/*
		@class CCamera

		@brief �J�����N���X
	*/

	class CCamera
	{
	public:
		//!�ʒu
		CVector3 m_Position;
		//!�����_�i���Ă�����W�j
		CVector3 m_TargetPosition;
		//!�����
		CVector3 m_UpVector;

		/*
			@brief	�R���X�g���N�^
		*/
		CCamera(void);

		/*
			@brief	�f�X�g���N�^
		*/
		~CCamera(void) = default;

		void	Initialize(void);

		/*
			@brief	�X�V
		*/
		void	Update(void);

	private:

		//!�ʒu�̏����l
		static const CVector3 m_default_position;
		//!������̏����l
		static const CVector3 m_default_up_vector;
		//!��O�N���b�v�����̏����l
		static const float m_default_near;
		//!���N���b�v�����̏����l
		static const float m_default_far;
		//!����p�̏����l
		static const float m_default_fov;
	};

}