#include "result_scene.h"
#include "..\..\..\scene_manager.h"
#include "../gamemain_scene.h"
#include"../../../../ui_manager/ui_manager.h"
#include"../../../../game_sound_manager/game_sound_manager.h"

const aqua::CColor CResultScene::m_default_panel_color = 0x0000ff;
const float CResultScene::m_fade_time = 1.0f;
const unsigned char CResultScene::m_max_fade_color = 0x80;
const aqua::CVector2 CResultScene::m_label_position = aqua::CVector2(200.0f, 330.0f);
const int CResultScene::m_label_size = 60;
const aqua::CVector2 CResultScene::m_score_position = aqua::CVector2(700.0f, 400.0f);
const float CResultScene::m_score_scale = 5.0f;
const aqua::CColor CResultScene::m_score_color = 0xffffff00;
const aqua::CVector2 CResultScene::m_message_position  =aqua::CVector2(455.5f,600.0f);
const std::string CResultScene::m_message = "クリックでタイトルへ";

//コンストラクタ
CResultScene::CResultScene(aqua::IGameObject* parent)
    : IScene(parent, "ResultScene")
    , m_State(STATE::FADE)
    ,m_ResultScore(0)
{
}

//初期化
void CResultScene::Initialize(void)
{
    m_BackgroundPanel.Setup(aqua::CVector2::ZERO, (float)aqua::GetWindowWidth(), (float)aqua::GetWindowHeight(), m_default_panel_color);

    m_ScoreLabel.Create(m_label_size);
    m_ScoreLabel.text = "スコア";
    m_ScoreLabel.position = m_label_position;

    CUIManager& ui_manager = CUIManager::GetInstance();

    //スコアを保存
    m_ResultScore = ui_manager.GetScore()->GetScore();

    ui_manager.Finalize();
    ui_manager.Initialize();

    IGameObject::Initialize();

    m_FadeTimer.Setup(m_fade_time);

    m_State = STATE::FADE;

}

//更新
void CResultScene::Update(void)
{
    CUIManager& ui_manager = CUIManager::GetInstance();
    CGameSoundManager& sound = CGameSoundManager::GetInstance();
    ui_manager.Update();

    switch (m_State)
    {
    case STATE::FADE:
    {
        m_FadeTimer.Update();

        m_BackgroundPanel.color.alpha = (unsigned char)aqua::easing::InOutQuad(
            m_FadeTimer.GetTime(), m_FadeTimer.GetLimit(), 0, m_max_fade_color);

        //フェード終わった
        if (m_FadeTimer.Finished())
        {
            ui_manager.Create(UI_ID::END_MESSAGE);
            m_State = STATE::MESSAGE_IN;
        }
    }
    break;
    case STATE::MESSAGE_IN:
    {
        //演出終わった
        if (!ui_manager.GetEndMessage()->GetAppearFlag())
        {
            ui_manager.Create(UI_ID::SHOW_SCORE, m_score_position, m_ResultScore, m_score_scale, m_score_color);
            ui_manager.Create(UI_ID::CLICK_MESSAGE, m_message_position, m_message);
            m_State = STATE::WAIT;
        }
    }
    break;
    case STATE::WAIT:
    {
        //タイトルへ
        if (aqua::mouse::Trigger(aqua::mouse::BUTTON_ID::LEFT))
        {
            sound.Play(SOUND_ID::DECISION);
            sound.Stop(SOUND_ID::GAMEMAIN_BGM);
            ChangeScene(SCENE_ID::TITLE);
        }
    }
    break;
    }

    IGameObject::Update();
}

//描画
void CResultScene::Draw(void)
{
    m_BackgroundPanel.Draw();

    CUIManager::GetInstance().Draw();

    if (m_State == STATE::WAIT)
        m_ScoreLabel.Draw();

    IGameObject::Draw();
}

//解放
void CResultScene::Finalize(void)
{
    CUIManager::GetInstance().Finalize();

    m_ScoreLabel.Delete();

    IGameObject::Finalize();
}
