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

private:
	static const float m_gravity;	//�d��

};