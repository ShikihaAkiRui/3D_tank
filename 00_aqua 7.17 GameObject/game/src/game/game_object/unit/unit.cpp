#include "unit.h"

//�R���X�g���N�^
IUnit::IUnit(aqua::IGameObject* parent, const std::string& object_name)
	:IGameObject(parent,object_name,"Unit")
{
}

//������
void IUnit::Initialize(void)
{
	SetupCollInfo(m_Model, 0, 8, 8, 8);
	
}

//�X�V
void IUnit::Update(void)
{
	RefreshCollInfo(0);
}

//�`��
void IUnit::Draw(void)
{
	m_Model->Draw();
}

//���
void IUnit::Finalize(void)
{
	TerminateCollInfo(0);

	m_Model->Unload();
}
