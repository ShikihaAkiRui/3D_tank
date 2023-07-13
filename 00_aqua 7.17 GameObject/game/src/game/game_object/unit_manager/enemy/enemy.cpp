#include "enemy.h"
#include"../../bullet_manager/bullet_manager.h"
#include"../player/player.h"
#include"../../item_manager/item_manager.h"
#include"../../enemy_appear/enemy_appear.h"

const aqua::CVector3 CEnemy::m_graund_ray_langth = aqua::CVector3(0.0f, -10.0f, 0.0f);
const int CEnemy::m_life = 1;
const float CEnemy::m_move_speed = 30.0f;
const float CEnemy::m_stop_distance = 250.0f;
const float CEnemy::m_back_distance = 230.0f;
const float CEnemy::m_shot_time = 2.0f;

//�R���X�g���N�^
CEnemy::CEnemy(aqua::IGameObject* parent)
	:ICharacter(parent,"Enemy")
	,m_Player(nullptr)
	,m_ShotFlag(false)
{
}

//������
void CEnemy::Initialize(const aqua::CVector3& position)
{
	ICharacter::Initialize("data/boxt.mv1");

	m_Position = position;

	CheckGround();

	m_UnitCategory = UNIT_CATEGORY::ENMEY;
	m_Life = m_life;
	m_GraundRayLength = m_graund_ray_langth;

	//�����ݒ�
	m_Player = (CPlayer*)aqua::FindGameObject("Player");
	if (!m_Player)return;
	//���������̊p�x�����߂�
	aqua::CVector3 distance = m_Player->GetModel()->position - m_Position;
	aqua::CVector2 move_direction = aqua::CVector2::ZERO;
	m_Rotation.y = aqua::RadToDeg(atan2(distance.x, distance.z));

	m_Model->rotation = m_Rotation;
	m_Model->position = m_Position;

	m_ShotTimer.Setup(m_shot_time);

	m_Test.Setup(2.0f);

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
	aqua::CVector3 distance = m_Player->GetModel()->position - m_Position;
	m_Rotation.y = aqua::RadToDeg(atan2(distance.x, distance.z));
	
	aqua::CVector3 floor = distance;
	floor.y = 0.0f;
	float x_angle = 0.0f;
	x_angle = acos(aqua::CVector3::Dot(floor.Normalize(), distance.Normalize()));

	//�v���C���[�����Ȃ��]������ς���
	x_angle *= distance.y < 0 ? 1.0f : -1.0f;
	
	m_Rotation.x = aqua::RadToDeg(x_angle);

	//�ړ�������ς���
	aqua::CMatrix matrix = aqua::CMatrix::Ident();
	matrix.RotY(aqua::DegToRad(m_Rotation.y));
	m_Velocity.Transform(matrix);

	ICharacter::Move();

	//�~�܂鋗����艓���Ƃ�
	if (distance.Length() > m_stop_distance)
	{
		m_Position += m_Velocity * m_move_speed * aqua::GetDeltaTime();
		m_ShotFlag = false;

	}
	//������ʒu���̂Ƃ�
	else if(distance.Length() < m_back_distance)
	{
		m_Position -= m_Velocity * m_move_speed * aqua::GetDeltaTime();
		m_ShotFlag = true;
	}
	//�߂Â����A������Ȃ��Ƃ�
	else
	{
		m_ShotFlag = true;
	}

	m_Model->rotation = m_Rotation;
	m_Model->position = m_Position;
}

//�|���ꂽ
void CEnemy::Dead(void)
{
	CItemManager* item_manager = (CItemManager*)aqua::FindGameObject("ItemManager");
	if (item_manager)
	{
		//�A�C�e�����h���b�v����
		item_manager->Create(m_Position);
	}

	CEnemyAppear* appear = (CEnemyAppear*)aqua::FindGameObject("EnemyAppear");
	if (appear)
	{
		//�o�Ă���G�l�~�[�̐������炷
		appear->SetCountEnemy(-1);
	}

	ICharacter::Dead();
}

//�e������
void CEnemy::Shot(void)
{
	m_ShotTimer.Update();

	if (m_ShotTimer.Finished())
	{
		m_ShotTimer.Reset();
		
		CBulletManager* bullet_manager = (CBulletManager*)aqua::FindGameObject("BulletManager");
		if (!bullet_manager)return;

		bullet_manager->Create(m_UnitCategory, m_Position, m_Rotation);

	}
}