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

	//ユニットの当たり判定
	bool CheckHitUnit(const std::string& object_name,const aqua::CVector3& start_position,const aqua::CVector3& end_position);

	//弾の当たり判定
	bool CheckHitBullet(UNIT_CATEGORY unit_category,const aqua::CVector3& center_position, float radius);

	//アイテムの当たり判定
	bool CheckHitItem(const aqua::CVector3& center_position,float radius);

private:
	static const int m_frame_index;		//フレーム番号

};