#include "player.h"

//�R���X�g���N�^
CPlayer::CPlayer(aqua::IGameObject* parent)
	:IUnit(parent,"Player")
{
}

//������
void CPlayer::Initialize(void)
{
	//m_Model->Load("data/box.mv1");

	IUnit::Initialize("data/box.mv1");

}
