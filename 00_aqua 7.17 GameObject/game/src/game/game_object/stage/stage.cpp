#include "stage.h"

const float CStage::m_gravity = -100.0f;
const float CStage::m_not_hit_height = -100.0f;

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

//�e�Ə��̓����蔻��
bool CStage::GetHitBulletGroundFlag(const aqua::CVector3& center_position, float radius)
{
	bool hit_flag = false;

	hit_flag = CollCheckSphere(center_position, radius);

	return hit_flag;
}

//�d�͎擾
float CStage::GetGravity(void)
{
	return m_gravity;
}

//���̍������擾
float CStage::GetGraundHeight(const aqua::CVector3& min_height_position, const aqua::CVector3& max_height_position)
{
	//�������ĂȂ��������̉��̒l��艺�̒l��Ԃ�
	if(!CollCheckLine(min_height_position, max_height_position))
		return min_height_position.y + m_not_hit_height;
	
	//�����������W���擾
	aqua::CVector3 hit_position = GetCollCheckLineHitPosition();

	return hit_position.y;
}
