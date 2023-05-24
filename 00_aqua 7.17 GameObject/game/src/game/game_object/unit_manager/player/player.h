#pragma once

#include"../character/character.h"

//プレイヤークラス
class CPlayer : public ICharacter
{
public:
	CPlayer(aqua::IGameObject* parent);
	CPlayer() = default;

	void Initialize(void);

	void Update(void);

	//移動
	void Move(void);
	//弾で攻撃
	void Shot(void);

private:
	aqua::CVector3 m_Velocity;	//速度
	float m_Angle;				//角度
	aqua::CVector3 m_Rotation;	//回転
	aqua::CMatrix m_Matrix;		//行列

	static const float m_move_speed;	//速度
	static const float m_ray_langth;	//レイ長さ
	static const float m_rotation_speed;//回転速さ
	static const aqua::CVector3 m_graund_ray_langth;	//床用のレイの長さ
};