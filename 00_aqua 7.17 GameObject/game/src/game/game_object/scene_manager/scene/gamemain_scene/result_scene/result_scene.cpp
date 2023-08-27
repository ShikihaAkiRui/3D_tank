#include "result_scene.h"
#include "..\..\..\scene_manager.h"
#include "../gamemain_scene.h"
#include"../../../../ui_manager/ui_manager.h"

const unsigned char CResultScene::m_max_fade_color = 0x90;
const aqua::CVector2 CResultScene::m_label_position = aqua::CVector2(200.0f, 330.0f);
const int CResultScene::m_label_size = 60.0f;
const aqua::CVector2 CResultScene::m_score_position = aqua::CVector2(400.0f, 400.0f);
const float CResultScene::m_score_scale = 5.0f;
const unsigned char CResultScene::m_score_color = 0xffffffff;
const aqua::CVector2 CResultScene::m_message_position  =aqua::CVector2(455.5f,600.0f);
const std::string CResultScene::m_message = "クリックでタイトルへ";

//コンストラクタ
CResultScene::CResultScene(aqua::IGameObject* parent)
    : IScene(parent, "ResultScene")
    , m_State(STATE::FADE)
{
}

//初期化
void CResultScene::Initialize(void)
{
    m_BackgroundPanel.Setup(aqua::CVector2::ZERO, (float)aqua::GetWindowWidth(), (float)aqua::GetWindowHeight(), aqua::CColor::BLUE);
    m_BackgroundPanel.color.alpha = 0;

    m_ScoreLabel.Create(m_label_size);
    m_ScoreLabel.text = "スコア";
    m_ScoreLabel.position = m_label_position;

    CUIManager::GetInstance().Finalize();
    CUIManager::GetInstance().Initialize();
    CUIManager& ui_manager = CUIManager::GetInstance();

    //ui_manager.Create(UI_ID::SHOW_SCORE, m_score_position, 0, m_score_scale, m_score_color);

    IGameObject::Initialize();

    m_FadeTimer.Setup(1.0f);

    m_State = STATE::FADE;

}

//更新
void CResultScene::Update(void)
{
    CUIManager& ui_manager = CUIManager::GetInstance();
    ui_manager.Update();

    switch (m_State)
    {
    case STATE::FADE:
    {
        m_FadeTimer.Update();

        m_BackgroundPanel.color.alpha = aqua::easing::InOutQuad(
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
            //ui_manager.Create(UI_ID::SHOW_SCORE, m_score_position, 10, m_score_scale, m_score_color);
            ui_manager.Create(UI_ID::CLICK_MESSAGE, m_message_position, m_message);
            m_State = STATE::WAIT;
        }
    }
    break;
    case STATE::WAIT:
    {

        if (aqua::mouse::Trigger(aqua::mouse::BUTTON_ID::LEFT))
            ChangeScene(SCENE_ID::TITLE);
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
