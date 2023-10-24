#pragma once

#include"../effect.h"

//�v���C���[�ɓ��������G�t�F�N�g
class CHitPlayerEffect : public IEffect
{
public:	
	//�R���X�g���N�^
	CHitPlayerEffect(aqua::IGameObject* parent);
	//�f�X�g���N�^
	~CHitPlayerEffect() = default;

	//������
	//�ʒu
	void Initialize(const aqua::CVector3& position)override;

private:

	static const aqua::CVector3 m_scale;	//�g�嗦
};