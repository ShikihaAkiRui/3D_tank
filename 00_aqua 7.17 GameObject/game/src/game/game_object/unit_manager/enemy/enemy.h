#pragma once

#include"../../unit/unit.h"

//�G�l�~�[
class CEnemy : public IUnit
{
public:
	CEnemy(aqua::IGameObject* parent);
	~CEnemy() = default;

	void Initialize(void);
	void Update(void)override;

	//�e�̓����蔻��
	bool CheckHitBullet(void);
};