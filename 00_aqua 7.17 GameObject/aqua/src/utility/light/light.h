#pragma once

#include<DxLib.h>
#include"../../mathematics/vector/vector.h"

/*
	aqua名前空間
*/
namespace aqua
{
	/*
		@class CLight

		@brief ライトクラス
	*/

	class CLight
	{
	public:
		//!方向
		CVector3 m_Direction;
		//!位置
		CVector3 m_Position;
		//!有効距離
		float m_Range;
		//!距離減衰
		float m_Attenuation;
		//!距離減衰(比例)
		float m_AttenuationProportion;
		//!距離減衰(二乗)
		float m_AttenuationSquaring;

		/*
			@brief	コンストラクタ
		*/
		CLight(void);

		/*
			@brief	デストラクタ
		*/
		~CLight(void) = default;

		void	Initialize(void);

		/*
			@brief	更新
		*/
		void	Update(void);

		/*
			@brief	標準ライトのタイプをディレクショナルライトにする

			@param[in]	direction	方向
		*/
		void ChangeTypeDir(const aqua::CVector3& direction);
		
		/*
			@brief	標準ライトのタイプをポイントライトにする

			@param[in]	position	位置
			@param[in]	range	有効距離
			@param[in]	attenuation	距離減衰
			@param[in]	attenuation_proportion	距離減衰(比例)
			@param[in]	attenuation_squaring	距離減衰(二乗)
		*/
		void	ChangeTypePoint(const aqua::CVector3& position, float range, float attenuation, float attenuation_proportion, float attenuation_squaring);

	private:

		//!方向の初期値
		static const CVector3 m_default_direction;
		//!位置の初期値
		static const CVector3 m_default_position;
		//!有効距離の初期値
		static const float m_default_range;
		//!距離減衰の初期値
		static const float m_default_attenuation;
		//!距離減衰(比例)の初期値
		static const float m_default_attenuation_proportion;
		//!距離減衰(二乗)の初期値
		static const float m_default_attenuation_squaring;
	};

}