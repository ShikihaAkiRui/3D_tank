/*
	@file camera.cpp
	@�J�����N���X
*/

#include"camera.h"
#include "../../mathematics/mathematics.h"

/*
	aqua���O���
*/
namespace aqua
{
	const CVector3 CCamera::m_default_position = CVector3(0.0f, 0.0f, -50.0f);
	const CVector3 CCamera::m_default_up_vector = CVector3(0.0f, 1.0f, 0.0f);
	const float CCamera::m_default_near = 0.1f;
	const float CCamera::m_default_far = 10000.0f;
	const float CCamera::m_default_fov = 60.0f;
	

	/*
		�R���X�g���N�^
	*/
	CCamera::
	CCamera(void)
		: m_Position(m_default_position)
		, m_TargetPosition(CVector3::ZERO)
		, m_UpVector(m_default_up_vector)
	{
	}

	void 
	CCamera::
	Initialize(void)
	{
		//��O�N���b�v�����Ɖ��N���b�v������ݒ�
		SetCameraNearFar(m_default_near, m_default_far);

		//���ߖ@�J������ݒ�
		SetupCamera_Perspective(DegToRad(m_default_fov));

		//���_�A�����_�A������ݒ�
		SetCameraPositionAndTargetAndUpVec(m_Position, m_TargetPosition, m_UpVector);
	}

	/*
		�X�V
	*/
	void 
	CCamera::
	Update(void)
	{
		//���_�A�����_�A������ݒ�
		SetCameraPositionAndTargetAndUpVec(m_Position, m_TargetPosition,m_UpVector);
	}
}