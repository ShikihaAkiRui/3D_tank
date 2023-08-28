#pragma once

#include"aqua.h"
#include"../unit_manager/unit_manager.h"

//�A�C�e���}�l�[�W���[
class CItemManager
{
public:
	//�C���X�^���X���擾
	static CItemManager& GetInstance(void);

	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);

	//����
	//�ʒu
	void Create(aqua::CVector3& position);

	//�A�C�e���ƃL�����N�^�[�̓����蔻��
	//�R���W����,	���j�b�g�̃J�e�S���[
	bool CheckHitCharacter(ICollision* collision, UNIT_CATEGORY unit_category);

private:
	//�R���X�g���N�^
	CItemManager() = default;
	//�R�s�[�R���X�g���N�^
	CItemManager(const CItemManager & rhs);
	//�f�X�g���N�^
	~CItemManager() = default;
	//������Z�q
	CItemManager& operator=(const CItemManager & rhs);

	aqua::IGameObject m_GameObject;	//�Q�[���I�u�W�F�N�g

};