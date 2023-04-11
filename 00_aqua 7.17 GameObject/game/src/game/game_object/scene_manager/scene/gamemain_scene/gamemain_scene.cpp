#include "gamemain_scene.h"

//コンストラクタ
CGameMainScene::CGameMainScene(aqua::IGameObject* parent)
	:IScene(parent,"GameMain")
{
}

//初期化
void CGameMainScene::Initialize(void)
{

	IGameObject::Initialize();

#ifdef _DEBUG
	m_Label.Create(30);
	m_Label.text = "gamemain";
#endif 

}

//更新
void CGameMainScene::Update(void)
{

	IGameObject::Update();
}

//描画
void CGameMainScene::Draw(void)
{

	IGameObject::Draw();
#ifdef _DEBUG
	m_Label.Draw();
#endif 

}

//解放
void CGameMainScene::Finalize(void)
{
	IGameObject::Finalize();

#ifdef _DEBUG
	m_Label.Delete();
#endif

}