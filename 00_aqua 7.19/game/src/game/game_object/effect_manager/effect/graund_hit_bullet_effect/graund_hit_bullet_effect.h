#pragma once

#include"../effect.h"

//�����G�t�F�N�g
class CGraundHitBulletEffect : public IEffect
{
public:
	//�R���X�g���N�^
	CGraundHitBulletEffect(aqua::IGameObject* parent);
	//�f�X�g���N�^
	~CGraundHitBulletEffect() = default;

	//������
	//�ʒu
	void Initialize(const aqua::CVector3& position)override;

private:

	static const aqua::CVector3 m_scale;	//�g�嗦
};