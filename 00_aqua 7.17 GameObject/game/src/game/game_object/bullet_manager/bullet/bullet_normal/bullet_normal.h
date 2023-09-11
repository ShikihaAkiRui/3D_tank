#pragma once
#include"../bullet.h"

//���ʂ̒e
class CBulletNormal : public IBullet
{
public:
	//�R���X�g���N�^
	CBulletNormal(aqua::IGameObject* parent);
	//�f�X�g���N�^
	~CBulletNormal() = default;

	//������
	//���j�b�g�̃J�e�S���[,	�o���ʒu,	�p�x
	void Initialize(UNIT_CATEGORY unit_category, const aqua::CVector3& position,const aqua::CVector3& rotation);

private:
	static const float m_move_speed;	//�ړ����x
	static const float m_radius;		//���a
};