#include "bullet_normal.h"

const float CBulletNormal::m_move_speed = 100.0f;
const float CBulletNormal::m_radius = 4.0f;

//コンストラクタ
CBulletNormal::CBulletNormal(aqua::IGameObject* parent)
	:IBullet(parent, "BulletNormal")
{
}

//初期化
void CBulletNormal::Initialize(UNIT_CATEGORY unit_category, const aqua::CVector3& position,const aqua::CVector3& rotation)
{
	m_Position = position;
	m_UnitCategory = unit_category;
	m_Radius = m_radius;

	IBullet::Initialize("data/model/ball.mv1");

	//飛ばす角度を求める
	aqua::CMatrix matrix = aqua::CMatrix::Ident();

	matrix.RotX(aqua::DegToRad(rotation.x));
	matrix.RotY(aqua::DegToRad(rotation.y));

	m_Velocity = m_Velocity.Transform(matrix) * m_move_speed * aqua::GetDeltaTime();

	m_Model.position = m_Position;
}
