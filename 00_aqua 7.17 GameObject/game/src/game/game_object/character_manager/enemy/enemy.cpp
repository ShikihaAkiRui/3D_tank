#include "enemy.h"

//コンストラクタ
IEnemy::IEnemy(aqua::IGameObject* parent, const std::string& object_name)
	:aqua::IGameObject(parent,object_name,"Enemy")
	,m_Position(aqua::CVector2::ZERO)
	,m_Velocity(aqua::CVector2::ZERO)
{
}

//初期化
void IEnemy::Initialize(std::string file_name)
{
	m_EnemySprite.Create(file_name);
	m_EnemySprite.position = m_Position;
}

//更新
void IEnemy::Update(void)
{
	switch (m_State)
	{
	case STATE::WAIT:
		break;
	case STATE::MOVE:
		Move();
		break;
	case STATE::DEAD:
		Dead();
		break;
	default:	break;
	}
}

//描画
void IEnemy::Draw(void)
{
	m_EnemySprite.Draw();
}

//解放
void IEnemy::Finalize(void)
{
	m_EnemySprite.Delete();
}

//移動
void IEnemy::Move(void)
{
	m_Position += m_Velocity;

	m_EnemySprite.position = m_Position;

}

//ダメージを受ける
void IEnemy::Damage(void)
{

}

//消える
void IEnemy::Dead(void)
{
}

//攻撃
void IEnemy::Attack(void)
{
}