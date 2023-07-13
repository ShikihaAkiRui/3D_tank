#include "bullet_manager.h"
#include"bullet/bullet.h"

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

}