#pragma once

#include"../unit/unit.h"
#include"unit_id.h"
//#include<map>

//ユニットマネージャー
class CUnitManager : public aqua::IGameObject
{
public:
	CUnitManager(aqua::IGameObject* parent);
	~CUnitManager() = default;

	//生成
	IUnit* Create(UNIT_ID id);

	//敵生成
	void CreateEnemy(UNIT_ID id, const aqua::CVector3& position);

	//ユニットの当たり判定
	bool CheckHitUnit(const std::string& object_name,const aqua::CVector3& start_position,const aqua::CVector3& end_position);

	//照準と敵の判定
	aqua::CVector3 CheckHitAim(const aqua::CVector3& start_position, const aqua::CVector3& end_position);

	//プレイヤーと敵の距離取得
	int GetEnemyData(aqua::CVector2* vectors,int max_enemy);

private:
	static const std::string m_enemy_name;	//当たる対象の名前

};