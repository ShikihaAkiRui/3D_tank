#include "scene.h"
#include"../scene_manager.h"

const std::string IScene::m_scene_category = "Scene";

//�R���X�g���N�^
IScene::IScene(aqua::IGameObject* parent, const std::string& object_name)
	:aqua::IGameObject(parent,object_name,m_scene_category)
{
}

//�V�[����ύX
void IScene::ChangeScene(SCENE_ID id)
{
	//�e�̃V�[���}�l�[�W���[���Ăяo��
	CSceneManager* sm = (CSceneManager*)GetParent();

	//�V�[����ύX
	sm->Change(id);

	//CSceneManager& sm = CSceneManager::GetInstance();
	//sm.Change(id);
}

//�V�[�����X�^�b�N
void IScene::PushScene(SCENE_ID id)
{
	//�e�̃V�[���}�l�[�W���[���Ăяo��
	CSceneManager* sm = (CSceneManager*)GetParent();

	//�V�[�����X�^�b�N
	sm->Push(id);

	//CSceneManager& sm = CSceneManager::GetInstance();
	//sm.Push(id);

}

//�X�^�b�N�����V�[�������o��
void IScene::PopScene(void)
{
	//�e�̃V�[���}�l�[�W���[���Ăяo��
	CSceneManager* sm = (CSceneManager*)GetParent();

	//�X�^�b�N���ꂽ�V�[�������o��
	sm->Pop();

	//CSceneManager& sm = CSceneManager::GetInstance();
	//sm.Pop();

}

//�V�[�������Z�b�g
void IScene::ResetScene(void)
{
	//�e�̃V�[���}�l�[�W���[���Ăяo��
	CSceneManager* sm = (CSceneManager*)GetParent();

	//�V�[�����폜
	sm->Reset();

	//CSceneManager& sm = CSceneManager::GetInstance();
	//sm.Reset();

}
