#pragma once

#include"../unit/unit.h"

//ステージ
class CStage : public IUnit
{
public:
	CStage(aqua::IGameObject* parent);
	~CStage() = default;

	//初期化
	void Initialize(void)override;

	//弾と床の判定
	bool GetHitBulletGroundFlag(const aqua::CVector3& center_position,float radius);

	//重力取得
	float GetGravity(void);

	//床の高さを取得
	float GetGraundHeight(const aqua::CVector3& min_height_position, const aqua::CVector3& max_height_position);

private:
	static const float m_gravity;			//重力
	static const float m_not_hit_height;	//当たらなかったときに返す値

};