#pragma once

#include"../effect.h"

//�v���C���[�ɓ��������G�t�F�N�g
class CHitPlayerEffect : public IEffect
{
public:
	CHitPlayerEffect(aqua::IGameObject* parent);
	~CHitPlayerEffect() = default;

	void Initialize(const aqua::CVector3& position)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;

private:
	aqua::CEffect3D m_Effect;	//�G�t�F�N�g

	static const aqua::CVector3 m_scale;	//�g�嗦
};