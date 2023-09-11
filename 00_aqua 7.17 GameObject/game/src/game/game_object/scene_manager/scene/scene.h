#pragma once

#include"aqua.h"
#include"scene_id.h"

//シーン
class IScene : public aqua::IGameObject
{
public:
	//コンストラクタ
	IScene(aqua::IGameObject* parent,const std::string& object_name);
	//デストラクタ
	~IScene() = default;

	//シーンを変更
	void ChangeScene(SCENE_ID id);
	//シーンをスタック
	void PushScene(SCENE_ID id);
	//スタックしたシーンを取り出す
	void PopScene(void);
	//シーンをリセット
	void ResetScene(void);

private:
	static const std::string m_scene_category;	//シーンのカテゴリー
};