#include "enemy_flight.h"
#include"../../../bullet_manager/bullet_manager.h"
#include"../../unit_manager.h"

const float CEnemyFlight::m_graund_ray_langth = -200.0f;
const int CEnemyFlight::m_life = 1;
const float CEnemyFlight::m_move_speed = 60.0f;
const float CEnemyFlight::m_homing_angle = 20.0f;
const float CEnemyFlight::m_shot_time = 3.0f;

//�R���X�g���N�^
CEnemyFlight::CEnemyFlight(aqua::IGameObject* parent)
	:IEnemy(parent, "EnemyNormal")
	, m_ShotFlag(false)
{
}

//������
void CEnemyFlight::Initialize(const aqua::CVector3& position)
{
	IEnemy::Initialize("data/model/boxt.mv1", position, m_graund_ray_langth, m_life);

	//�����ݒ�
	m_Player = CUnitManager::GetInstance().GetPlayer();
	if (!m_Player)return;

	//���������̊p�x�����߂�
	aqua::CVector3 distance = m_Player->GetModel()->position - m_Position;
	m_Rotation.y = aqua::RadToDeg(atan2(distance.x, distance.z));

	//m_Velocity.x = m_move_speed * cos(aqua::DegToRad(m_Rotation.y));
	//m_Velocity.y = m_move_speed * sin(aqua::DegToRad(m_Rotation.y));

	m_Model->rotation = m_Rotation;

	m_ShotTimer.Setup(m_shot_time);

}

//�X�V
void CEnemyFlight::Update(void)
{
	IEnemy::Update();

	//�ړ�
	Move();

	//�t���O��true�̂Ƃ��U��
	if (m_ShotFlag)
		Shot();

}

//�ړ�
void CEnemyFlight::Move(void)
{
	//������ς���
	aqua::CVector3 distance = m_Player->GetModel()->position - m_Position;
	
	float direction = aqua::CVector2::Cross(aqua::CVector2(distance.x, distance.z), aqua::CVector2(m_Velocity.x, m_Velocity.z));

	float angle = m_Rotation.y;
	//if (direction > 0.0f)
		angle -= m_homing_angle;
	//else
	//	m_Rotation.y += m_homing_angle;
	/*
	aqua::CVector3 floor = distance;
	floor.y = 0.0f;
	float x_angle = 0.0f;
	x_angle = acos(aqua::CVector3::Dot(floor.Normalize(), distance.Normalize()));

	//�v���C���[�����Ȃ��]������ς���
	x_angle *= distance.y < 0 ? 1.0f : -1.0f;

	m_Rotation.x = aqua::RadToDeg(x_angle);	
	*/

	m_Velocity.x += m_move_speed * cos(aqua::DegToRad(angle)) * aqua::GetDeltaTime();
	m_Velocity.z += m_move_speed * sin(aqua::DegToRad(angle)) * aqua::GetDeltaTime();

	m_Rotation.y = aqua::RadToDeg(atan2(m_Velocity.x, m_Velocity.z));
	m_Position = m_Velocity;

	m_Model->rotation = m_Rotation;
	m_Model->position = m_Position;

}

//�e������
void CEnemyFlight::Shot(void)
{
	m_ShotTimer.Update();

	if (m_ShotTimer.Finished())
	{
		m_ShotTimer.Reset();

		CBulletManager& bullet_manager = CBulletManager::GetInstance();

		bullet_manager.Create(BULLET_ID::NORMAL, m_UnitCategory, m_Position, m_Rotation);
	}

}
