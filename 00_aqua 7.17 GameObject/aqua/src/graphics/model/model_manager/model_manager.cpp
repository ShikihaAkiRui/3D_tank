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
		//新しいモデルを生成
		CModelResource* model = AQUA_NEW CModelResource();

		//モデルを複製
	//	model->Duplicate();

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
UnLoad(CModelResource* model)
{
	if (!model)return;

	if (m_ModelList.empty())return;

	//参照ポインタ減算
	//参照がなくなったら解放
	if (model->RemoveReference() > 0) return;

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



	return NULL;
}

void aqua::core::CModelManager::Clear(void)
{
}

aqua::core::CModelManager::CModelManager(void)
{
}

aqua::core::CModelManager::CModelManager(const CModelManager& rhs)
{
}

aqua::core::CModelManager& aqua::core::CModelManager::operator=(const CModelManager& rhs)
{
	// TODO: return ステートメントをここに挿入します
}
