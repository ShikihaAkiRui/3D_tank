#pragma once

#include<DxLib.h>
#include"../mathematics.h"

/*
	aqua���O���
*/
namespace aqua
{
	/*
		@class	CMatrix

		@brief	�}�g���N�X�N���X	
	*/
	class CMatrix : private MATRIX
	{
	public:
		/*
			@brief	�R���X�g���N�^
		*/
		CMatrix(void);

		/*
			@brief	�R���X�g���N�^

			@param	matrix	�}�g���N�X�N���X
		*/
		CMatrix(const MATRIX& matrix);


		/*
			@brief	�f�X�g���N�^
		*/
		~CMatrix(void) = default;


		/*
			@brief	�P�ʍs����擾

			@return	�P�ʍs��
		*/
		static CMatrix Ident(void);

		/*
			@brief	�g��s����擾

			@param[in]	scale	�g�嗦

			@return	�g��s��
		*/
		CMatrix Scale(const VECTOR& scale);

		/*
			@brief	���s�ړ��s����擾

			@param[in]	trans	���s�ړ��l

			@return	���s�ړ��s��
		*/
		CMatrix Translate(const VECTOR& trans);

		/*
			@brief	X����]�s����擾

			@param[in]	x_axis_rotate	��]�l(�P��:���W�A��)

			@return	X����]�s��
		*/
		CMatrix RotX(float x_axis_rotate);

		/*
			@brief	Y����]�s����擾

			@param[in]	y_axis_rotate	��]�l(�P��:���W�A��)

			@return	Y����]�s��
		*/
		CMatrix RotY(float y_axis_rotate);

		/*
			@brief	Z����]�s����擾

			@param[in]	z_axis_rotate	��]�l(�P��:���W�A��)

			@return	Z����]�s��
		*/
		CMatrix	RotZ(float z_axis_rotate);

		/*
			@brief	�w�莲�Ŏw��p�x��]����s����擾

			@param[in]	rotate_axis	��]��
			@param[in]	rotate	��]�l(�P��:���W�A��)

			@return	��]�s��
		*/
		CMatrix RotAxis(VECTOR rotate_axis, float rotate);

		/*
			@brief	�]�u�s����擾

			@return	�]�u�������ʂ̍s��
		*/
		CMatrix Transpose(void);

		/*
			@brief	�]�u�s����擾

			@param[in]	matrix	�}�g���N�X�N���X

			@return �]�u�������ʂ̍s��
		*/
		static CMatrix Transpose(const MATRIX& matrix);

		/*
			@brief	�t�s����擾

			@return	�t�s��
		*/
		CMatrix Inverse(void);

		/*
			@brief	�t�s����擾

			@param[in]	matrix	�}�g���N�X�N���X

			@return	�t�s��
		*/
		static CMatrix Inverse(const MATRIX& matrix);


		/*
			@brief	���Z���Z�q�̃I�[�o�[���[�h

			@param[in]	matrix	�}�g���N�X�N���X

			@return	�}�g���N�X�N���X
		*/
		CMatrix& operator+=(const MATRIX& matrix);

		/*
			@brief	��Z���Z�q�̃I�[�o�[���[�h

			@param[in]	matrix	�}�g���N�X�N���X

			@return	�}�g���N�X�N���X

		*/
		CMatrix& operator*=(const MATRIX& matrix);

		/*
			@brief	��Z���Z�q�̃I�[�o�[���[�h

			@param[in]	scale	�X�P�[�����O�l

			@return	�}�g���N�X�N���X

		*/
		CMatrix& operator*=(float scale);

		/*
			@brief	���Z���Z�q�̃I�[�o�[���[�h

			@param[in]	mA	�}�g���N�X�N���X
			@pstsm[in]	mB	�}�g���N�X�N���X

			@return	�}�g���N�X�N���X
		*/
		friend CMatrix operator+(const MATRIX & mA, const MATRIX & mB);

		/*
			@brief	��Z���Z�q�̃I�[�o�[���[�h

			@param[in]	mA	�}�g���N�X�N���X
			@pstsm[in]	mB	�}�g���N�X�N���X

			@return	�}�g���N�X�N���X
		*/
		friend CMatrix operator*(const MATRIX & mA, const MATRIX & mB);

		/*
			@brief	��Z���Z�q�̃I�[�o�[���[�h

			@param[in]	matrix	�}�g���N�X�N���X
			@param[in]	scale	�X�P�[�����O�l

			@return	�}�g���N�X�N���X
		*/
		friend CMatrix operator*(const MATRIX& matrix, float scale);

	};

}