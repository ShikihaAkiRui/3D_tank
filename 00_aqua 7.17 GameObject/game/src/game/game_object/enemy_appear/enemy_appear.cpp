#include "enemy_appear.h"
#include"../stage/stage.h"
#include"../unit_manager/unit_manager.h"

const float CEnemyAppear::m_max_ray_height = 500.0f;
const float CEnemyAppear::m_min_ray_height = -500.0f;
const float CEnemyAppear::m_appear_time = 10.0f;

//コンストラクタ
CEnemyAppear::CEnemyAppear(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"EnemyAppear")
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
	m_AppearTimer.Update();

	//出す時間になったら出す
	if (m_AppearTimer.Finished())
	{
		aqua::CVector3 appear_position = aqua::CVector3::ZERO;
		
		//平面上の座標を決める
		appear_position.x = (float)aqua::Rand(100, -1500);
		appear_position.z = (float)aqua::Rand(100, -800);
		
		CStage* stage = (CStage*)aqua::FindGameObject("Stage");
		if (!stage)return;
		
		appear_position.y = stage->GetGraundHeight(aqua::CVector3(appear_position.x, m_min_ray_height, appear_position.z),
													aqua::CVector3(appear_position.x, m_max_ray_height, appear_position.z));
		appear_position.y += 10.0f;

		//出現範囲ないなら
		if (appear_position.y >= m_min_ray_height)
		{
			m_AppearTimer.Reset();

			CUnitManager* unit_manager = aqua::CreateGameObject<CUnitManager>(this);
			if (!unit_manager)return;

			unit_manager->CreateEnemy(UNIT_ID::ENEMY, appear_position);
		}

	}

	
	aqua::IGameObject::Update();
}
