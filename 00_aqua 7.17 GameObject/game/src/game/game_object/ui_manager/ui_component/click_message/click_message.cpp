#include "click_message.h"

const float CClickMessage::m_label_angle_speed = 1.0f;
const float CClickMessage::m_max_alpha = 255.0f;
const int CClickMessage::m_size = 40.0f;

//�R���X�g���N�^
CClickMessage::CClickMessage(aqua::IGameObject* parent)
	:IUIComponent(parent,"ClickMessage")
	,m_AlphaAngle(m_max_alpha)
{
}

//������
void CClickMessage::Initialize(const aqua::CVector2& position, const std::string word)
{
	m_Label.Create(m_size);
	m_Label.text = word;
	m_Label.position = position;
}

//�X�V
void CClickMessage::Update(void)
{
	m_AlphaAngle += m_label_angle_speed;

	m_Label.color.alpha = abs(sin(aqua::DegToRad(m_AlphaAngle))) * m_max_alpha;

}

//�`��
void CClickMessage::Draw(void)
{
	m_Label.Draw();
}

//���
void CClickMessage::Finalize(void)
{
	m_Label.Delete();
}
