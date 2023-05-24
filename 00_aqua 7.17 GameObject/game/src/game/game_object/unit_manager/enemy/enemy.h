#pragma once

#include"../character/character.h"

//エネミー
class CEnemy : public ICharacter
{
public:
	CEnemy(aqua::IGameObject* parent);
	~CEnemy() = default;

	void Initialize(void) override;
	void Update(void)override;

	//弾の当たり判定
	bool CheckHitBullet(void);
};