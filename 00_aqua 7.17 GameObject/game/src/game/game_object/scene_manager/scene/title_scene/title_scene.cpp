#include "title_scene.h"
#include"../../..\game_sound_manager/game_sound_manager.h"

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
	if (aqua::mouse::Trigger(aqua::mouse::BUTTON_ID::LEFT))
	{
		CGameSoundManager::GetInstance().Play(SOUND_ID::DECISION);
		ChangeScene(SCENE_ID::GAMEMAIN);
	}

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
