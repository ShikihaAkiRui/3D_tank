#pragma once

#include"../../unit/unit.h"

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
	//弾で攻撃
	void Shot(void);

private:
	aqua::CVector3 m_Position;	//位置
	aqua::CVector3 m_Velocity;	//速度
	float m_Angle;				//角度
	aqua::CVector3 m_Rotation;	//回転
	aqua::CMatrix m_Matrix;		//行列

	static const float m_move_speed;	//速度
	static const float m_ray_langth;	//レイ長さ
	static const float m_rotation_speed;//回転速さ
};