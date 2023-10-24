/*
	@file	model.cpp

	@brief	3Dモデルクラス
*/

#include<windows.h>
#include"model.h"
#include"model_manager/model_manager.h"
#include"../../debug/debug.h"

/*
	コンストラクタ
*/
aqua::CModel::
CModel(void)
	:m_ModelResource(nullptr)
	,position(aqua::CVector3::ZERO)
	,scale(aqua::CVector3::ONE)
	,rotation(aqua::CVector3::ZERO)
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
	描画
*/
void 
aqua::CModel::
Draw(void)
{
	//モデルが読み込まれていなければ描画しない
	if (!m_ModelResource->IsEnable()) return;	

	//モデルリソースハンドルを取得
	int handle = m_ModelResource->GetResourceHandle();

	//位置設定
	MV1SetPosition(handle,position);
	//拡大率設定
	MV1SetScale(handle, scale);
	//回転値設定
	MV1SetRotationXYZ(handle,aqua::CVector3(aqua::DegToRad(rotation.x), aqua::DegToRad(rotation.y), aqua::DegToRad(rotation.z)));

	//描画
	MV1DrawModel(handle);
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
