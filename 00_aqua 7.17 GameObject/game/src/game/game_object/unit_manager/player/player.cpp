#include "player.h"
#include"../unit_manager.h"
#include"../../bullet_manager/bullet_manager.h"
#include"../../bullet_manager/bullet/bullet.h"
#include"../../control_camera/control_camera.h"

const float CPlayer::m_move_speed = 100.0f;
const float CPlayer::m_ray_langth = 15.0f;
const float CPlayer::m_rotation_speed = 180.0f;
const aqua::CVector3 CPlayer::m_graund_ray_langth = aqua::CVector3(0.0f,-15.0f,0.0f);

//コンストラクタ
CPlayer::CPlayer(aqua::IGameObject* parent)
	:ICharacter(parent,"Player")
	,m_Angle(0.0f)
	, m_Matrix(aqua::CMatrix::Ident())
{
}

//初期化
void CPlayer::Initialize(void)
{
	ICharacter::Initialize("data/cube.mv1");

	m_UnitCategory = UNIT_CATEGORY::PLAYER;

	m_Position = aqua::CVector3(-1250.0f, 50.0f,-600.0f);
	m_Model->position = m_Position;
	m_Model->scale = aqua::CVector3(0.5f, 0.5f, 0.5f);

	m_GraundRayLength = m_graund_ray_langth;
}

//更新
void CPlayer::Update(void)
{
	CUnitManager* unit_manager = (CUnitManager*)aqua::FindGameObject("UnitManager");

	if (unit_manager->CheckHitUnit("Enemy", m_Position, m_Position + m_Velocity *  m_ray_langth))
		m_Position = aqua::CVector3(-1250.0f, 50.0f, -600.0f);


	ICharacter::Update();

	//移動
	Move();

	//弾で攻撃
	Shot();


}

//移動
void CPlayer::Move(void)
{
	m_Velocity = aqua::CVector3::ZERO;
	m_Matrix = aqua::CMatrix::Ident();

	aqua::CVector3 direction_rotation = aqua::CVector3::ZERO;
	float difference_angle = 0.0f;

	//左右方向変更
	if (aqua::keyboard::Button(aqua::keyboard::KEY_ID::A))
	{
		m_Angle -= m_rotation_speed * aqua::GetDeltaTime();

	//	direction_rotation.x += -1.0f;

		m_Velocity.z = 1.0f;
	}
	if (aqua::keyboard::Button(aqua::keyboard::KEY_ID::D))
	{
		m_Angle += m_rotation_speed * aqua::GetDeltaTime();

	//	direction_rotation.x += 1.0f;

		m_Velocity.z = 1.0f;

	}
	//上下移動
	if (aqua::keyboard::Button(aqua::keyboard::KEY_ID::W))
	{
		m_Velocity.z = 1.0f;
	}
	if (aqua::keyboard::Button(aqua::keyboard::KEY_ID::S))
	{
		m_Velocity.z = -1.0f;
	}




	if (m_Angle >= 360.0f)
		m_Angle -= 360.0f;
	if (m_Angle < 0)
		m_Angle += 360.0f;

	//行列で方向変更
	m_Rotation.y = m_Angle;
	m_Matrix.RotY(aqua::DegToRad(m_Rotation.y));
	m_Velocity.Transform(m_Matrix);

	ICharacter::Move();

	m_Position += m_Velocity * m_move_speed * aqua::GetDeltaTime();

	m_Model->rotation = m_Rotation;
	m_Model->position = m_Position;
}

//弾で攻撃
void CPlayer::Shot(void)
{
	//弾を出す
	if (aqua::mouse::Trigger(aqua::mouse::BUTTON_ID::LEFT))
	{
		CBulletManager* bullet_manager = (CBulletManager*)aqua::FindGameObject("BulletManager");
		if (!bullet_manager)return;

		CControlCamera* camera = (CControlCamera*)aqua::FindGameObject("ControlCamera");
		if (!camera)return;

		bullet_manager->Create(m_UnitCategory,m_Position, camera->GetAngle());

	}
}