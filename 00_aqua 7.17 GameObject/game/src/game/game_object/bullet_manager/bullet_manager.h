#pragma once

#include"aqua.h"
#include"../unit_manager/unit_id.h"

//弾のマネージャー
class CBulletManager : public aqua::IGameObject
{
public:
	CBulletManager(aqua::IGameObject* parent);
	~CBulletManager() = default;

	//生成
	void Create(UNIT_CATEGORY unit_category,const aqua::CVector3& position, const aqua::CVector3& rotation);

	//弾とキャラクターの当たり判定
	bool CheckHitCharacter(ICollision* collision,UNIT_CATEGORY unit_category);

};