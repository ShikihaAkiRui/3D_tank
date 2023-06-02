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

		@param[in]	model	モデル情報
		@param[in]	frame_index	コリジョンの情報を構築するフレームの番号
		@param[in]	x_divnum	コリジョン情報のx軸方向の空間分割数
		@param[in]	y_divnum	コリジョン情報のy軸方向の空間分割数
		@param[in]	z_divnum	コリジョン情報のz軸方向の空間分割数
	*/
	void	SetupCollInfo(aqua::CModel* model,int frame_index,int x_divnum,int y_divnum,int z_divnum);

	/*
		@brief	コリジョン情報の後始末

		@param[in]	frame_index	コリジョンの情報を後始末を行うフレーム番号
	*/
	void	TerminateCollInfo(int frame_index);

	/*
		@brief	コリジョン情報の更新

		@param[in]	frame_index	コリジョンの情報を更新するフレームの番号
	*/
	void	RefreshCollInfo(int frame_index);

	/*
		@brief	線分とモデルの当たり判定

		@param[in]	frame_index	コリジョンの情報を更新するフレームの番号
		@param[in]	pos_start	当たり判定で使用する線分の始点
		@param[in]	pos_end		当たり判定で使用する線分の終点

		@return 当たったどうか
	*/
	bool	CollCheckLine(int frame_index, const aqua::CVector3& pos_start, const aqua::CVector3& pos_end);
	
	/*
		@brief 線分とモデルの当たったかのフラグ

		@return 当たったどうか
	*/
	bool	GetCollCheckLineHitFlag(void);

	/*
		@brief 線分とモデルの当たった位置

		@return 当たった位置
	*/
	aqua::CVector3	GetCollCheckLineHitPosition(void);

	/*
		@brief	線分とモデルの当たったポリゴンの法線

		@return 当たったポリゴンの法線
	*/
	aqua::CVector3	GetCollCheckLineNormal(void);

	/*
		@brief 玉とモデルの当たり判定

		@param[in]	frame_index	コリジョンの情報を更新するフレームの番号
		@param[in]	center_pos	当たり判定に使用する球の中心座標
		@param[in]	radius	当たり判定で使用する球の半径
		
		@return	当たったどうか
	*/
	bool	CollCheckSphere( int frame_index,const aqua::CVector3& center_pos, float radius);

	/*
		@brief	カプセルとモデルの当たり判定

		@param[in]	frame_index コリジョン情報を更新するフレームの番号
		@param[in]	pos1	カプセルを生成する2点中の１点の座標
		@param[in]	pos2	カプセルを生成する2点中の１点の座標
		@param[in]	radius	カプセルの半径

		@return 当たったどうか
	*/
	bool	CollCheckCapsule(int frame_index,const aqua::CVector3& pos1,const aqua::CVector3& pos2, float radius);

	/*
		@brief	当たり判定結果ポリゴン配列から指定番のポリゴン情報を取得

		@param[in]	result_poly_dim	当たり判定結果ポリゴン配列構造体
		@param[in]	poly_no	取得したいポリゴンの番号

		@return 当たり判定結果ポリゴン
	*/
	MV1_COLL_RESULT_POLY	CollCheckGetResultPoly(const MV1_COLL_RESULT_POLY_DIM& result_poly_dim, int poly_no);

	/*
		@brief	当たり判定結果ポリゴン配列の後始末

		@param[in]	result_poly_dim	当たり判定結果ポリゴン配列構造体
	*/
	void	CollResultPolyDimTerminate(const MV1_COLL_RESULT_POLY_DIM& result_poly_dim);

	//!モデルのポインタ
	aqua::CModel* m_Model;
	
	//線分が当たったのデータ
	MV1_COLL_RESULT_POLY m_HitLineResult;
};