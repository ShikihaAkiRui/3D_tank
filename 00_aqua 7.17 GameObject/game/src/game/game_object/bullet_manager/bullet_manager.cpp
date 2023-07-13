#include "bullet_manager.h"
#include"bullet/bullet.h"

//コンストラクタ
CBulletManager::CBulletManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"BulletManager")
{
}

//生成
void CBulletManager::Create(UNIT_CATEGORY unit_category,const aqua::CVector3& position, const aqua::CVector3& rotation)
{
	CBullet* bullet = aqua::CreateGameObject<CBullet>(this);

	if (!bullet)
		return;

	bullet->Initialize(unit_category,position,rotation);
}

//弾とキャラクターの当たり判定
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

			//当たったら
			if (hit_flag)
			{
				bullet->HitCharacter();
				return hit_flag;
			}
		}

		it++;
	}

	//当たってないなら
	return hit_flag;

}