#include "scene_manager.h"
#include"scene/title_scene/title_scene.h"
#include"scene/gamemain_scene/gamemain_scene.h"

const float CSceneManager::m_fade_speed = 255.0f;

//コンストラクタ
CSceneManager::CSceneManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"SceneManager")
	,m_CurrentSceneID(SCENE_ID::DUMMY)
	,m_NextSceneID(SCENE_ID::DUMMY)
	,m_PushSceneID(SCENE_ID::DUMMY)
	,m_State(STATE::SCENE_IN)
	,m_PushFlag(false)
{
}

//初期化
void CSceneManager::Initialize(void)
{
	//フェード用パネル設定
	m_FadePlane.Setup(aqua::CVector2::ZERO, (float)aqua::GetWindowWidth(), (float)aqua::GetWindowHeight(), aqua::CColor::BLACK);

	//タイトルシーンを生成
	Create(SCENE_ID::TITLE);

	//シーンインの状態に設定
	m_State = STATE::SCENE_IN;

	//PushフラグをOFF
	m_PushFlag = false;

}

//更新
void CSceneManager::Update(void)
{
	switch (m_State)
	{
	case STATE::SCENE_IN:		SceneIn();		break;
	case STATE::SCENE_UPDATE:	SceneUpdate();	break;
	case STATE::SCENE_OUT:		SceneOut();		break;
	case STATE::SCENE_CHANGE:	SceneChange();	break;
	default:	break;
	}

}

//描画
void CSceneManager::Draw(void)
{
	IGameObject::Draw();

	if (m_State != STATE::SCENE_UPDATE)
		m_FadePlane.Draw();
}

//シーンを変更
void CSceneManager::Change(SCENE_ID id)
{
	//次のシーンID
	m_NextSceneID = id;
}

//シーンをスタック
void CSceneManager::Push(SCENE_ID id)
{
	//同じフレーム中にすでにプッシュされてる
	if (m_PushFlag || m_PushSceneID != SCENE_ID::DUMMY)
		return;

	//プッシュフラグをON
	m_PushFlag = true;

	//スタックするシーンIDを保存
	m_PushSceneID = id;
}

//スタックしたシーンを取り出す
void CSceneManager::Pop(void)
{
	//このシーンが一つの場合はポップできない
	if (m_ChildObjectList.size() <= 1)
		return;
	//末尾のシーンのイテレータを取得
	aqua::GAME_OBJECT_LIST::reverse_iterator it = m_ChildObjectList.rbegin();

	//シーンクラスにキャストする
	IScene* scene = (IScene*)(*it);

	//末尾のシーンを削除対象に設定
	scene->DeleteObject();

	//ひとつ前のシーンを取得
	scene = (IScene*)(*(++it));

	//ひとつ前のシーンをアクティブ状態に変更
	scene->SetGameObjectState(aqua::GAME_OBJECT_STATE::ACTIVE);
}

//現在のシーンをリセット
void CSceneManager::Reset(void)
{
	m_NextSceneID = m_CurrentSceneID;

	m_CurrentSceneID = SCENE_ID::DUMMY;
}

//現在のシーンID
SCENE_ID CSceneManager::GetSceneID(void) const
{
	return m_CurrentSceneID;
}

//シーンを生成
void CSceneManager::Create(SCENE_ID id)
{
	IScene* scene = nullptr;

	//IDごとに新しくシーンを生成
	switch (id)
	{
	case SCENE_ID::TITLE:	scene = aqua::CreateGameObject<CTitleScene>(this);			break;
	case SCENE_ID::GAMEMAIN:	scene = aqua::CreateGameObject<CGameMainScene>(this);	break;
	default:	break;
	}

	AQUA_ASSERT(scene, "シーンが生成できませんでした");

	//シーンの初期化
	scene->Initialize();
}

//シーンの削除
void CSceneManager::Delete(void)
{
	IGameObject::Finalize();
}

//シーン演出開始
void CSceneManager::SceneIn(void)
{
	float alpha = (float)m_FadePlane.color.alpha;

	alpha -= m_fade_speed * aqua::GetDeltaTime();

	if (alpha < 0.0f)
	{
		alpha = 0.0f;

		m_State = STATE::SCENE_UPDATE;
	}

	m_FadePlane.color.alpha = (unsigned char)alpha;
}

//シーンを更新
void CSceneManager::SceneUpdate(void)
{
	//プッシュ処理が行われた場合
	if (m_PushFlag)
	{
		//末尾のシーンのイテレータを取得
		aqua::GAME_OBJECT_LIST::reverse_iterator it = m_ChildObjectList.rbegin();

		//シーンクラスにキャスト
		IScene* scene = (IScene*)(*it);

		//現在のシーンを非アクティブに変更
		scene->SetGameObjectState(aqua::GAME_OBJECT_STATE::WAIT);

		//新しいシーンを生成してスタック
		Create(m_PushSceneID);

		//未使用時はダミーIDを入れておく
		m_PushSceneID = SCENE_ID::DUMMY;

		//シーンのプッシュを終了
		m_PushFlag = false;
	}

	IGameObject::Update();

	//シーンの変更を検知
	if (m_CurrentSceneID != m_NextSceneID)
		m_State = STATE::SCENE_OUT;
}

//シーンの終了演出
void CSceneManager::SceneOut(void)
{
	float alpha = (float)m_FadePlane.color.alpha;

	alpha += m_fade_speed * aqua::GetDeltaTime();

	if (alpha > (float)aqua::CColor::MAX_COLOR)
	{
		alpha = (float)aqua::CColor::MAX_COLOR;

		m_State = STATE::SCENE_CHANGE;
	}

	m_FadePlane.color.alpha = (unsigned char)alpha;
}

//シーンを変更
void CSceneManager::SceneChange(void)
{
	//現在のシーンを削除
	Delete();

	//次のシーンを生成
	Create(m_NextSceneID);

	//シーンIDを保存
	m_CurrentSceneID = m_NextSceneID;

	//状態を移行
	m_State = STATE::SCENE_IN;
}

//シーンマネージャーを取得
CSceneManager* GetSceneManager(void)
{
	return (CSceneManager*)aqua::FindGameObject("SceneManager");
}
