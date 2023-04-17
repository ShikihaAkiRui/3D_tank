#pragma once

#include<DxLib.h>
#include"../../mathematics/vector/vector.h"

namespace aqua
{
	/*
		@class CCamera

		@brief カメラクラス
	*/

	class CCamera
	{
	public:
		/*
			コンストラクタ
		*/
		CCamera(void);

		/*
			デストラクタ
		*/
		~CCamera(void) = default;

		void Initialize(void);

		/*
			更新
		*/
		void Update(void);

	private:
		//!位置
		CVector3 m_Position;
		//!注視点（見ている座標）
		CVector3 m_TargetPosition;
		//!上方向
		CVector3 m_UpVector;

		static const CVector3 m_default_position;
		static const CVector3 m_default_up_vector;
	};

}