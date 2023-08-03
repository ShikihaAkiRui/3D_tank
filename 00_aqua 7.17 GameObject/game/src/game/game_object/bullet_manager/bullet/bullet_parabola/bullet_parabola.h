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
	//移動方向設定
	void SetVelocity(void);

	aqua::CVector3 m_ImpactPosition;	//着弾位置

	static const float m_move_angle;	//角度
	static const float m_move_speed;	//移動速度
};