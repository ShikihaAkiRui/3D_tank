/*
	@file       matrix.cpp
	@brief      �s��

*/

#include "matrix.h"

/*
	�R���X�g���N�^
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
	�R���X�g���N�^
*/
aqua::CMatrix::
CMatrix(const MATRIX& matrix)
	:MATRIX(matrix)
{
}

/*
	�P�ʍs����擾
*/
aqua::CMatrix
aqua::CMatrix::
Ident(void)
{
	return MGetIdent();
}

/*
	�g��s����擾
*/
aqua::CMatrix
aqua::CMatrix::
Scale(const VECTOR& scale)
{
	*this *= MGetScale(scale);

	return *this;
}

/*
	���s�ړ��s����擾
*/
aqua::CMatrix
aqua::CMatrix::
Translate(const VECTOR& trans)
{
	*this *= MGetTranslate(trans);

	return *this;
}

/*
	X����]�s����擾
*/
aqua::CMatrix
aqua::CMatrix::
RotX(float x_axis_rotate)
{
	*this *= MGetRotX(x_axis_rotate);

	return *this;
}

/*
	Y����]�s����擾
*/
aqua::CMatrix
aqua::CMatrix::
RotY(float y_axis_rotate)
{
	*this *= MGetRotY(y_axis_rotate);

	return *this;
}

/*
	Z����]�s����擾
*/
aqua::CMatrix
aqua::CMatrix::
RotZ(float z_axis_rotate)
{
	*this *= MGetRotZ(z_axis_rotate);

	return *this;
}

/*
	�w�莲�Ŏw��p�x��]����s����擾
*/
aqua::CMatrix
aqua::CMatrix::
RotAxis(VECTOR rotate_axis, float rotate)
{
	*this *= MGetRotAxis(rotate_axis, rotate);

	return *this;
}

/*
	�]�u�s����擾
*/
aqua::CMatrix
aqua::CMatrix::
Transpose(void)
{
	return Transpose(*this);
}

/*
	�]�u�s����擾
*/
aqua::CMatrix
aqua::CMatrix::
Transpose(const MATRIX& matrix)
{
	return MTranspose(matrix);
}

/*
	�t�s����擾
*/
aqua::CMatrix
aqua::CMatrix::
Inverse(void)
{
	return Inverse(*this);
}

/*
	�t�s����擾
*/
aqua::CMatrix
aqua::CMatrix::
Inverse(const MATRIX& matrix)
{
	return MInverse(matrix);
}

/*
	���Z���Z�q�̃I�[�o�[���[�h
*/
aqua::CMatrix& 
aqua::CMatrix::
operator+=(const MATRIX& matrix)
{
	*this = MAdd(*this, matrix);

	return *this;
}

/*
	��Z���Z�q�̃I�[�o�[���[�h
*/
aqua::CMatrix&
aqua::CMatrix::
operator*=(const MATRIX& matrix)
{
	*this = MMult(*this, matrix);

	return *this;
}

/*
	��Z���Z�q�̃I�[�o�[���[�h
*/
aqua::CMatrix&
aqua::CMatrix::
operator*=(float scale)
{
	*this = MScale(*this, scale);
	return *this;
}

/*
	���Z���Z�q�̃I�[�o�[���[�h
*/
aqua::CMatrix
aqua::operator+(const MATRIX& mA, const MATRIX& mB)
{
	return MAdd(mA,mB);
}

/*
	��Z���Z�q�̃I�[�o�[���[�h
*/
aqua::CMatrix
aqua::operator*(const MATRIX& mA, const MATRIX& mB)
{
	return MMult(mA,mB);
}

/*
	��Z���Z�q�̃I�[�o�[���[�h
*/
aqua::CMatrix
aqua::operator*(const MATRIX& matrix,float scale)
{
	return MScale(matrix,scale);
}
