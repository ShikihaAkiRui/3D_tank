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
	//CBullet* bullet = nullptr;
	CBullet* bullet = aqua::CreateGameObject<CBullet>(this);

	if (!bullet)
		return;

	bullet->Initialize(unit_category,position,rotation);
}