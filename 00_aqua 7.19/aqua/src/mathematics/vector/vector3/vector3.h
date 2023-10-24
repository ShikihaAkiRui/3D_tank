#pragma once

#include<DxLib.h>

/*
	aqua名前空間
*/
namespace aqua
{
	class CMatrix;

	/*
		@class	CVector3

		@brief	三次元ベクトルクラス
	*/

	class CVector3 : public VECTOR
	{
	public:
		/*
			@brief	コンストラクタ
		*/
		CVector3(void);

		/*
			@brief	コンストラクタ

			@param[in]	x	x成分
			@param[in]	y	y成分
			@param[in]	z	z成分
		*/
		CVector3(float x,float y,float z);

		/*
			@brief	コンストラクタ

			@param[in]	v	ベクトル
		*/
		CVector3(const VECTOR& v);

		/*
			@brief	デストラクタ
		*/
		~CVector3(void) = default;

		/*
			@brief	ベクトルの正規化<br>
					自身のベクトルも正規化される

			@return	正規化されたベクトル
		*/
		CVector3	Normalize(void);

		/*
			@brief	ベクトルの正規化		

			@param[in]	v	ベクトルクラス

			@return	正規化されたベクトル
		*/
		static CVector3	Normalize(const VECTOR& v);

		/*
			@brief	ベクトルの大きさ取得
			
			@return	ベクトルの大きさ
		*/
		float	Length(void);

		/*
			@brief	ベクトルの大きさ取得

			@param[in]	v ベクトルクラス

			@return	ベクトルの大きさ
		*/
		static float Length(const VECTOR& v);

		/*
			@brief	2つのベクトルの内積<br>

			@param[in]	vA	ベクトルクラス	
			@param[in]	vB	ベクトルクラス	

			@return	内積
		*/
		static float Dot(const VECTOR& vA, const VECTOR& vB);

		/*
			@brief	2つのベクトルの外積<br>

			@param[in]	vA	ベクトルクラス
			@param[in]	vB	ベクトルクラス

			@return	外積
		*/
		static CVector3 Cross(const VECTOR& vA, const VECTOR& vB);

		/*
			@brief 行列を使ったベクトル変換

			@param[in] vector	変換処理を行いたいベクトル
			@param[in] matrix	変換処理に使用するベクトル

			@return 変換後のベクトル
		*/
		CVector3& Transform(const CMatrix& matrix);

		/*
			@brief	代入演算子のオーバーロード

			@param[in]	v	ベクトルクラス

			@return	ベクトルクラス
		*/
		CVector3& operator=(const VECTOR& v)
		{
			x = v.x;
			y = v.y;
			z = v.z;

			return *this;
		}

		/*
			@brief 加算演算子のオーバーロード

			@param[in]	v	ベクトルクラス

			@return　ベクトルクラス
		*/
		CVector3& operator+=(const VECTOR& v)
		{
			x += v.x;
			y += v.y;
			z += v.z;

			return *this;
		}

		/*
			@brief	減算演算子のオーバーロード

			@param[in]	v	ベクトルクラス

			@return	ベクトルクラス
		*/
		CVector3& operator-=(const VECTOR& v)
		{
			x -= v.x;
			y -= v.y;
			z -= v.z;

			return *this;
		}

		/*
			@brief	乗算演算子のオーバーロード

			@param[in]	v	ベクトルクラス

			@return	ベクトルクラス
		*/
		CVector3& operator*=(float scalar)
		{
			x *= scalar;
			y *= scalar;
			z *= scalar;

			return *this;
		}
		
		/*
			@brief	等価演算子のオーバーロード

			@param[in]	v ベクトルクラス

			@return 二つのベクトルが等しい
			@retval true	等しい
			@retval false	等しくない
		*/
		bool	operator==(const VECTOR& v)const 
		{
			return(x == v.x && y == v.y && z == v.z);
		}

		/*
			@brief	不等演算子のオーバーロード

			@param[in] v ベクトルクラス

			@return 二つのベクトルが等しくない
			@retval	ture	等しくない
			@retval	false	等しい
		*/
		bool	operator!=(const VECTOR& v)const
		{
			return(x != v.x || y != v.y || z != v.z);
		}

		/*
			@brief	正符号演算子のオーバーロード

			@param[in] v ベクトルクラス

			@return ベクトルクラス
		*/
		friend CVector3 operator+(const VECTOR& v) { return v; }

		/*
			@brief 負符号演算子のオーバーロード

			@param[in]	v	ベクトルクラス

			@return ベクトルクラス
		*/
		friend CVector3 operator-(const VECTOR& v) { return CVector3(-v.x, -v.y, -v.z); }

		/*
			@brief	加算演算子のオーバーロード

			@param[in]	vA	ベクトルクラス
			@param[in]	vB	ベクトルクラス

			@return	ベクトルクラス
		*/
		friend CVector3 operator+(const VECTOR& vA, const VECTOR& vB) { return CVector3(vA.x + vB.x, vA.y + vB.y, vA.z + vB.z); }

		/*
			@brief	減算演算子のオーバーロード

			@param[in]	vA	ベクトルクラス
			@param[in]	vB	ベクトルクラス

			@return ベクトルクラス
		*/
		friend CVector3 operator-(const VECTOR& vA, const VECTOR& vB) { return CVector3(vA.x - vB.x, vA.y - vB.y, vA.z - vB.z); }

		/*
			@brief  乗算演算子のオーバーロード

			@param[in]	vA	ベクトルクラス
			@param[in]	vB	ベクトルクラス

			@return ベクトルクラス
		*/
		friend CVector3 operator*(const VECTOR& vA, const VECTOR& vB) { return CVector3(vA.x * vB.x, vA.y * vB.y, vA.z * vB.z); }

		/*
			@brief  乗算演算子のオーバーロード

			@param[in]	v	ベクトルクラス
			@param[in]	scalar	スカラー値

			@return ベクトルクラス
		*/
		friend CVector3 operator*(const VECTOR& v, float scalar) { return CVector3(v.x * scalar, v.y * scalar, v.z * scalar); }

		/*
			@brief	乗算演算子のオーバーロード

			@param[in]	scalar	スカラー値
			@param[in]	v	ベクトルクラス

			@return ベクトルクラス
		*/
		friend CVector3	operator*(float scalar, const VECTOR& v) { return CVector3(v.x * scalar, v.y * scalar, v.z * scalar); }

		/*
			@brief	除算演算子のオーバーロード

			@param[in]	vA	ベクトルクラス
			@param[in]	vB	ベクトルクラス

			@return ベクトルクラス
		*/
		friend CVector3 operator/(const VECTOR& vA, const VECTOR& vB) { return CVector3(vA.x / vB.x, vA.y / vB.y, vA.z / vB.z); }

		/*
			@brief	除算演算子のオーバーロード

			@param[in]	v	ベクトルクラス
			@param[in]	scalar	スカラー値

			@return ベクトルクラス
		*/
		friend CVector3 operator/(const VECTOR& v, float scalar) { return CVector3(v.x / scalar, v.y / scalar, v.z / scalar); }

		/*
			@brief	除算演算子のオーバーロード

			@param[in]	scalar	スカラー値
			@param[in]	v	ベクトルクラス

			@return ベクトルクラス
		*/
		friend CVector3 operator/(float scalar, const VECTOR& v) { return CVector3(scalar / v.x, scalar / v.y, scalar / v.z); }

		/*
			@brief	デバックログに値を表示
		*/
		void DebugLog(void);

		//!成分がすべて0のベクトル
		static const CVector3 ZERO;
		//!成分がすべて1のベクトル
		static const CVector3 ONE;

	};

}