#pragma once

#include"aqua.h"
#include"ui_component/ui_id.h"
#include"ui_component/aim/aim.h"
#include"ui_component/life/life.h"
#include"ui_component/score/score.h"
#include"ui_component/start_message/start_message.h"
#include"ui_component/end_message/end_message.h"

//UI�}�l�[�W���[
class CUIManager
{
public:
	//�C���X�^���X���擾
	static CUIManager& GetInstance(void);

	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);

	//����
	//UI��ID
	void Create(UI_ID id);
	//UI��ID,	�ʒu
	void Create(UI_ID id, const aqua::CVector2& position);
	//UI��ID,	�ʒu,	����
	void Create(UI_ID id, const aqua::CVector2& position,const std::string& word);
	//UI��ID,	�ʒu,	�X�R�A,	�g�嗦,	�F
	void Create(UI_ID id, const aqua::CVector2& position, int score, float scale, aqua::CColor color);

	//�Ə�UI�擾
	CAim* GetAim(void);
	//�̗�UI�擾
	CLife* GetLife(void);
	//�X�R�AUI�擾
	CScore* GetScore(void);
	//�J�n���b�Z�[�W�擾
	CStartMessage* GetStartMessage(void);
	//�I�����b�Z�[�W�擾
	CEndMessage* GetEndMessage(void);

private:

	//�R���X�g���N�^
	CUIManager() = default;
	//�R�s�[�R���X�g���N�^
	CUIManager(const CUIManager & rhs);
	//�f�X�g���N�^
	~CUIManager() = default;
	//������Z�q
	CUIManager& operator=(const CUIManager & rhs);

	aqua::IGameObject m_GameObject;	//�Q�[���I�u�W�F�N�g

	static const std::string m_aim_name;	//�Ə��̖��O
	static const std::string m_life_name;	//�̗̖͂��O
	static const std::string m_score_name;	//�X�R�A�̖��O
	static const std::string m_start_message_name;	//�J�n���b�Z�[�W�̖��O
	static const std::string m_end_message_name;	//�I�����b�Z�[�W�̖��O
};