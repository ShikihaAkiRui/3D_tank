#include "gamemain_scene.h"
#include"../../../unit_manager/unit_manager.h"
#include"../../../bullet_manager/bullet_manager.h"
#include"../../../control_camera/control_camera.h"
#include"../../../stage/stage.h"
#include"../../../item_manager/item_manager.h"

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
	CControlCamera* cam_con = aqua::CreateGameObject<CControlCamera>(this);
	aqua::CreateGameObject<CStage>(this);
	aqua::CreateGameObject<CBulletManager>(this);
	aqua::CreateGameObject<CItemManager>(this);

	IGameObject::Initialize();

	IUnit* player = unit_manager->Create(UNIT_ID::PLAYER);
	unit_manager->Create(UNIT_ID::ENEMY);

	m_Camera.Initialize();
	cam_con->Initialize(&m_Camera, player);

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