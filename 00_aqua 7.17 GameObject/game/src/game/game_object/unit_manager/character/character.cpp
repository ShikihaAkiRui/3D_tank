#include "character.h"
#include"../../stage/stage.h"
#include"../../bullet_manager/bullet_manager.h"
#include"../../bullet_manager/bullet/bullet.h"

const aqua::CVector3 ICharacter::m_default_position = aqua::CVector3::ZERO;
const aqua::CVector3 ICharacter::m_default_graund_ray_length = aqua::CVector3(0.0f,-10.0f,0.0f);
const aqua::CVector3 ICharacter::m_model_right_vector = aqua::CVector3(1.0f,0.0f,0.0f);

//コンストラクタ
ICharacter::ICharacter(aqua::IGameObject* parent, const std::string& object_name)
	:IUnit(parent,object_name)
	,m_Position(m_default_position)
	,m_GraundRayLength(m_default_graund_ray_length)
	,m_Velocity(aqua::CVector3::ZERO)
	,m_Rotation(aqua::CVector3::ZERO)
	,m_UnitCategory(UNIT_CATEGORY::DUMMY)
{
}

//初期化
void ICharacter::Initialize(const std::string& file_name)
{
	IUnit::Initialize(file_name);
}

//更新
void ICharacter::Update(void)
{
	IUnit::Update();

	//床の判定
	CheckGround();
	
	//弾の判定
	if (CheckHitBullet())
		HitAttack();
}

void ICharacter::Draw(void)
{
#if 1
	aqua::CLinePrimitive3D line;
	aqua::CVector3 dir;
	dir.x = sin(aqua::DegToRad(m_Rotation.y)) * 100.0f;
	dir.z = cos(aqua::DegToRad(m_Rotation.y)) * 100.0f;
	line.Setup(m_Position, m_Position + dir, 0xffff8888);
	line.Draw();
#endif
		IUnit::Draw();
}

//ユニットのカテゴリーを取得
UNIT_CATEGORY ICharacter::GetUnitCategory(void)
{
	return m_UnitCategory;
}

//床の判定
void ICharacter::CheckGround(void)
{
	CStage* stage = (CStage*)aqua::FindGameObject("Stage");
	if (!stage)return;

	//重力
	m_Position.y += stage->GetGravity() * aqua::GetDeltaTime();

	//床と当たってたら
	if (stage->CollCheckLine(m_frame_index,m_Position, m_Position + m_GraundRayLength))
	{
		aqua::CVector3 hit_position;

		hit_position = stage->GetCollCheckLineHitPosition();

		m_Position.y = hit_position.y - m_GraundRayLength.y;
	}

	m_Model->position.y = m_Position.y;

}

//弾の判定
bool ICharacter::CheckHitBullet(void)
{
	CBulletManager* bullet_manager = (CBulletManager*)aqua::FindGameObject("BulletManager");
	if (!bullet_manager || bullet_manager->GetChildList()->empty())
		return false;

	auto it = bullet_manager->GetChildList()->begin();

	bool hit_flag = false;

	while (it != bullet_manager->GetChildList()->end())
	{
		CBullet* bullet = (CBullet*)(*it);

		if (bullet->GetCategory() != m_UnitCategory)
		{
			hit_flag = CollCheckSphere(m_frame_index, bullet->GetCenterPosition(), bullet->GetRadius());

			//当たったらtrue
			if (hit_flag)
				return hit_flag;
		}

		++it;
	}

	//当たってないならfalse
	return hit_flag;

}

//移動
void ICharacter::Move(void)
{
	CStage* stage = (CStage*)aqua::FindGameObject("Stage");
	if (!stage)return;

	if (stage->CollCheckLine(m_frame_index, m_Position, m_Position + m_GraundRayLength))
	{
		aqua::CVector3 right = m_model_right_vector;
		aqua::CMatrix matrix = aqua::CMatrix::Ident();
		matrix.RotY(aqua::DegToRad(m_Rotation.y));
		right.Transform(matrix);

		m_Velocity = aqua::CVector3::Cross(right, stage->GetCollCheckLineNormal());
	}
}

//攻撃が当たった
void ICharacter::HitAttack(void)
{
	DeleteObject();
}
