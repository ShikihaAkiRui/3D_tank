/*
	@file	model.cpp

	@brief	3Dモデルクラス
*/

#include<windows.h>
#include"model.h"
#include"model_manager/model_manager.h"

/*
	コンストラクタ
*/
aqua::CModel::
CModel(void)
	:m_ModelResource(nullptr)
{
}

/*
	コピーコンストラクタ
*/
aqua::CModel::
CModel(const aqua::CModel& model)
{
	if (m_ModelResource)
		m_ModelResource->RemoveReference();

	m_ModelResource = model.m_ModelResource;

	//参照カウンタ加算
	m_ModelResource->AddReference();
}

/*
	モデル読み込み
*/
void 
aqua::CModel::
Load(const std::string& file_name)
{
	//モデルリソース退避
	core::CModelResource* model = m_ModelResource;

	//モデルマネージャーからモデルを取得
	m_ModelResource = core::CModelManager::GetInstance().Load(file_name);

	if (model)
	{
		int count = model->RemoveReference();

		//前のモデルの参照がなくなったら解放
		if (count <= 0)
			core::CModelManager::GetInstance().UnLoad(model);
	}
}

/*
	モデル開放
*/
void
aqua::CModel::
Unload(void)
{
	//モデル解放
	if (m_ModelResource)
		core::CModelManager::GetInstance().UnLoad(m_ModelResource);

	m_ModelResource = nullptr;
}

/*
	代入演算子のオーバーロード
*/
aqua::CModel&
aqua::CModel::
operator=(const aqua::CModel& model)
{
	//モデルを持っていたら参照を減算
	if (m_ModelResource)
		m_ModelResource->RemoveReference();

	m_ModelResource = model.m_ModelResource;

	//参照カウンタの加算
	m_ModelResource->AddReference();

	return *this;
}
