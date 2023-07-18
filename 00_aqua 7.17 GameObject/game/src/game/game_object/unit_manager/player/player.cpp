#include "player.h"
#include"../unit_manager.h"
#include"../../bullet_manager/bullet_manager.h"
#include"../../bullet_manager/bullet/bullet.h"
#include"../../control_camera/control_camera.h"
#include"../../ui_component/score/score.h"
#include"../../ui_component/life/life.h"
#include"../../ui_component/aim/aim.h"

const int CPlayer::m_life = 3;
const float CPlayer::m_move_speed = 100.0f;
const float CPlayer::m_ray_langth = 15.0f;
const float CPlayer::m_rotation_speed = 10.0f;
const float CPlayer::m_shot_rotation_speed = 40.0f;
const aqua::CVector3 CPlayer::m_graund_ray_langth = aqua::CVector3(0.0f,-15.0f,0.0f);
const float CPlayer::m_jump_power = 5.0f;
const float CPlayer::m_deceleration = 0.9f;

//�R���X�g���N�^
CPlayer::CPlayer(aqua::IGameObject* parent)
	:ICharacter(parent,"Player")
	,m_Angle(0.0f)
	, m_Matrix(aqua::CMatrix::Ident())
	,m_ShotRotationFlag(false)
{
}

//������
void CPlayer::Initialize(void)
{
	ICharacter::Initialize("data/cube.mv1");

	m_UnitCategory = UNIT_CATEGORY::PLAYER;
	m_Life = m_life;

	m_Position = aqua::CVector3(-1250.0f, 50.0f,-600.0f);
	m_Model->position = m_Position;
	m_Model->scale = aqua::CVector3(0.5f, 0.5f, 0.5f);

	m_GraundRayLength = m_graund_ray_langth;

}

//�X�V
void CPlayer::Update(void)
{
	CUnitManager* unit_manager = (CUnitManager*)aqua::FindGameObject("UnitManager");

	if (unit_manager->CheckHitUnit("Enemy", m_Position, m_Position + m_Velocity *  m_ray_langth))
		m_Position = aqua::CVector3(-1250.0f, 50.0f, -600.0f);

	//�ړ�
	Move();

	//�e�ōU��
	Shot();

	ICharacter::Update();

}

//�ړ�
void CPlayer::Move(void)
{	
	m_Velocity.x = 0.0f;
	m_Velocity.z = 0.0f;

	m_Matrix = aqua::CMatrix::Ident();
	float direction_angle = 0.0f;
	aqua::CVector3 direction_vector = aqua::CVector3::ZERO;

	//���E�ړ�
	if (aqua::keyboard::Button(aqua::keyboard::KEY_ID::A))
	{
		direction_vector.x = -1.0f;

		m_Velocity.z = 1.0f;

	}
	if (aqua::keyboard::Button(aqua::keyboard::KEY_ID::D))
	{
		direction_vector.x = 1.0f;

		m_Velocity.z = 1.0f;

	}
	//�O��ړ�
	if (aqua::keyboard::Button(aqua::keyboard::KEY_ID::W))
	{
		direction_vector.z = 1.0f;
	
		m_Velocity.z = 1.0f;

	}
	if (aqua::keyboard::Button(aqua::keyboard::KEY_ID::S))
	{
		direction_vector.z = -1.0f;
	
		m_Velocity.z = 1.0f;

	}

	//�e���������� �J�����̕����ɂ���
	if (m_ShotRotationFlag)
	{
		direction_vector.z = 1.0f;
		direction_vector.x = 0.0f;

		m_Velocity.z = 0.0f;
	}

	//�J�����̌����ɍ��킹��
	CControlCamera* camera = (CControlCamera*)aqua::FindGameObject("ControlCamera");
	if (!camera)return;
	aqua::CMatrix camera_matrix = aqua::CMatrix::Ident();
	camera_matrix.RotY(aqua::DegToRad(camera->GetAngle().y));
	direction_vector.Transform(camera_matrix);
	direction_vector.y = 0.0f;

#define TEST
#ifdef TEST
	//���݌����Ă�������̃x�N�g��
	aqua::CVector3 current_dir;
	current_dir.x = sin(aqua::DegToRad(m_Rotation.y));
	current_dir.y = 0.0f;
	current_dir.z = cos(aqua::DegToRad(m_Rotation.y));

	//�����x�N�g���܂ł̊p�x
	direction_angle = aqua::RadToDeg(acos(aqua::CVector3::Dot(current_dir.Normalize(), direction_vector.Normalize())));

	//�ǂ��瑤�ɉ�邩���v�Z
	aqua::CVector3 cross = aqua::CVector3::Cross(current_dir.Normalize(), direction_vector.Normalize());
	if (cross.x != 0.0f)cross = aqua::CVector3(0.0f, 1.0f, 0.0f);
#else
	direction_angle = aqua::RadToDeg(atan2(direction_vector.x, direction_vector.z));
	
#endif

	//�����Ă����������ς���
	if (direction_vector.Length() > 0)
	{
#ifdef TEST

		//���������͉�]��ς���
		if (m_ShotRotationFlag)
			m_Angle = m_Angle + ((m_shot_rotation_speed * direction_angle) * aqua::GetDeltaTime() * cross.y);
		else
			m_Angle = m_Angle + ((m_rotation_speed * direction_angle) * aqua::GetDeltaTime() * cross.y);

#else
		m_Angle = m_Angle + (m_rotation_speed * (direction_angle - m_Angle)) * aqua::GetDeltaTime();
#endif
	}

	//�s��ŕ����ύX
	m_Rotation.y = m_Angle;
	m_Matrix.RotY(aqua::DegToRad(m_Rotation.y));
	m_Velocity.Transform(m_Matrix);
	
	ICharacter::Move();

	//�n�ʂɂ��Ă���Ƃ����
	if (aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::SPACE) && m_GraundFlag)
	{
		m_Velocity.y += m_jump_power;
		m_GraundFlag = false;
	}

	m_Position += m_Velocity * m_move_speed * aqua::GetDeltaTime();

	//�W�����v�͂����炷
	m_Velocity *= m_deceleration;

	m_Model->rotation = m_Rotation;
	m_Model->position = m_Position;
}

//�e�ōU��
void CPlayer::Shot(void)
{
	//�e���o��
	if (aqua::mouse::Trigger(aqua::mouse::BUTTON_ID::LEFT))
	{
		
		CAim* aim = (CAim*)aqua::FindGameObject("Aim");
		if (!aim)return;
	
		CBulletManager& bullet_manager = CBulletManager::GetInstance();
		
		//�e����
		bullet_manager.Create(m_UnitCategory, m_Position, aim->GetAimAngle());

		m_ShotRotationFlag = true;
	}

	//������������������Ȃ���
	if (aqua::mouse::Released(aqua::mouse::BUTTON_ID::LEFT))
	{
		m_ShotRotationFlag = false;
	}
}

//�U������������
void CPlayer::HitAttack(void)
{
	ICharacter::HitAttack();

	//�̗͂̕\�������炷
	CLife* life = (CLife*)aqua::FindGameObject("Life");
	if (!life)return;

	life->Reduce(m_default_damage);
}

//�|���ꂽ
void CPlayer::Dead(void)
{
}

//�A�C�e���ɓ�������
void CPlayer::HitItem(void)
{
	CScore* score = (CScore*)aqua::FindGameObject("Score");
	if (!score)return;

	score->Add(1);
}
