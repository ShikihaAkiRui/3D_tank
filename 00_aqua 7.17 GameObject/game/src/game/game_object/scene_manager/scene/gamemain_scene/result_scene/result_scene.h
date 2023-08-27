#pragma once

#include "aqua.h"
#include "..\..\scene.h"

//リザルトシーン
class CResultScene : public IScene
{
public:
    CResultScene(aqua::IGameObject* parent);
    ~CResultScene() = default;

    void        Initialize(void) override;
    void        Update(void) override;
    void        Draw(void) override;
    void        Finalize(void) override;

private:
    //状態ID
    enum class STATE
    {
        FADE,   
        MESSAGE_IN,
        WAIT
    };

    aqua::CBoxPrimitive    m_BackgroundPanel;  //背景
    STATE   m_State;                //状態
    aqua::CTimer    m_FadeTimer;    //フェード時間
    aqua::CLabel    m_ScoreLabel;   //スコアのラベル

    static const unsigned char m_max_fade_color;    //フェード色
    static const aqua::CVector2 m_label_position;   //ラベル位置
    static const int m_label_size;                  //ラベル大きさ
    static const aqua::CVector2 m_score_position;   //スコア位置
    static const float m_score_scale;               //スコア拡大率
    static const unsigned char m_score_color;       //スコア色
    static const aqua::CVector2 m_message_position;	//メッセージ位置
    static const std::string m_message;				//メッセージ文字
};
