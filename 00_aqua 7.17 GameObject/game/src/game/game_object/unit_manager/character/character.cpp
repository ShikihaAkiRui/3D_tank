#include "character.h"
#include"../../stage/stage.h"

const aqua::CVector3 ICharacter::m_default_position = aqua::CVector3::ZERO;
const aqua::CVector3 ICharacter::m_default_graund_ray_length = aqua::CVector3(0.0f,-10.0f,0.0f);
const aqua::CVector3 ICharacter::m_model_right_vector = aqua::CVector3(1.0f,0.0f,0.0f);

//�R���X�g���N�^
ICharacter::ICharacter(aqua::IGameObject* parent, const std::string& object_name)
	:IUnit(parent,object_name)
	,m_Position(m_default_position)
	,m_GraundRayLength(m_default_graund_ray_length)
	,m_Velocity(aqua::CVector3::ZERO)
	,m_Rotation(aqua::CVector3::ZERO)
{
}

//������
void ICharacter::Initialize(const std::string& file_name)
{
	IUnit::Initialize(file_name);
}

//�X�V
void ICharacter::Update(void)
{
	IUnit::Update();

	//���̔���
	CheckGround();
}

//���̔���
void ICharacter::CheckGround(void)
{
	CStage* stage = (CStage*)aqua::FindGameObject("Stage");
	if (!stage)return;

	//�d��
	m_Position.y += stage->GetGravity() * aqua::GetDeltaTime();

	//���Ɠ������Ă���
	if (stage->CollCheckLine(m_frame_index,m_Position, m_Position + m_GraundRayLength))
	{
		aqua::CVector3 hit_position;

		hit_position = stage->GetCollCheckLineHitPosition(m_frame_index, m_Position, m_Position + m_GraundRayLength);
		//hit_position = stage->GetCollCheckLineHitPosition();

		m_Position.y = hit_position.y - m_GraundRayLength.y;
	}

	m_Model->position.y = m_Position.y;

}

//�ړ�
void ICharacter::Move(void)
{
	CStage* stage = (CStage*)aqua::FindGameObject("Stage");
	if (!stage)return;

	if (stage->CollCheckLine(m_frame_index, m_Position, m_Position + m_GraundRayLength))
	{
		aqua::CVector3 right = m_model_right_vector;
		aqua::CMatrix matrix = aqua::CMatrix::Ident();
		matrix.RotY(aqua::DegToRad(m_Rotation.y));
		right.Transform(matrix);

		m_Velocity = aqua::CVector3::Cross(right, stage->GetCollCheckLineNormal(m_frame_index, m_Position, m_Position + m_GraundRayLength));
	}
}
