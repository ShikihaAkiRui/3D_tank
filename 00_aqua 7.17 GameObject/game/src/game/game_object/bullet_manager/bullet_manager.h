#pragma once

#include"aqua.h"

//�e�̃}�l�[�W���[
class CBulletManager : public aqua::IGameObject
{
public:
	CBulletManager(aqua::IGameObject* parent);
	~CBulletManager() = default;

	//����
	void Create(const aqua::CVector3& position,float direction);
};