#include "enemy_parabola.h"
#include"../../../bullet_manager/bullet_manager.h"
#include"../../unit_manager.h"

const float CEnemyParabola::m_graund_ray_langth = -15.0f;
const int CEnemyParabola::m_life = 1;
const float CEnemyParabola::m_move_speed = 10.0f;
const float CEnemyParabola::m_stop_distance = 300.0f;
const float CEnemyParabola::m_shot_time = 3.0f;

//�R���X�g���N�^
CEnemyParabola::CEnemyParabola(aqua::IGameObject* parent)
	:IEnemy(parent, "EnemyNormal")
	,m_Distance(aqua::CVector3::ZERO)
{
}

//������
void CEnemyParabola::Initialize(const aqua::CVector3& position)
{
	IEnemy::Initialize("data/model/enemy_tank/TankFree_Red.mv1", position, m_graund_ray_langth, m_life);

	//�����ݒ�
	m_Player = CUnitManager::GetInstance().GetPlayer();
	if (!m_Player)return;

	//���������̊p�x�����߂�
	aqua::CVector3 distance = m_Player->GetModel()->position - m_Position;
	aqua::CVector2 move_direction = aqua::CVector2::ZERO;
	m_Rotation.y = aqua::RadToDeg(atan2(distance.x, distance.z));

	m_Model->rotation = m_Rotation;
	m_Model->scale = aqua::CVector3(0.3f, 0.3f, 0.3f);

	m_ShotTimer.Setup(m_shot_time);

}

//�X�V
void CEnemyParabola::Update(void)
{
	IEnemy::Update();

	//�ړ�
	Move();

	//�e������
	Shot();

}

//�ړ�
void CEnemyParabola::Move(void)
{
	m_Velocity = aqua::CVector3(0.0f, 0.0f, 1.0f);

	//������ς���
	m_Distance = m_Player->GetModel()->position - m_Position;
	m_Rotation.y = aqua::RadToDeg(atan2(m_Distance.x, m_Distance.z));

	aqua::CVector3 floor = m_Distance;
	floor.y = 0.0f;
	float x_angle = 0.0f;
	x_angle = acos(aqua::CVector3::Dot(floor.Normalize(), m_Distance.Normalize()));

	//�v���C���[�����Ȃ��]������ς���
	x_angle *= m_Distance.y < 0 ? 1.0f : -1.0f;

	m_Rotation.x = aqua::RadToDeg(x_angle);

	//�ړ�������ς���
	aqua::CMatrix matrix = aqua::CMatrix::Ident();
	matrix.RotY(aqua::DegToRad(m_Rotation.y));
	m_Velocity.Transform(matrix);

	IEnemy::Move();

	//�~�܂鋗����艓���Ƃ�
	if (m_Distance.Length() > m_stop_distance)
	{
		m_Position += m_Velocity * m_move_speed * aqua::GetDeltaTime();

	}
	//������ʒu���̂Ƃ�
	else
	{
		m_Position -= m_Velocity * m_move_speed * aqua::GetDeltaTime();
	}

	m_Model->rotation = m_Rotation;
	m_Model->position = m_Position;

}

//�e������
void CEnemyParabola::Shot(void)
{
	m_ShotTimer.Update();

	if (m_ShotTimer.Finished())
	{
		m_ShotTimer.Reset();

		CBulletManager& bullet_manager = CBulletManager::GetInstance();
		bullet_manager.Create(BULLET_ID::PARABOLA,m_UnitCategory, m_Position,m_Player->GetModel()->position );

	}
}
