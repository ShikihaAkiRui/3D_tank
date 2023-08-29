#include "effect_manager.h"
#include"effect/effect.h"
#include"effect/explosion_effect/explosion_effect.h"
#include"effect/graund_hit_bullet_effect/graund_hit_bullet_effect.h"
#include"effect/hit_player_effect/hit_player_effect.h"
#include"effect/not_hit_effect/not_hit_effect.h"

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

	m_LoadEffect = AQUA_NEW aqua::CEffect3D[(int)EFFECT_ID::MAX];

	//使うエフェクトを読み込む
	m_LoadEffect[0].Create("data/effect/explosion/explosion.efkefc");
	m_LoadEffect[1].Create("data/effect/fire/fire.efkefc");
	m_LoadEffect[2].Create("data/effect/hit_player/hit_player.efkefc");
	m_LoadEffect[3].Create("data/effect/not_hit/not_hit.efkefc");
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

	for (int i = 0; i < (int)EFFECT_ID::MAX; ++i)
		m_LoadEffect[i].Delete();

	AQUA_SAFE_DELETE_ARRAY(m_LoadEffect);
}

//生成
void CEffectManager::Create(EFFECT_ID id, const aqua::CVector3 position)
{
	IEffect* effect = nullptr;

	switch (id)
	{
	case EFFECT_ID::EXPLOSION:	effect = aqua::CreateGameObject<CExplosionEffect>(&m_GameObject);	break;
	case EFFECT_ID::GRAUND_HIT_BULLET: effect = aqua::CreateGameObject<CGraundHitBulletEffect>(&m_GameObject);  break;
	case EFFECT_ID::HITPLAYER:	effect = aqua::CreateGameObject<CHitPlayerEffect>(&m_GameObject);	break;
	case EFFECT_ID::NOT_HIT:	effect = aqua::CreateGameObject<CNotHitEffect>(&m_GameObject);		break;
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
