#include "enemy_normal.h"
#include"../../../bullet_manager/bullet_manager.h"
#include"../../unit_manager.h"
#include"../../../game_sound_manager/game_sound_manager.h"

const aqua::CVector3 CEnemyNormal::m_scale = aqua::CVector3(0.3f, 0.3f, 0.3f);
const float CEnemyNormal::m_graund_ray_langth = -15.0f;
const int CEnemyNormal::m_life = 1;
const float CEnemyNormal::m_move_speed = 50.0f;
const float CEnemyNormal::m_stop_distance = 250.0f;
const float CEnemyNormal::m_back_distance = 230.0f;
const float CEnemyNormal::m_shot_length = 700.0f;
const float CEnemyNormal::m_shot_time = 3.0f;
const float CEnemyNormal::m_wheel_rotation_speed = 1.5f;

//�R���X�g���N�^
CEnemyNormal::CEnemyNormal(aqua::IGameObject* parent)
	:IEnemy(parent,"EnemyNormal")
	,m_PlayerDistance(aqua::CVector3::ZERO)
	,m_WheelRotationSpeed(0.0f)
{
}

//������
void CEnemyNormal::Initialize(const aqua::CVector3& position)
{
	IEnemy::Initialize("data/model/enemy_tank/TankFree_Red.mv1", position, m_graund_ray_langth,m_life);

	m_Model->scale = m_scale;

	//�����ݒ�
	m_Player = CUnitManager::GetInstance().GetPlayer();
	if (!m_Player)return;

	//���������̊p�x�����߂�
	aqua::CVector3 distance = m_Player->GetModel()->position - m_Position;
	aqua::CVector2 move_direction = aqua::CVector2::ZERO;
	m_Rotation.y = aqua::RadToDeg(atan2(distance.x, distance.z));

	m_Model->rotation = m_Rotation;

	m_ShotTimer.Setup(m_shot_time);

}

//�X�V
void CEnemyNormal::Update(void)
{
	//�ړ�
	Move();

	//�^�C������]
	IEnemy::WheelRotation(m_WheelRotationSpeed);

	//�v���C���[�������n�߂鋗�����߂��Ƃ�����
	if (m_PlayerDistance.Length() < m_shot_length)
		Shot();

	IEnemy::Update();
}

//�ړ�
void CEnemyNormal::Move(void)
{
	m_Velocity = aqua::CVector3(0.0f, 0.0f, 1.0f);

	//������ς���
	m_PlayerDistance = m_Player->GetModel()->position - m_Position;
	m_Rotation.y = aqua::RadToDeg(atan2(m_PlayerDistance.x, m_PlayerDistance.z));

	aqua::CVector3 floor = m_PlayerDistance;
	floor.y = 0.0f;
	float x_angle = 0.0f;
	x_angle = acos(aqua::CVector3::Dot(floor.Normalize(), m_PlayerDistance.Normalize()));

	//�v���C���[�����Ȃ��]������ς���
	x_angle *= m_PlayerDistance.y < 0 ? 1.0f : -1.0f;

	m_Rotation.x = aqua::RadToDeg(x_angle);

	//�ړ�������ς���
	aqua::CMatrix matrix = aqua::CMatrix::Ident();
	matrix.RotY(aqua::DegToRad(m_Rotation.y));
	m_Velocity.Transform(matrix);

	IEnemy::Move();

	CheckWall();

	m_WheelRotationSpeed = 0.0f;

	//�~�܂鋗����艓���Ƃ�
	if (m_PlayerDistance.Length() > m_stop_distance)
	{
		m_Position += m_Velocity * m_move_speed * aqua::GetDeltaTime();

		m_WheelRotationSpeed += m_wheel_rotation_speed;

	}
	//������ʒu���̂Ƃ�
	if (m_PlayerDistance.Length() < m_back_distance)
	{
		m_Position -= m_Velocity * m_move_speed * aqua::GetDeltaTime();

		m_WheelRotationSpeed -= m_wheel_rotation_speed;
	}

	m_Model->rotation = m_Rotation;
	m_Model->position = m_Position;

}

//�e������
void CEnemyNormal::Shot(void)
{
	m_ShotTimer.Update();

	if (m_ShotTimer.Finished())
	{
		m_ShotTimer.Reset();

		CBulletManager& bullet_manager = CBulletManager::GetInstance();

		bullet_manager.Create(BULLET_ID::NORMAL,m_UnitCategory, m_Position, m_Rotation);

		CGameSoundManager::GetInstance().Play(SOUND_ID::SHOT);
	}

}
