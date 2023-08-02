#pragma once

#include"aqua.h"
#include"../unit_manager/unit_id.h"
#include"bullet/bullet_id.h"

//�e�̃}�l�[�W���[
class CBulletManager
{
public:
	//�C���X�^���X�̎擾
	static CBulletManager& GetInstance(void);

	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);

	//����
	void Create(BULLET_ID id,UNIT_CATEGORY unit_category, const aqua::CVector3& position, const aqua::CVector3& rotation);

	//�e�ƃL�����N�^�[�̓����蔻��
	bool CheckHitCharacter(ICollision* collision, UNIT_CATEGORY unit_category);

private:
	//�R���X�g���N�^
	CBulletManager() = default;
	//�R�s�[�R���X�g���N�^
	CBulletManager(const CBulletManager& rhs);
	//�f�X�g���N�^
	~CBulletManager() = default;
	//������Z�q
	CBulletManager& operator=(const CBulletManager& rhs);

	aqua::IGameObject m_GameObject;	//�Q�[���I�u�W�F�N�g
};
