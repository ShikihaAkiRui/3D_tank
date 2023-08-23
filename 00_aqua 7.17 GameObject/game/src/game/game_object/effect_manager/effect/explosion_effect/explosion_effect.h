#pragma once

#include"../effect.h"

//�����G�t�F�N�g
class CExplosionEffect : public IEffect
{
public:
	CExplosionEffect(aqua::IGameObject* parent);
	~CExplosionEffect() = default;

	void Initialize(const aqua::CVector3& position)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;

private:

	static const aqua::CVector3 m_scale;	//�g�嗦
};