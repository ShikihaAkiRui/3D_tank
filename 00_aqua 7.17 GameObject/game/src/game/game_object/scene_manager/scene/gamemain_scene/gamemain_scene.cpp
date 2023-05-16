#include "gamemain_scene.h"
#include"../../../unit_manager/unit_manager.h"
#include"../../../bullet_manager/bullet_manager.h"

const std::string CGameMainScene::m_object_name = "GameMainScene";

//コンストラクタ
CGameMainScene::CGameMainScene(aqua::IGameObject* parent)
	:IScene(parent,m_object_name)
{
}

//初期化
void CGameMainScene::Initialize(void)
{
	CUnitManager* unit_manager = aqua::CreateGameObject<CUnitManager>(this);
	unit_manager->Create(UNIT_ID::PLAYER);
	unit_manager->Create(UNIT_ID::ENEMY);

	aqua::CreateGameObject<CBulletManager>(this);

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