#include "effect_manager.h"
#include"effect/effect.h"
#include"effect/explosion_effect/explosion_effect.h"
#include"effect/graund_hit_bullet_effect/graund_hit_bullet_effect.h"
#include"effect/hit_player_effect/hit_player_effect.h"

//インスタンスを取得
CEffectManager& CEffectManager::GetInstance(void)
{
	static CEffectManager instance;
	return instance;
}

//初期化
void CEffectManager::Initialize(void)
{
	m_GameObject.Initialize();
}

//更新
void CEffectManager::Update(void)
{
	m_GameObject.Update();
}

//描画
void CEffectManager::Draw(void)
{
	m_GameObject.Draw();
}

//解放
void CEffectManager::Finalize(void)
{
	m_GameObject.Finalize();
}

//生成
void CEffectManager::Create(EFFECT_ID id, const aqua::CVector3 position)
{
	IEffect* effect = nullptr;

	switch (id)
	{
	case EFFECT_ID::EXPLOSION:	effect = aqua::CreateGameObject<CExplosionEffect>(&m_GameObject);	break;
	case EFFECT_ID::GRAUND_HIT_BULLET: effect = aqua::CreateGameObject<CGraundHitBulletEffect>(&m_GameObject);  break;
	case EFFECT_ID::HITPLAYER: effect = aqua::CreateGameObject<CHitPlayerEffect>(&m_GameObject);	break;
	default:	break;
	}

	if (effect)
		effect->Initialize(position);
}

//コピーコンストラクタ
CEffectManager::CEffectManager(const CEffectManager& rhs)
{
	(void)rhs;
}

//代入演算子
CEffectManager& CEffectManager::operator=(const CEffectManager& rhs)
{
	(void)rhs;
	return *this;
}
