#include "radar.h"
#include"../../enemy_appear/enemy_appear.h"

//コンストラクタ
CRadar::CRadar(aqua::IGameObject* parent)
	:IUIComponent(parent,"Radar")
	,m_MaxEnemyCount(0)
{
}

//初期化
void CRadar::Initialize(const aqua::CVector2& position)
{
	IUIComponent::Initialize(position);
}

//更新
void CRadar::Update(void)
{

}

//描画
void CRadar::Draw(void)
{
}

//解放
void CRadar::Finalize(void)
{

}