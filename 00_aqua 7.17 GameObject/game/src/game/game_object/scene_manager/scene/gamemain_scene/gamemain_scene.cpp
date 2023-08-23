#include "gamemain_scene.h"
#include"../../../unit_manager/unit_manager.h"
#include"../../../bullet_manager/bullet_manager.h"
#include"../../../control_camera/control_camera.h"
#include"../../../stage/stage.h"
#include"../../../item_manager/item_manager.h"
#include"../../../enemy_appear/enemy_appear.h"
#include"../../../ui_manager/ui_manager.h"
#include"../../../effect_manager/effect_manager.h"

const std::string CGameMainScene::m_object_name = "GameMainScene";
const aqua::CVector2 CGameMainScene::m_radar_position = aqua::CVector2(1000.0f, 10.0f);
const aqua::CVector2 CGameMainScene::m_life_position = aqua::CVector2(680.0f,0.0f);
const aqua::CVector2 CGameMainScene::m_score_position = aqua::CVector2(100.0f, 0.0f);

//コンストラクタ
CGameMainScene::CGameMainScene(aqua::IGameObject* parent)
	:IScene(parent,m_object_name)
	,m_GameState(GAME_STATE::START)
{
}

//初期化
void CGameMainScene::Initialize(void)
{
	CUnitManager& unit_manager = CUnitManager::GetInstance();
	unit_manager.GetInstance().Initialzie();
	CControlCamera* cam_con = aqua::CreateGameObject<CControlCamera>(this);
	aqua::CreateGameObject<CStage>(this);
	aqua::CreateGameObject<CEnemyAppear>(this);
	CItemManager::GetInstance().Initialize();
	CBulletManager::GetInstance().Initialize();
	CUIManager& ui_manager = CUIManager::GetInstance();

	IGameObject::Initialize();

	CEffectManager::GetInstance().Initialize();
	ui_manager.Initialize();

	IUnit* player = unit_manager.Create(UNIT_ID::PLAYER);

	m_Camera.Initialize();
	cam_con->Initialize(&m_Camera, player);

	ui_manager.Create(UI_ID::AIM);
	ui_manager.Create(UI_ID::LIFE,m_life_position);
	ui_manager.Create(UI_ID::SCORE,m_score_position);
	ui_manager.Create(UI_ID::RADAR,m_radar_position);

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

	CUnitManager::GetInstance().Update();
	CItemManager::GetInstance().Update();
	CBulletManager::GetInstance().Update();
	CEffectManager::GetInstance().Update();
	CUIManager& ui_manager = CUIManager::GetInstance();
	ui_manager.Update();
	CLife life = CUIManager::GetInstance().GetLife();
	CScore score = CUIManager::GetInstance().GetScore();


	//ゲームの状態
	switch (m_GameState)
	{
	case CGameMainScene::GAME_STATE::START:

		m_GameState = GAME_STATE::MAIN;
		break;
	case CGameMainScene::GAME_STATE::MAIN:

		//体力がなくなったら
		if (life.GetLife() <= 0)
		{
			m_GameState = GAME_STATE::END;
			score.SetCountFlag(false);
		}
		
		break;
	case CGameMainScene::GAME_STATE::END:

		ui_manager.Create(UI_ID::SHOW_SCORE, aqua::CVector2(500.0f, 100.0f), 0, 5.0f, 0xffffff00);

		ChangeScene(SCENE_ID::TITLE);
		break;
	default:	break;
	}
}

//描画
void CGameMainScene::Draw(void)
{
	CUnitManager::GetInstance().Draw();
	CItemManager::GetInstance().Draw();
	CBulletManager::GetInstance().Draw();

	IGameObject::Draw();
	CEffectManager::GetInstance().Draw();
	CUIManager::GetInstance().Draw();

#ifdef _DEBUG
	//m_Label.Draw();
#endif 

}

//解放
void CGameMainScene::Finalize(void)
{
	CUnitManager::GetInstance().Finalize();
	CItemManager::GetInstance().Finalize();
	CBulletManager::GetInstance().Finalize();

	IGameObject::Finalize();
	CEffectManager::GetInstance().Finalize();
	CUIManager::GetInstance().Finalize();

#ifdef _DEBUG
	m_Label.Delete();
#endif

}