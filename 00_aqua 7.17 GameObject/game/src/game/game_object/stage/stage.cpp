#include "stage.h"

const std::string CStage::m_object_name = "Stage";

//�R���X�g���N�^
CStage::CStage(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,m_object_name)
{
}

//������
void CStage::Initialize(void)
{

}

//�X�V
void CStage::Update(void)
{
}

//�`��
void CStage::Draw(void)
{
}

//���
void CStage::Finalize(void)
{
}
