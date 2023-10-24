#include"bullet.h"
#include"../../stage/stage.h"
#include"../../effect_manager/effect_manager.h"
#include"../../game_sound_manager/game_sound_manager.h"

const aqua::CVector3 IBullet::m_default_direction = aqua::CVector3(0.0f,0.0f,1.0f);
const aqua::CVector3 IBullet::m_min_range = aqua::CVector3(-1600.0f,-300.0f,-1600.0f);
const aqua::CVector3 IBullet::m_max_range = aqua::CVector3(1000.0f,500.0f,1000.0f);


//�R���X�g���N�^
IBullet::IBullet(aqua::IGameObject* parent, const std::string& object_name)
	:aqua::IGameObject(parent,object_name)
	,m_Position(aqua::CVector3::ZERO)
	,m_Velocity(m_default_direction)
	,m_Radius(0.0f)
	,m_UnitCategory(UNIT_CATEGORY::DUMMY)
{
}

//������
void IBullet::Initialize(const std::string& file_name)
{
	m_Model.Load(file_name);

	m_Model.position = m_Position;
}

//�X�V
void IBullet::Update(void)
{
	//�ʒu���ړ�
	m_Position += m_Velocity;
	m_Model.position = m_Position;

	//���̓����蔻��
	CheckGraund();

	//�\���͈͂̔���
	CheckRange();
}

//�`��
void IBullet::Draw(void)
{
	m_Model.Draw();
}

//���
void IBullet::Finalize(void)
{
	m_Model.Unload();
}

//�L�����N�^�[�ɓ�������
void IBullet::HitCharacter(void)
{
	DeleteObject();
}

//���S�ʒu�擾
aqua::CVector3 IBullet::GetCenterPosition(void)
{
	return m_Position;
}

//���a�擾
float IBullet::GetRadius(void)
{
	return m_Radius;
}

//�J�e�S���[�擾
UNIT_CATEGORY IBullet::GetCategory(void)
{
	return m_UnitCategory;
}

//���̓����蔻��
void IBullet::CheckGraund(void)
{
	CStage* stage = (CStage*)aqua::FindGameObject("Stage");

	//���ɓ������������
	if (stage->GetHitBulletGroundFlag(m_Position, m_Radius))
	{
		CEffectManager& effect = CEffectManager::GetInstance();
		effect.Create(EFFECT_ID::GRAUND_HIT_BULLET, m_Position);

		CGameSoundManager::GetInstance().Play(SOUND_ID::IMPACT);

		DeleteObject();
	}

}

//�\���͈͂̔���
void IBullet::CheckRange(void)
{
	CEffectManager& effect = CEffectManager::GetInstance();
	CGameSoundManager& sound = CGameSoundManager::GetInstance();


	//�͈͂���o�������
	if (m_min_range.x > m_Position.x || m_max_range.x < m_Position.x)
	{
		effect.Create(EFFECT_ID::NOT_HIT, m_Position);
		sound.Play(SOUND_ID::IMPACT);
		DeleteObject();
	}

	if (m_min_range.y > m_Position.y || m_max_range.y < m_Position.y)
	{
		effect.Create(EFFECT_ID::NOT_HIT, m_Position);
		sound.Play(SOUND_ID::IMPACT);
		DeleteObject();
	}

	if (m_min_range.z > m_Position.z || m_max_range.z < m_Position.z)
	{
		effect.Create(EFFECT_ID::NOT_HIT, m_Position);
		sound.Play(SOUND_ID::IMPACT);
		DeleteObject();
	}

}
