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

	static const float m_move_speed;	//����
	static const float m_fall_speed;	//�����鑬�x
	static const float m_max_lenght_angle;	//�ő�˒��ɂȂ�p�x

};