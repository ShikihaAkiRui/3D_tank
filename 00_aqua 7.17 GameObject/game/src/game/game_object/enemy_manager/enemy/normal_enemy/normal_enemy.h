#pragma once

#include"../enemy.h"

//���ʂ̓G
class CNormalEnemy : public IEnemy
{
	CNormalEnemy(aqua::IGameObject* parent);
	~CNormalEnemy() = default;

	void Initialize(void);


};