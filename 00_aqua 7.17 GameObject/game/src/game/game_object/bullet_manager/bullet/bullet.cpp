#include "bullet.h"
#include"../../unit_manager/unit_manager.h"
#include"../../stage/stage.h"

const aqua::CVector3 CBullet::m_direction = aqua::CVector3(0.0f, 0.0f, 1.0f);
const float CBullet::m_move_speed = 100.0f;
const float CBullet::m_radius = 4.0f;
const aqua::CVector3 CBullet::m_min_range = aqua::CVector3(-2000.0f, -500.0f, -2000.0f);
const aqua::CVector3 CBullet::m_max_range = aqua::CVector3(1000.0f, 500.0f, 1000.0f);

//コンストラクタ
CBullet::CBullet(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"Bullet")
	,m_Position(aqua::CVector3::ZERO)
	,m_Velocity(m_direction)
	,m_UnitCategory(UNIT_CATEGORY::DUMMY)
{
}

//初期化
void CBullet::Initialize(UNIT_CATEGORY unit_category,const aqua::CVector3& position, const aqua::CVector3& rotation)
{
	m_Model.Load("data/ball.mv1");

	m_UnitCategory = unit_category;
	m_Position = position;

	aqua::CMatrix matrix = aqua::CMatrix::Ident();

	matrix.RotX(aqua::DegToRad(rotation.x));
	matrix.RotY(aqua::DegToRad(rotation.y));

	m_Velocity = m_Velocity.Transform(matrix) * m_move_speed * aqua::GetDeltaTime();

	m_Model.position = m_Position;
}

//更新
void CBullet::Update(void)
{
	m_Position += m_Velocity;
	m_Model.position = m_Position;
	
	//床の当たり判定
	CheckGraund();

	//範囲の判定
	CheckRange();

}
//描画
void CBullet::Draw(void)
{
	m_Model.Draw();
}

//解放
void CBullet::Finalize(void)
{
	m_Model.Unload();
}

//キャラクターに当たった
void CBullet::HitCharacter(void)
{
	DeleteObject();
}

//中心位置取得
aqua::CVector3 CBullet::GetCenterPosition(void)
{
	return m_Position;
}

//半径取得
float CBullet::GetRadius(void)
{
	return m_radius;
}

//カテゴリー取得
UNIT_CATEGORY CBullet::GetCategory(void)
{
	return m_UnitCategory;
}


//床の当たり判定
void CBullet::CheckGraund(void)
{	
	CStage* stage = (CStage*)aqua::FindGameObject("Stage");
	if (!stage) return;

	if (stage->GetHitBulletGroundFlag(m_Position, m_radius))
	{
		DeleteObject();
	}
	
}

//範囲の判定
void CBullet::CheckRange(void)
{
	//範囲から出たら消す
	if (m_min_range.x > m_Position.x || m_max_range.x < m_Position.x)
		DeleteObject();
	
	if (m_min_range.y > m_Position.y || m_max_range.y < m_Position.y)
		DeleteObject();

	if (m_min_range.z > m_Position.z || m_max_range.z < m_Position.z)
		DeleteObject();
}
