#include "gamemain_scene.h"

const std::string CGameMainScene::m_object_name = "GameMainScene";

//�R���X�g���N�^
CGameMainScene::CGameMainScene(aqua::IGameObject* parent)
	:IScene(parent,m_object_name)
{
}

//������
void CGameMainScene::Initialize(void)
{

	IGameObject::Initialize();
	m_Model.Load("data/model.pmd");
	m_Model.position = aqua::CVector3(10.0f, 10.0f, 10.0f);
	m_Model.scale = aqua::CVector3(0.5f,0.5f, 0.5f);

#ifdef _DEBUG
	m_Label.Create(30);
	m_Label.text = "gamemain";
#endif 

}

//�X�V
void CGameMainScene::Update(void)
{
	IGameObject::Update();

	m_Model.rotation.y += 1.0f;

}

//�`��
void CGameMainScene::Draw(void)
{

	IGameObject::Draw();

	m_Model.Draw();
	//DrawSphere3D(aqua::CVector3::ZERO, 10.0f, 10, 0xffffffff, 0xffffffff, TRUE);

#ifdef _DEBUG
	m_Label.Draw();
#endif 

}

//���
void CGameMainScene::Finalize(void)
{
	IGameObject::Finalize();
	m_Model.Unload();

#ifdef _DEBUG
	m_Label.Delete();
#endif

}