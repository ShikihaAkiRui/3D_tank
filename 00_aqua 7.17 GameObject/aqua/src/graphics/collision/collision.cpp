#include "collision.h"

/*
	コンストラクタ
*/
ICollision::
ICollision(void)
	:m_HitLineResult()
{
}

/*
	コリジョン情報を構築
*/
void
ICollision::
SetupCollInfo(aqua::CModel* model, int frame_index, int x_divnum, int y_divnum, int z_divnum)
{
	m_Model = model;

	MV1SetupCollInfo(m_Model->GetResourceHandle(), frame_index, x_divnum, y_divnum, z_divnum);
}

/*
	コリジョン情報の後始末
*/
void 
ICollision::
TerminateCollInfo(int frame_index)
{
	MV1TerminateCollInfo(m_Model->GetResourceHandle(), frame_index);
}

/*
	コリジョン情報の更新
*/
void
ICollision::
RefreshCollInfo(int frame_index)
{
	MV1RefreshCollInfo(m_Model->GetResourceHandle(), frame_index);
}

/*
	線分とモデルの当たり判定
*/
bool
ICollision::
CollCheckLine(int frame_index,const aqua::CVector3& pos_start,const aqua::CVector3& pos_end)
{
	m_HitLineResult = MV1CollCheck_Line(m_Model->GetResourceHandle(), frame_index, pos_start, pos_end);
	
	return m_HitLineResult.HitFlag;

}

/*
	線分とモデルの当たったかのフラグ
*/
bool 
ICollision::
GetCollCheckLineHitFlag(void)
{
	return m_HitLineResult.HitFlag;
}

/*
	線分とモデルの当たった位置 t
*/
aqua::CVector3 ICollision::GetCollCheckLineHitPosition(void)
{
	return m_HitLineResult.HitPosition;
}

/*
	線分とモデルの当たったポリゴンの法線 t
*/
aqua::CVector3
ICollision::
GetCollCheckLineNormal(void)
{
	return m_HitLineResult.Normal;
}

/*
	 玉とモデルの当たり判定
*/
bool
ICollision::
CollCheckSphere(int frame_index,const aqua::CVector3& center_pos, float radius)
{
	MV1_COLL_RESULT_POLY_DIM result = MV1CollCheck_Sphere(m_Model->GetResourceHandle(), frame_index, center_pos, radius);

	//0なら当たってない
	bool hit_flag = result.HitNum <= 0 ? false : true;

	//当たり判定結果ポリゴン配列の後始末
	CollResultPolyDimTerminate(result);

	return hit_flag;
}

/*
	カプセルとモデルの当たり判定
*/
bool
ICollision::
CollCheckCapsule(int frame_index,const aqua::CVector3& pos1,const aqua::CVector3& pos2, float radius)
{
	MV1_COLL_RESULT_POLY_DIM result = MV1CollCheck_Capsule(m_Model->GetResourceHandle(), frame_index, pos1, pos2, radius);

	//0なら当たってない
	bool hit_flag = result.HitNum <= 0 ? false : true;

	//当たり判定結果ポリゴン配列の後始末
	CollResultPolyDimTerminate(result);

	return hit_flag;
}

/*
	当たり判定結果ポリゴン配列から指定番のポリゴン情報を取得
*/
MV1_COLL_RESULT_POLY 
ICollision::
CollCheckGetResultPoly(const MV1_COLL_RESULT_POLY_DIM& result_poly_dim, int poly_no)
{
	return MV1CollCheck_GetResultPoly(result_poly_dim,poly_no);
}

/*
	当たり判定結果ポリゴン配列の後始末
*/
void
ICollision::
CollResultPolyDimTerminate(const MV1_COLL_RESULT_POLY_DIM& result_poly_dim)
{
	MV1CollResultPolyDimTerminate(result_poly_dim);
}