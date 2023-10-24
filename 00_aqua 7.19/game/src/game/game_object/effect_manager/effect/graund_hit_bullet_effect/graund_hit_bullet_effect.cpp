#include "graund_hit_bullet_effect.h"

const aqua::CVector3 CGraundHitBulletEffect::m_scale = aqua::CVector3(3.0f, 3.0f, 3.0f);

//コンストラクタ
CGraundHitBulletEffect::CGraundHitBulletEffect(aqua::IGameObject* parent)
	:IEffect(parent, "ExplosionEffect")
{
}

//初期化
void CGraundHitBulletEffect::Initialize(const aqua::CVector3& position)
{
	IEffect::Initialize("data/effect/fire/fire.efkefc", position, m_scale);
}
