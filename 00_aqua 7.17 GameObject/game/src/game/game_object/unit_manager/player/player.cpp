#include "player.h"
#include"../unit_manager.h"
#include"../../bullet_manager/bullet_manager.h"
#include"../../bullet_manager/bullet/bullet.h"
#include"../../control_camera/control_camera.h"

const float CPlayer::m_move_speed = 100.0f;
const float CPlayer::m_ray_langth = 15.0f;
const float CPlayer::m_rotation_speed = 10.0f;
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

void CPlayer::Draw()
{
	aqua::CLinePrimitive3D line;
	line.Setup(m_Position, m_Position + line_dir * 100.0f, 0xff8888ff);
	line.Draw();

	ICharacter::Draw();
}

//移動
void CPlayer::Move(void)
{	
	m_Velocity = aqua::CVector3::ZERO;
	m_Matrix = aqua::CMatrix::Ident();

	float direction_angle = 0.0f;
	aqua::CVector3 direction_vector = aqua::CVector3::ZERO;

	//左右方向変更
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
	//上下移動
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

	//カメラの向きに合わせる
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

	//動いていたら方向を変える
	if (direction_vector.Length() > 0)
	{
#ifdef TEST
		m_Angle = m_Angle + ((m_rotation_speed * (direction_angle)) * aqua::GetDeltaTime() * cross.y);
#else
		m_Angle = m_Angle + (m_rotation_speed * (direction_angle - m_Angle)) * aqua::GetDeltaTime();
#endif
	}

	//行列で方向変更
	m_Rotation.y = m_Angle;
	m_Matrix.RotY(aqua::DegToRad(m_Rotation.y));
	m_Velocity.Transform(m_Matrix);
	
	ICharacter::Move();

	if (aqua::keyboard::Button(aqua::keyboard::KEY_ID::SPACE))
		m_Velocity.y += 3;

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

//攻撃が当たった
void CPlayer::HitAttack(void)
{
}
