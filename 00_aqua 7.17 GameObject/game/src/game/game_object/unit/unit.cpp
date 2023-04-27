#include "unit.h"

//コンストラクタ
IUnit::IUnit(aqua::IGameObject* parent, const std::string& object_name)
	:IGameObject(parent,object_name,"Unit")
{
}

//初期化
void IUnit::Initialize(void)
{
	SetupCollInfo(m_Model, 0, 8, 8, 8);
	
}

//更新
void IUnit::Update(void)
{
	RefreshCollInfo(0);
}

//描画
void IUnit::Draw(void)
{
	m_Model->Draw();
}

//解放
void IUnit::Finalize(void)
{
	TerminateCollInfo(0);

	m_Model->Unload();
}
