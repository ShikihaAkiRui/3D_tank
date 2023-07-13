#include "item_manager.h"
#include"item/item.h"

//�R���X�g���N�^
CItemManager::CItemManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"ItemManager")
{
}

//����
void CItemManager::Create(aqua::CVector3& position)
{
	CItem* item = nullptr;
	//CItem* item = aqua::CreateGameObject<CItem>(this);

	if (!item)	return;

	item->Initialize(position);
}

//�A�C�e���ƃL�����N�^�[�̔���
bool CItemManager::CheckHitCharacter(ICollision* collision)
{
	auto it = GetChildList()->begin();

	bool hit_flag = false;

	while (it != GetChildList()->end())
	{
		CItem* item = (CItem*)(*it);

		hit_flag = collision->CollCheckSphere(item->GetCenterPosition(), item->GetRadius());

		//����������true
		if (hit_flag && IGameObject::GetGameObjectName() == "Player")
		{
			item->HitCharacter();
			return hit_flag;
		}

		++it;
	}

	//������Ȃ�������false
	return hit_flag;

}
