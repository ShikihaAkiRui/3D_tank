#pragma once

#include"aqua.h"
#include"../unit_manager/unit_id.h"

//�e�̃}�l�[�W���[
class CBulletManager : public aqua::IGameObject
{
public:
	CBulletManager(aqua::IGameObject* parent);
	~CBulletManager() = default;

	//����
	void Create(UNIT_CATEGORY unit_category,const aqua::CVector3& position, const aqua::CVector3& rotation);

	//�e�ƃL�����N�^�[�̓����蔻��
	bool CheckHitCharacter(ICollision* collision,UNIT_CATEGORY unit_category);

};