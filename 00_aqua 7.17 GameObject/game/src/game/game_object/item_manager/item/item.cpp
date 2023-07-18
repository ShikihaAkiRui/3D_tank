#include "item.h"
#include"../../stage/stage.h"
#include"../../unit_manager/unit_manager.h"

const aqua::CVector3 CItem::m_graund_ray = aqua::CVector3(0.0f, -4.0f, 0.0f);
const float CItem::m_radius = 4.0f;

//コンストラクタ
CItem::CItem(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"Item")
	,m_Position(aqua::CVector3::ZERO)
{
}

//初期化
void CItem::Initialize(const aqua::CVector3& position)
{
	m_Model.Load("data/ball.mv1");

	m_Position = position;

	m_Model.position = m_Position;
}

//更新
void CItem::Update(void)
{
	//重力
	Gravity();
}

//描画
void CItem::Draw(void)
{
	m_Model.Draw();
}

//解放
void CItem::Finalize(void)
{
	m_Model.Unload();
}

//キャラクターに当たった
void CItem::HitCharacter(void)
{
	DeleteObject();
}

//中心位置取得
aqua::CVector3 CItem::GetCenterPosition(void)
{
	return m_Position;
}

//半径取得
float CItem::GetRadius(void)
{
	return m_radius;
}

//重力
void CItem::Gravity(void)
{
	CStage* stage = (CStage*)aqua::FindGameObject("Stage");

	m_Position.y += stage->GetGravity() * aqua::GetDeltaTime();

	//床と当たってたら
	if (stage->CollCheckLine(m_Position, m_Position + m_graund_ray))
	{
		aqua::CVector3 hit_position;

		hit_position = stage->GetCollCheckLineHitPosition();

		m_Position.y = hit_position.y - m_graund_ray.y;
	}

	m_Model.position = m_Position;
}