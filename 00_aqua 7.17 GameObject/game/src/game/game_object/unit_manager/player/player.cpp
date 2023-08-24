#include "player.h"
#include"../unit_manager.h"
#include"../../bullet_manager/bullet_manager.h"
#include"../../bullet_manager/bullet/bullet.h"
#include"../../control_camera/control_camera.h"
#include"../../ui_manager/ui_manager.h"
#include"../../effect_manager/effect_manager.h"

const int CPlayer::m_life = 3;
const float CPlayer::m_move_speed = 100.0f;
const float CPlayer::m_ray_langth = 15.0f;
const float CPlayer::m_rotation_speed = 10.0f;
const float CPlayer::m_shot_rotation_speed = 40.0f;
const aqua::CVector3 CPlayer::m_graund_ray_langth = aqua::CVector3(0.0f,-15.0f,0.0f);
const float CPlayer::m_jump_power = 5.0f;
const float CPlayer::m_deceleration = 0.9f;
const float CPlayer::m_damage_interval_time = 3.0f;
const float CPlayer::m_shot_bullet_time = 1.0f;

//ƒRƒ“ƒXƒgƒ‰ƒNƒ^
CPlayer::CPlayer(aqua::IGameObject* parent)
	:ICharacter(parent,"Player")
	,m_Angle(0.0f)
	, m_Matrix(aqua::CMatrix::Ident())
	,m_ShotRotationFlag(false)
	,m_DamageFlag(false)
	,m_FirstShotFlag(true)
{
}

//‰Šú‰»
void CPlayer::Initialize(void)
{
	ICharacter::Initialize("data/model/cube.mv1");

	m_UnitCategory = UNIT_CATEGORY::PLAYER;
	m_Life = m_life;

	m_Position = aqua::CVector3(-1250.0f, 50.0f,-600.0f);
	m_Model->position = m_Position;
	m_Model->scale = aqua::CVector3(0.5f, 0.5f, 0.5f);

	m_GraundRayLength = m_graund_ray_langth;

	m_DamageIntervalTimer.Setup(m_damage_interval_time);
}

//XV
void CPlayer::Update(void)
{
	//ˆÚ“®
	Move();

	//’e‚ÅUŒ‚
	Shot();

	//–³“GŽžŠÔ
	if(m_DamageFlag)
	{
		m_DamageIntervalTimer.Update();
		if(m_DamageIntervalTimer.Finished())
			m_DamageFlag = false;
	}

	ICharacter::Update();

}

//ˆÚ“®
void CPlayer::Move(void)
{	
	m_Velocity.x = 0.0f;
	m_Velocity.z = 0.0f;

	m_Matrix = aqua::CMatrix::Ident();
	float direction_angle = 0.0f;
	aqua::CVector3 direction_vector = aqua::CVector3::ZERO;

	//¶‰EˆÚ“®
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
	//‘OŒãˆÚ“®
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

	//’e‚ðŒ‚‚Á‚½Žž ƒJƒƒ‰‚Ì•ûŒü‚É‚·‚é
	if (m_ShotRotationFlag)
	{
		direction_vector.z = 1.0f;
		direction_vector.x = 0.0f;

		m_Velocity.z = 0.0f;
	}

	//ƒJƒƒ‰‚ÌŒü‚«‚É‡‚í‚¹‚é
	CControlCamera* camera = (CControlCamera*)aqua::FindGameObject("ControlCamera");
	if (!camera)return;
	aqua::CMatrix camera_matrix = aqua::CMatrix::Ident();
	camera_matrix.RotY(aqua::DegToRad(camera->GetAngle().y));
	direction_vector.Transform(camera_matrix);
	direction_vector.y = 0.0f;

#define TEST
#ifdef TEST
	//Œ»ÝŒü‚¢‚Ä‚¢‚é•ûŒü‚ÌƒxƒNƒgƒ‹
	aqua::CVector3 current_dir;
	current_dir.x = sin(aqua::DegToRad(m_Rotation.y));
	current_dir.y = 0.0f;
	current_dir.z = cos(aqua::DegToRad(m_Rotation.y));

	//Œü‚­ƒxƒNƒgƒ‹‚Ü‚Å‚ÌŠp“x
	direction_angle = aqua::RadToDeg(acos(aqua::CVector3::Dot(current_dir.Normalize(), direction_vector.Normalize())));

	//‚Ç‚¿‚ç‘¤‚É‰ñ‚é‚©‚ðŒvŽZ
	aqua::CVector3 cross = aqua::CVector3::Cross(current_dir.Normalize(), direction_vector.Normalize());
	if (cross.x != 0.0f)cross = aqua::CVector3(0.0f, 1.0f, 0.0f);
#else
	direction_angle = aqua::RadToDeg(atan2(direction_vector.x, direction_vector.z));
	
#endif

	//“®‚¢‚Ä‚¢‚½‚ç•ûŒü‚ð•Ï‚¦‚é
	if (direction_vector.Length() > 0)
	{
#ifdef TEST

		//Œ‚‚Á‚½Žž‚Í‰ñ“]‚ð•Ï‚¦‚é
		if (m_ShotRotationFlag)
			m_Angle = m_Angle + ((m_shot_rotation_speed * direction_angle) * aqua::GetDeltaTime() * cross.y);
		else
			m_Angle = m_Angle + ((m_rotation_speed * direction_angle) * aqua::GetDeltaTime() * cross.y);

#else
		m_Angle = m_Angle + (m_rotation_speed * (direction_angle - m_Angle)) * aqua::GetDeltaTime();
#endif
	}

	//s—ñ‚Å•ûŒü•ÏX
	m_Rotation.y = m_Angle;
	m_Matrix.RotY(aqua::DegToRad(m_Rotation.y));
	m_Velocity.Transform(m_Matrix);
	
	ICharacter::Move();

	//’n–Ê‚É‚Â‚¢‚Ä‚¢‚é‚Æ‚«”ò‚Ô
	if (aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::SPACE) && m_GraundFlag)
	{
		m_Velocity.y += m_jump_power;
		m_GraundFlag = false;
	}

	m_Position += m_Velocity * m_move_speed * aqua::GetDeltaTime();

	//ƒWƒƒƒ“ƒv—Í‚ðŒ¸‚ç‚·
	m_Velocity *= m_deceleration;

	m_Model->rotation = m_Rotation;
	m_Model->position = m_Position;
}

