#include "hit_player_effect.h"

const aqua::CVector3 CHitPlayerEffect::m_scale = aqua::CVector3(8.0f, 8.0f, 8.0f);

//�R���X�g���N�^
CHitPlayerEffect::CHitPlayerEffect(aqua::IGameObject* parent)
	:IEffect(parent, "ExplosionEffect")
{
}

//������
void CHitPlayerEffect::Initialize(const aqua::CVector3& position)
{
	IEffect::Initialize(position);

	m_Effect.Create("data/effect/hit_player/hit_player.efkefc");

	m_Effect.Play();
	m_Effect.position = m_Position;
	m_Effect.scale = m_scale;
}

//�X�V
void CHitPlayerEffect::Update(void)
{
	m_Effect.Update();

	if (m_Effect.Finished())
		DeleteObject();
}

//�`��
void CHitPlayerEffect::Draw(void)
{
	m_Effect.Draw();
}

//���
void CHitPlayerEffect::Finalize(void)
{
	m_Effect.Delete();
}
