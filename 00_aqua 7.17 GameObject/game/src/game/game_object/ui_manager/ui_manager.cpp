#include "ui_manager.h"
#include"ui_component/radar/radar.h"
#include"ui_component/show_score/show_score.h"
#include"ui_component/click_message/click_message.h"
#include"ui_component/title_name/title_name.h"

const std::string CUIManager::m_aim_name = "Aim";
const std::string CUIManager::m_life_name = "Life";
const std::string CUIManager::m_score_name = "Score";
const std::string CUIManager::m_start_message_name = "StartMessage";
const std::string CUIManager::m_end_message_name = "EndMessage";

//インスタンスを取得
CUIManager& CUIManager::GetInstance(void)
{
	static CUIManager instance;
	return instance;
}

//初期化
void CUIManager::Initialize(void)
{
	m_GameObject.Initialize();
}

//更新
void CUIManager::Update(void)
{
	m_GameObject.Update();
}

//描画
void CUIManager::Draw(void)
{
	m_GameObject.Draw();
}

//解放
void CUIManager::Finalize(void)
{
	m_GameObject.Finalize();
}

//生成
void CUIManager::Create(UI_ID id)
{
	IUIComponent* ui = nullptr;

	switch (id)
	{
	case UI_ID::AIM:	ui = aqua::CreateGameObject<CAim>(&m_GameObject);	break;
	case UI_ID::START_MESSAGE:	ui = aqua::CreateGameObject<CStartMessage>(&m_GameObject);	break;
	case UI_ID::END_MESSAGE:	ui = aqua::CreateGameObject<CEndMessage>(&m_GameObject);	break;
	default:break;
	}

	if (ui)
		ui->Initialize();
}

//生成
void CUIManager::Create(UI_ID id, const aqua::CVector2& position)
{
	IUIComponent* ui = nullptr;

	switch (id)
	{
	case UI_ID::LIFE:	ui = aqua::CreateGameObject<CLife>(&m_GameObject);	break;
	case UI_ID::RADAR:	ui = aqua::CreateGameObject<CRadar>(&m_GameObject);	break;
	case UI_ID::SCORE:	ui = aqua::CreateGameObject<CScore>(&m_GameObject);	break;
	case UI_ID::TITLE_NAME:	ui = aqua::CreateGameObject<CTitleName>(&m_GameObject);	break;
	default:break;
	}

	if (ui)
		ui->Initialize(position);
}

//生成
void CUIManager::Create(UI_ID id, const aqua::CVector2& position,const std::string& word)
{
	CClickMessage* click_message = nullptr;

	if (UI_ID::CLICK_MESSAGE == id)
		click_message = aqua::CreateGameObject<CClickMessage>(&m_GameObject);

	if (click_message)
		click_message->Initialize(position, word);
}

//生成
void CUIManager::Create(UI_ID id, const aqua::CVector2& position, int score, float scale, aqua::CColor color)
{
	CShowScore* show_score = nullptr;

	if (UI_ID::SHOW_SCORE == id)
		show_score = aqua::CreateGameObject<CShowScore>(&m_GameObject);

	if (show_score)
		show_score->Initialize(position, score, scale, color);
}


//照準UI取得
CAim* CUIManager::GetAim(void)
{
	if (m_GameObject.GetChildList()->empty())
		return nullptr;

	auto it = m_GameObject.GetChildList()->begin();

	while (it != m_GameObject.GetChildList()->end())
	{

		if ((*it)->GetGameObjectName() == m_aim_name)
		{
			CAim* aim = (CAim*)(*it);

			return aim;
		}

		++it;
	}

	return nullptr;

}

//体力UI取得
CLife* CUIManager::GetLife(void)
{
	if (m_GameObject.GetChildList()->empty())
		return nullptr;

	auto it = m_GameObject.GetChildList()->begin();

	while (it != m_GameObject.GetChildList()->end())
	{

		if ((*it)->GetGameObjectName() == m_life_name)
		{
			CLife* life = (CLife*)(*it);

			return life;
		}

		++it;
	}

	return nullptr;

}

//スコアUI取得
CScore* CUIManager::GetScore(void)
{
	if (m_GameObject.GetChildList()->empty())
		return nullptr;

	auto it = m_GameObject.GetChildList()->begin();

	while (it != m_GameObject.GetChildList()->end())
	{

		if ((*it)->GetGameObjectName() == m_score_name)
		{
			CScore* score = (CScore*)(*it);

			return score;
		}

		++it;
	}

	return nullptr;

}

//開始メッセージを取得
CStartMessage* CUIManager::GetStartMessage(void)
{
	if (m_GameObject.GetChildList()->empty())
		return nullptr;

	auto it = m_GameObject.GetChildList()->begin();

	while (it != m_GameObject.GetChildList()->end())
	{

		if ((*it)->GetGameObjectName() == m_start_message_name)
		{
			CStartMessage* start_message = (CStartMessage*)(*it);

			return start_message;
		}

		++it;
	}

	return nullptr;

}

//終了メッセージ取得
CEndMessage* CUIManager::GetEndMessage(void)
{
	if (m_GameObject.GetChildList()->empty())
		return nullptr;

	auto it = m_GameObject.GetChildList()->begin();

	while (it != m_GameObject.GetChildList()->end())
	{

		if ((*it)->GetGameObjectName() == m_end_message_name)
		{
			CEndMessage* end_message = (CEndMessage*)(*it);

			return end_message;
		}

		++it;
	}

	return nullptr;
}

//コピーコンストラクタ
CUIManager::CUIManager(const CUIManager& rhs)
{
	(void)rhs;
}

//代入演算子
CUIManager& CUIManager::operator=(const CUIManager& rhs)
{
	(void)rhs;

	return *this;
}
