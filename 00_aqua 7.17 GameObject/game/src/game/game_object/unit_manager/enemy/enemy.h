#pragma once

#include"../../unit/unit.h"

//�G�l�~�[
class CEnemy : public IUnit
{
public:
	CEnemy(aqua::IGameObject* parent);
	~CEnemy() = default;

	void Initialize(void);

};