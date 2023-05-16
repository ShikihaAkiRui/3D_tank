#pragma once

#include<DxLib.h>

/*
	aqua���O���
*/
namespace aqua
{
	class CMatrix;

	/*
		@class	CVector3

		@brief	�O�����x�N�g���N���X
	*/

	class CVector3 : public VECTOR
	{
	public:
		/*
			@brief	�R���X�g���N�^
		*/
		CVector3(void);

		/*
			@brief	�R���X�g���N�^

			@param[in]	x	x����
			@param[in]	y	y����
			@param[in]	z	z����
		*/
		CVector3(float x,float y,float z);

		/*
			@brief	�R���X�g���N�^

			@param[in]	v	�x�N�g��
		*/
		CVector3(const VECTOR& v);

		/*
			@brief	�f�X�g���N�^
		*/
		~CVector3(void) = default;

		/*
			@brief	�x�N�g���̐��K��<br>
					���g�̃x�N�g�������K�������

			@return	���K�����ꂽ�x�N�g��
		*/
		CVector3	Normalize(void);

		/*
			@brief	�x�N�g���̐��K��		

			@param[in]	v	�x�N�g���N���X

			@return	���K�����ꂽ�x�N�g��
		*/
		static CVector3	Normalize(const VECTOR& v);

		/*
			@brief	�x�N�g���̑傫���擾
			
			@return	�x�N�g���̑傫��
		*/
		float	Length(void);

		/*
			@brief	�x�N�g���̑傫���擾

			@param[in]	v �x�N�g���N���X

			@return	�x�N�g���̑傫��
		*/
		static float Length(const VECTOR& v);

		/*
			@brief	2�̃x�N�g���̓���<br>

			@param[in]	vA	�x�N�g���N���X	
			@param[in]	vB	�x�N�g���N���X	

			@return	����
		*/
		static float Dot(const VECTOR& vA, const VECTOR& vB);

		/*
			@brief	2�̃x�N�g���̊O��<br>

			@param[in]	vA	�x�N�g���N���X
			@param[in]	vB	�x�N�g���N���X

			@return	�O��
		*/
		static CVector3 Cross(const VECTOR& vA, const VECTOR& vB);

		/*
			@brief �s����g�����x�N�g���ϊ�

			@param[in] vector	�ϊ��������s�������x�N�g��
			@param[in] matrix	�ϊ������Ɏg�p����x�N�g��

			@return �ϊ���̃x�N�g��
		*/
		CVector3& Transform(const CMatrix& matrix);

		/*
			@brief	������Z�q�̃I�[�o�[���[�h

			@param[in]	v	�x�N�g���N���X

			@return	�x�N�g���N���X
		*/
		CVector3& operator=(const VECTOR& v)
		{
			x = v.x;
			y = v.y;
			z = v.z;

			return *this;
		}

		/*
			@brief ���Z���Z�q�̃I�[�o�[���[�h

			@param[in]	v	�x�N�g���N���X

			@return�@�x�N�g���N���X
		*/
		CVector3& operator+=(const VECTOR& v)
		{
			x += v.x;
			y += v.y;
			z += v.z;

			return *this;
		}

		/*
			@brief	���Z���Z�q�̃I�[�o�[���[�h

			@param[in]	v	�x�N�g���N���X

			@return	�x�N�g���N���X
		*/
		CVector3& operator-=(const VECTOR& v)
		{
			x -= v.x;
			y -= v.y;
			z -= v.z;

			return *this;
		}

		/*
			@brief	��Z���Z�q�̃I�[�o�[���[�h

			@param[in]	v	�x�N�g���N���X

			@return	�x�N�g���N���X
		*/
		CVector3& operator*=(float scalar)
		{
			x *= scalar;
			y *= scalar;
			z *= scalar;

			return *this;
		}
		
		/*
			@brief	�������Z�q�̃I�[�o�[���[�h

			@param[in]	v �x�N�g���N���X

			@return ��̃x�N�g����������
			@retval true	������
			@retval false	�������Ȃ�
		*/
		bool	operator==(const VECTOR& v)const 
		{
			return(x == v.x && y == v.y && z == v.z);
		}

