/*
	@file	model_resource.cpp

	@brief	3Dモデルリソース
*/
#include<DxLib.h>
#include<ctime>
#include "model_resource.h"
#include"../../../debug/debug.h"
#include"../../../utility/memory/memory.h"
#include"../model_manager/model_manager.h"

/*
	コンストラクタ
*/
aqua::core::
CModelResource::
CModelResource(void)
	:IResourceObject(aqua::core::RESOURCE_TYPE::LOAD_MODEL)
{
}

/*
	モデル読み込み
*/
void
aqua::core::CModelResource::
Load(const std::string& file_name)
{
	if (m_Enabel) return;

	//モデルの読み込み
	m_ResourceHandle = MV1LoadModel(file_name.c_str());

	AQUA_DX_ASSERT(m_ResourceHandle, file_name + "の読み込みに失敗しました。");

	// ファイルパスを保存
	m_ResourceName = file_name;

	// 読み込み済み
	m_Enabel = true;

}

/*
	モデルがある場合の読み込み
*/
void 
aqua::core::CModelResource::
Duplicate(const aqua::core::CModelResource* model)
{
	if (m_Enabel) return;

	//モデルの複製
	m_ResourceHandle = MV1DuplicateModel(model->GetResourceHandle());

	AQUA_DX_ASSERT(m_ResourceHandle, model->GetResourceName() + "の読み込みに失敗しました。");

	// ファイルパスを保存
	m_ResourceName = model->GetResourceName();
	
	//名前の同名を避ける
	m_ResourceName += std::to_string(model->m_ReferenceCount);

	// 読み込み済み
	m_Enabel = true;
}

/*
	モデル解放
*/
void
aqua::core::CModelResource::
Unload(void)
{
	MV1DeleteModel(m_ResourceHandle);

	m_ResourceHandle = AQUA_UNUSED_HANDLE;

	m_ResourceName.clear();

	m_ReferenceCount = 0;

	m_ResourceType = RESOURCE_TYPE::DUMMY;

	m_Enabel = true;

}
