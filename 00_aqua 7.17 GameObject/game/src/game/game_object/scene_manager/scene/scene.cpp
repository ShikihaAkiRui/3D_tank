#include "scene.h"
#include"../scene_manager.h"

const std::string IScene::m_scene_category = "Scene";

//コンストラクタ
IScene::IScene(aqua::IGameObject* parent, const std::string& object_name)
	:aqua::IGameObject(parent,object_name,m_scene_category)
{
}

//シーンを変更
void IScene::ChangeScene(SCENE_ID id)
{
	//親のシーンマネージャーを呼び出す
	CSceneManager* sm = (CSceneManager*)GetParent();

	//シーンを変更
	sm->Change(id);

	//CSceneManager& sm = CSceneManager::GetInstance();
	//sm.Change(id);
}

//シーンをスタック
void IScene::PushScene(SCENE_ID id)
{
	//親のシーンマネージャーを呼び出す
	CSceneManager* sm = (CSceneManager*)GetParent();

	//シーンをスタック
	sm->Push(id);

	//CSceneManager& sm = CSceneManager::GetInstance();
	//sm.Push(id);

}

//スタックしたシーンを取り出す
void IScene::PopScene(void)
{
	//親のシーンマネージャーを呼び出す
	CSceneManager* sm = (CSceneManager*)GetParent();

	//スタックされたシーンを取り出す
	sm->Pop();

	//CSceneManager& sm = CSceneManager::GetInstance();
	//sm.Pop();

}

//シーンをリセット
void IScene::ResetScene(void)
{
	//親のシーンマネージャーを呼び出す
	CSceneManager* sm = (CSceneManager*)GetParent();

	//シーンを削除
	sm->Reset();

	//CSceneManager& sm = CSceneManager::GetInstance();
	//sm.Reset();

}
