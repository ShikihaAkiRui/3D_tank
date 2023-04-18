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

const unsigned int aqua::core::CModelResource::m_transparent_color = 0xffff00ff;

/*
	コンストラクタ
*/
aqua::core::
CModelResource::
CModelResource(void)
	:IResourceObject(aqua::core::RESOURCE_TYPE::LOAD_MODEL)
	,m_Width(0)
	,m_Height(0)
	,m_Depth(0)
{
}

/*
	テクスチャ読み込み
*/
void
aqua::core::CModelResource::
Load(const std::string& file_name)
{
	if (m_Enabel) return;

	// 透過色指定
	SetTransColor((m_transparent_color >> 16) & 0xff, (m_transparent_color >> 8) & 0xff, m_transparent_color & 0xff);

	//テクスチャ読み込み
	m_ResourceHandle = MV1LoadModel(file_name.c_str());

	AQUA_DX_ASSERT(m_ResourceHandle, file_name + "の読み込みに失敗しました。");

	// グラフィックサイズ取得
	

	// ファイルパスを保存
	m_ResourceName = file_name;

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
}

/*
	モデル生成
*/
void
aqua::core::CModelResource::
Create(int width, int height, int depth, bool alpha_channel)
{

}

/*
	モデル解放
*/
void
aqua::core::CModelResource::
Delete(void)
{
}
