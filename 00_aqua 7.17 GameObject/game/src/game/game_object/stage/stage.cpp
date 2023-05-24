#include "stage.h"

const float CStage::m_gravity = -100.0f;

//�R���X�g���N�^
CStage::CStage(aqua::IGameObject* parent)
	:IUnit(parent, "Stage")
{
}

//������
void CStage::Initialize(void)
{
	IUnit::Initialize("data/Terrain.mv1");
	m_Model->position = aqua::CVector3(0.0f, -13.0f, 0.0f);
}

//�X�V
void CStage::Update(void)
{
	IUnit::Update();
}

//���̓����蔻��
aqua::CVector3 CStage::GetHitGroundPosition(const aqua::CVector3& ray_start_position, const aqua::CVector3& ray_end_position)
{
	aqua::CVector3 hit_position = aqua::CVector3::ZERO;

	hit_position = GetCollCheckLineHitPosition(m_frame_index, ray_start_position, ray_end_position);

	return hit_position;
}

//�d�͎擾
float CStage::GetGravity(void)
{
	return m_gravity;
}
