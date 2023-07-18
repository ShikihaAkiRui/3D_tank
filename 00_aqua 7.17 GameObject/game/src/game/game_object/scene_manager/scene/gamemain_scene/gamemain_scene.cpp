#include "gamemain_scene.h"
#include"../../../unit_manager/unit_manager.h"
#include"../../../bullet_manager/bullet_manager.h"
#include"../../../control_camera/control_camera.h"
#include"../../../stage/stage.h"
#include"../../../item_manager/item_manager.h"
#include"../../../ui_component/score/score.h"
#include"../../../ui_component/life/life.h"
#include"../../../enemy_appear/enemy_appear.h"
#include"../../../ui_component/aim/aim.h"
#include"../../../ui_component/radar/radar.h"

const std::string CGameMainScene::m_object_name = "GameMainScene";

//コンストラクタ
CGameMainScene::CGameMainScene(aqua::IGameObject* parent)
	:IScene(parent,m_object_name)
	,m_GameState(GAME_STATE::START)
{
}

//初期化
void CGameMainScene::Initialize(void)
{
	CUnitManager* unit_manager = aqua::CreateGameObject<CUnitManager>(this);
	CControlCamera* cam_con = aqua::CreateGameObject<CControlCamera>(this);
	aqua::CreateGameObject<CStage>(this);
	//aqua::CreateGameObject<CBulletManager>(this);
	//aqua::CreateGameObject<CItemManager>(this);
	aqua::CreateGameObject<CEnemyAppear>(this);

	CBulletManager::GetInstance().Initialize();

	CScore* score = aqua::CreateGameObject<CScore>(this);
	CLife* life = aqua::CreateGameObject<CLife>(this);
	CRadar* radar = aqua::CreateGameObject<CRadar>(this);
	aqua::CreateGameObject<CAim>(this);

	IGameObject::Initialize();

	IUnit* player = unit_manager->Create(UNIT_ID::PLAYER);

	m_Camera.Initialize();
	cam_con->Initialize(&m_Camera, player);

	life->Initialize(aqua::CVector2(500.0f, 0.0f),3);
	score->Initialize(aqua::CVector2(100.0f, 0.0f));
	radar->Initialize(aqua::CVector2(1100.0f, 0.0f));

	m_GameState = GAME_STATE::START;

#ifdef _DEBUG
	m_Label.Create(30);
	m_Label.text = "gamemain";
#endif 

}

//更新
void CGameMainScene::Update(void)
{
	IGameObject::Update();

	CBulletManager::GetInstance().Update();

	CLife* life = nullptr;

	//ゲームの状態
	switch (m_GameState)
	{
	case CGameMainScene::GAME_STATE::START:
		m_GameState = GAME_STATE::MAIN;

		break;
	case CGameMainScene::GAME_STATE::MAIN:

		
		
		/*
		life = (CLife*)aqua::FindGameObject("Life");
		if (!life)return;
		if (life->GetLife() <= 0)
			m_GameState = GAME_STATE::END;
		*/
		break;
	case CGameMainScene::GAME_STATE::END:

		ChangeScene(SCENE_ID::TITLE);
		break;
	default:	break;
	}
}

//描画
void CGameMainScene::Draw(void)
{
	CBulletManager::GetInstance().Draw();

	IGameObject::Draw();

#ifdef _DEBUG
	//m_Label.Draw();
#endif 

}

//解放
void CGameMainScene::Finalize(void)
{
	CBulletManager::GetInstance().Finalize();

	IGameObject::Finalize();

#ifdef _DEBUG
	m_Label.Delete();
#endif

}