#pragma once

#include"aqua.h"
#include"scene/scene_id.h"

//シーンマネージャー
class CSceneManager : public aqua::IGameObject
{
public:
	CSceneManager(aqua::IGameObject* parent);
	~CSceneManager() = default;

	void Initialize(void)override;
	void Update(void)override;
	void Draw(void)override;

	//シーンを変更
	void Change(SCENE_ID id);
	//シーンをスタック
	void Push(SCENE_ID id);
	//スタックしたシーンを取り出す
	void Pop(void);
	//シーンをリセット
	void Reset(void);

	//現在のシーンID
	SCENE_ID GetSceneID(void)const;

private:
	//状態
	enum class STATE
	{
		SCENE_IN,		//開始
		SCENE_UPDATE,	//更新
		SCENE_OUT,		//終了
		SCENE_CHANGE	//変更
	};

	//シーンを生成
	void Create(SCENE_ID id);
	//現在のシーンを削除
	void Delete(void);
	//シーンの開始演出
	void SceneIn(void);
	//シーンを更新
	void SceneUpdate(void);
	//シーンの終了演出
	void SceneOut(void);
	//シーンを変更
	void SceneChange(void);

	static const float m_fade_speed;	//フェード速度
	SCENE_ID m_CurrentSceneID;			//現在のシーンID
	SCENE_ID m_NextSceneID;				//次のシーンID
	SCENE_ID m_PushSceneID;				//プッシュするシーンID
	STATE m_State;						//状態ID
	bool m_PushFlag;					//シーンのプッシュが行われた
	aqua::CBoxPrimitive m_FadePlane;	//フェード用の黒い板

	aqua::CCamera m_Camera;
};

//シーンマネージャーの取得
CSceneManager* GetSceneManager(void);