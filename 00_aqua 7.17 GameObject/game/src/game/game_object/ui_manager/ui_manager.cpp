#include "ui_manager.h"
#include"ui_component/radar/radar.h"
#include"ui_component/show_score/show_score.h"

const std::string CUIManager::m_aim_name = "Aim";
const std::string CUIManager::m_life_name = "Life";
const std::string CUIManager::m_score_name = "Score";

//�C���X�^���X���擾
CUIManager& CUIManager::GetInstance(void)
{
	static CUIManager instance;
	return instance;
}

//������
void CUIManager::Initialize(void)
{
	m_GameObject.Initialize();
}

//�X�V
void CUIManager::Update(void)
{
	m_GameObject.Update();
}

//�`��
void CUIManager::Draw(void)
{
	m_GameObject.Draw();
}

//���
void CUIManager::Finalize(void)
{
	m_GameObject.Finalize();
}

//����
void CUIManager::Create(UI_ID id)
{
	IUIComponent* ui = nullptr;

	switch (id)
	{
	case UI_ID::AIM:	ui = aqua::CreateGameObject<CAim>(&m_GameObject);	break;
	default:break;
	}

	if (ui)
		ui->Initialize();
}

//����
void CUIManager::Create(UI_ID id, const aqua::CVector2& position)
{
	IUIComponent* ui = nullptr;

	switch (id)
	{
	case UI_ID::AIM:	ui = aqua::CreateGameObject<CAim>(&m_GameObject);	break;
	case UI_ID::LIFE:	ui = aqua::CreateGameObject<CLife>(&m_GameObject);	break;
	case UI_ID::RADAR:	ui = aqua::CreateGameObject<CRadar>(&m_GameObject);	break;
	case UI_ID::SCORE:	ui = aqua::CreateGameObject<CScore>(&m_GameObject);	break;
	default:break;
	}

	if (ui)
		ui->Initialize(position);
}

//����
void CUIManager::Create(UI_ID id, const aqua::CVector2& position, int score, float scale, aqua::CColor color)
{
	CShowScore* show_score = nullptr;

	if (UI_ID::SHOW_SCORE == id)
		show_score = aqua::CreateGameObject<CShowScore>(&m_GameObject);

	if (show_score)
		show_score->Initialize(position, score, scale, color);
}

//�Ə�UI�擾
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

//�̗�UI�擾
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

//�X�R�AUI�擾
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

//�R�s�[�R���X�g���N�^
CUIManager::CUIManager(const CUIManager& rhs)
{
	(void)rhs;
}

//������Z�q
CUIManager& CUIManager::operator=(const CUIManager& rhs)
{
	(void)rhs;

	return *this;
}
