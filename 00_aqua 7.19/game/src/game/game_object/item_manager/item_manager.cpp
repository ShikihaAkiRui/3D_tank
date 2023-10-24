#include "item_manager.h"
#include"item/item.h"

//インスタンスを取得
CItemManager& CItemManager::GetInstance(void)
{
	static CItemManager instance;

	return instance;
}

//初期化
void CItemManager::Initialize(void)
{
	m_GameObject.Initialize();
}

//更新
void CItemManager::Update(void)
{
	m_GameObject.Update();
}

//描画
void CItemManager::Draw(void)
{
	m_GameObject.Draw();
}

//解放
void CItemManager::Finalize(void)
{
	m_GameObject.Finalize();
}

//生成
void CItemManager::Create(aqua::CVector3& position)
{
	CItem* item = aqua::CreateGameObject<CItem>(&m_GameObject);

	if (!item)
		return;

	item->Initialize(position);
}

//アイテムとキャラクターの当たり判定
bool CItemManager::CheckHitCharacter(ICollision* collision, UNIT_CATEGORY unit_category)
{
	bool hit_flag = false;

	auto it = m_GameObject.GetChildList()->begin();

	while (it != m_GameObject.GetChildList()->end())
	{
		CItem* item = (CItem*)(*it);

		{
			hit_flag = collision->CollCheckSphere(item->GetCenterPosition(), item->GetRadius());

			//当たったらtrue
			if (hit_flag && unit_category == UNIT_CATEGORY::PLAYER)
			{
				item->HitCharacter();
				return hit_flag;
			}

		}

		it++;
	}

	//当たってないなら
	return hit_flag;

}

//コピーコンストラクタ
CItemManager::CItemManager(const CItemManager& rhs)
{
	(void)rhs;
}

//代入演算子
CItemManager& CItemManager::operator=(const CItemManager& rhs)
{
	(void)rhs;

	return *this;
}
