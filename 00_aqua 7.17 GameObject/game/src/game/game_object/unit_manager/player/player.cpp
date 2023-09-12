#include "player.h"
#include"../unit_manager.h"
#include"../../bullet_manager/bullet_manager.h"
#include"../../bullet_manager/bullet/bullet.h"
#include"../../control_camera/control_camera.h"
#include"../../ui_manager/ui_manager.h"
#include"../../effect_manager/effect_manager.h"
#include"../../game_sound_manager/game_sound_manager.h"

const aqua::CVector3 CPlayer::m_default_position = aqua::CVector3(0.0f, 2.0f, 0.0f);
const aqua::CVector3 CPlayer::m_scale = aqua::CVector3(-0.3f, 0.3f, -0.3f);
const int CPlayer::m_life = 3;
const float CPlayer::m_move_speed = 100.0f;
const float CPlayer::m_ray_langth = 15.0f;
const float CPlayer::m_rotation_speed = 5.0f;
const float CPlayer::m_shot_rotation_speed = 40.0f;
const aqua::CVector3 CPlayer::m_graund_ray_langth = aqua::CVector3(0.0f,-15.0f,0.0f);
const float CPlayer::m_damage_interval_time = 2.0f;
const float CPlayer::m_shot_bullet_time = 1.0f;
const int CPlayer::m_tank_tower_frame = 1;
const aqua::CVector3 CPlayer::m_tank_tower_height = aqua::CVector3(0.0f, 50.0f, 8.9f);
const float CPlayer::m_wheel_angle_speed = 3.0f;

//�R���X�g���N�^
CPlayer::CPlayer(aqua::IGameObject* parent)
	:ICharacter(parent,"Player")
	,m_Angle(0.0f)
	,m_Matrix(aqua::CMatrix::Ident())
	,m_DamageFlag(false)
	,m_FirstShotFlag(true)
	,m_BodyLine(aqua::CVector3::ZERO)
	,m_MoveFlag(false)
{
}

//������
void CPlayer::Initialize(void)
{
	ICharacter::Initialize("data/model/tank/TankFree_Green.mv1");

	m_UnitCategory = UNIT_CATEGORY::PLAYER;
	m_Life = m_life;

	m_Position = m_default_position;
	m_Model->position = m_Position;
	m_Model->scale = m_scale;

	m_GraundRayLength = m_graund_ray_langth;

	m_DamageIntervalTimer.Setup(m_damage_interval_time);
}

//�X�V
void CPlayer::Update(void)
{
	//�ړ�
	Move();

	//�^�C���̉�]
	WheelRotation(m_wheel_angle_speed);

	//��C��]
	GunRotation();

	//�e�ōU��
	Shot();

	ICharacter::Update();

	//�G�ƏՓ˂���
	HitEnemyBody();

	//���G���Ԃ��J�E���g
	CountDamageInterval();
}

//�ړ�
void CPlayer::Move(void)
{	
	m_MoveFlag = false;
	m_Velocity = aqua::CVector3::ZERO;

	m_Matrix = aqua::CMatrix::Ident();
	float direction_angle = 0.0f;
	aqua::CVector3 direction_vector = aqua::CVector3::ZERO;

	//���E�ړ�
	if (aqua::keyboard::Button(aqua::keyboard::KEY_ID::A))
	{
		direction_vector.x = -1.0f;

		m_Velocity.z = 1.0f;

		m_MoveFlag = true;
	}
	if (aqua::keyboard::Button(aqua::keyboard::KEY_ID::D))
	{
		direction_vector.x = 1.0f;

		m_Velocity.z = 1.0f;

		m_MoveFlag = true;
	}
	//�O��ړ�
	if (aqua::keyboard::Button(aqua::keyboard::KEY_ID::W))
	{
		direction_vector.z = 1.0f;
	
		m_Velocity.z = 1.0f;

		m_MoveFlag = true;
	}
	if (aqua::keyboard::Button(aqua::keyboard::KEY_ID::S))
	{
		direction_vector.z = -1.0f;
	
		m_Velocity.z = 1.0f;

		m_MoveFlag = true;
	}

	//�J�����̌����ɍ��킹��
	CControlCamera* camera = (CControlCamera*)aqua::FindGameObject("ControlCamera");
	if (!camera)return;
	aqua::CMatrix camera_matrix = aqua::CMatrix::Ident();
	camera_matrix.RotY(aqua::DegToRad(camera->GetAngle().y));
	direction_vector.Transform(camera_matrix);
	direction_vector.y = 0.0f;

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

	//�����Ă����������ς���
	if (direction_vector.Length() > 0.0f)
		m_Angle = m_Angle + ((m_rotation_speed * direction_angle) * aqua::GetDeltaTime() * cross.y);


	//�s��ŕ����ύX
	m_Rotation.y = m_Angle;
	m_Matrix.RotY(aqua::DegToRad(m_Rotation.y));
	m_Velocity.Transform(m_Matrix);
	
	//�����Ă��Ȃ���ΌĂ΂Ȃ�
	if (m_MoveFlag)
	{
		ICharacter::Move();
		m_BodyLine = m_Velocity;
	}

	//�ǂ̔���
	CheckWall();

	m_Position += m_Velocity * m_move_speed * aqua::GetDeltaTime();

	m_Model->rotation = m_Rotation;
	m_Model->position = m_Position;
}

