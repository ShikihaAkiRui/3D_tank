#pragma once

#include"../character/character.h"

//�v���C���[�N���X
class CPlayer : public ICharacter
{
public:
	//�R���X�g���N�^
	CPlayer(aqua::IGameObject* parent);
	//�f�X�g���N�^
	CPlayer() = default;

	//������
	void Initialize(void);
	//�X�V
	void Update(void);

private:
	//�ړ�
	void Move(void)override;

	//�^�C����]
	//��]���x
	void WheelRotation(float rotation_speed)override;

	//��C��]
	void GunRotation(void);

	//�e�ōU��
	void Shot(void);

	//�G�ƏՓ˂���
	void HitEnemyBody(void);

	//�U������������
	void HitAttack(void)override;

	//�|���ꂽ
	void Dead(void)override;

	//�A�C�e���ɓ�������
	void HitItem(void)override;

	//���G���Ԃ̃J�E���g
	void CountDamageInterval(void);

	float m_Angle;				//�p�x
	aqua::CMatrix m_Matrix;		//�s��
	bool m_DamageFlag;			//�_���[�W�̃t���O
	aqua::CTimer m_DamageIntervalTimer;//���G���Ԃ̃^�C�}�[
	aqua::CTimer m_ShotBulletTimer;	   //�ˌ��Ԋu
	bool m_FirstShotFlag;		//�ŏ��̍U�����������̃t���O
	aqua::CVector3 m_BodyLine;	//�Փ˂̔���
	bool m_MoveFlag;			//�ړ��̃t���O

	static const aqua::CVector3 m_default_position;	//�����ʒu
	static const aqua::CVector3 m_scale;		//�g�嗦
	static const int m_life;					//�̗�
	static const float m_move_speed;			//���x
	static const float m_ray_langth;			//���C����
	static const float m_rotation_speed;		//��]����
	static const float m_shot_rotation_speed;	//�e�����������̉�]����
	static const aqua::CVector3 m_graund_ray_langth;	//���p�̃��C�̒���
	static const float m_damage_interval_time;	//���G����
	static const float m_shot_bullet_time;		//�ˌ��Ԋu
	static const int m_tank_tower_frame;		//��Ԃ̎�C�̃t���[���ԍ�
	static const aqua::CVector3 m_tank_tower_height;	//��Ԃ̎�C�̃��[�J�����W
	static const float m_wheel_angle_speed;		//�^�C���̉�]���x
};