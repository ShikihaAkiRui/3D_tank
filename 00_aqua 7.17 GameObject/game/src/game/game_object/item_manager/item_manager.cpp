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
