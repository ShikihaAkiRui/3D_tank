#pragma once

#include"../effect.h"

//�e��������Ȃ������Ƃ��̃G�t�F�N�g
class CNotHitEffect : public IEffect
{
public:
	//�R���X�g���N�^
	CNotHitEffect(aqua::IGameObject* parent);
	//�f�X�g���N�^
	~CNotHitEffect() = default;

	//������
	//�ʒu
	void Initialize(const aqua::CVector3& position)override;

private:
	static const aqua::CVector3 m_scale;	//�g�嗦
};