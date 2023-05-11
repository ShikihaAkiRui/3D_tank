#include "enemy.h"

//コンストラクタ
CEnemy::CEnemy(aqua::IGameObject* parent)
	:IUnit(parent,"Enemy")
{
}

//初期化
void CEnemy::Initialize(void)
{
	IUnit::Initialize("data/boxt.mv1");

	m_Model->position = aqua::CVector3(30.0f, 0.0f, 30.0f);

}