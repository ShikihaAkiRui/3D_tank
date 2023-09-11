#pragma once

#include"../effect.h"

//�����G�t�F�N�g
class CExplosionEffect : public IEffect
{
public:
	//�R���X�g���N�^
	CExplosionEffect(aqua::IGameObject* parent);
	//�f�X�g���N�^
	~CExplosionEffect() = default;

	//������
	//�ʒu
	void Initialize(const aqua::CVector3& position)override;

private:

	static const aqua::CVector3 m_scale;	//�g�嗦
};