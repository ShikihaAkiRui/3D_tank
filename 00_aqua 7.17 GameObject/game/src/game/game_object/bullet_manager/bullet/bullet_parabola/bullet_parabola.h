#pragma once

#include"../bullet.h"

//�������̒e
class CBulletParabola : public IBullet
{
public:
	CBulletParabola(aqua::IGameObject* parent);
	~CBulletParabola() = default;

	void Initialize(UNIT_CATEGORY unit_category, const aqua::CVector3& position, const aqua::CVector3& impact_position);
	void Update(void)override;

private:

	aqua::CVector3 m_ImpactPosition;	//���e�ʒu
	aqua::CVector3 m_Accelerate;		//�����x
	float m_Lenght;						//��΂�����

	static const float m_move_angle;	//�p�x
	static const float m_move_speed;	//����
	static const float m_accelerate;	//�����x

};