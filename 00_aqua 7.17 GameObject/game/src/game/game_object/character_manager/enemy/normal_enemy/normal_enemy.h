#pragma once

#include"../enemy.h"

class CNormalEnemy : public IEnemy
{
	CNormalEnemy(aqua::IGameObject* parent);
	~CNormalEnemy() = default;

	void Initialize(void);

private:
	//çUåÇ
	void Attack(void)override;

};