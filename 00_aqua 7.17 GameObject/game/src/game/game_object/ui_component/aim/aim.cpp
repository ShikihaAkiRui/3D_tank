#include "aim.h"
#include"../../control_camera/control_camera.h"
#include"../../unit_manager/unit_manager.h"
#include"../../unit_manager/player/player.h"

const aqua::CVector2 CAim::m_aim_position = aqua::CVector2(aqua::GetWindowWidth() / 2.0f, aqua::GetWindowHeight() / 2.0f);
const float CAim::m_ray_length = 800.0f;
const std::string CAim::m_hit_object_name = "Enemy";
const int CAim::m_frame_index = -1;

//コンストラクタ
CAim::CAim(aqua::IGameObject* parent)
	:IUIComponent(parent,"Aim")
	,m_Position(aqua::CVector2::ZERO)
	,m_DirectionAngle(aqua::CVector3::ZERO)
	,m_StartRayPosition(aqua::CVector3::ZERO)
	,m_EndRayPosition(aqua::CVector3::ZERO)
{
}

//初期化
void CAim::Initialize(void)
{
	/*
	m_Sprite.Create("data/abe.png");
	m_Sprite.position.x = m_aim_position.x - m_Sprite.GetTextureWidth() / 2.0f;
	m_Sprite.position.y = m_aim_position.y - m_Sprite.GetTextureHeight() / 2.0f;
	*/
}

//更新
void CAim::Update(void)
{
	//カメラからのレイの位置を設定
	SetAimRay();

	//弾を撃つ方向を設定
	GetBulletAngle(CheckHitRay());
}

//描画
void CAim::Draw(void)
{
	//m_Sprite.Draw();
}

//解放
void CAim::Finalize(void)
{
//	m_Sprite.Delete();
}

//狙っている方向を取得
aqua::CVector3 CAim::GetAimAngle(void)
{
	return m_DirectionAngle;
}

//カメラからのレイの位置
void CAim::SetAimRay(void)
{
	CControlCamera* camera = (CControlCamera*)aqua::FindGameObject("ControlCamera");
	if (!camera)return;

	m_StartRayPosition = camera->GetPosition();

	//向いている方向のベクトル取得
	aqua::CVector3 vector = aqua::CVector3(0.0f, 0.0f, 1.0f);
	aqua::CMatrix matrix = aqua::CMatrix::Ident();

	matrix.RotX(aqua::DegToRad(camera->GetAngle().x));
	matrix.RotY(aqua::DegToRad(camera->GetAngle().y));
	vector.Transform(matrix);

	m_EndRayPosition = camera->GetPosition() + (vector * m_ray_length);

}

//レイが当たった位置を取得
aqua::CVector3 CAim::CheckHitRay(void)
{
	CUnitManager& unit_manager = CUnitManager::GetInstance();

	return unit_manager.CheckHitAim(m_StartRayPosition, m_EndRayPosition);
}

//弾を撃つ角度
void CAim::GetBulletAngle(const aqua::CVector3& position)
{
	CPlayer* player = CUnitManager::GetInstance().GetPlayer();
	if (!player)return;

	aqua::CVector3 distance = position - player->GetModel()->position;
	m_DirectionAngle.y = aqua::RadToDeg(atan2(distance.x, distance.z));

	aqua::CVector3 floor = distance;
	floor.y = 0.0f;
	float x_angle = 0.0f;
	x_angle = acos(aqua::CVector3::Dot(floor.Normalize(), distance.Normalize()));

	x_angle *= distance.y < 0 ? 1.0f : -1.0f;
	m_DirectionAngle.x = aqua::RadToDeg(x_angle);

}
