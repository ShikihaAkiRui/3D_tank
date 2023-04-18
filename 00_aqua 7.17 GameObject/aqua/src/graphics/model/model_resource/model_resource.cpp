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
	MV1DeleteModel(m_ResourceHandle);

	m_ResourceHandle = AQUA_UNUSED_HANDLE;

	m_ResourceName.clear();

	m_ReferenceCount = 0;

	m_ResourceType = RESOURCE_TYPE::DUMMY;

	m_Enabel = true;

	//
	m_Width = m_Height = 0;
}

/*
	モデル生成
*/
void
aqua::core::CModelResource::
Create(int width, int height, int depth, bool alpha_channel)
{
	if (m_Enabel)return;

	m_Width = width;
	m_Height = height;

	//サイズに合わせてサーフェスを生成
	

	AQUA_DX_ASSERT(m_ResourceHandle, "テクスチャの作成に失敗しました。");

	//リソース名を保存
	//時間で名前を付ける
	time_t now = time(NULL);

	tm local_time;

	localtime_s(&local_time, &now);

	m_ResourceName = "Texture";

	m_ResourceName += std::to_string(local_time.tm_year) + std::to_string(local_time.tm_mon) + std::to_string(local_time.tm_mday);

	m_ResourceName += std::to_string(local_time.tm_hour) + std::to_string(local_time.tm_min) + std::to_string(local_time.tm_sec);

	//生成済み
	m_Enabel = true;
}

/*
	モデル解放
*/
void
aqua::core::CModelResource::
Delete(void)
{
	m_ResourceName.clear();

	m_ReferenceCount = 0;

	m_ResourceType = RESOURCE_TYPE::DUMMY;

	m_Enabel = false;

	m_Width = m_Height = 0;
}
