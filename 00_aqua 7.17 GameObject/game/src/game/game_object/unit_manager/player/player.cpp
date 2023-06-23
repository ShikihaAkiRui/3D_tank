#include "player.h"
#include"../unit_manager.h"
#include"../../bullet_manager/bullet_manager.h"
#include"../../bullet_manager/bullet/bullet.h"
#include"../../control_camera/control_camera.h"
#include"../../scene_manager/scene/gamemain_scene/gamemain_scene.h"

const int CPlayer::m_life = 3;
const float CPlayer::m_move_speed = 100.0f;
const float CPlayer::m_ray_langth = 15.0f;
const float CPlayer::m_rotation_speed = 10.0f;
const aqua::CVector3 CPlayer::m_graund_ray_langth = aqua::CVector3(0.0f,-15.0f,0.0f);
const float CPlayer::m_jump_power = 5.0f;
const float CPlayer::m_deceleration = 0.9f;

//ƒRƒ“ƒXƒgƒ‰ƒNƒ^
CPlayer::CPlayer(aqua::IGameObject* parent)
	:ICharacter(parent,"Player")
	,m_Angle(0.0f)
	, m_Matrix(aqua::CMatrix::Ident())
{
}

//‰Šú‰»
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

//XV
void CPlayer::Update(void)
{
	CUnitManager* unit_manager = (CUnitManager*)aqua::FindGameObject("UnitManager");

	if (unit_manager->CheckHitUnit("Enemy", m_Position, m_Position + m_Velocity *  m_ray_langth))
		m_Position = aqua::CVector3(-1250.0f, 50.0f, -600.0f);

	ICharacter::Update();

	//ˆÚ“®
	Move();

	//’e‚ÅUŒ‚
	Shot();


}

void CPlayer::Draw()
{
	aqua::CLinePrimitive3D line;
	line.Setup(m_Position, m_Position + line_dir * 100.0f, 0xff8888ff);
	line.Draw();

	ICharacter::Draw();
}

//ˆÚ“®
void CPlayer::Move(void)
{	
	//m_Velocity = aqua::CVector3::ZERO;
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
	//ã‰ºˆÚ“®
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

	//ƒJƒƒ‰‚ÌŒü‚«‚É‡‚í‚¹‚é
	CControlCamera* camera = (CControlCamera*)aqua::FindGameObject("ControlCamera");
	if (!camera)return;
	aqua::CMatrix camera_matrix = aqua::CMatrix::Ident();
	camera_matrix.RotY(aqua::DegToRad(camera->GetAngle().y));
	direction_vector.Transform(camera_matrix);
	direction_vector.y = 0.0f;

#define TEST
#ifdef TEST
	aqua::CVector3 current_dir;
	current_dir.x = sin(aqua::DegToRad(m_Rotation.y));
	current_dir.y = 0.0f;
	current_dir.z = cos(aqua::DegToRad(m_Rotation.y));

	direction_angle = aqua::RadToDeg(acos(aqua::CVector3::Dot(current_dir.Normalize(), direction_vector.Normalize())));

	aqua::CVector3 cross = aqua::CVector3::Cross(current_dir.Normalize(), direction_vector.Normalize());
	if (cross.x != 0.0f)cross = aqua::CVector3(0.0f, 1.0f, 0.0f);
	line_dir = cross;
#else
	direction_angle = aqua::RadToDeg(atan2(direction_vector.x, direction_vector.z));
	

#endif

	//“®‚¢‚Ä‚¢‚½‚ç•ûŒü‚ð•Ï‚¦‚é
	if (direction_vector.Length() > 0)
	{
#ifdef TEST
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
	m_Velocity *= m_deceleration;

	m_Model->rotation = m_Rotation;
	m_Model->position = m_Position;
}

//’e‚ÅUŒ‚
void CPlayer::Shot(void)
{
	//’e‚ðo‚·
	if (aqua::mouse::Trigger(aqua::mouse::BUTTON_ID::LEFT))
	{
		CBulletManager* bullet_manager = (CBulletManager*)aqua::FindGameObject("BulletManager");
		if (!bullet_manager)return;

		CControlCamera* camera = (CControlCamera*)aqua::FindGameObject("ControlCamera");
		if (!camera)return;
		
		bullet_manager->Create(m_UnitCategory,m_Position, camera->GetAngle());

	}
}

//“|‚³‚ê‚½
void CPlayer::Dead(void)
{
}
