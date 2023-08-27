#pragma once

#include "aqua.h"
#include "..\..\scene.h"

//���U���g�V�[��
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
    //���ID
    enum class STATE
    {
        FADE,   
        MESSAGE_IN,
        WAIT
    };

    aqua::CBoxPrimitive    m_BackgroundPanel;  //�w�i
    STATE   m_State;                //���
    aqua::CTimer    m_FadeTimer;    //�t�F�[�h����
    aqua::CLabel    m_ScoreLabel;   //�X�R�A�̃��x��

    static const unsigned char m_max_fade_color;    //�t�F�[�h�F
    static const aqua::CVector2 m_label_position;   //���x���ʒu
    static const int m_label_size;                  //���x���傫��
    static const aqua::CVector2 m_score_position;   //�X�R�A�ʒu
    static const float m_score_scale;               //�X�R�A�g�嗦
    static const unsigned char m_score_color;       //�X�R�A�F
    static const aqua::CVector2 m_message_position;	//���b�Z�[�W�ʒu
    static const std::string m_message;				//���b�Z�[�W����
};
