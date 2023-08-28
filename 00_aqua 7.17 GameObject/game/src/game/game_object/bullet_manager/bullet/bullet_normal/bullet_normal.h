#pragma once
#include"../bullet.h"

//普通の弾
class CBulletNormal : public IBullet
{
public:
	CBulletNormal(aqua::IGameObject* parent);
	~CBulletNormal() = default;

	//初期化
	//ユニットのカテゴリー,	出す位置,	角度
	void Initialize(UNIT_CATEGORY unit_category, const aqua::CVector3& position,const aqua::CVector3& rotation);

private:
	static const float m_move_speed;	//移動速度
	static const float m_radius;		//半径
};