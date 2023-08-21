#pragma once

#include"aqua.h"
#include"ui_component/ui_id.h"
#include"ui_component/aim/aim.h"
#include"ui_component/life/life.h"
#include"ui_component/score/score.h"

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
	void Create(UI_ID id);
	void Create(UI_ID id, const aqua::CVector2& position);

	//�Ə�UI�擾
	CAim* GetAim(void);
	//�̗�UI�擾
	CLife* GetLife(void);
	//�X�R�AUI�擾
	CScore* GetScore(void);

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
};