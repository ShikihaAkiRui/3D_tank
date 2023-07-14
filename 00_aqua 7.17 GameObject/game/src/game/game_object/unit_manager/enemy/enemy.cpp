#include "enemy.h"
#include"../../item_manager/item_manager.h"
#include"../../enemy_appear/enemy_appear.h"

//コンストラクタ
IEnemy::IEnemy(aqua::IGameObject* parent,const std::string& object_name)
	:ICharacter(parent,object_name)
{
}

//初期化
void IEnemy::Initialize(const std::string& file_name,const aqua::CVector3& position, float graund_ray_langeth, int life)
{
	ICharacter::Initialize(file_name);

	CheckGround();

	m_Position = position;
	m_GraundRayLength.y = graund_ray_langeth;
	m_Life = life;
	m_UnitCategory = UNIT_CATEGORY::ENMEY;

	m_Model->position = m_Position;
}

void IEnemy::Update(void)
{
	ICharacter::Update();
}

//倒された
void IEnemy::Dead(void)
{
	CItemManager* item_manager = (CItemManager*)aqua::FindGameObject("ItemManager");
	if (item_manager)
	{
		//アイテムをドロップする
		item_manager->Create(m_Position);
	}

	CEnemyAppear* appear = (CEnemyAppear*)aqua::FindGameObject("EnemyAppear");
	if (appear)
	{
		//出ているエネミーの数を減らす
		appear->SetCountEnemy(-1);
	}

	ICharacter::Dead();
}
