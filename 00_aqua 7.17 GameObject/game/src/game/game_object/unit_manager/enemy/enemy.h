#pragma once

#include"../character/character.h"

//�G�l�~�[
class CEnemy : public ICharacter
{
public:
	CEnemy(aqua::IGameObject* parent);
	~CEnemy() = default;

	void Initialize(void) override;
	void Update(void)override;

	//�e�̓����蔻��
	bool CheckHitBullet(void);
};