#pragma once

#include"../unit/unit.h"

//�v���C���[�N���X
class CPlayer : public IUnit
{
public:
	CPlayer(aqua::IGameObject* parent);
	CPlayer() = default;

	void Initialize(void);
};