#include "stage.h"

const std::string CStage::m_object_name = "Stage";

//コンストラクタ
CStage::CStage(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,m_object_name)
{
}

//初期化
void CStage::Initialize(void)
{

}

//更新
void CStage::Update(void)
{
}

//描画
void CStage::Draw(void)
{
}

//解放
void CStage::Finalize(void)
{
}
