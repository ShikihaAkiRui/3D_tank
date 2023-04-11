#include "gamemain_scene.h"

//�R���X�g���N�^
CGameMainScene::CGameMainScene(aqua::IGameObject* parent)
	:IScene(parent,"GameMain")
{
}

//������
void CGameMainScene::Initialize(void)
{

	IGameObject::Initialize();

#ifdef _DEBUG
	m_Label.Create(30);
	m_Label.text = "gamemain";
#endif 

}

//�X�V
void CGameMainScene::Update(void)
{

	IGameObject::Update();
}

//�`��
void CGameMainScene::Draw(void)
{

	IGameObject::Draw();
#ifdef _DEBUG
	m_Label.Draw();
#endif 

}

//���
void CGameMainScene::Finalize(void)
{
	IGameObject::Finalize();

#ifdef _DEBUG
	m_Label.Delete();
#endif

}