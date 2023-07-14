#pragma once

#include"../enemy.h"
#include"../../player/player.h"

//���ʂ̃G�l�~�[
class CEnemyNormal : public IEnemy
{
public:
	CEnemyNormal(aqua::IGameObject* parent);
	~CEnemyNormal() = default;

	void Initialize(const aqua::CVector3& position)override;

	void Update(void)override;

private:
	//�ړ�
	void Move(void)override;

	//�e������
	void Shot(void);

	CPlayer* m_Player;						//�v���C���[
	bool m_ShotFlag;						//�U������t���O
	aqua::CTimer m_ShotTimer;				//���Ԋu�̎���

	static const float  m_graund_ray_langth;		//���p�̃��C�̒���
	static const int m_life;						//�̗�
	static const float m_move_speed;				//�ړ����x
	static const float m_stop_distance;				//�~�܂鋗��
	static const float m_back_distance;				//�����鋗��
	static const float m_shot_time;					//�����o�̎���

};