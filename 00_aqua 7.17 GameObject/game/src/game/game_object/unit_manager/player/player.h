#pragma once

#include"../../unit/unit.h"

//�v���C���[�N���X
class CPlayer : public IUnit
{
public:
	CPlayer(aqua::IGameObject* parent);
	CPlayer() = default;

	void Initialize(void);

	void Update(void);

	void Draw(void);
	//�ړ�
	void Move(void);

private:
	aqua::CVector3 m_Position;	//�ʒu
	aqua::CVector3 m_Velocity;	//���x
	float m_Angle;				//�p�x
	aqua::CVector3 m_Rotation;	//��]

	static const float m_move_speed;	//���x
	static const float m_ray_langth;	//���C����
	static const float m_rotation_speed;//��]����
};