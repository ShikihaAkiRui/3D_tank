/*
	@file       animation_model.h
    @brief      アニメーションモデル
 */

#pragma once

#include<DxLib.h>
#include"../model/model.h"

 /*
	 aqua名前空間
 */
namespace aqua
{
	/*
	   @class      CAnimationModel

	   @brief      アニメーションモデルクラス
	*/
	class CAnimationModel
	{
	public:
		/*
			コンストラクタ
		*/
		CAnimationModel(void);

		/*
			デストラクタ
		*/
		~CAnimationModel(void) = default;

		/*
			@brief	フレームの座標変換行列を設定

			@param[in]	model	モデルのポインタ
			@param[in]	frame_index	フレーム番号
			@param[in]	matrix	フレームに設定する変換行列
		*/
		static void SetFrameUserLocalMatrix(aqua::CModel* model, int frame_index, const aqua::CMatrix& matrix);
	};
}