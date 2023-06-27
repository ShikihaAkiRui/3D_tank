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
	bool GetHitBulletGroundFlag(const aqua::CVector3& center_position,float radius);

	//�d�͎擾
	float GetGravity(void);

	//���̍������擾
	float GetGraundHeight(const aqua::CVector3& min_height_position, const aqua::CVector3& max_height_position);

private:
	static const float m_gravity;			//�d��
	static const float m_not_hit_height;	//������Ȃ������Ƃ��ɕԂ��l

};