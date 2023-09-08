#include "character.h"
#include"../../stage/stage.h"
#include"../../bullet_manager/bullet_manager.h"
#include"../../bullet_manager/bullet/bullet.h"
#include"../../item_manager/item_manager.h"
#include"../../item_manager/item/item.h"
#include"../../game_sound_manager/game_sound_manager.h"

const aqua::CVector3 ICharacter::m_default_position = aqua::CVector3::ZERO;
const aqua::CVector3 ICharacter::m_default_graund_ray_length = aqua::CVector3(0.0f,-10.0f,0.0f);
const aqua::CVector3 ICharacter::m_model_right_vector = aqua::CVector3(1.0f,0.0f,0.0f);
const int ICharacter::m_default_damage = 1;
const aqua::CVector3 ICharacter::m_tank_wheel_position[] = 
{
	aqua::CVector3(78.1f,-33.7f,57.2f),
	aqua::CVector3(-78.1f,-33.7f,57.2f),
	aqua::CVector3(78.1f,-33.7f,-55.1f),
	aqua::CVector3(-78.1f,-33.7f,-55.1f)
};
const int ICharacter::m_wheel_first_frame = 3;
const int ICharacter::m_max_wheel = 4;


//コンストラクタ
ICharacter::ICharacter(aqua::IGameObject* parent, const std::string& object_name)
	:IUnit(parent,object_name)
	,m_Position(m_default_position)
	,m_GraundRayLength(m_default_graund_ray_length)
	,m_Velocity(aqua::CVector3::ZERO)
	,m_Rotation(aqua::CVector3::ZERO)
	,m_UnitCategory(UNIT_CATEGORY::DUMMY)
	,m_Life(0)
	,m_GraundFlag(false)
	,m_WheelAngle(0.0f)
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
	//床の判定
	CheckGround();
	
	//弾の判定
	if (CheckHitBullet())
		HitAttack();

	//アイテムの判定
	if (CheckHitItem())
		HitItem();

	IUnit::Update();
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
	if (stage->CollCheckLine(m_Position, m_Position + m_GraundRayLength))
	{
		aqua::CVector3 hit_position;

		hit_position = stage->GetCollCheckLineHitPosition();

		//床の高さに合わせる
		m_Position.y = hit_position.y - m_GraundRayLength.y;

		m_GraundFlag = true;
	}

	m_Model->position.y = m_Position.y;

}

//壁の判定
void ICharacter::CheckWall(void)
{
	CStage* stage = (CStage*)aqua::FindGameObject("Stage");
	if (!stage)return;

	aqua::CVector3 moved_position = m_Position + m_Velocity;

	if (stage->GetHitWall(moved_position))
		m_Velocity = aqua::CVector3::ZERO;
}

//弾の判定
bool ICharacter::CheckHitBullet(void)
{
	CBulletManager& bullet_manager = CBulletManager::GetInstance();

	return bullet_manager.CheckHitCharacter(this, m_UnitCategory);
}

//アイテムの判定
bool ICharacter::CheckHitItem(void)
{
	CItemManager& item_manager = CItemManager::GetInstance();

	return item_manager.CheckHitCharacter(this,m_UnitCategory);
}

//移動
void ICharacter::Move(void)
{
	CStage* stage = (CStage*)aqua::FindGameObject("Stage");
	if (!stage)return;

	if (stage->CollCheckLine(m_Position, m_Position + m_GraundRayLength))
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
	m_Life -= m_default_damage;

	//体力が0以下になった
	if (m_Life <= 0)
	{
		Dead();
	}
}

//倒された
void ICharacter::Dead(void)
{
	CGameSoundManager::GetInstance().Play(SOUND_ID::EXPLOSION);

	DeleteObject();
}

//アイテムが当たった
void ICharacter::HitItem(void)
{
}

//タイヤの回転
void ICharacter::WheelRotation(float rotation_speed)
{
	aqua::CMatrix wheel_matrix = aqua::CMatrix::Ident();

	//回転させる
	m_WheelAngle -= rotation_speed;

	int end_loop = m_wheel_first_frame + m_max_wheel;

	//タイヤを設定
	for (int i = m_wheel_first_frame; i < end_loop; ++i)
	{
		wheel_matrix.RotX(aqua::DegToRad(m_WheelAngle));
		wheel_matrix.Translate(m_tank_wheel_position[i - m_wheel_first_frame]);

		aqua::CAnimationModel::SetFrameUserLocalMatrix(m_Model, i, wheel_matrix);

		wheel_matrix = aqua::CMatrix::Ident();
	}

}
