#include "unit_manager.h"
#include"../unit/unit.h"
#include"character/character.h"
#include"enemy/enemy_normal/enemy_normal.h"
#include"enemy/enemy_parabola/enemy_parabola.h"

const std::string CUnitManager::m_enemy_name = "Enemy";
const std::string CUnitManager::m_player_name = "Player";

//インスタンスの取得
CUnitManager& CUnitManager::GetInstance(void)
{
	static CUnitManager instance;

	return instance;
}

//初期化
void CUnitManager::Initialzie(void)
{
	m_GameObject.Initialize();

	//あらかじめ読み込んでおく
	m_LoadModel.Load("data/model/enemy_tank/TankFree_Red.mv1");
}

//更新
void CUnitManager::Update(void)
{
	m_GameObject.Update();
}

//描画
void CUnitManager::Draw(void)
{
	m_GameObject.Draw();
}

//解放
void CUnitManager::Finalize(void)
{
	m_LoadModel.Unload();

	m_GameObject.Finalize();
}

//生成
IUnit* CUnitManager::Create(UNIT_ID id)
{
	IUnit* unit = nullptr;

	switch (id)
	{
	case UNIT_ID::PLAYER:	unit = aqua::CreateGameObject<CPlayer>(&m_GameObject); break;
	default:	break;
	}

	if (!unit)return nullptr;

	unit->Initialize();

	return unit;

}

//敵の生成
void CUnitManager::CreateEnemy(UNIT_ID id, const aqua::CVector3& position)
{
	IEnemy* enemy = nullptr;

	switch (id)
	{
	case UNIT_ID::ENEMY_NORMAL:	enemy = aqua::CreateGameObject<CEnemyNormal>(&m_GameObject);	break;
	case UNIT_ID::ENEMY_PARABOLA:	enemy = aqua::CreateGameObject<CEnemyParabola>(&m_GameObject);	break;
	default:	break;
	}

	if (!enemy)return;

	enemy->Initialize(position);

}

//ユニットの当たり判定
bool CUnitManager::CheckHitUnit(const std::string& object_name, const aqua::CVector3& start_position, const aqua::CVector3& end_position)
{
	if (m_GameObject.GetChildList()->empty())
		return false;

	auto it = m_GameObject.GetChildList()->begin();

	bool hit_flag = false;

	while (it != m_GameObject.GetChildList()->end())
	{
		IUnit* unit = (IUnit*)(*it);

		//指定したオブジェクト名だったら
		if (unit->GetGameObjectName().find(object_name) != std::string::npos)
		{
			hit_flag = unit->CollCheckLine(start_position, end_position);

			//当たったたらtrue
			if (hit_flag)
				return hit_flag;
		}

		it++;
	}

	//当たってないならfalse
	return hit_flag;

}

//照準と敵の判定
aqua::CVector3 CUnitManager::CheckHitAim(const aqua::CVector3& start_position, const aqua::CVector3& end_position)
{
	bool hit_flag = false;
	aqua::CVector3 hit_position = end_position;
	float more_near = 0.0f;

	auto it = m_GameObject.GetChildList()->begin();

	while (it != m_GameObject.GetChildList()->end())
	{
		IUnit* unit = (IUnit*)(*it);

		//敵だったら判定する
		if (unit->GetGameObjectName().find(m_enemy_name) != std::string::npos)
		{
			//当たった位置を取得
			if (unit->CollCheckLine(start_position, end_position))
			{
				CPlayer* player = GetPlayer();
				if (!player)return end_position;

				//初めて当たった
				if (!hit_flag)
				{
					//当たった位置を保存
					hit_position = unit->GetCollCheckLineHitPosition();

					aqua::CVector3 vector = unit->GetCollCheckLineHitPosition() - player->GetModel()->position;
					//距離を取得
					more_near = vector.Length();

				}
				else
				{
					//キャラクターに近い位置を取得
					aqua::CVector3 vector = unit->GetCollCheckLineHitPosition() - player->GetModel()->position;
					float length = vector.Length();

					//位置が近いほうに変更
					if (more_near > length)
					{
						hit_position = unit->GetCollCheckLineHitPosition();
					}

				}

				hit_flag = true;

			}

		}

		it++;
	}

	return hit_position;

}

//プレイヤーと敵の距離取得
int CUnitManager::GetEnemyData(aqua::CVector2* vectors, int max_enemy)
{
	CPlayer* player = GetPlayer();
	if (!player)return 0;

	int appear_enemy_count = 0;

	auto it = m_GameObject.GetChildList()->begin();

	while (it != m_GameObject.GetChildList()->end())
	{
		IUnit* unit = (IUnit*)(*it);

		//指定したオブジェクト名だったら
		if (unit->GetGameObjectName().find(m_enemy_name) != std::string::npos)
		{
			//プレイヤーからのベクトル取得
			vectors[appear_enemy_count].x = unit->GetModel()->position.x - player->GetModel()->position.x;
			vectors[appear_enemy_count].y = -(unit->GetModel()->position.z - player->GetModel()->position.z);

			//出現している数を増やす
			appear_enemy_count++;

			//出現最大数を満たした場合
			if (appear_enemy_count >= max_enemy)
				break;
		}

		it++;
	}

	//エネミー数を返す
	return appear_enemy_count;

}

//全ユニットの状態変更
void CUnitManager::SetGameState(aqua::GAME_OBJECT_STATE state)
{
	if (m_GameObject.GetChildList()->empty())
		return;

	auto it = m_GameObject.GetChildList()->begin();


	while (it != m_GameObject.GetChildList()->end())
	{
		ICharacter* character = (ICharacter*)(*it);
		
		//状態変更
		character->SetGameObjectState(state);

		it++;
	}

}

//プレイヤーを取得
CPlayer* CUnitManager::GetPlayer(void)
{
	if (m_GameObject.GetChildList()->empty())
		return nullptr;

	auto it = m_GameObject.GetChildList()->begin();

	while (it != m_GameObject.GetChildList()->end())
	{
		if ((*it)->GetGameObjectName() == m_player_name)
		{
			CPlayer* player = (CPlayer*)(*it);

			return player;
		}

		++it;
	}

	return nullptr;
}

//コピーコンストラクタ
CUnitManager::CUnitManager(const CUnitManager& rhs)
{
	(void)rhs;
}

//代入演算子
CUnitManager& CUnitManager::operator=(const CUnitManager& rhs)
{
	(void)rhs;

	return *this;
}