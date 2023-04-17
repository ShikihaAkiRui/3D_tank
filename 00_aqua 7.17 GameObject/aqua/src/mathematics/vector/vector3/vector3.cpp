/*
	@file       vector3.cpp
	@brief      三次元ベクトル

*/

#include "vector3.h"
#include"../../../debug/debug.h"
#include<cmath>

const aqua::CVector3 aqua::CVector3::ZERO = aqua::CVector3(0.0f, 0.0f, 0.0f);
const aqua::CVector3 aqua::CVector3::ONE = aqua::CVector3(1.0f, 1.0f, 1.0f);

/*
	コンストラクタ
*/
aqua::CVector3::
CVector3(void)
	:VECTOR({0.0f,0.0f,0.0f})
{
}

/*
	コンストラクタ
*/
aqua::CVector3::
CVector3(float x, float y, float z)
	:VECTOR({x,y,z})
{
}

/*
	コンストラクタ
*/
aqua::CVector3::
CVector3(const VECTOR& v)
	:VECTOR(v)
{
}

/*
	正規化
*/
aqua::CVector3
aqua::CVector3::
Normalize(void)
{
	return Normalize(*this);
}

/*
	正規化
*/
aqua::CVector3 aqua::CVector3::Normalize(const VECTOR& v)
{
	return VNorm(v);
}

/*
	ベクトルの大きさ
*/
float
aqua::CVector3::
Length(void)
{
	return Length(*this);
}

/*
	ベクトルの大きさ
*/
float
aqua::CVector3::
Length(const VECTOR& v)
{
	return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

/*
	内積
*/
float
aqua::CVector3::
Dot(const VECTOR& vA, const VECTOR& vB)
{
	return VDot(vA,vB);
}

/*
	外積
*/
aqua::CVector3 
aqua::CVector3::
Cross(const VECTOR& vA, const VECTOR& vB)
{
	return VCross(vA,vB);
}

/*
	デバックログに出力する
*/
void
aqua::CVector3::
DebugLog(void)
{
	AQUA_DEBUG_LOG("Vector3(x:" + std::to_string(x) + ", y:" + std::to_string(y) + ", z:" + std::to_string(z) + ")");
}
