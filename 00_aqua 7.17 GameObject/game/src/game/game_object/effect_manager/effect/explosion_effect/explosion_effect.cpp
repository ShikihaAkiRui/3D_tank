#include "explosion_effect.h"

const aqua::CVector3 CExplosionEffect::m_scale = aqua::CVector3(5.0f, 5.0f,5.0f);

//�R���X�g���N�^
CExplosionEffect::CExplosionEffect(aqua::IGameObject* parent)
	:IEffect(parent, "ExplosionEffect")
{
}

//������
void CExplosionEffect::Initialize(const aqua::CVector3& position)
{
	IEffect::Initialize(position);

	m_Effect.Create("data/effect/explosion/explosion.efkefc");

	m_Effect.Play();
	m_Effect.position = m_Position;
	m_Effect.scale = m_scale;
}

//�X�V
void CExplosionEffect::Update(void)
{
	m_Effect.Update();

	//�G�t�F�N�g���I����������
	if (m_Effect.Finished())
		DeleteObject();
}

//�`��
void CExplosionEffect::Draw(void)
{
	m_Effect.Draw();
}

//���
void CExplosionEffect::Finalize(void)
{
	m_Effect.Delete();
}
