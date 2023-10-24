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
	IEffect::Initialize("data/effect/explosion/explosion.efkefc", position, m_scale);
}
