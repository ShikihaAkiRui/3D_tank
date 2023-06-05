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

private:
	static const aqua::CVector3 m_graund_ray_langth;	//床用のレイの長さ
};