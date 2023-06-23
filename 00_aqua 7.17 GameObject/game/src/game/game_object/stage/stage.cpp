#include "stage.h"

const float CStage::m_gravity = -100.0f;

//コンストラクタ
CStage::CStage(aqua::IGameObject* parent)
	:IUnit(parent, "Stage")
{
}

//初期化
void CStage::Initialize(void)
{
	IUnit::Initialize("data/Terrain.mv1");
	m_Model->position = aqua::CVector3(0.0f, -13.0f, 0.0f);
}

//弾と床の当たり判定
bool CStage::GetHitBulletGroundFlag(const aqua::CVector3& center_position, float radius)
{
	bool hit_flag = false;

	hit_flag = CollCheckSphere(m_frame_index, center_position, radius);

	return hit_flag;
}

//重力取得
float CStage::GetGravity(void)
{
	return m_gravity;
}
