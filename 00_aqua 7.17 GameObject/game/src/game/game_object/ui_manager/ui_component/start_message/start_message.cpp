#include "start_message.h"

const float CStartMessage::m_start_display_time = 1.0f;
const float CStartMessage::m_max_scale = 1.0f;

//�R���X�g���N�^
CStartMessage::CStartMessage(aqua::IGameObject* parent)
	:IUIComponent(parent, "StartMessage")
{
}

//������
void CStartMessage::Initialize(void)
{
	m_StartSprite.Create("data/texture/start.png");

	m_StartSprite.position.x = aqua::GetWindowWidth() / 2.0f - m_StartSprite.GetTextureWidth() / 2.0f;
	m_StartSprite.position.y = aqua::GetWindowHeight() / 2.0f - m_StartSprite.GetTextureHeight() / 2.0f;
	m_StartSprite.anchor.x = m_StartSprite.GetTextureWidth() / 2.0f;
	m_StartSprite.anchor.y = m_StartSprite.GetTextureHeight() / 2.0f;
	m_StartSprite.scale = aqua::CVector2(0.0f, 0.0f);

	m_StartDisplayTimer.Setup(m_start_display_time);

	m_State = STATE::START_IN;
}

//�X�V
void CStartMessage::Update(void)
{
	switch (m_State)
	{
	case CStartMessage::STATE::START_IN:

		m_StartSprite.scale.x = aqua::easing::OutBack(m_StartDisplayTimer.GetTime(), m_StartDisplayTimer.GetLimit(), 0.0f, m_max_scale);
		m_StartSprite.scale.y = aqua::easing::OutBack(m_StartDisplayTimer.GetTime(), m_StartDisplayTimer.GetLimit(), 0.0f, m_max_scale);

		//�o�����I������؂�ւ�
		if (m_StartDisplayTimer.Finished())
		{
			m_StartDisplayTimer.Reset();
			m_State = STATE::WAIT;
		}

		break;
	case CStartMessage::STATE::WAIT:

		m_StartSprite.color.alpha = (unsigned char)(255.0f - aqua::easing::InExp(m_StartDisplayTimer.GetTime(), m_StartDisplayTimer.GetLimit(), 0.0f, 255.0f));

		//�����������
		if (m_StartDisplayTimer.Finished())
		{
			DeleteObject();
		}

		break;
	}

	m_StartDisplayTimer.Update();
}

//�`��
void CStartMessage::Draw(void)
{
	m_StartSprite.Draw();
}

//���
void CStartMessage::Finalize(void)
{
	m_StartSprite.Delete();
}
