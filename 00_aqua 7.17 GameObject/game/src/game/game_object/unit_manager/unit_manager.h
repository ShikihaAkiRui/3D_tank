#pragma once

#include"../unit/unit.h"
#include"unit_id.h"
#include<map>

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

private:
	static const int m_frame_index;		//フレーム番号

};