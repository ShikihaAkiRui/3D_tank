#pragma once

#include"../enemy.h"
#include"../../player/player.h"

//���ʂ̃G�l�~�[
class CEnemyNormal : public IEnemy
{
public:
	//�R���X�g���N�^
	CEnemyNormal(aqua::IGameObject* parent);
	//�f�X�g���N�^
	~CEnemyNormal() = default;

	//������
	//�ʒu
	void Initialize(const aqua::CVector3& position)override;
	//�X�V
	void Update(void)override;

private:
	//�ړ�
	void Move(void)override;

	//�e������
	void Shot(void);

	CPlayer* m_Player;						//�v���C���[
	aqua::CTimer m_ShotTimer;				//���Ԋu�̎���
	aqua::CVector3 m_PlayerDistance;		//�v���C���[�Ƃ̋���
	float m_WheelRotationSpeed;				//�^�C���̉�]���x

	static const aqua::CVector3 m_scale;			//�g�嗦
	static const float m_graund_ray_langth;			//���p�̃��C�̒���
	static const int m_life;						//�̗�
	static const float m_move_speed;				//�ړ����x
	static const float m_stop_distance;				//�~�܂鋗��
	static const float m_back_distance;				//�����鋗��
	static const float m_shot_length;				//������
	static const float m_shot_time;					//�����o�̎���
	static const float m_wheel_rotation_speed;		//�^�C���̉�]���x

};