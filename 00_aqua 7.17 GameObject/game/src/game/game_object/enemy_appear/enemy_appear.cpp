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

//コンストラクタ
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

//初期化
void CEnemyAppear::Initialize(void)
{
	m_AppearTimer.Setup(m_first_appear_time);
}

//更新
void CEnemyAppear::Update(void)
{
	aqua::IGameObject::Update();
	
	m_AppearTimer.Update();

	//出す時間になったら出す
	if (m_AppearTimer.Finished())
	{
		//次の出現までの時間を変更
		//最初の一体なら初期値を設定
		if (m_FirstAppearFlag)
		{
			m_FirstAppearFlag = false;
		}
		else
		{
			//徐々に出現時間を減らす
			m_AppearTime *= m_acceleration;

			if (m_AppearTime < m_max_appear_time)
				m_AppearTime = m_max_appear_time;
		}

		m_AppearTimer.Reset();
		m_AppearTimer.Setup(m_AppearTime);

		aqua::CVector3 appear_position = aqua::CVector3::ZERO;
		
		//平面上の座標を決める
		appear_position.x = (float)aqua::Rand((int)m_max_appear_area.x,(int)m_min_appear_area.x);
		appear_position.z = (float)aqua::Rand((int)m_max_appear_area.y,(int)m_min_appear_area.y);
		
		CStage* stage = (CStage*)aqua::FindGameObject("Stage");
		if (!stage)return;
		
		//出現予定地に床があるか探す
		appear_position.y = stage->GetGraundHeight(aqua::CVector3(appear_position.x, m_min_ray_height, appear_position.z),
													aqua::CVector3(appear_position.x, m_max_ray_height, appear_position.z));
		appear_position.y += m_appear_height;

		//出現範囲ないかつ最大数に達していないとき出す
		if (appear_position.y >= m_min_ray_height && m_CountEnemy < m_max_enemy)
		{
			//出す敵を変える
			ChangeAppear();

			SetCountEnemy(1);
			m_TotalCountEnemy++;

			CUnitManager& unit_manager = CUnitManager::GetInstance();

			unit_manager.CreateEnemy(m_UnitID, appear_position);
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

//出す方法を変える
void CEnemyAppear::ChangeAppear(void)
{
	//出す方法切り替え
	if (m_TotalCountEnemy > m_second_change_count)
		m_AppearState = APPEAR_STATE::SECOND;

	//出す敵の選択方法
	switch (m_AppearState)
	{
	case APPEAR_STATE::FIRST:	FirstAppear();	break;
	case APPEAR_STATE::SECOND:	SecondAppear();	break;
	default:	break;
	}

}

//出す方法1
void CEnemyAppear::FirstAppear(void)
{
	m_UnitID = UNIT_ID::ENEMY_NORMAL;
}

//出す方法2
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
