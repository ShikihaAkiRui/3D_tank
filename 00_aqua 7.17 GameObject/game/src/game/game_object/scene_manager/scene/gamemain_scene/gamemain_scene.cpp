#include "gamemain_scene.h"
#include"../../../unit_manager/unit_manager.h"
#include"../../../bullet_manager/bullet_manager.h"
#include"../../../control_camera/control_camera.h"
#include"../../../stage/stage.h"
#include"../../../item_manager/item_manager.h"
#include"../../../enemy_appear/enemy_appear.h"
#include"../../../ui_manager/ui_manager.h"
#include"../../../effect_manager/effect_manager.h"
#include"../../../game_sound_manager/game_sound_manager.h"

const std::string CGameMainScene::m_object_name = "GameMainScene";
const aqua::CVector2 CGameMainScene::m_radar_position = aqua::CVector2(1000.0f, 10.0f);
const aqua::CVector2 CGameMainScene::m_life_position = aqua::CVector2(680.0f,0.0f);
const aqua::CVector2 CGameMainScene::m_score_position = aqua::CVector2(100.0f, 0.0f);
const aqua::CVector2 CGameMainScene::m_show_score_position = aqua::CVector2(800.0f, 300.0f);
const float CGameMainScene::m_show_score_scale = 5.0f;
const aqua::CColor CGameMainScene::m_show_score_color = 0xffffff00;

//コンストラクタ
CGameMainScene::CGameMainScene(aqua::IGameObject* parent)
	:IScene(parent,m_object_name)
	,m_GameState(GAME_STATE::START)
{
}

//初期化
void CGameMainScene::Initialize(void)
{
	aqua::CreateGameObject<CStage>(this);
	CUnitManager& unit_manager = CUnitManager::GetInstance();
	unit_manager.GetInstance().Initialzie();
	CControlCamera* cam_con = aqua::CreateGameObject<CControlCamera>(this);
	aqua::CreateGameObject<CEnemyAppear>(this);
	CItemManager::GetInstance().Initialize();
	CBulletManager::GetInstance().Initialize();
	CUIManager& ui_manager = CUIManager::GetInstance();

	IGameObject::Initialize();

	CEffectManager::GetInstance().Initialize();
	ui_manager.Initialize();

	IUnit* player = unit_manager.Create(UNIT_ID::PLAYER);
	unit_manager.SetGameState(aqua::GAME_OBJECT_STATE::WAIT);

	m_Camera.Initialize();
	cam_con->Initialize(&m_Camera, player);

	ui_manager.Create(UI_ID::AIM);
	ui_manager.Create(UI_ID::LIFE,m_life_position);
	ui_manager.Create(UI_ID::SCORE,m_score_position);
	ui_manager.Create(UI_ID::RADAR,m_radar_position);
	ui_manager.Create(UI_ID::START_MESSAGE);

	m_GameState = GAME_STATE::START;

	CGameSoundManager::GetInstance().Play(SOUND_ID::GAMEMAIN_BGM);

#ifdef _DEBUG
	m_Label.Create(30);
	m_Label.text = "gamemain";
#endif 

}

//更新
void CGameMainScene::Update(void)
{
	IGameObject::Update();

	CUnitManager& unit_manager = CUnitManager::GetInstance();
	unit_manager.Update();
	CItemManager::GetInstance().Update();
	CBulletManager::GetInstance().Update();
	CEffectManager::GetInstance().Update();
	CUIManager& ui_manager = CUIManager::GetInstance();
	ui_manager.Update();
	CLife* life = CUIManager::GetInstance().GetLife();
	CScore* score = CUIManager::GetInstance().GetScore();


	//ゲームの状態
	switch (m_GameState)
	{
	case CGameMainScene::GAME_STATE::START:

		//演出が終わったら行動開始
		if (ui_manager.GetStartMessage() == nullptr)
		{
			unit_manager.SetGameState(aqua::GAME_OBJECT_STATE::ACTIVE);
			m_GameState = GAME_STATE::MAIN;
		}

		break;
	case CGameMainScene::GAME_STATE::MAIN:

		//体力がなくなったら
		if (life->GetLife() <= 0)
		{
			m_GameState = GAME_STATE::END;
			score->SetCountFlag(false);
		}
		
		break;
	case CGameMainScene::GAME_STATE::END:
		//リザルトをプッシュ
		PushScene(SCENE_ID::RESULT);

		break;
	default:	break;
	}
}

//描画
void CGameMainScene::Draw(void)
{
	IGameObject::Draw();
	CUnitManager::GetInstance().Draw();
	CItemManager::GetInstance().Draw();
	CBulletManager::GetInstance().Draw();

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