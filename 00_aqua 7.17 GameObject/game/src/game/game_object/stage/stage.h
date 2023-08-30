#pragma once

#include"../unit/unit.h"

//�X�e�[�W
class CStage : public IUnit
{
public:
	CStage(aqua::IGameObject* parent);
	~CStage() = default;

	//������
	void Initialize(void)override;

	//�e�Ə��̔���
	//�e�̒��S�ʒu,	�e�̔��a
	bool GetHitBulletGroundFlag(const aqua::CVector3& center_position,float radius);

	//�d�͎擾
	float GetGravity(void);

	//���̍������擾
	//���̉��̈ʒu,	���̏�̈ʒu
	float GetGraundHeight(const aqua::CVector3& min_height_position, const aqua::CVector3& max_height_position);

	//�ǂ̔���
	//�ʒu
	bool GetHitWall(const aqua::CVector3& position);

private:
	static const aqua::CVector3 m_position;	//�ʒu
	static const aqua::CVector3 m_scale;	//�g�嗦
	static const float m_gravity;			//�d��
	static const float m_not_hit_height;	//������Ȃ������Ƃ��ɕԂ��l
	static const aqua::CVector3 m_min_wall_position;	//�ŏ��̕ǂ̈ʒu
	static const aqua::CVector3 m_max_wall_position;	//�ő�̕ǂ̈ʒu

};