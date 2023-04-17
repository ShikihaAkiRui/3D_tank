/*
	@file camera.cpp
	@カメラクラス
*/

#include"camera.h"
#include "../../mathematics/mathematics.h"

namespace aqua
{
	const aqua::CVector3 CCamera::m_default_position = aqua::CVector3(0.0f, 10.0f, -50.0f);
	const aqua::CVector3 CCamera::m_default_up_vector = aqua::CVector3(0.0f, 1.0f, 0.0f);
	

	/*
		コンストラクタ
	*/
	CCamera::CCamera(void)
		: m_Position(m_default_position)
		, m_TargetPosition(aqua::CVector3::ZERO)
		, m_UpVector(m_default_up_vector)
	{
	}

	void CCamera::Initialize(void)
	{
		SetCameraNearFar(0.1f, 10000.0f);

		SetupCamera_Perspective(aqua::DegToRad(60.0f));

		SetCameraPositionAndTargetAndUpVec(m_Position, m_TargetPosition, m_UpVector);
	}

	/*
		更新
	*/
	void CCamera::Update(void)
	{
		SetCameraPositionAndTargetAndUpVec(m_Position, m_TargetPosition,m_UpVector);


	}
}