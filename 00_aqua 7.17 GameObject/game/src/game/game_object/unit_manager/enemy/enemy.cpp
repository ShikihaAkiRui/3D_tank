#include "enemy.h"
#include"../../bullet_manager/bullet_manager.h"
#include"../player/player.h"

const aqua::CVector3 CEnemy::m_graund_ray_langth = aqua::CVector3(0.0f, -10.0f, 0.0f);
const float CEnemy::m_move_speed = 30.0f;
const float CEnemy::m_stop_distance = 250.0f;
const float CEnemy::m_shot_time = 4.0f;

//�R���X�g���N�^
CEnemy::CEnemy(aqua::IGameObject* parent)
	:ICharacter(parent,"Enemy")
	,m_Player(nullptr)
	,m_PlayerDirectionAngle(0.0f)
	,m_ShotFlag(false)
{
}

//������
void CEnemy::Initialize(void)
{
	ICharacter::Initialize("data/boxt.mv1");

	m_UnitCategory = UNIT_CATEGORY::ENMEY;

	m_GraundRayLength = m_graund_ray_langth;
	m_Position = aqua::CVector3(-1200.0f, 100.0f, -600.0f);

	m_Player = (CPlayer*)aqua::FindGameObject("Player");
	if (!m_Player)return;

	m_Rotation.y = GetPlayerDirectionAngle();

	m_Model->rotation = m_Rotation;
	m_Model->position = m_Position;

	m_ShotTimer.Setup(m_shot_time);
}

//�X�V
void CEnemy::Update(void)
{
	ICharacter::Update();

	//�ړ�
	Move();

	//�t���O��true�̂Ƃ��U��
	if (m_ShotFlag)
		Shot();

}

//�ړ�
void CEnemy::Move(void)
{
	m_Velocity = aqua::CVector3(0.0f,0.0f,1.0f);

	//������ς���
	m_Rotation.y = GetPlayerDirectionAngle();

	aqua::CMatrix matrix = aqua::CMatrix::Ident();
	matrix.RotY(m_Rotation.y);
	m_Velocity.Transform(matrix);

	//�G�Ƃ̋������o��
	aqua::CVector3 distance = m_Player->GetModel()->position - m_Position;

	ICharacter::Move();

	//�~�܂鋗����艓���Ƃ�
	if (distance.Length() > m_stop_distance)
	{
		m_Position += m_Velocity * m_move_speed * aqua::GetDeltaTime();
		m_ShotFlag = false;
	}
	else
	{
		//m_Position -= m_Velocity * m_move_speed * aqua::GetDeltaTime();
		m_ShotFlag = true;
	}

	m_Model->rotation = m_Rotation;
	m_Model->position = m_Position;

}

//�e������
void CEnemy::Shot(void)
{
	m_ShotTimer.Update();

	if (m_ShotTimer.Finished())
	{
		CBulletManager* bullet_manager = (CBulletManager*)aqua::FindGameObject("BulletManager");
		if (!bullet_manager)return;

		bullet_manager->Create(m_UnitCategory, m_Position, m_Rotation);

		m_ShotTimer.Reset();
	}
}

//�v���C���[����������̊p�x���擾����
float CEnemy::GetPlayerDirectionAngle(void)
{
	aqua::CVector3 distance = m_Player->GetModel()->position - m_Position;
	float move_direction = aqua::RadToDeg(atan2(distance.x, distance.z));
	return move_direction;
}
