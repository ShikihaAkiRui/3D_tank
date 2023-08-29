#include "not_hit_effect.h"

const aqua::CVector3 CNotHitEffect::m_scale = aqua::CVector3(2.0f, 2.0f,2.0f);

//�R���X�g���N�^
CNotHitEffect::CNotHitEffect(aqua::IGameObject* parent)
	:IEffect(parent,"NotHitEffect")
{
}

//������
void CNotHitEffect::Initialize(const aqua::CVector3& position)
{
	IEffect::Initialize(position);

	m_Effect.Create("data/effect/not_hit/not_hit.efkefc");

	m_Effect.position = m_Position;
	m_Effect.scale = m_scale;
	m_Effect.Play();
}

//�X�V
void CNotHitEffect::Update(void)
{
	m_Effect.Update();

	//�G�t�F�N�g���I����������
	if (m_Effect.Finished())
		DeleteObject();
}

//�`��
void CNotHitEffect::Draw(void)
{
	m_Effect.Draw();
}

//���
void CNotHitEffect::Finalize(void)
{
	m_Effect.Delete();
}