//’e‚ÅUŒ‚
void CPlayer::Shot(void)
{
	m_ShotBulletTimer.Update();

	//’e‚ðo‚·
	if (aqua::mouse::Trigger(aqua::mouse::BUTTON_ID::LEFT))
	{
		//Å‰‚ÌUŒ‚‚©AŽËŒ‚ŠÔŠu‚Ì•b”‚ð’´‚¦‚½
		if (m_FirstShotFlag || m_ShotBulletTimer.Finished())
		{
			//Å‰‚ÌUŒ‚‚¾‚Á‚½‚çƒ^ƒCƒ}[Ý’è
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

			//’e¶¬
			bullet_manager.Create(BULLET_ID::NORMAL, m_UnitCategory, m_Position, aim->GetAimAngle());

			m_ShotRotationFlag = true;
		}
	}


	//•ú‚µ‚½‚ç•ûŒüˆ—‚ð‚È‚­‚·
	if (aqua::mouse::Released(aqua::mouse::BUTTON_ID::LEFT))
	{
		m_ShotRotationFlag = false;
	}
}

//“G‚ÆÕ“Ë‚µ‚½
void CPlayer::HitEnemyBody(void)
{
	CUnitManager& unit_manager = CUnitManager::GetInstance();

	if (unit_manager.CheckHitUnit("Enemy", m_Position, m_Position + m_Velocity * m_ray_langth) && !m_DamageFlag)
	{
		m_DamageFlag = true;
		m_DamageIntervalTimer.Reset();

		ICharacter::HitAttack();

		//‘Ì—Í‚ª‚ ‚é‚Æ‚«
		if (m_Life > 0)
		{
			CEffectManager::GetInstance().Create(EFFECT_ID::HITPLAYER, m_Position);
		}

		//‘Ì—Í‚Ì•\Ž¦‚ðŒ¸‚ç‚·
		CLife* life = CUIManager::GetInstance().GetLife();
		if (!life)return;

		life->Reduce(m_default_damage);
	}
}

//UŒ‚‚ª“–‚½‚Á‚½
void CPlayer::HitAttack(void)
{
	if (!m_DamageFlag)
	{
		m_DamageFlag = true;
		m_DamageIntervalTimer.Reset();

		ICharacter::HitAttack();

		//‘Ì—Í‚ª‚ ‚é‚Æ‚«
		if (m_Life > 0)
		{
			CEffectManager::GetInstance().Create(EFFECT_ID::HITPLAYER, m_Position);
		}
	
		//‘Ì—Í‚Ì•\Ž¦‚ðŒ¸‚ç‚·
		CLife* life = CUIManager::GetInstance().GetLife();
		if (!life)return;

		life->Reduce(m_default_damage);
	}
}

//“|‚³‚ê‚½
void CPlayer::Dead(void)
{
	CEffectManager::GetInstance().Create(EFFECT_ID::EXPLOSION, m_Position);
}

//ƒAƒCƒeƒ€‚É“–‚½‚Á‚½
void CPlayer::HitItem(void)
{
	CScore* score = CUIManager::GetInstance().GetScore();
	if (!score)return;

	score->Add(1);
}
