#pragma once

#include "aqua.h"
#include "..\..\scene.h"

//リザルトシーン
class CResultScene : public IScene
{
public:
    //コンストラクタ
    CResultScene(aqua::IGameObject* parent);
    //デストラクタ
    ~CResultScene() = default;

    //初期化
    void        Initialize(void) override;
    //更新
    void        Update(void) override;
    //描画
    void        Draw(void) override;
    //解放
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
    int m_ResultScore;              //結果スコア

    static const aqua::CColor m_default_panel_color;//初期の背景色
    static const float m_fade_time;                 //フェード時間
    static const unsigned char m_max_fade_color;    //フェード色
    static const aqua::CVector2 m_label_position;   //ラベル位置
    static const int m_label_size;                  //ラベル大きさ
    static const aqua::CVector2 m_score_position;   //スコア位置
    static const float m_score_scale;               //スコア拡大率
    static const aqua::CColor m_score_color;        //スコア色
    static const aqua::CVector2 m_message_position;	//メッセージ位置
    static const std::string m_message;				//メッセージ文字
};
