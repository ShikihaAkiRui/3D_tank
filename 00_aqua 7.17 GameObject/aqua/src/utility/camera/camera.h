#pragma once

#include<DxLib.h>
#include"../../mathematics/vector/vector.h"

namespace aqua
{
	/*
		@class CCamera

		@brief �J�����N���X
	*/

	class CCamera
	{
	public:
		/*
			�R���X�g���N�^
		*/
		CCamera(void);

		/*
			�f�X�g���N�^
		*/
		~CCamera(void) = default;

		void Initialize(void);

		/*
			�X�V
		*/
		void Update(void);

	private:
		//!�ʒu
		CVector3 m_Position;
		//!�����_�i���Ă�����W�j
		CVector3 m_TargetPosition;
		//!�����
		CVector3 m_UpVector;

		static const CVector3 m_default_position;
		static const CVector3 m_default_up_vector;
	};

}