		/*
			@brief	�s�����Z�q�̃I�[�o�[���[�h

			@param[in] v �x�N�g���N���X

			@return ��̃x�N�g�����������Ȃ�
			@retval	ture	�������Ȃ�
			@retval	false	������
		*/
		bool	operator!=(const VECTOR& v)const
		{
			return(x != v.x || y != v.y || z != v.z);
		}

		/*
			@brief	���������Z�q�̃I�[�o�[���[�h

			@param[in] v �x�N�g���N���X

			@return �x�N�g���N���X
		*/
		friend CVector3 operator+(const VECTOR& v) { return v; }

		/*
			@brief ���������Z�q�̃I�[�o�[���[�h

			@param[in]	v	�x�N�g���N���X

			@return �x�N�g���N���X
		*/
		friend CVector3 operator-(const VECTOR& v) { return CVector3(-v.x, -v.y, -v.z); }

		/*
			@brief	���Z���Z�q�̃I�[�o�[���[�h

			@param[in]	vA	�x�N�g���N���X
			@param[in]	vB	�x�N�g���N���X

			@return	�x�N�g���N���X
		*/
		friend CVector3 operator+(const VECTOR& vA, const VECTOR& vB) { return CVector3(vA.x + vB.x, vA.y + vB.y, vA.z + vB.z); }

		/*
			@brief	���Z���Z�q�̃I�[�o�[���[�h

			@param[in]	vA	�x�N�g���N���X
			@param[in]	vB	�x�N�g���N���X

			@return �x�N�g���N���X
		*/
		friend CVector3 operator-(const VECTOR& vA, const VECTOR& vB) { return CVector3(vA.x - vB.x, vA.y - vB.y, vA.z - vB.z); }

		/*
			@brief  ��Z���Z�q�̃I�[�o�[���[�h

			@param[in]	vA	�x�N�g���N���X
			@param[in]	vB	�x�N�g���N���X

			@return �x�N�g���N���X
		*/
		friend CVector3 operator*(const VECTOR& vA, const VECTOR& vB) { return CVector3(vA.x * vB.x, vA.y * vB.y, vA.z * vB.z); }

		/*
			@brief  ��Z���Z�q�̃I�[�o�[���[�h

			@param[in]	v	�x�N�g���N���X
			@param[in]	scalar	�X�J���[�l

			@return �x�N�g���N���X
		*/
		friend CVector3 operator*(const VECTOR& v, float scalar) { return CVector3(v.x * scalar, v.y * scalar, v.z * scalar); }

		/*
			@brief	��Z���Z�q�̃I�[�o�[���[�h

			@param[in]	scalar	�X�J���[�l
			@param[in]	v	�x�N�g���N���X

			@return �x�N�g���N���X
		*/
		friend CVector3	operator*(float scalar, const VECTOR& v) { return CVector3(v.x * scalar, v.y * scalar, v.z * scalar); }

		/*
			@brief	���Z���Z�q�̃I�[�o�[���[�h

			@param[in]	vA	�x�N�g���N���X
			@param[in]	vB	�x�N�g���N���X

			@return �x�N�g���N���X
		*/
		friend CVector3 operator/(const VECTOR& vA, const VECTOR& vB) { return CVector3(vA.x / vB.x, vA.y / vB.y, vA.z / vB.z); }

		/*
			@brief	���Z���Z�q�̃I�[�o�[���[�h

			@param[in]	v	�x�N�g���N���X
			@param[in]	scalar	�X�J���[�l

			@return �x�N�g���N���X
		*/
		friend CVector3 operator/(const VECTOR& v, float scalar) { return CVector3(v.x / scalar, v.y / scalar, v.z / scalar); }

		/*
			@brief	���Z���Z�q�̃I�[�o�[���[�h

			@param[in]	scalar	�X�J���[�l
			@param[in]	v	�x�N�g���N���X

			@return �x�N�g���N���X
		*/
		friend CVector3 operator/(float scalar, const VECTOR& v) { return CVector3(scalar / v.x, scalar / v.y, scalar / v.z); }

		/*
			@brief	�f�o�b�N���O�ɒl��\��
		*/
		void DebugLog(void);

		//!���������ׂ�0�̃x�N�g��
		static const CVector3 ZERO;
		//!���������ׂ�1�̃x�N�g��
		static const CVector3 ONE;

	};

}