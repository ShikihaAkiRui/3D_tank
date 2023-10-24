#include "end_message.h"
#include"../../../game_sound_manager/game_sound_manager.h"

const float CEndMessage::m_display_time = 1.5f;
const float CEndMessage::m_position_height = 0.0f;
const aqua::CVector2 CEndMessage::m_default_scale = aqua::CVector2(0.0f,0.0f);
const aqua::CVector2 CEndMessage::m_max_scale = aqua::CVector2(1.5f, 1.5f);

//コンストラクタ
CEndMessage::CEndMessage(aqua::IGameObject* parent)
	:IUIComponent(parent, "EndMessage")
	,m_AppearFlag(true)
{
}

//初期化
void CEndMessage::Initialize(void)
{
	m_Sprite.Create("data/texture/finish.png");

	m_Sprite.position.x = aqua::GetWindowWidth() / 2.0f - m_Sprite.GetTextureWidth() / 2.0f;
	m_Sprite.position.y = m_position_height;
	m_Sprite.anchor.x = m_Sprite.GetTextureWidth() / 2.0f;
	m_Sprite.anchor.y = m_Sprite.GetTextureHeight() / 2.0f;
	m_Sprite.scale = m_default_scale;

	m_DisplayTimer.Setup(m_display_time);

	m_State = STATE::START_IN;

	CGameSoundManager::GetInstance().Play(SOUND_ID::HORN);

}

//更新
void CEndMessage::Update(void)
{
	m_DisplayTimer.Update();

	switch (m_State)
	{
	case CEndMessage::STATE::START_IN:

		m_Sprite.scale.x = aqua::easing::OutBack(m_DisplayTimer.GetTime(), m_DisplayTimer.GetLimit(), m_default_scale.x, m_max_scale.x);
		m_Sprite.scale.y = aqua::easing::OutBack(m_DisplayTimer.GetTime(), m_DisplayTimer.GetLimit(), m_default_scale.y, m_max_scale.y);

		//出し終えたら切り替え
		if (m_DisplayTimer.Finished())
		{
			m_DisplayTimer.Reset();
			m_State = STATE::WAIT;
		}

		break;
	case CEndMessage::STATE::WAIT:

		//出している状態かのフラグfalse
			m_AppearFlag = false;

		break;
	}

}

//描画
void CEndMessage::Draw(void)
{
	m_Sprite.Draw();
}

//解放
void CEndMessage::Finalize(void)
{
	m_Sprite.Delete();
}

//出しているかを取得
bool CEndMessage::GetAppearFlag(void)
{
	return m_AppearFlag;
}
