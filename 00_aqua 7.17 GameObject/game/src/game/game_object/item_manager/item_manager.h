#pragma once

#include"aqua.h"
#include"../unit_manager/unit_manager.h"

//�A�C�e���}�l�[�W���[
class CItemManager : public aqua::IGameObject
{
public:
	CItemManager(aqua::IGameObject* parent);
	~CItemManager() = default;

	//����
	void Create(aqua::CVector3& position);

	//�A�C�e���ƃL�����N�^�[�̔���
	bool CheckHitCharacter(ICollision* collision,UNIT_CATEGORY unit_category);
};