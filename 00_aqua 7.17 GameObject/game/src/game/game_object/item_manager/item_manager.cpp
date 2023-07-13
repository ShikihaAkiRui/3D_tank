#include "item_manager.h"
#include"item/item.h"

//コンストラクタ
CItemManager::CItemManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"ItemManager")
{
}

//生成
void CItemManager::Create(aqua::CVector3& position)
{
	CItem* item = nullptr;
	//CItem* item = aqua::CreateGameObject<CItem>(this);

	if (!item)	return;

	item->Initialize(position);
}

//アイテムとキャラクターの判定
bool CItemManager::CheckHitCharacter(ICollision* collision)
{
	auto it = GetChildList()->begin();

	bool hit_flag = false;

	while (it != GetChildList()->end())
	{
		CItem* item = (CItem*)(*it);

		hit_flag = collision->CollCheckSphere(item->GetCenterPosition(), item->GetRadius());

		//当たったらtrue
		if (hit_flag && IGameObject::GetGameObjectName() == "Player")
		{
			item->HitCharacter();
			return hit_flag;
		}

		++it;
	}

	//当たらなかったらfalse
	return hit_flag;

}
