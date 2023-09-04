#include "enemy_appear.h"
#include"../stage/stage.h"
#include"../unit_manager/unit_manager.h"

const float CEnemyAppear::m_max_ray_height = 500.0f;
const float CEnemyAppear::m_min_ray_height = -500.0f;
const float CEnemyAppear::m_appear_height = 10.0f;
const int CEnemyAppear::m_max_enemy = 10;
const aqua::CVector2 CEnemyAppear::m_max_appear_area = aqua::CVector2(800.0f,800.0f);
const aqua::CVector2 CEnemyAppear::m_min_appear_area = aqua::CVector2(-800.0f, -800.0f);
const float CEnemyAppear::m_first_appear_time = 2.5f;
const float CEnemyAppear::m_default_appear_time = 10.0f;
const float CEnemyAppear::m_max_appear_time = 2.0f;
const float CEnemyAppear::m_acceleration = 0.9f;
const int CEnemyAppear::m_second_change_count = 5;

//�R���X�g���N�^
CEnemyAppear::CEnemyAppear(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"EnemyAppear")
	,m_FirstAppearFlag(true)
	,m_CountEnemy(0)
	,m_TotalCountEnemy(0)
	,m_AppearTime(m_default_appear_time)
	,m_AppearState(APPEAR_STATE::FIRST)
	,m_UnitID(UNIT_ID::ENEMY_NORMAL)
{
}

//������
void CEnemyAppear::Initialize(void)
{
	m_AppearTimer.Setup(m_first_appear_time);
}

//�X�V
void CEnemyAppear::Update(void)
{
	aqua::IGameObject::Update();
	
	m_AppearTimer.Update();

	//�o�����ԂɂȂ�����o��
	if (m_AppearTimer.Finished())
	{
		//���̏o���܂ł̎��Ԃ�ύX
		//�ŏ��̈�̂Ȃ珉���l��ݒ�
		if (m_FirstAppearFlag)
		{
			m_FirstAppearFlag = false;
		}
		else
		{
			//���X�ɏo�����Ԃ����炷
			m_AppearTime *= m_acceleration;

			if (m_AppearTime < m_max_appear_time)
				m_AppearTime = m_max_appear_time;
		}

		m_AppearTimer.Reset();
		m_AppearTimer.Setup(m_AppearTime);

		aqua::CVector3 appear_position = aqua::CVector3::ZERO;
		
		//���ʏ�̍��W�����߂�
		appear_position.x = (float)aqua::Rand((int)m_max_appear_area.x,(int)m_min_appear_area.x);
		appear_position.z = (float)aqua::Rand((int)m_max_appear_area.y,(int)m_min_appear_area.y);
		
		CStage* stage = (CStage*)aqua::FindGameObject("Stage");
		if (!stage)return;
		
		//�o���\��n�ɏ������邩�T��
		appear_position.y = stage->GetGraundHeight(aqua::CVector3(appear_position.x, m_min_ray_height, appear_position.z),
													aqua::CVector3(appear_position.x, m_max_ray_height, appear_position.z));
		appear_position.y += m_appear_height;

		//�o���͈͂Ȃ����ő吔�ɒB���Ă��Ȃ��Ƃ��o��
		if (appear_position.y >= m_min_ray_height && m_CountEnemy < m_max_enemy)
		{
			//�o���G��ς���
			ChangeAppear();

			SetCountEnemy(1);
			m_TotalCountEnemy++;

			CUnitManager& unit_manager = CUnitManager::GetInstance();

			unit_manager.CreateEnemy(m_UnitID, appear_position);
		}
	}
}

//�G�l�~�[�̐���ݒ�
void CEnemyAppear::SetCountEnemy(int count)
{
	m_CountEnemy += count;

	if (m_CountEnemy >= m_max_enemy)
		m_CountEnemy = m_max_enemy;
	if (m_CountEnemy <= 0)
		m_CountEnemy = 0;
}

//�G�l�~�[�̍ő吔�擾
int CEnemyAppear::GetMaxCountEnemy(void)
{
	return m_max_enemy;
}

//�o�����@��ς���
void CEnemyAppear::ChangeAppear(void)
{
	//�o�����@�؂�ւ�
	if (m_TotalCountEnemy > m_second_change_count)
		m_AppearState = APPEAR_STATE::SECOND;

	//�o���G�̑I����@
	switch (m_AppearState)
	{
	case APPEAR_STATE::FIRST:	FirstAppear();	break;
	case APPEAR_STATE::SECOND:	SecondAppear();	break;
	default:	break;
	}

}

//�o�����@1
void CEnemyAppear::FirstAppear(void)
{
	m_UnitID = UNIT_ID::ENEMY_NORMAL;
}

//�o�����@2
void CEnemyAppear::SecondAppear(void)
{
	int select = aqua::Rand(1, 0);

	if (select < 1)
	{
		m_UnitID = UNIT_ID::ENEMY_NORMAL;
	}
	else
	{
		m_UnitID = UNIT_ID::ENEMY_PARABOLA;
	}
}
