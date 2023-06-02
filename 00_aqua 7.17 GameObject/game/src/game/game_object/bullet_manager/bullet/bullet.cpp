#include "bullet.h"
#include"../../unit_manager/unit_manager.h"
#include"../../stage/stage.h"

const aqua::CVector3 CBullet::m_direction = aqua::CVector3(0.0f, 0.0f, 1.0f);
const float CBullet::m_move_speed = 100.0f;
const float CBullet::m_radius = 4.0f;

//コンストラクタ
CBullet::CBullet(aqua::IGameObject* parent)
	:IUnit(parent,"Bullet")
	,m_Position(aqua::CVector3::ZERO)
	,m_Velocity(m_direction)
{
}

//初期化
void CBullet::Initialize(const aqua::CVector3& position, const aqua::CVector3& rotation)
{
	IUnit::Initialize("data/ball.mv1");

	m_Position = position;

	aqua::CMatrix matrix = aqua::CMatrix::Ident();

	matrix.RotX(aqua::DegToRad(rotation.x));
	matrix.RotY(aqua::DegToRad(rotation.y));

	m_Velocity = m_Velocity.Transform(matrix) * m_move_speed * aqua::GetDeltaTime();

	m_Model->position = m_Position;
}

//更新
void CBullet::Update(void)
{
	IUnit::Update();

	m_Position += m_Velocity;
	m_Model->position = m_Position;
	
	//敵の判定
	CheckEnemy();

	//床の当たり判定
	CheckGraund();
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

//敵の当たり判定
void CBullet::CheckEnemy(void)
{
	CUnitManager* unit_manager = (CUnitManager*)aqua::FindGameObject("UnitManager");
	if (!unit_manager)return;

	if (unit_manager->EnemyCheckHitBullet(m_Position, m_radius))
	{
		DeleteObject();
	}
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
