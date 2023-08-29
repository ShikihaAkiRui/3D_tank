#include "not_hit_effect.h"

const aqua::CVector3 CNotHitEffect::m_scale = aqua::CVector3(2.0f, 2.0f,2.0f);

//コンストラクタ
CNotHitEffect::CNotHitEffect(aqua::IGameObject* parent)
	:IEffect(parent,"NotHitEffect")
{
}

//初期化
void CNotHitEffect::Initialize(const aqua::CVector3& position)
{
	IEffect::Initialize(position);

	m_Effect.Create("data/effect/not_hit/not_hit.efkefc");

	m_Effect.position = m_Position;
	m_Effect.scale = m_scale;
	m_Effect.Play();
}

//更新
void CNotHitEffect::Update(void)
{
	m_Effect.Update();

	//エフェクトが終わったら消す
	if (m_Effect.Finished())
		DeleteObject();
}

//描画
void CNotHitEffect::Draw(void)
{
	m_Effect.Draw();
}

//解放
void CNotHitEffect::Finalize(void)
{
	m_Effect.Delete();
}
