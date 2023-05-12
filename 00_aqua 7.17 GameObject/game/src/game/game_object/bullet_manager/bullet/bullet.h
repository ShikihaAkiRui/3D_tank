#pragma once

#include"../../unit/unit.h"

//�e�N���X
class CBullet : public IUnit
{
public:
	CBullet(aqua::IGameObject* parent);
	~CBullet() = default;

	void Initialize(const aqua::CVector3& position,float direction);
	void Update(void)override;

	//���S�ʒu�擾
	aqua::CVector3 GetCenterPosition(void);
	//���a�擾
	float GetRadius(void);

private:
	aqua::CVector3 m_Position;		//�ʒu
	aqua::CVector3 m_Velocity;		//���x

	static const float m_move_speed;	//�ړ����x
	static const float m_radius;		//���a
};