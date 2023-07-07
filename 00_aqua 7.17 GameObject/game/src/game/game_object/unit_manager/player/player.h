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

private:
	//�ړ�
	void Move(void)override;

	//�e�ōU��
	void Shot(void);

	//�U������������
	void HitAttack(void)override;

	//�|���ꂽ
	void Dead(void)override;

	//�A�C�e���ɓ�������
	void HitItem(void)override;

	float m_Angle;				//�p�x
	aqua::CMatrix m_Matrix;		//�s��
	bool m_ShotRotationFlag;	//�e���������ւ̕����]���t���O

	static const int m_life;					//�̗�
	static const float m_move_speed;			//���x
	static const float m_ray_langth;			//���C����
	static const float m_rotation_speed;		//��]����
	static const float m_shot_rotation_speed;	//�e�����������̉�]����
	static const aqua::CVector3 m_graund_ray_langth;	//���p�̃��C�̒���
	static const float m_jump_power;			//��ԂƂ��̗�
	static const float m_deceleration;			//������

	aqua::CVector3 line_dir;
};