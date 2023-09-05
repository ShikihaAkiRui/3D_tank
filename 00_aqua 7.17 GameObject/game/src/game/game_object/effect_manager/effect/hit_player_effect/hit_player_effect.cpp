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
	IEffect::Initialize("data/effect/hit_player/hit_player.efkefc", position, m_scale);
}