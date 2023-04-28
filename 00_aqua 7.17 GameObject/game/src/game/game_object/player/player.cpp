#include "player.h"

//コンストラクタ
CPlayer::CPlayer(aqua::IGameObject* parent)
	:IUnit(parent,"Player")
{
}

//初期化
void CPlayer::Initialize(void)
{
	//m_Model->Load("data/box.mv1");

	IUnit::Initialize("data/box.mv1");

}
