#pragma once

#include"../../unit/unit.h"

//弾クラス
class CBullet : public IUnit
{
public:
	CBullet(aqua::IGameObject* parent);
	~CBullet() = default;

	void Initialize(const aqua::CVector3& position,float direction);
	void Update(void)override;

private:
	aqua::CVector3 m_Position;		//位置
	aqua::CVector3 m_Velocity;		//速度

	static const float m_move_speed;	//移動速度
	static const float m_radius;		//半径
};