#include "title_scene.h"

const std::string CTitleScene::m_object_name = "TitleScene";

//�R���X�g���N�^
CTitleScene::CTitleScene(aqua::IGameObject* parent)
	:IScene(parent,"TitleScene")
{
}

//������
void CTitleScene::Initialize(void)
{
	IGameObject::Initialize();

#ifdef _DEBUG
	m_Label.Create(30);
	m_Label.text = "title";

#endif 

}

//�X�V
void CTitleScene::Update(void)
{
	if (aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::Z))
		ChangeScene(SCENE_ID::GAMEMAIN);

	IGameObject::Update();
}

//�`��
void CTitleScene::Draw(void)
{
#ifdef _DEBUG
	m_Label.Draw();
#endif

	IGameObject::Draw();
}

//���
void CTitleScene::Finalize(void)
{
#ifdef _DEBUG
	m_Label.Delete();
#endif

	IGameObject::Finalize();
}
