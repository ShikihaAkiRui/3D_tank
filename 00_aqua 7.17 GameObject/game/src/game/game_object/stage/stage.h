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

	//�X�V
	void Update(void)override;

	//���̔���
	aqua::CVector3 GetHitGroundPosition(const aqua::CVector3& ray_start_position, const aqua::CVector3& ray_end_position);

	//�d�͎擾
	float GetGravity(void);

private:
	static const float m_gravity;	//�d��

};