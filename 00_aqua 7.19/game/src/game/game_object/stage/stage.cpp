#include "stage.h"

const aqua::CVector3 CStage::m_position = aqua::CVector3(0.0f, -13.0f, 0.0f);
const aqua::CVector3 CStage::m_scale = aqua::CVector3(0.5f, 0.75f, 0.5f);
const float CStage::m_gravity = -80.0f;
const float CStage::m_not_hit_height = -100.0f;
const aqua::CVector3 CStage::m_min_wall_position = aqua::CVector3(-1000.0f,0.0f, -1000.0f);
const aqua::CVector3 CStage::m_max_wall_position = aqua::CVector3(1000.0f,0.0f, 1000.0f);
const aqua::CColor CStage::m_background_color = 0xff87cefa;

//�R���X�g���N�^
CStage::CStage(aqua::IGameObject* parent)
	:IUnit(parent, "Stage")
{
}

//������
void CStage::Initialize(void)
{
	m_BackgroundPanel.Setup(aqua::CVector2::ZERO, (float)aqua::GetWindowWidth(), (float)aqua::GetWindowHeight(), m_background_color);

	IUnit::Initialize("data/model/Terrainte.mv1");
	m_Model->position = m_position;
	m_Model->scale = m_scale;
}

//�`��
void CStage::Draw(void)
{
	m_BackgroundPanel.Draw();

	IUnit::Draw();
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

//�Ə��Ə��̔���
aqua::CVector3 CStage::CheckHitAim(const aqua::CVector3& start_position, const aqua::CVector3& end_position)
{
	//�������Ă��Ȃ���������̍Ō�̈ʒu��Ԃ�
	if (!CollCheckLine(start_position, end_position))
		return end_position;

	//�������Ă�������W���擾
	aqua::CVector3 hit_position = GetCollCheckLineHitPosition();

	return hit_position;
}

//�ǂ̔���
bool CStage::GetHitWall(const aqua::CVector3& position)
{
	bool hit_flag = false;

	if (position.x >= m_max_wall_position.x || position.x <= m_min_wall_position.x)
		hit_flag = true;
	if (position.z >= m_max_wall_position.z || position.z <= m_min_wall_position.z)
		hit_flag = true;

	return hit_flag;
}
