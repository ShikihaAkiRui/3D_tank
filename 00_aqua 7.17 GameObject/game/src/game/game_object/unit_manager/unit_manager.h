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
	bool CheckHitUnit(const std::string& object_name,aqua::CVector3 center_position,aqua::CVector3 end_position);

	//エネミーと弾の当たり判定
	bool EnemyCheckHitBullet(aqua::CVector3 start_position, float radius);

private:
	static const int m_frame_index;		//フレーム番号

};