#include "start_message.h"
#include"../../../game_sound_manager/game_sound_manager.h"

const float CStartMessage::m_start_display_time = 1.0f;
const aqua::CVector2 CStartMessage::m_default_scale = aqua::CVector2(0.0f, 0.0f);
const aqua::CVector2 CStartMessage::m_max_scale = aqua::CVector2(1.5f, 1.0f);
const float CStartMessage::m_max_alpha = 255.0f;
const float CStartMessage::m_min_alpha = 0.0f;

//コンストラクタ
CStartMessage::CStartMessage(aqua::IGameObject* parent)
	:IUIComponent(parent, "StartMessage")
{
}

//初期化
void CStartMessage::Initialize(void)
{
	m_StartSprite.Create("data/texture/start.png");

	m_StartSprite.position.x = aqua::GetWindowWidth() / 2.0f - m_StartSprite.GetTextureWidth() / 2.0f;
	m_StartSprite.position.y = aqua::GetWindowHeight() / 2.0f - m_StartSprite.GetTextureHeight() / 2.0f;
	m_StartSprite.anchor.x = m_StartSprite.GetTextureWidth() / 2.0f;
	m_StartSprite.anchor.y = m_StartSprite.GetTextureHeight() / 2.0f;
	m_StartSprite.scale = m_default_scale;

	m_StartDisplayTimer.Setup(m_start_display_time);

	m_State = STATE::START_IN;

	CGameSoundManager::GetInstance().Play(SOUND_ID::HORN);
}

//更新
void CStartMessage::Update(void)
{
	switch (m_State)
	{
	case CStartMessage::STATE::START_IN:

		m_StartSprite.scale.x = aqua::easing::OutBack(m_StartDisplayTimer.GetTime(), m_StartDisplayTimer.GetLimit(), m_default_scale.x, m_max_scale.x);
		m_StartSprite.scale.y = aqua::easing::OutBack(m_StartDisplayTimer.GetTime(), m_StartDisplayTimer.GetLimit(), m_default_scale.y, m_max_scale.y);

		//出現し終えたら切り替え
		if (m_StartDisplayTimer.Finished())
		{
			m_StartDisplayTimer.Reset();
			m_State = STATE::WAIT;
		}

		break;
	case CStartMessage::STATE::WAIT:

		m_StartSprite.color.alpha = (unsigned char)(m_max_alpha - aqua::easing::InExp(m_StartDisplayTimer.GetTime(), m_StartDisplayTimer.GetLimit(), m_min_alpha, m_max_alpha));

		//消えたら消す
		if (m_StartDisplayTimer.Finished())
		{
			m_StartSprite.color.alpha = m_min_alpha;
			DeleteObject();
		}

		break;
	}

	m_StartDisplayTimer.Update();
}

//描画
void CStartMessage::Draw(void)
{
	m_StartSprite.Draw();
}

//解放
void CStartMessage::Finalize(void)
{
	m_StartSprite.Delete();
}
