#include "end_message.h"

const float CEndMessage::m_display_time = 1.5f;
const float CEndMessage::m_position_height = 0.0f;
const float CEndMessage::m_max_scale = 1.5f;

//�R���X�g���N�^
CEndMessage::CEndMessage(aqua::IGameObject* parent)
	:IUIComponent(parent, "EndMessage")
	,m_AppearFlag(true)
{
}

//������
void CEndMessage::Initialize(void)
{
	m_Sprite.Create("data/texture/finish.png");

	m_Sprite.position.x = aqua::GetWindowWidth() / 2.0f - m_Sprite.GetTextureWidth() / 2.0f;
	m_Sprite.position.y = m_position_height;
	m_Sprite.anchor.x = m_Sprite.GetTextureWidth() / 2.0f;
	m_Sprite.anchor.y = m_Sprite.GetTextureHeight() / 2.0f;
	m_Sprite.scale = aqua::CVector2(0.0f, 0.0f);

	m_DisplayTimer.Setup(m_display_time);

	m_State = STATE::START_IN;
}

//�X�V
void CEndMessage::Update(void)
{
	m_DisplayTimer.Update();

	switch (m_State)
	{
	case CEndMessage::STATE::START_IN:

		m_Sprite.scale.x = aqua::easing::OutBack(m_DisplayTimer.GetTime(), m_DisplayTimer.GetLimit(), 0.0f, m_max_scale);
		m_Sprite.scale.y = aqua::easing::OutBack(m_DisplayTimer.GetTime(), m_DisplayTimer.GetLimit(), 0.0f, m_max_scale);

		//�o���I������؂�ւ�
		if (m_DisplayTimer.Finished())
		{
			m_DisplayTimer.Reset();
			m_State = STATE::WAIT;
		}

		break;
	case CEndMessage::STATE::WAIT:

		//�o���Ă����Ԃ��̃t���Ofalse
			m_AppearFlag = false;

		break;
	}

}

//�`��
void CEndMessage::Draw(void)
{
	m_Sprite.Draw();
}

//���
void CEndMessage::Finalize(void)
{
	m_Sprite.Delete();
}

//�o���Ă��邩���擾
bool CEndMessage::GetAppearFlag(void)
{
	return m_AppearFlag;
}