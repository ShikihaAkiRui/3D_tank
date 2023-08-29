#pragma once

#include"../effect.h"

//�e��������Ȃ������Ƃ��̃G�t�F�N�g
class CNotHitEffect : public IEffect
{
public:
	CNotHitEffect(aqua::IGameObject* parent);
	~CNotHitEffect() = default;

	//������
	//�ʒu
	void Initialize(const aqua::CVector3& position)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;

private:
	static const aqua::CVector3 m_scale;	//�g�嗦
};