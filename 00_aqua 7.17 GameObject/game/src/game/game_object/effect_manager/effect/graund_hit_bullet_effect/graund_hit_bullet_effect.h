#pragma once

#include"../effect.h"

//�����G�t�F�N�g
class CGraundHitBulletEffect : public IEffect
{
public:
	CGraundHitBulletEffect(aqua::IGameObject* parent);
	~CGraundHitBulletEffect() = default;

	void Initialize(const aqua::CVector3& position)override;

private:

	static const aqua::CVector3 m_scale;	//�g�嗦
};