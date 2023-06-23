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

private:
	static const float m_gravity;	//重力

};