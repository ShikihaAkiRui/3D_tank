#include "bullet_manager.h"
#include"bullet/bullet.h"
#include"bullet/bullet_normal/bullet_normal.h"
#include"bullet/bullet_parabola/bullet_parabola.h"

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
void CBulletManager::Create(BULLET_ID id,UNIT_CATEGORY unit_category, const aqua::CVector3& position, const aqua::CVector3& rotation)
{
	CBulletNormal* bullet = nullptr;
	CBulletParabola* parabola = nullptr;

	switch (id)
	{
	case BULLET_ID::NORMAL:	
		bullet = aqua::CreateGameObject<CBulletNormal>(&m_GameObject);	break;
	case BULLET_ID::PARABOLA:	
		parabola = aqua::CreateGameObject<CBulletParabola>(&m_GameObject);	break;
		break;
	default:	break;
	}

	if (bullet)
		bullet->Initialize(unit_category, position, rotation);
	else if (parabola)
		parabola->Initialize(unit_category, position, rotation);


}

//弾とキャラクターの当たり判定
bool CBulletManager::CheckHitCharacter(ICollision* collision, UNIT_CATEGORY unit_category)
{
	bool hit_flag = false;

	auto it = m_GameObject.GetChildList()->begin();

	while (it != m_GameObject.GetChildList()->end())
	{
		IBullet* bullet = (IBullet*)(*it);

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

//コピーコンストラクタ
CBulletManager::CBulletManager(const CBulletManager& rhs)
{
	(void)rhs;
}

//代入演算子
CBulletManager& CBulletManager::operator=(const CBulletManager& rhs)
{
	(void)rhs;

	return *this;
}
