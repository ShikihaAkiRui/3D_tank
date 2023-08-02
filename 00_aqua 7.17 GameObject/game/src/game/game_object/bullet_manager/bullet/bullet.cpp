#include"bullet.h"
#include"../../stage/stage.h"

const aqua::CVector3 IBullet::m_default_direction = aqua::CVector3(0.0f,0.0f,1.0f);
const aqua::CVector3 IBullet::m_min_range = aqua::CVector3(-2000.0f,-500.0f,-2000.0f);
const aqua::CVector3 IBullet::m_max_range = aqua::CVector3(2000.0f,500.0f,2000.0f);


//コンストラクタ
IBullet::IBullet(aqua::IGameObject* parent, const std::string& object_name)
	:aqua::IGameObject(parent,object_name)
	,m_Position(aqua::CVector3::ZERO)
	,m_Velocity(m_default_direction)
	,m_Radius(0.0f)
	,m_UnitCategory(UNIT_CATEGORY::DUMMY)
{
}

//初期化
void IBullet::Initialize(const std::string& file_name)
{
	m_Model.Load(file_name);

	m_Model.position = m_Position;
}

//更新
void IBullet::Update(void)
{
	m_Position += m_Velocity;
	m_Model.position = m_Position;

	//床の当たり判定
	CheckGraund();

	//表示範囲の判定
	CheckRange();
}

//描画
void IBullet::Draw(void)
{
	m_Model.Draw();
}

//解放
void IBullet::Finalize(void)
{
	m_Model.Unload();
}

//キャラクターに当たった
void IBullet::HitCharacter(void)
{
	DeleteObject();
}

//中心位置取得
aqua::CVector3 IBullet::GetCenterPosition(void)
{
	return m_Position;
}

//半径取得
float IBullet::GetRadius(void)
{
	return m_Radius;
}

//カテゴリー取得
UNIT_CATEGORY IBullet::GetCategory(void)
{
	return m_UnitCategory;
}

//床の当たり判定
void IBullet::CheckGraund(void)
{
	CStage* stage = (CStage*)aqua::FindGameObject("Stage");

	if (stage->GetHitBulletGroundFlag(m_Position, m_Radius))
	{
		DeleteObject();
	}

}

//表示範囲の判定
void IBullet::CheckRange(void)
{
	//範囲から出たら消す
	if (m_min_range.x > m_Position.x || m_max_range.x < m_Position.x)
		DeleteObject();

	if (m_min_range.y > m_Position.y || m_max_range.y < m_Position.y)
		DeleteObject();

	if (m_min_range.z > m_Position.z || m_max_range.z < m_Position.z)
		DeleteObject();

}
