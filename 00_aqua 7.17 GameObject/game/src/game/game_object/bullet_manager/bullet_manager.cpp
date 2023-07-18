#include "bullet_manager.h"
#include"bullet/bullet.h"

/*
//�R���X�g���N�^
CBulletManager::CBulletManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"BulletManager")
{
}

//����
void CBulletManager::Create(UNIT_CATEGORY unit_category,const aqua::CVector3& position, const aqua::CVector3& rotation)
{
	CBullet* bullet = aqua::CreateGameObject<CBullet>(this);

	if (!bullet)
		return;

	bullet->Initialize(unit_category,position,rotation);
}

//�e�ƃL�����N�^�[�̓����蔻��
bool CBulletManager::CheckHitCharacter(ICollision* collision,UNIT_CATEGORY unit_category)
{
	bool hit_flag = false;

	auto it = GetChildList()->begin();

	while (it != GetChildList()->end())
	{
		CBullet* bullet = (CBullet*)(*it);
		
		if (bullet->GetCategory() != unit_category)
		{
			hit_flag = collision->CollCheckSphere(bullet->GetCenterPosition(), bullet->GetRadius());

			//����������
			if (hit_flag)
			{
				bullet->HitCharacter();
				return hit_flag;
			}
		}

		it++;
	}

	//�������ĂȂ��Ȃ�
	return hit_flag;

}*/


//�C���X�^���X�̎擾
CBulletManager& CBulletManager::GetInstance(void)
{
	static CBulletManager instance;

	return instance;
}

//������
void CBulletManager::Initialize(void)
{
	m_GameObject.Initialize();
}

//�X�V
void CBulletManager::Update(void)
{
	m_GameObject.Update();
}

//�`��
void CBulletManager::Draw(void)
{
	m_GameObject.Draw();
}

//���
void CBulletManager::Finalize(void)
{
	m_GameObject.Finalize();
}

//����
void CBulletManager::Create(UNIT_CATEGORY unit_category, const aqua::CVector3& position, const aqua::CVector3& rotation)
{
	CBullet* bullet = nullptr;

	bullet = new CBullet(&m_GameObject);

	if (!bullet)
		return;

	bullet->Initialize(unit_category, position, rotation);

	m_GameObject.GetChildList()->push_back(bullet);

}

//�e�ƃL�����N�^�[�̓����蔻��
bool CBulletManager::CheckHitCharacter(ICollision* collision, UNIT_CATEGORY unit_category)
{
	bool hit_flag = false;

	auto it = m_GameObject.GetChildList()->begin();

	while (it != m_GameObject.GetChildList()->end())
	{
		CBullet* bullet = (CBullet*)(*it);

		if (bullet->GetCategory() != unit_category)
		{
			hit_flag = collision->CollCheckSphere(bullet->GetCenterPosition(), bullet->GetRadius());

			//����������
			if (hit_flag)
			{
				bullet->HitCharacter();
				return hit_flag;
			}
		}

		it++;
	}

	//�������ĂȂ��Ȃ�
	return hit_flag;

}

/*//�R���X�g���N�^
CBulletManager::CBulletManager(void)
{
}*/

//�R�s�[�R���X�g���N�^
CBulletManager::CBulletManager(const CBulletManager& rhs)
{
	(void)rhs;
}

/*//�f�X�g���N�^
CBulletManager::~CBulletManager(void)
{
}*/

//������Z�q
CBulletManager& CBulletManager::operator=(const CBulletManager& rhs)
{
	(void)rhs;

	return *this;
}