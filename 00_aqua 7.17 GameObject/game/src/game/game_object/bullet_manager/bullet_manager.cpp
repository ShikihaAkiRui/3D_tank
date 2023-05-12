#include "bullet_manager.h"
#include"bullet/bullet.h"

//コンストラクタ
CBulletManager::CBulletManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"BulletManager")
{
}

//生成
void CBulletManager::Create(const aqua::CVector3& position,float direction )
{
	CBullet* bullet = aqua::CreateGameObject<CBullet>(this);

	if (!bullet)
		return;

	bullet->Initialize(position, direction);
}