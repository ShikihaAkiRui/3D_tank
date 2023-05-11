#pragma once

#include"aqua.h"

//弾のマネージャー
class CBulletManager : public aqua::IGameObject
{
public:
	CBulletManager(aqua::IGameObject* parent);
	~CBulletManager() = default;

	//生成
	void Create(const aqua::CVector3& position,float direction);
};