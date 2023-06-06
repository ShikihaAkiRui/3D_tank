#include "player.h"
#include"../unit_manager.h"
#include"../../bullet_manager/bullet_manager.h"
#include"../../bullet_manager/bullet/bullet.h"
#include"../../control_camera/control_camera.h"

const float CPlayer::m_move_speed = 100.0f;
const float CPlayer::m_ray_langth = 15.0f;
const float CPlayer::m_rotation_speed = 10.0f;
const aqua::CVector3 CPlayer::m_graund_ray_langth = aqua::CVector3(0.0f,-15.0f,0.0f);

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

//ˆÚ“®
void CPlayer::Move(void)
{
	m_Velocity = aqua::CVector3::ZERO;
	m_Matrix = aqua::CMatrix::Ident();

	CControlCamera* camera = (CControlCamera*)aqua::FindGameObject("ControlCamera");
	if (!camera)return;

	float direction_angle = 0.0f;
	aqua::CVector3 direction_vector = aqua::CVector3::ZERO;

	//¶‰E•ûŒü•ÏX
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

	aqua::CMatrix direction_mat = aqua::CMatrix::Ident();
	direction_mat.RotY(aqua::DegToRad(camera->GetAngle().y));
	direction_vector.Transform(direction_mat);

	//Šp“x‚É’¼‚·
	direction_angle = aqua::RadToDeg(atan2(direction_vector.x, direction_vector.z));

	if (direction_angle < 0)
		direction_angle += 360.0f;

	//“®‚¢‚Ä‚¢‚½‚ç•ûŒü“]Š·
	if (m_Velocity.Length() > 0)
	{
		m_Angle = m_Angle + m_rotation_speed * (direction_angle - m_Angle) * aqua::GetDeltaTime();
	}

	if (m_Angle >= 360.0f)
		m_Angle -= 360.0f;
	if (m_Angle < 0)
		m_Angle += 360.0f;

	//s—ñ‚Å•ûŒü•ÏX
	m_Rotation.y = m_Angle;
	m_Matrix.RotY(aqua::DegToRad(m_Rotation.y));
	m_Velocity.Transform(m_Matrix);

	ICharacter::Move();

	m_Position += m_Velocity * m_move_speed * aqua::GetDeltaTime();

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