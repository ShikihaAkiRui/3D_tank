#pragma once

#include"../enemy.h"

class CNormalEnemy : public IEnemy
{
	CNormalEnemy(aqua::IGameObject* parent);
	~CNormalEnemy() = default;

	void Initialize(void);

private:
	//�U��
	void Attack(void)override;

};