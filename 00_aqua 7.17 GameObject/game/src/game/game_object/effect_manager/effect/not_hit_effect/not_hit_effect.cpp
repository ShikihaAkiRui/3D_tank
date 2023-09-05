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
	IEffect::Initialize("data/effect/not_hit/not_hit.efkefc", position, m_scale);
}