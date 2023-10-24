#include "bullet_manager.h"
#include"bullet/bullet.h"
#include"bullet/bullet_normal/bullet_normal.h"
#include"bullet/bullet_parabola/bullet_parabola.h"

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
void CBulletManager::Create(BULLET_ID id,UNIT_CATEGORY unit_category, const aqua::CVector3& position, const aqua::CVector3& rotation)
{
	CBulletNormal* bullet = nullptr;
	CBulletParabola* parabola = nullptr;

	switch (id)
	{
	case BULLET_ID::NORMAL:	
		bullet = aqua::CreateGameObject<CBulletNormal>(&m_GameObject);	break;
	case BULLET_ID::PARABOLA:	
		parabola = aqua::CreateGameObject<CBulletParabola>(&m_GameObject);	break;
		break;
	default:	break;
	}

	if (bullet)
		bullet->Initialize(unit_category, position, rotation);
	else if (parabola)
		parabola->Initialize(unit_category, position, rotation);


}

//�e�ƃL�����N�^�[�̓����蔻��
bool CBulletManager::CheckHitCharacter(ICollision* collision, UNIT_CATEGORY unit_category)
{
	bool hit_flag = false;

	auto it = m_GameObject.GetChildList()->begin();

	while (it != m_GameObject.GetChildList()->end())
	{
		IBullet* bullet = (IBullet*)(*it);

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

//�R�s�[�R���X�g���N�^
CBulletManager::CBulletManager(const CBulletManager& rhs)
{
	(void)rhs;
}

//������Z�q
CBulletManager& CBulletManager::operator=(const CBulletManager& rhs)
{
	(void)rhs;

	return *this;
}
