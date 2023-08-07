#pragma once

#include"../enemy.h"
#include"../../player/player.h"

//���ʂ̃G�l�~�[
class CEnemyParabola : public IEnemy
{
public:
	CEnemyParabola(aqua::IGameObject* parent);
	~CEnemyParabola() = default;

	void Initialize(const aqua::CVector3& position)override;

	void Update(void)override;

private:
	//�ړ�
	void Move(void)override;

	//�e������
	void Shot(void);

	CPlayer* m_Player;						//�v���C���[
	aqua::CVector3 m_Distance;				//�v���C���[�Ƃ̋���
	aqua::CTimer m_ShotTimer;				//���Ԋu�̎���

	static const float  m_graund_ray_langth;		//���p�̃��C�̒���
	static const int m_life;						//�̗�
	static const float m_move_speed;				//�ړ����x
	static const float m_stop_distance;				//�~�܂鋗��
	static const float m_shot_lenght;				//������
	static const float m_shot_time;					//�����o�̎���

};