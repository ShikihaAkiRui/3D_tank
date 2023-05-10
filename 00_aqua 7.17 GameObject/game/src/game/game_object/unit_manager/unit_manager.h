#pragma once

#include"../unit/unit.h"
#include"unit_id.h"

//ユニットマネージャー
class CUnitManager : public aqua::IGameObject
{
public:
	CUnitManager(aqua::IGameObject* parent);
	~CUnitManager() = default;

	//生成
	void Create(UNIT_ID id);

	//ユニットの当たり判定
	bool HitUnitFlag(const std::string& object_name,aqua::CVector3 start_position,aqua::CVector3 end_position);

};