//�^�C����]
void CPlayer::WheelRotation(float rotation_speed)
{
	//�����Ă������]
	if (m_MoveFlag)
	{
		ICharacter::WheelRotation(rotation_speed);
	}
}

//��C��]
void CPlayer::GunRotation(void)
{
	//�J�����̌����擾
	CControlCamera* camera = (CControlCamera*)aqua::FindGameObject("ControlCamera");
	if (!camera)return;

	aqua::CMatrix tower_matrix = aqua::CMatrix::Ident();
	//���[���h���W�̊p�x�ɒ���
	float tower_angle = camera->GetAngle().y - m_Rotation.y;

	tower_matrix.Translate(m_tank_tower_height);
	tower_matrix.RotY(aqua::DegToRad(tower_angle));

	//��C��ݒ�
	aqua::CAnimationModel::SetFrameUserLocalMatrix(m_Model, m_tank_tower_frame, tower_matrix);
}

//�e�ōU��
void CPlayer::Shot(void)
{
	m_ShotBulletTimer.Update();

	//�e���o��
	if (aqua::mouse::Trigger(aqua::mouse::BUTTON_ID::LEFT))
	{
		//�ŏ��̍U�����A�ˌ��Ԋu�̕b���𒴂���
		if (m_FirstShotFlag || m_ShotBulletTimer.Finished())
		{
			//�ŏ��̍U����������^�C�}�[�ݒ�
			if (m_FirstShotFlag)
			{
				m_FirstShotFlag = false;
				m_ShotBulletTimer.Setup(m_shot_bullet_time);
			}
			else
			{
				m_ShotBulletTimer.Reset();
			}

			CAim* aim = CUIManager::GetInstance().GetAim();
			if (!aim)return;

			CBulletManager& bullet_manager = CBulletManager::GetInstance();

			//�e����
			bullet_manager.Create(BULLET_ID::NORMAL, m_UnitCategory, m_Position, aim->GetAimAngle());

			CGameSoundManager::GetInstance().Play(SOUND_ID::SHOT);

		}
	}

}

//�G�ƏՓ˂���
void CPlayer::HitEnemyBody(void)
{
	CUnitManager& unit_manager = CUnitManager::GetInstance();

	//���S����̒���
	aqua::CVector3 body_line = m_BodyLine * m_ray_langth;

	if (unit_manager.CheckHitUnit("Enemy", m_Position - body_line , m_Position + body_line) && !m_DamageFlag)
	{
		m_DamageFlag = true;
		m_DamageIntervalTimer.Reset();

		ICharacter::HitAttack();

		//�̗͂�����Ƃ�
		if (m_Life > 0)
		{
			CEffectManager::GetInstance().Create(EFFECT_ID::HITPLAYER, m_Position);
			CGameSoundManager::GetInstance().Play(SOUND_ID::DAMAGE);
		}

		//�̗͂̕\�������炷
		CLife* life = CUIManager::GetInstance().GetLife();
		if (!life)return;

		life->Reduce(m_default_damage);
	}
}

//�U������������
void CPlayer::HitAttack(void)
{
	if (!m_DamageFlag)
	{
		m_DamageFlag = true;
		m_DamageIntervalTimer.Reset();

		ICharacter::HitAttack();

		//�̗͂�����Ƃ�
		if (m_Life > 0)
		{
			CEffectManager::GetInstance().Create(EFFECT_ID::HITPLAYER, m_Position);
			CGameSoundManager::GetInstance().Play(SOUND_ID::DAMAGE);
		}
	
		//�̗͂̕\�������炷
		CLife* life = CUIManager::GetInstance().GetLife();
		if (!life)return;

		life->Reduce(m_default_damage);
	}
}

//�|���ꂽ
void CPlayer::Dead(void)
{
	CEffectManager::GetInstance().Create(EFFECT_ID::EXPLOSION, m_Position);
	CGameSoundManager::GetInstance().Play(SOUND_ID::EXPLOSION);

	SetGameObjectState(aqua::GAME_OBJECT_STATE::WAIT);

}

//�A�C�e���ɓ�������
void CPlayer::HitItem(void)
{
	CScore* score = CUIManager::GetInstance().GetScore();
	if (!score)return;

	score->Add(1);

	CGameSoundManager::GetInstance().Play(SOUND_ID::GET_ITEM);
}

//���G���Ԃ̃J�E���g
void CPlayer::CountDamageInterval(void)
{
	//true�̊Ԑ�����
	if (m_DamageFlag)
	{
		m_DamageIntervalTimer.Update();

		//�����I�������false�ɂ���
		if (m_DamageIntervalTimer.Finished())
			m_DamageFlag = false;
	}

}
