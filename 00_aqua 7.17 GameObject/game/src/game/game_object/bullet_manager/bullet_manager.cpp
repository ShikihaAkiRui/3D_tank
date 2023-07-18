#include "bullet_manager.h"
#include"bullet/bullet.h"

/*
//コンストラクタ
CBulletManager::CBulletManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"BulletManager")
{
}

//生成
void CBulletManager::Create(UNIT_CATEGORY unit_category,const aqua::CVector3& position, const aqua::CVector3& rotation)
{
	CBullet* bullet = aqua::CreateGameObject<CBullet>(this);

	if (!bullet)
		return;

	bullet->Initialize(unit_category,position,rotation);
}

//弾とキャラクターの当たり判定
bool CBulletManager::CheckHitCharacter(ICollision* collision,UNIT_CATEGORY unit_category)
{
	bool hit_flag = false;

	auto it = GetChildList()->begin();

	while (it != GetChildList()->end())
	{
		CBullet* bullet = (CBullet*)(*it);
		
		if (bullet->GetCategory() != unit_category)
		{
			hit_flag = collision->CollCheckSphere(bullet->GetCenterPosition(), bullet->GetRadius());

			//当たったら
			if (hit_flag)
			{
				bullet->HitCharacter();
				return hit_flag;
			}
		}

		it++;
	}

	//当たってないなら
	return hit_flag;

}*/


//インスタンスの取得
CBulletManager& CBulletManager::GetInstance(void)
{
	static CBulletManager instance;

	return instance;
}

//初期化
void CBulletManager::Initialize(void)
{
	m_GameObject.Initialize();
}

//更新
void CBulletManager::Update(void)
{
	m_GameObject.Update();
}

//描画
void CBulletManager::Draw(void)
{
	m_GameObject.Draw();
}

//解放
void CBulletManager::Finalize(void)
{
	m_GameObject.Finalize();
}

//生成
void CBulletManager::Create(UNIT_CATEGORY unit_category, const aqua::CVector3& position, const aqua::CVector3& rotation)
{
	CBullet* bullet = nullptr;

	bullet = new CBullet(&m_GameObject);

	if (!bullet)
		return;

	bullet->Initialize(unit_category, position, rotation);

	m_GameObject.GetChildList()->push_back(bullet);

}

//弾とキャラクターの当たり判定
bool CBulletManager::CheckHitCharacter(ICollision* collision, UNIT_CATEGORY unit_category)
{
	bool hit_flag = false;

	auto it = m_GameObject.GetChildList()->begin();

	while (it != m_GameObject.GetChildList()->end())
	{
		CBullet* bullet = (CBullet*)(*it);

		if (bullet->GetCategory() != unit_category)
		{
			hit_flag = collision->CollCheckSphere(bullet->GetCenterPosition(), bullet->GetRadius());

			//当たったら
			if (hit_flag)
			{
				bullet->HitCharacter();
				return hit_flag;
			}
		}

		it++;
	}

	//当たってないなら
	return hit_flag;

}

/*//コンストラクタ
CBulletManager::CBulletManager(void)
{
}*/

//コピーコンストラクタ
CBulletManager::CBulletManager(const CBulletManager& rhs)
{
	(void)rhs;
}

/*//デストラクタ
CBulletManager::~CBulletManager(void)
{
}*/

//代入演算子
CBulletManager& CBulletManager::operator=(const CBulletManager& rhs)
{
	(void)rhs;

	return *this;
}