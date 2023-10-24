#include "item.h"
#include"../../stage/stage.h"
#include"../../unit_manager/unit_manager.h"

const std::string CItem::m_item_file_names[] = {
	"data/model/Diamondo.mv1",
	"data/model/Diamondo_red.mv1",
	"data/model/Hexgon.mv1"
};
const int CItem::m_max_file = 3;
const aqua::CVector3 CItem::m_graund_ray = aqua::CVector3(0.0f, -10.0f, 0.0f);
const float CItem::m_radius = 10.0f;

//�R���X�g���N�^
CItem::CItem(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"Item")
	,m_Position(aqua::CVector3::ZERO)
	,m_GraundFlag(false)
{
}

//������
void CItem::Initialize(const aqua::CVector3& position)
{
	//�\�����郂�f�������߂�
	int rand = aqua::Rand(m_max_file - 1, 0);

	m_Model.Load(m_item_file_names[rand]);

	m_Position = position;

	m_Model.position = m_Position;
}

//�X�V
void CItem::Update(void)
{
	//�d��
	if(!m_GraundFlag)
		Gravity();
}

//�`��
void CItem::Draw(void)
{
	m_Model.Draw();
}

//���
void CItem::Finalize(void)
{
	m_Model.Unload();
}

//�L�����N�^�[�ɓ�������
void CItem::HitCharacter(void)
{
	DeleteObject();
}

//���S�ʒu�擾
aqua::CVector3 CItem::GetCenterPosition(void)
{
	return m_Position;
}

//���a�擾
float CItem::GetRadius(void)
{
	return m_radius;
}

//�d��
void CItem::Gravity(void)
{
	CStage* stage = (CStage*)aqua::FindGameObject("Stage");

	m_Position.y += stage->GetGravity() * aqua::GetDeltaTime();

	//���Ɠ������Ă��痎�����~�߂�
	if (stage->CollCheckLine(m_Position, m_Position + m_graund_ray))
	{
		aqua::CVector3 hit_position;

		hit_position = stage->GetCollCheckLineHitPosition();

		m_Position.y = hit_position.y - m_graund_ray.y;

		m_GraundFlag = true;
	}

	m_Model.position = m_Position;
}