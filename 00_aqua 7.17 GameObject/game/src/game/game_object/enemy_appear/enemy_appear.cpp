#include "enemy_appear.h"
#include"../stage/stage.h"
#include"../unit_manager/unit_manager.h"

const float CEnemyAppear::m_max_ray_height = 500.0f;
const float CEnemyAppear::m_min_ray_height = -500.0f;
const float CEnemyAppear::m_appear_time = 10.0f;
const float CEnemyAppear::m_appear_height = 10.0f;
const int CEnemyAppear::m_max_enemy = 5;
const aqua::CVector2 CEnemyAppear::m_max_appear_area = aqua::CVector2(-2000.0f,-2000.0f);
const aqua::CVector2 CEnemyAppear::m_min_appear_area = aqua::CVector2(100.0f, 100.0f);

//コンストラクタ
CEnemyAppear::CEnemyAppear(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"EnemyAppear")
	,m_CountEnemy(0)
{
}

//初期化
void CEnemyAppear::Initialize(void)
{
	m_AppearTimer.Setup(m_appear_time);
}

//更新
void CEnemyAppear::Update(void)
{
	aqua::IGameObject::Update();
	
	m_AppearTimer.Update();

	//出す時間になったら出す
	if (m_AppearTimer.Finished())
	{
		m_AppearTimer.Reset();

		aqua::CVector3 appear_position = aqua::CVector3::ZERO;
		
		//平面上の座標を決める
		appear_position.x = (float)aqua::Rand(m_min_appear_area.x, m_max_appear_area.x);
		appear_position.z = (float)aqua::Rand(m_min_appear_area.y,m_max_appear_area.y);
		
		CStage* stage = (CStage*)aqua::FindGameObject("Stage");
		if (!stage)return;
		
		appear_position.y = stage->GetGraundHeight(aqua::CVector3(appear_position.x, m_min_ray_height, appear_position.z),
													aqua::CVector3(appear_position.x, m_max_ray_height, appear_position.z));
		appear_position.y += m_appear_height;

		//出現範囲ないかつ最大数に達していない
		if (appear_position.y >= m_min_ray_height && m_CountEnemy < m_max_enemy)
		{
			SetCountEnemy(1);

			CUnitManager& unit_manager = CUnitManager::GetInstance();

			unit_manager.CreateEnemy(UNIT_ID::ENEMY_PARABOLA, appear_position);
		}

	}
	
}

//エネミーの数を設定
void CEnemyAppear::SetCountEnemy(int count)
{
	m_CountEnemy += count;

	if (m_CountEnemy >= m_max_enemy)
		m_CountEnemy = m_max_enemy;
	if (m_CountEnemy <= 0)
		m_CountEnemy = 0;
}

//エネミーの最大数取得
int CEnemyAppear::GetMaxCountEnemy(void)
{
	return m_max_enemy;
}
