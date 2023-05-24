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

	//更新
	void Update(void)override;

	//床の判定
	aqua::CVector3 GetHitGroundPosition(const aqua::CVector3& ray_start_position, const aqua::CVector3& ray_end_position);

	//重力取得
	float GetGravity(void);

private:
	static const float m_gravity;	//重力

};