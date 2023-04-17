/*
	@file       vector3.cpp
	@brief      �O�����x�N�g��

*/

#include "vector3.h"
#include"../../../debug/debug.h"
#include<cmath>

const aqua::CVector3 aqua::CVector3::ZERO = aqua::CVector3(0.0f, 0.0f, 0.0f);
const aqua::CVector3 aqua::CVector3::ONE = aqua::CVector3(1.0f, 1.0f, 1.0f);

/*
	�R���X�g���N�^
*/
aqua::CVector3::
CVector3(void)
	:VECTOR({0.0f,0.0f,0.0f})
{
}

/*
	�R���X�g���N�^
*/
aqua::CVector3::
CVector3(float x, float y, float z)
	:VECTOR({x,y,z})
{
}

/*
	�R���X�g���N�^
*/
aqua::CVector3::
CVector3(const VECTOR& v)
	:VECTOR(v)
{
}

/*
	���K��
*/
aqua::CVector3
aqua::CVector3::
Normalize(void)
{
	return Normalize(*this);
}

/*
	���K��
*/
aqua::CVector3 aqua::CVector3::Normalize(const VECTOR& v)
{
	return VNorm(v);
}

/*
	�x�N�g���̑傫��
*/
float
aqua::CVector3::
Length(void)
{
	return Length(*this);
}

/*
	�x�N�g���̑傫��
*/
float
aqua::CVector3::
Length(const VECTOR& v)
{
	return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

/*
	����
*/
float
aqua::CVector3::
Dot(const VECTOR& vA, const VECTOR& vB)
{
	return VDot(vA,vB);
}

/*
	�O��
*/
aqua::CVector3 
aqua::CVector3::
Cross(const VECTOR& vA, const VECTOR& vB)
{
	return VCross(vA,vB);
}

/*
	�f�o�b�N���O�ɏo�͂���
*/
void
aqua::CVector3::
DebugLog(void)
{
	AQUA_DEBUG_LOG("Vector3(x:" + std::to_string(x) + ", y:" + std::to_string(y) + ", z:" + std::to_string(z) + ")");
}
