#include "title_scene.h"

//コンストラクタ
CTitleScene::CTitleScene(aqua::IGameObject* parent)
	:IScene(parent,"TitleScene")
{
}

//初期化
void CTitleScene::Initialize(void)
{
	IGameObject::Initialize();

#ifdef _DEBUG
	m_Label.Create(30);
	m_Label.text = "title";

#endif 

}

//更新
void CTitleScene::Update(void)
{
	if (aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::Z))
		ChangeScene(SCENE_ID::GAMEMAIN);

	IGameObject::Update();
}

//描画
void CTitleScene::Draw(void)
{
#ifdef _DEBUG
	m_Label.Draw();
#endif

	IGameObject::Draw();
}

//解放
void CTitleScene::Finalize(void)
{
#ifdef _DEBUG
	m_Label.Delete();
#endif

	IGameObject::Finalize();
}
