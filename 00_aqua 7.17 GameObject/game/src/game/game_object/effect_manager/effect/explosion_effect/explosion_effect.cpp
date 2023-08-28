#include "explosion_effect.h"

const aqua::CVector3 CExplosionEffect::m_scale = aqua::CVector3(5.0f, 5.0f,5.0f);

//コンストラクタ
CExplosionEffect::CExplosionEffect(aqua::IGameObject* parent)
	:IEffect(parent, "ExplosionEffect")
{
}

//初期化
void CExplosionEffect::Initialize(const aqua::CVector3& position)
{
	IEffect::Initialize(position);

	m_Effect.Create("data/effect/explosion/explosion.efkefc");

	m_Effect.Play();
	m_Effect.position = m_Position;
	m_Effect.scale = m_scale;
}

//更新
void CExplosionEffect::Update(void)
{
	m_Effect.Update();

	//エフェクトが終わったら消す
	if (m_Effect.Finished())
		DeleteObject();
}

//描画
void CExplosionEffect::Draw(void)
{
	m_Effect.Draw();
}

//解放
void CExplosionEffect::Finalize(void)
{
	m_Effect.Delete();
}
