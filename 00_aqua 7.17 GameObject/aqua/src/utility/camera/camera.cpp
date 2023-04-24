/*
	@file camera.cpp
	@カメラクラス
*/

#include"camera.h"
#include "../../mathematics/mathematics.h"

/*
	aqua名前空間
*/
namespace aqua
{
	const CVector3 CCamera::m_default_position = CVector3(0.0f, 0.0f, -50.0f);
	const CVector3 CCamera::m_default_up_vector = CVector3(0.0f, 1.0f, 0.0f);
	const float CCamera::m_default_near = 0.1f;
	const float CCamera::m_default_far = 10000.0f;
	const float CCamera::m_default_fov = 60.0f;
	

	/*
		コンストラクタ
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
		//手前クリップ距離と奥クリップ距離を設定
		SetCameraNearFar(m_default_near, m_default_far);

		//遠近法カメラを設定
		SetupCamera_Perspective(DegToRad(m_default_fov));

		//視点、注視点、上方向設定
		SetCameraPositionAndTargetAndUpVec(m_Position, m_TargetPosition, m_UpVector);
	}

	/*
		更新
	*/
	void 
	CCamera::
	Update(void)
	{
		//視点、注視点、上方向設定
		SetCameraPositionAndTargetAndUpVec(m_Position, m_TargetPosition,m_UpVector);
	}
}