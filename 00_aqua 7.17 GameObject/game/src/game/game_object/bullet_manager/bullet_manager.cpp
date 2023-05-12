#include "bullet_manager.h"
#include"bullet/bullet.h"

//�R���X�g���N�^
CBulletManager::CBulletManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"BulletManager")
{
}

//����
void CBulletManager::Create(const aqua::CVector3& position,float direction )
{
	CBullet* bullet = aqua::CreateGameObject<CBullet>(this);

	if (!bullet)
		return;

	bullet->Initialize(position, direction);
}