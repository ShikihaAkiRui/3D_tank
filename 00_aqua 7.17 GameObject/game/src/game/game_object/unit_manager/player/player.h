#pragma once

#include"../character/character.h"

//�v���C���[�N���X
class CPlayer : public ICharacter
{
public:
	CPlayer(aqua::IGameObject* parent);
	CPlayer() = default;

	void Initialize(void);

	void Update(void);

	//�ړ�
	void Move(void);
	//�e�ōU��
	void Shot(void);

private:
	aqua::CVector3 m_Velocity;	//���x
	float m_Angle;				//�p�x
	aqua::CVector3 m_Rotation;	//��]
	aqua::CMatrix m_Matrix;		//�s��

	static const float m_move_speed;	//���x
	static const float m_ray_langth;	//���C����
	static const float m_rotation_speed;//��]����
	static const aqua::CVector3 m_graund_ray_langth;	//���p�̃��C�̒���
};