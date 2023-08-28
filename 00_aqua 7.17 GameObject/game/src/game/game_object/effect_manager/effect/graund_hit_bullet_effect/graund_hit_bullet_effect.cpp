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
	IEffect::Initialize(position);

	m_Effect.Create("data/effect/fire/fire.efkefc");

	m_Effect.Play();
	m_Effect.position = m_Position;
	m_Effect.scale = m_scale;
}

//更新
void CGraundHitBulletEffect::Update(void)
{
	m_Effect.Update();

	//エフェクトが終わったら消す
	if (m_Effect.Finished())
		DeleteObject();
}

//描画
void CGraundHitBulletEffect::Draw(void)
{
	m_Effect.Draw();
}

//解放
void CGraundHitBulletEffect::Finalize(void)
{
	m_Effect.Delete();
}
