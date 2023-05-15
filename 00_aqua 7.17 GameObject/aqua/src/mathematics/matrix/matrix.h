#pragma once

#include<DxLib.h>
#include"../mathematics.h"

/*
	aqua名前空間
*/
namespace aqua
{
	/*
		@class	CMatrix

		@brief	マトリクスクラス	
	*/
	class CMatrix : private MATRIX
	{
	public:
		/*
			@brief	コンストラクタ
		*/
		CMatrix(void);

		/*
			@brief	コンストラクタ

			@param	matrix	マトリクスクラス
		*/
		CMatrix(const MATRIX& matrix);


		/*
			@brief	デストラクタ
		*/
		~CMatrix(void) = default;


		/*
			@brief	単位行列を取得

			@return	単位行列
		*/
		static CMatrix Ident(void);

		/*
			@brief	拡大行列を取得

			@param[in]	scale	拡大率

			@return	拡大行列
		*/
		CMatrix Scale(const VECTOR& scale);

		/*
			@brief	平行移動行列を取得

			@param[in]	trans	平行移動値

			@return	平行移動行列
		*/
		CMatrix Translate(const VECTOR& trans);

		/*
			@brief	X軸回転行列を取得

			@param[in]	x_axis_rotate	回転値(単位:ラジアン)

			@return	X軸回転行列
		*/
		CMatrix RotX(float x_axis_rotate);

		/*
			@brief	Y軸回転行列を取得

			@param[in]	y_axis_rotate	回転値(単位:ラジアン)

			@return	Y軸回転行列
		*/
		CMatrix RotY(float y_axis_rotate);

		/*
			@brief	Z軸回転行列を取得

			@param[in]	z_axis_rotate	回転値(単位:ラジアン)

			@return	Z軸回転行列
		*/
		CMatrix	RotZ(float z_axis_rotate);

		/*
			@brief	指定軸で指定角度回転する行列を取得

			@param[in]	rotate_axis	回転軸
			@param[in]	rotate	回転値(単位:ラジアン)

			@return	回転行列
		*/
		CMatrix RotAxis(VECTOR rotate_axis, float rotate);

		/*
			@brief	転置行列を取得

			@return	転置した結果の行列
		*/
		CMatrix Transpose(void);

		/*
			@brief	転置行列を取得

			@param[in]	matrix	マトリクスクラス

			@return 転置した結果の行列
		*/
		static CMatrix Transpose(const MATRIX& matrix);

		/*
			@brief	逆行列を取得

			@return	逆行列
		*/
		CMatrix Inverse(void);

		/*
			@brief	逆行列を取得

			@param[in]	matrix	マトリクスクラス

			@return	逆行列
		*/
		static CMatrix Inverse(const MATRIX& matrix);


		/*
			@brief	加算演算子のオーバーロード

			@param[in]	matrix	マトリクスクラス

			@return	マトリクスクラス
		*/
		CMatrix& operator+=(const MATRIX& matrix);

		/*
			@brief	乗算演算子のオーバーロード

			@param[in]	matrix	マトリクスクラス

			@return	マトリクスクラス

		*/
		CMatrix& operator*=(const MATRIX& matrix);

		/*
			@brief	乗算演算子のオーバーロード

			@param[in]	scale	スケーリング値

			@return	マトリクスクラス

		*/
		CMatrix& operator*=(float scale);

		/*
			@brief	加算演算子のオーバーロード

			@param[in]	mA	マトリクスクラス
			@pstsm[in]	mB	マトリクスクラス

			@return	マトリクスクラス
		*/
		friend CMatrix operator+(const MATRIX & mA, const MATRIX & mB);

		/*
			@brief	乗算演算子のオーバーロード

			@param[in]	mA	マトリクスクラス
			@pstsm[in]	mB	マトリクスクラス

			@return	マトリクスクラス
		*/
		friend CMatrix operator*(const MATRIX & mA, const MATRIX & mB);

		/*
			@brief	乗算演算子のオーバーロード

			@param[in]	matrix	マトリクスクラス
			@param[in]	scale	スケーリング値

			@return	マトリクスクラス
		*/
		friend CMatrix operator*(const MATRIX& matrix, float scale);

	};

}