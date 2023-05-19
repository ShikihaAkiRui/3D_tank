#pragma once

#include<DxLib.h>
#include"../../mathematics/vector/vector.h"

/*
	aqua名前空間
*/
namespace aqua
{
	/*
		@class CCamera

		@brief カメラクラス
	*/

	class CCamera
	{
	public:
		//!位置
		CVector3 m_Position;
		//!注視点（見ている座標）
		CVector3 m_TargetPosition;
		//!上方向
		CVector3 m_UpVector;

		/*
			@brief	コンストラクタ
		*/
		CCamera(void);

		/*
			@brief	デストラクタ
		*/
		~CCamera(void) = default;

		void	Initialize(void);

		/*
			@brief	更新
		*/
		void	Update(void);

	private:

		//!位置の初期値
		static const CVector3 m_default_position;
		//!上方向の初期値
		static const CVector3 m_default_up_vector;
		//!手前クリップ距離の初期値
		static const float m_default_near;
		//!奥クリップ距離の初期値
		static const float m_default_far;
		//!視野角の初期値
		static const float m_default_fov;
	};

}