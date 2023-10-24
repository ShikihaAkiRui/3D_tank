#pragma once

#include"../enemy.h"
#include"../../player/player.h"

//��ԓG
class CEnemyFly : public IEnemy
{
public:
	//�R���X�g���N�^
	CEnemyFly(aqua::IGameObject* parent);
	//�f�X�g���N�^
	~CEnemyFly() = default;

	//������
	//�ʒu
	void Initialize(const aqua::CVector3& position)override;
	//�X�V
	void Update(void)override;

private:
	//�ړ�
	void Move(void)override;

	//�e�����p�x�����߂�
	void ShotAngle(void);

	//�v���y������]
	void PropellerRotation(void);

	//�@�̂̌X��
	void MoveRotation(void);

	//�e������
	void Shot(void);

	CPlayer* m_Player;						//�v���C���[
	aqua::CTimer m_ShotTimer;				//���Ԋu�̎���
	aqua::CVector3 m_BulletAngle;			//�e�����p�x
	aqua::CVector3 m_PlayerDistance;		//�v���C���[�Ƃ̋���
	aqua::CTimer m_FlyTimer;				//��яオ�鎞��
	float m_DefaultPositionY;				//���������l
	float m_MoveAngle;						//�ړ����̉�]
	bool m_HoveringFlag;					//�z�o�����O�t���O
	float m_PropellerAngle;					//�v���y���̊p�x

	static const aqua::CVector3 m_scale;			//�g�嗦
	static const float m_graund_ray_langth;			//���p�̃��C�̒���
	static const int m_life;						//�̗�
	static const float m_move_speed;				//�ړ����x
	static const float m_stop_distance;				//�~�܂鋗��
	static const float m_back_distance;				//�����鋗��
	static const float m_shot_length;				//������
	static const float m_shot_time;					//�����o�̎���
	static const float m_max_fly_height;			//�ō����x
	static const float m_fly_speed;					//�ō����x�܂ł̎���
	static const float m_max_front_angle;			//�O�����̍ő�p�x
	static const float m_max_back_angle;			//�������̍ő�p�x
	static const float m_move_angle_speed;			//��]���x

	static const float m_propeller_angle_speed;		//�v���y���̉�]���x
	static const float m_main_propeller_angle;		//���C���v���y����x���̊p�x
	static const aqua::CVector3 m_main_propeller_position;	//���C���v���y���̃��[�J�����W
	static const int m_main_propeller_frame;		//���C���v���y���̃t���[���ԍ�
	static const aqua::CVector3 m_back_propeller_position;	//���̃v���y���̃��[�J�����W
	static const int m_back_propeller_frame;		//���̃v���y���̃t���[���ԍ�
};