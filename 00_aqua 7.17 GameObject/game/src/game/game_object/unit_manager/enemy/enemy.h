#pragma once

#include"../character/character.h"
#include"../player/player.h"

//�G�l�~�[
class CEnemy : public ICharacter
{
public:
	CEnemy(aqua::IGameObject* parent);
	~CEnemy() = default;

	void Initialize(void)override {};
	void Initialize(const aqua::CVector3& position);
	void Update(void)override;

private:
	//�ړ�
	void Move(void)override;

	//�|����Ă�
	void Dead(void)override;

	//�e������
	void Shot(void);

	CPlayer* m_Player;						//�v���C���[
	bool m_ShotFlag;						//�U������t���O
	aqua::CTimer m_ShotTimer;				//���Ԋu�̎���

	static const aqua::CVector3 m_graund_ray_langth;	//���p�̃��C�̒���
	static const int m_life;							//�̗�
	static const float m_move_speed;					//�ړ����x
	static const float m_stop_distance;					//�~�܂鋗��
	static const float m_back_distance;					//�����鋗��
	static const float m_shot_time;						//�����o�̎���

	aqua::CTimer m_Test;
};