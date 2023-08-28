#include "graund_hit_bullet_effect.h"

const aqua::CVector3 CGraundHitBulletEffect::m_scale = aqua::CVector3(3.0f, 3.0f, 3.0f);

//�R���X�g���N�^
CGraundHitBulletEffect::CGraundHitBulletEffect(aqua::IGameObject* parent)
	:IEffect(parent, "ExplosionEffect")
{
}

//������
void CGraundHitBulletEffect::Initialize(const aqua::CVector3& position)
{
	IEffect::Initialize(position);

	m_Effect.Create("data/effect/fire/fire.efkefc");

	m_Effect.Play();
	m_Effect.position = m_Position;
	m_Effect.scale = m_scale;
}

//�X�V
void CGraundHitBulletEffect::Update(void)
{
	m_Effect.Update();

	//�G�t�F�N�g���I����������
	if (m_Effect.Finished())
		DeleteObject();
}

//�`��
void CGraundHitBulletEffect::Draw(void)
{
	m_Effect.Draw();
}

//���
void CGraundHitBulletEffect::Finalize(void)
{
	m_Effect.Delete();
}
