#pragma once

#include"../bullet.h"

//•ú•¨ü‚Ì’e
class CBulletParabola : public IBullet
{
public:
	CBulletParabola(aqua::IGameObject* parent);
	~CBulletParabola() = default;

	void Initialize(UNIT_CATEGORY unit_category, const aqua::CVector3& position, const aqua::CVector3& impact_position);
	void Update(void)override;

private:
	//ˆÚ“®•ûŒüİ’è
	void SetVelocity(void);

	aqua::CVector3 m_ImpactPosition;	//’…’eˆÊ’u

	static const float m_move_angle;	//Šp“x
	static const float m_move_speed;	//ˆÚ“®‘¬“x
};