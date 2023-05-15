/*
	@file       matrix.cpp
	@brief      行列

*/

#include "matrix.h"

/*
	コンストラクタ
*/
aqua::CMatrix::
CMatrix(void)
	:MATRIX({ {{0.0f,0.0f,0.0f,0.0f},
			   {0.0f,0.0f,0.0f,0.0f},
			   {0.0f,0.0f,0.0f,0.0f},
			   {0.0f,0.0f,0.0f,0.0f}} })
{
}

/*
	コンストラクタ
*/
aqua::CMatrix::
CMatrix(const MATRIX& matrix)
	:MATRIX(matrix)
{
}

/*
	単位行列を取得
*/
aqua::CMatrix
aqua::CMatrix::
Ident(void)
{
	return MGetIdent();
}

/*
	拡大行列を取得
*/
aqua::CMatrix
aqua::CMatrix::
Scale(const VECTOR& scale)
{
	*this *= MGetScale(scale);

	return *this;
}

/*
	平行移動行列を取得
*/
aqua::CMatrix
aqua::CMatrix::
Translate(const VECTOR& trans)
{
	*this *= MGetTranslate(trans);

	return *this;
}

/*
	X軸回転行列を取得
*/
aqua::CMatrix
aqua::CMatrix::
RotX(float x_axis_rotate)
{
	*this *= MGetRotX(x_axis_rotate);

	return *this;
}

/*
	Y軸回転行列を取得
*/
aqua::CMatrix
aqua::CMatrix::
RotY(float y_axis_rotate)
{
	*this *= MGetRotY(y_axis_rotate);

	return *this;
}

/*
	Z軸回転行列を取得
*/
aqua::CMatrix
aqua::CMatrix::
RotZ(float z_axis_rotate)
{
	*this *= MGetRotZ(z_axis_rotate);

	return *this;
}

/*
	指定軸で指定角度回転する行列を取得
*/
aqua::CMatrix
aqua::CMatrix::
RotAxis(VECTOR rotate_axis, float rotate)
{
	*this *= MGetRotAxis(rotate_axis, rotate);

	return *this;
}

/*
	転置行列を取得
*/
aqua::CMatrix
aqua::CMatrix::
Transpose(void)
{
	return Transpose(*this);
}

/*
	転置行列を取得
*/
aqua::CMatrix
aqua::CMatrix::
Transpose(const MATRIX& matrix)
{
	return MTranspose(matrix);
}

/*
	逆行列を取得
*/
aqua::CMatrix
aqua::CMatrix::
Inverse(void)
{
	return Inverse(*this);
}

/*
	逆行列を取得
*/
aqua::CMatrix
aqua::CMatrix::
Inverse(const MATRIX& matrix)
{
	return MInverse(matrix);
}

/*
	加算演算子のオーバーロード
*/
aqua::CMatrix& 
aqua::CMatrix::
operator+=(const MATRIX& matrix)
{
	*this = MAdd(*this, matrix);

	return *this;
}

/*
	乗算演算子のオーバーロード
*/
aqua::CMatrix&
aqua::CMatrix::
operator*=(const MATRIX& matrix)
{
	*this = MMult(*this, matrix);

	return *this;
}

/*
	乗算演算子のオーバーロード
*/
aqua::CMatrix&
aqua::CMatrix::
operator*=(float scale)
{
	*this = MScale(*this, scale);
	return *this;
}

/*
	加算演算子のオーバーロード
*/
aqua::CMatrix
aqua::operator+(const MATRIX& mA, const MATRIX& mB)
{
	return MAdd(mA,mB);
}

/*
	乗算演算子のオーバーロード
*/
aqua::CMatrix
aqua::operator*(const MATRIX& mA, const MATRIX& mB)
{
	return MMult(mA,mB);
}

/*
	乗算演算子のオーバーロード
*/
aqua::CMatrix
aqua::operator*(const MATRIX& matrix,float scale)
{
	return MScale(matrix,scale);
}
