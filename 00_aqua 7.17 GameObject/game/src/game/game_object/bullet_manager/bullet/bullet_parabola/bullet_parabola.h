#pragma once

#include"../bullet.h"

//放物線の弾
class CBulletParabola : public IBullet
{
public:
	CBulletParabola(aqua::IGameObject* parent);
	~CBulletParabola() = default;

	void Initialize(UNIT_CATEGORY unit_category, const aqua::CVector3& position, const aqua::CVector3& impact_position);
	void Update(void)override;

private:

	aqua::CVector3 m_ImpactPosition;	//着弾位置
	aqua::CVector3 m_Accelerate;		//加速度
	float m_Lenght;						//飛ばす距離

	static const float m_move_angle;	//角度
	static const float m_move_speed;	//初速
	static const float m_accelerate;	//加速度

};