#pragma once

#include"aqua.h"
#include"enemy/enemy_id.h"

//�G�l�~�[�}�l�[�W���[
class CEnemyManager : public aqua::IGameObject
{
public:
	CEnemyManager(aqua::IGameObject* parent);
	~CEnemyManager() = default;

	//����
	void Create(ENEMY_ID id);
};