#include "aim.h"
#include"../../../control_camera/control_camera.h"
#include"../../../unit_manager/unit_manager.h"
#include"../../../unit_manager/player/player.h"
#include"../../../stage/stage.h"

const aqua::CVector2 CAim::m_aim_position = aqua::CVector2(aqua::GetWindowWidth() / 2.0f, aqua::GetWindowHeight() / 2.0f);
const aqua::CColor CAim::m_aim_default_color = 0xff000000;
const aqua::CColor CAim::m_aim_target_color = 0xffff0000;
const float CAim::m_ray_length = 750.0f;
const std::string CAim::m_hit_object_name = "Enemy";
const int CAim::m_frame_index = -1;

//�R���X�g���N�^
CAim::CAim(aqua::IGameObject* parent)
	:IUIComponent(parent,"Aim")
	,m_Position(aqua::CVector2::ZERO)
	,m_DirectionAngle(aqua::CVector3::ZERO)
	,m_StartRayPosition(aqua::CVector3::ZERO)
	,m_EndRayPosition(aqua::CVector3::ZERO)
	,m_HitEnemyFlag(false)
{
}

//������
void CAim::Initialize(void)
{
	m_Sprite.Create("data/texture/aim.png");
	m_Sprite.position.x = m_aim_position.x - m_Sprite.GetTextureWidth() / 2.0f;
	m_Sprite.position.y = m_aim_position.y - m_Sprite.GetTextureHeight() / 2.0f;
	m_Sprite.color = m_aim_default_color;
	
}

//�X�V
void CAim::Update(void)
{
	//�J��������̃��C�̈ʒu��ݒ�
	SetAimRay();

	//���������ꏊ���󂯎��
	aqua::CVector3 hit_position = CheckHitRay();

	//�e����������ݒ�
	GetBulletAngle(hit_position);

	//�ː���̂Ƃ��F��ς���
	ChangeColor();
}

//�`��
void CAim::Draw(void)
{
	m_Sprite.Draw();
}

//���
void CAim::Finalize(void)
{
	m_Sprite.Delete();
}

//�_���Ă���������擾
aqua::CVector3 CAim::GetAimAngle(void)
{
	return m_DirectionAngle;
}

//�J��������̃��C�̈ʒu
void CAim::SetAimRay(void)
{
	CControlCamera* camera = (CControlCamera*)aqua::FindGameObject("ControlCamera");
	if (!camera)return;

	m_StartRayPosition = camera->GetTargetPosition();

	//�����Ă�������̃x�N�g���擾
	aqua::CVector3 vector = aqua::CVector3(0.0f, 0.0f, 1.0f);
	aqua::CMatrix matrix = aqua::CMatrix::Ident();

	matrix.RotX(aqua::DegToRad(camera->GetAngle().x));
	matrix.RotY(aqua::DegToRad(camera->GetAngle().y));
	vector.Transform(matrix);

	m_EndRayPosition = camera->GetTargetPosition() + (vector * m_ray_length);

}

//���C�����������ʒu���擾
aqua::CVector3 CAim::CheckHitRay(void)
{
	CUnitManager& unit_manager = CUnitManager::GetInstance();
	CStage* stage = (CStage*)aqua::FindGameObject("Stage");
	aqua::CVector3 hit_position;

	m_HitEnemyFlag = true;

	//�G�Ɠ��������ʒu���擾
	hit_position = unit_manager.CheckHitAim(m_StartRayPosition, m_EndRayPosition);

	//�G�Ɠ������Ă��Ȃ���΃X�e�[�W�Ɣ��肷��
	if (hit_position == m_EndRayPosition)
	{
		hit_position = stage->CheckHitAim(m_StartRayPosition, m_EndRayPosition);
		m_HitEnemyFlag = false;
	}

	return hit_position;
}

//�e�����p�x
void CAim::GetBulletAngle(const aqua::CVector3& position)
{
	CPlayer* player = CUnitManager::GetInstance().GetPlayer();
	if (!player)return;

	aqua::CVector3 distance = position - player->GetModel()->position;
	m_DirectionAngle.y = aqua::RadToDeg(atan2(distance.x, distance.z));

	aqua::CVector3 floor = distance;
	floor.y = 0.0f;
	float x_angle = 0.0f;
	x_angle = acos(aqua::CVector3::Dot(floor.Normalize(), distance.Normalize()));

	x_angle *= distance.y < 0 ? 1.0f : -1.0f;
	m_DirectionAngle.x = aqua::RadToDeg(x_angle);

}

//�ː���̂Ƃ��F��ς���
void CAim::ChangeColor(void)
{
	//�������Ă�����F��ς���
	if (m_HitEnemyFlag)
		m_Sprite.color = m_aim_target_color;
	else
		m_Sprite.color = m_aim_default_color;
}