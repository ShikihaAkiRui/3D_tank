#include "radar.h"
#include"../../enemy_appear/enemy_appear.h"

//�R���X�g���N�^
CRadar::CRadar(aqua::IGameObject* parent)
	:IUIComponent(parent,"Radar")
	,m_MaxEnemyCount(0)
{
}

//������
void CRadar::Initialize(const aqua::CVector2& position)
{
	IUIComponent::Initialize(position);
}

//�X�V
void CRadar::Update(void)
{

}

//�`��
void CRadar::Draw(void)
{
}

//���
void CRadar::Finalize(void)
{

}