#include "enemy_manager.h"

//コンストラクタ
CEnemyManager::CEnemyManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"Enemy")
{
}

//生成
void CEnemyManager::Create(ENEMY_ID id)
{
}
