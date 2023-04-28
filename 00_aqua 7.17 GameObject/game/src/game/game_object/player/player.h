#pragma once

#include"../unit/unit.h"

//プレイヤークラス
class CPlayer : public IUnit
{
public:
	CPlayer(aqua::IGameObject* parent);
	CPlayer() = default;

	void Initialize(void);
};