/*
	@file	collision.h

	@brief	コリジョン
*/

#pragma once
#include"../model/model.h"

/*
	@class ICollision
	
	@brief	コリジョンクラス
*/
class ICollision
{
public:
	/*
		@brief	コンストラクタ
	*/
	ICollision(void);

	/*
		@brief	デストラクタ
	*/
	~ICollision(void) = default;

	/*
		@brief	コリジョン情報を構築

		@param[in]	handle	ハンドル情報
		@param[in]	frame_index	コリジョンの情報を構築するフレームの番号
		@param[in]	x_divnum	コリジョン情報のx軸方向の空間分割数
		@param[in]	y_divnum	コリジョン情報のy軸方向の空間分割数
		@param[in]	z_divnum	コリジョン情報のz軸方向の空間分割数
	*/
	void SetupCollision(aqua::CModel* handle,int frame_index,int x_divnum,int y_divnum,int z_divnum);

	/*
		@brief	コリジョン情報の後始末

		@param[in]	handle	モデルのハンドル
		@param[in]	frame_index	コリジョンの情報を後始末を行うフレーム番号
	*/
	void TerminateCollision(aqua::CModel* handle, int frame_index);

	/*
		@brief	コリジョン情報の更新

		@param[in]	handle	モデルのハンドル
		@param[in]	frame_index	コリジョンの情報を更新するフレームの番号
	*/
	void RefreshCollision(aqua::CModel* handle, int frame_index);

	/*
		@brief	線分とモデルの当たり判定

		@param[in]	handle	モデルのハンドル
		@param[in]	frame_index	コリジョンの情報を更新するフレームの番号
		@param[in]	pos_start	当たり判定で使用する線分の始点
		@param[in]	pos_end		当たり判定で使用する線分の終点

		@return 当たり判定結果構造体
	*/
	MV1_COLL_RESULT_POLY CollCheckLine(aqua::CModel* handle, int frame_index, VECTOR pos_start, VECTOR pos_end);
	
	/*
		@brief 玉とモデルの当たり判定

		@param[in]	handle	モデルハンドル
		@param[in]	frame_index	コリジョンの情報を更新するフレームの番号
		@param[in]	center_pos	当たり判定に使用する球の中心座標
		@param[in]	radius	当たり判定で使用する球の半径
		
		@return	当たり判定結果ポリゴン配列構造体
	*/
	MV1_COLL_RESULT_POLY_DIM CollCheckSphere(aqua::CModel* handle, int frame_index, VECTOR center_pos, float radius);
};