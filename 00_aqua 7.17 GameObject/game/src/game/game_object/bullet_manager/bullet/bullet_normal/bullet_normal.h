#pragma once
#include"../bullet.h"

//���ʂ̒e
class CBulletNormal : public IBullet
{
public:
	CBulletNormal(aqua::IGameObject* parent);
	~CBulletNormal() = default;

	void Initialize(UNIT_CATEGORY unit_category, const aqua::CVector3& position,const aqua::CVector3& rotation);

private:
	static const float m_move_speed;	//�ړ����x
	static const float m_radius;		//���a
};