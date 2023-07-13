#pragma once

#include"aqua.h"

//アイテムマネージャー
class CItemManager : public aqua::IGameObject
{
public:
	CItemManager(aqua::IGameObject* parent);
	~CItemManager() = default;

	//生成
	void Create(aqua::CVector3& position);

	//アイテムとキャラクターの判定
	bool CheckHitCharacter(ICollision* collision);
};