#pragma once

#include"aqua.h"
#include"enemy/enemy_id.h"

//エネミーマネージャー
class CEnemyManager : public aqua::IGameObject
{
public:
	CEnemyManager(aqua::IGameObject* parent);
	~CEnemyManager() = default;

	//生成
	void Create(ENEMY_ID id);
};