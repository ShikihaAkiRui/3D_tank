#pragma once

#include"../unit/unit.h"

//プレイヤークラス
class CPlayer : public IUnit
{
public:
	CPlayer(aqua::IGameObject* parent);
	CPlayer() = default;

	void Initialize(void);

	void Update(void);

	void Draw(void);
	//移動
	void Move(void);

private:
	aqua::CVector3 m_Position;	//位置
	aqua::CVector3 m_Velocity;	//速度

	static const float m_move_speed;	//速度
	static const float m_ray_langth;	//レイ長さ
};