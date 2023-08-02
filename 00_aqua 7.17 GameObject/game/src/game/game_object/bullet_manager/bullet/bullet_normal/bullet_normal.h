#pragma once
#include"../bullet.h"

//•’Ê‚Ì’e
class CBulletNormal : public IBullet
{
public:
	CBulletNormal(aqua::IGameObject* parent);
	~CBulletNormal() = default;

	void Initialize(UNIT_CATEGORY unit_category, const aqua::CVector3& position,const aqua::CVector3& rotation);

private:
	static const float m_move_speed;	//ˆÚ“®‘¬“x
	static const float m_radius;		//”¼Œa
};