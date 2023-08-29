#include "effect_manager.h"
#include"effect/effect.h"
#include"effect/explosion_effect/explosion_effect.h"
#include"effect/graund_hit_bullet_effect/graund_hit_bullet_effect.h"
#include"effect/hit_player_effect/hit_player_effect.h"
#include"effect/not_hit_effect/not_hit_effect.h"

//�C���X�^���X���擾
CEffectManager& CEffectManager::GetInstance(void)
{
	static CEffectManager instance;
	return instance;
}

//������
void CEffectManager::Initialize(void)
{
	m_GameObject.Initialize();

	m_LoadEffect = AQUA_NEW aqua::CEffect3D[(int)EFFECT_ID::MAX];

	//�g���G�t�F�N�g��ǂݍ���
	m_LoadEffect[0].Create("data/effect/explosion/explosion.efkefc");
	m_LoadEffect[1].Create("data/effect/fire/fire.efkefc");
	m_LoadEffect[2].Create("data/effect/hit_player/hit_player.efkefc");
	m_LoadEffect[3].Create("data/effect/not_hit/not_hit.efkefc");
}

//�X�V
void CEffectManager::Update(void)
{
	m_GameObject.Update();
}

//�`��
void CEffectManager::Draw(void)
{
	m_GameObject.Draw();
}

//���
void CEffectManager::Finalize(void)
{
	m_GameObject.Finalize();

	for (int i = 0; i < (int)EFFECT_ID::MAX; ++i)
		m_LoadEffect[i].Delete();

	AQUA_SAFE_DELETE_ARRAY(m_LoadEffect);
}

//����
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

//�R�s�[�R���X�g���N�^
CEffectManager::CEffectManager(const CEffectManager& rhs)
{
	(void)rhs;
}

//������Z�q
CEffectManager& CEffectManager::operator=(const CEffectManager& rhs)
{
	(void)rhs;
	return *this;
}
