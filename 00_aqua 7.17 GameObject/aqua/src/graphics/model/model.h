/*
	@file	model.h
	@brief	3Dモデルクラス
*/

#pragma once

#include"model_resource/model_resource.h"

/*
	@brief	aqua名前空間
*/
namespace aqua
{
	/*
		@class	CModel

		@brief	モデルクラス
	*/
	class CModel
	{
	public:
		/*
			@brief	コンストラクタ
		*/
		CModel(void);

		/*
			@brief	コピーコンストラクタ

			@param[in]	texture	モデルクラス
		*/
		CModel(const CModel& model);

		/*
			@brief	デストラクタ
		*/
		~CModel(void) = default;

		/*
			@brief	モデルの読み込み

			@param[in]	file_name ファイル名
		*/
		void Load(const std::string& file_name);

		/*
			@brief	テクスチャの解放
		*/
		void Unload(void);

		/*
			@brief	モデルのリソースハンドル取得

			@param[in]	モデルのリソースハンドル取得
		*/
		int GetResourceHandle(void)const
		{
			if (!m_ModelResource) return AQUA_UNUSED_HANDLE;

			return m_ModelResource->GetResourceHandle();
		}

		/*
			@brief	モデルの読み込みチェック

			@retval	true	読み込み済み
			@retval false	読み込まれていない
		*/
		bool	IsEnable(void)const
		{
			if (!m_ModelResource)return false;

			return m_ModelResource->IsEnable();
		}

		/*
			@brief	代入演算子のオーバーロード

			@param[in]	model	モデルクラス
		*/
		CModel& operator=(const CModel& model);

	private:
		// モデルリソースクラス
		core::CModelResource* m_ModelResource;

	};
	
}
