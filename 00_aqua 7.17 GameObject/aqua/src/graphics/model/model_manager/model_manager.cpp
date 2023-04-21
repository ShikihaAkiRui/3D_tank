/*
	@file model_manager.cpp
	@brief	3Dモデル管理クラス
*/

#include "model_manager.h"
#include"../model_resource/model_resource.h"
#include"../../../debug/debug.h"
#include"../../../utility/memory/memory.h"

/*
	インスタンスの取得
*/
aqua::core::CModelManager& 
aqua::core::CModelManager::
GetInstance(void)
{
	static CModelManager instance;

	return instance;
}

/*
	モデルクラスの読み込み
*/
aqua::core::CModelResource* 
aqua::core::CModelManager::
Load(const std::string& file_name)
{
	//モデルの検索
	CModelResource* model = Find(file_name);

	//モデルが見つからなかった
	if (!model)
	{
		//新しいモデルを生成
		model = AQUA_NEW CModelResource();

		//読み込み
		model->Load(file_name);

		//モデルリストに追加
		m_ModelList.push_back(model);
	}
	//モデルが見つかった
	else
	{
		//データを退避
		CModelResource* src_model = model;
		//参照ポインタを加算
		src_model->AddReference();

		//新しいモデルを生成
		model = AQUA_NEW CModelResource();

		//モデルを複製
		model->Duplicate(src_model);

		//モデルリストに追加
		m_ModelList.push_back(model);
	}

	//参照ポインタ加算
	model->AddReference();

	return model;
}

/*
	モデルの解放
*/
void 
aqua::core::CModelManager::
UnLoad(aqua::core::CModelResource* model)
{
	if (!model)return;

	if (m_ModelList.empty())return;

	//参照ポインタ減算
	//参照がなくなったら解放
//	if (model->RemoveReference() > 0) return;

	MODEL_LIST::iterator it = m_ModelList.begin();
	MODEL_LIST::iterator end = m_ModelList.end();


	while (it != end)
	{
		if ((*it)->GetResourceName() == model->GetResourceName())
		{
			(*it)->Unload();

			AQUA_SAFE_DELETE((*it));

			m_ModelList.erase(it);

			break;
		}

		++it;
	}
}

/*
	モデルの検索
*/
aqua::core::CModelResource* 
aqua::core::CModelManager::
Find(const std::string& file_name)
{
	if (m_ModelList.empty())return NULL;

	MODEL_LIST::iterator it = m_ModelList.begin();
	MODEL_LIST::iterator end = m_ModelList.end();

	//ファイル名が一致したテクスチャクラスを返す
	while (it != end)
	{
		if ((*it)->GetResourceName() == file_name)
			return (*it);

		++it;
	}

	return NULL;
}

/*
	モデルリストのクリア
*/
void
aqua::core::CModelManager::
Clear(void)
{
	if (m_ModelList.empty())return;

	MODEL_LIST::iterator it = m_ModelList.begin();
	MODEL_LIST::iterator end = m_ModelList.end();

	while (it != end)
	{
		if ((*it))
		{
			//モデルの解放
			(*it)->Unload();

			AQUA_SAFE_DELETE((*it));
		}

		++it;
	}

	//モデルリスト解放
	m_ModelList.clear();
}

/*
	コンストラクタ
*/
aqua::core::CModelManager::
CModelManager(void)
{
	m_ModelList.clear();
}

/*
	コピーコンストラクタ
*/
aqua::core::CModelManager::
CModelManager(const aqua::core::CModelManager& rhs)
{
	(void)rhs;

}

/*
	代入演算子
*/
aqua::core::CModelManager& 
aqua::core::CModelManager::
operator=(const aqua::core::CModelManager& rhs)
{
	(void)rhs;

	return *this;
}
