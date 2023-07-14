#include "enemy_appear.h"
#include"../stage/stage.h"
#include"../unit_manager/unit_manager.h"

const float CEnemyAppear::m_max_ray_height = 500.0f;
const float CEnemyAppear::m_min_ray_height = -500.0f;
//const float CEnemyAppear::m_appear_time = 10.0f;
const float CEnemyAppear::m_appear_time = 2.0f;
const float CEnemyAppear::m_appear_height = 10.0f;
const int CEnemyAppear::m_max_enemy = 5;

//�R���X�g���N�^
CEnemyAppear::CEnemyAppear(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"EnemyAppear")
	,m_CountEnemy(0)
{
}

//������
void CEnemyAppear::Initialize(void)
{
	m_AppearTimer.Setup(m_appear_time);
}

//�X�V
void CEnemyAppear::Update(void)
{
	aqua::IGameObject::Update();
	
	m_AppearTimer.Update();

	//�o�����ԂɂȂ�����o��
	if (m_AppearTimer.Finished())
	{
		m_AppearTimer.Reset();

		aqua::CVector3 appear_position = aqua::CVector3::ZERO;
		
		//���ʏ�̍��W�����߂�
		appear_position.x = (float)aqua::Rand(100, -2500);
		appear_position.z = (float)aqua::Rand(100, -1500);
		
		CStage* stage = (CStage*)aqua::FindGameObject("Stage");
		if (!stage)return;
		
		appear_position.y = stage->GetGraundHeight(aqua::CVector3(appear_position.x, m_min_ray_height, appear_position.z),
													aqua::CVector3(appear_position.x, m_max_ray_height, appear_position.z));
		appear_position.y += m_appear_height;

		//�o���͈͂Ȃ����ő吔�ɒB���Ă��Ȃ�
		if (appear_position.y >= m_min_ray_height && m_CountEnemy < m_max_enemy)
		{
			SetCountEnemy(1);

			CUnitManager* unit_manager = (CUnitManager*)aqua::FindGameObject("UnitManager");
			if (!unit_manager)return;

			unit_manager->CreateEnemy(UNIT_ID::ENEMY_NORMAL, appear_position);
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
