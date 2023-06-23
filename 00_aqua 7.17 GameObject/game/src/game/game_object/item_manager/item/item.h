#pragma once

#include"../../unit/unit.h"

//アイテム
class CItem : public IUnit
{
public:
	CItem(aqua::IGameObject* parent);
	~CItem() = default;

	void Initialize(void)override {};
	void Initialize(const aqua::CVector3& position);

	void Update(void)override;

	//中心位置取得
	aqua::CVector3 GetCenterPosition(void);

	//半径取得
	float GetRadius(void);

private:
	//重力
	void Gravity(void);

	aqua::CVector3 m_Position;	//位置
	
	static const aqua::CVector3 m_graund_ray;	//床の判定のレイの大きさ
	static const float m_radius;				//半径
};