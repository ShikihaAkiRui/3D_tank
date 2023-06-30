#include "aim.h"
#include"../../control_camera/control_camera.h"
#include"../../unit_manager/player/player.h"

const float CAim::m_ray_length = 1000.0f;

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
}

//更新
void CAim::Update(void)
{
	SetAimRay();

	GetNormalBulletAngle();
}

//描画
void CAim::Draw(void)
{
	CPlayer* player = (CPlayer*)aqua::FindGameObject("Player");
	if (!player)return;

	aqua::CLinePrimitive3D line;
	line.Setup(player->GetModel()->position + aqua::CVector3(0.0f,30.0f,0.0f), m_EndRayPosition , 0xffff8888);
	line.Draw();
}

//解放
void CAim::Finalize(void)
{
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

	matrix.RotY(aqua::DegToRad(camera->GetAngle().y));
	matrix.RotX(aqua::DegToRad(camera->GetAngle().x));
	vector.Transform(matrix);

	m_EndRayPosition = camera->GetPosition() + (vector * m_ray_length);

}

//通常時の弾の角度
void CAim::GetNormalBulletAngle(void)
{
	CPlayer* player = (CPlayer*)aqua::FindGameObject("Player");
	if (!player)return;

	aqua::CVector3 distance = m_EndRayPosition - player->GetModel()->position;
	m_DirectionAngle.y = aqua::RadToDeg(atan2(distance.x, distance.z));

	aqua::CVector3 floor = distance;
	floor.y = 0.0f;
	float x_angle = 0.0f;
	x_angle = acos(aqua::CVector3::Dot(floor.Normalize(), distance.Normalize()));

	x_angle *= distance.y < 0 ? 1.0f : -1.0f;
	m_DirectionAngle.x = aqua::RadToDeg(x_angle);

}

//レイが当たった時の弾の角度
void CAim::GetRayHitBulletAngle(void)
{
	return ;
}
