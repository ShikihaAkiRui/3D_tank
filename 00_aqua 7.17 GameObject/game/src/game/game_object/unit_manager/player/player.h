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

	void Draw()override;

private:
	//�ړ�
	void Move(void)override;

	//�e�ōU��
	void Shot(void);

	//�U������������
	void HitAttack(void)override;

	float m_Angle;				//�p�x
	aqua::CMatrix m_Matrix;		//�s��

	static const float m_move_speed;	//���x
	static const float m_ray_langth;	//���C����
	static const float m_rotation_speed;//��]����
	static const aqua::CVector3 m_graund_ray_langth;	//���p�̃��C�̒���

	aqua::CVector3 line_dir;
};