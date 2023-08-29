#include "title_scene.h"
#include"../../../game_sound_manager/game_sound_manager.h"
#include"../../../ui_manager/ui_manager.h"

const aqua::CVector2 CTitleScene::m_title_name_position = aqua::CVector2(342.5f, 230.0f);
const aqua::CVector2 CTitleScene::m_message_position = aqua::CVector2(455.5f,600.0f);
const std::string CTitleScene::m_message = "クリックでスタート";
const std::string CTitleScene::m_object_name = "TitleScene";

//コンストラクタ
CTitleScene::CTitleScene(aqua::IGameObject* parent)
	:IScene(parent,"TitleScene")
{
}

//初期化
void CTitleScene::Initialize(void)
{
	m_BackSprite.Create("data/texture/mountain.png");

	CUIManager& ui_manager = CUIManager::GetInstance();
	ui_manager.Initialize();
	ui_manager.Create(UI_ID::TITLE_NAME, m_title_name_position);
	ui_manager.Create(UI_ID::CLICK_MESSAGE, m_message_position,m_message);

	IGameObject::Initialize();

#ifdef _DEBUG
	m_Label.Create(30);
	m_Label.text = "title";

#endif 

}

//更新
void CTitleScene::Update(void)
{
	CUIManager::GetInstance().Update();

	if (aqua::mouse::Trigger(aqua::mouse::BUTTON_ID::LEFT))
	{
		CGameSoundManager::GetInstance().Play(SOUND_ID::DECISION);
		ChangeScene(SCENE_ID::GAMEMAIN);
	}

	IGameObject::Update();
}

//描画
void CTitleScene::Draw(void)
{
#ifdef _DEBUG
	m_Label.Draw();
#endif

	m_BackSprite.Draw();

	CUIManager::GetInstance().Draw();

	IGameObject::Draw();
}

//解放
void CTitleScene::Finalize(void)
{
#ifdef _DEBUG
	m_Label.Delete();
#endif

	m_BackSprite.Delete();

	CUIManager::GetInstance().Finalize();

	IGameObject::Finalize();
}
