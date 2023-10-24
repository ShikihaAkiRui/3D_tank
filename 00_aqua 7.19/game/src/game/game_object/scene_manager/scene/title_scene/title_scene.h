#pragma once

#include"../scene.h"

//タイトルシーン
class CTitleScene : public IScene
{
public:
	//コンストラクタ
	CTitleScene(aqua::IGameObject* parent);
	//デストラクタ
	~CTitleScene() = default;

	//初期化
	void Initialize(void)override;
	//更新
	void Update(void)override;
	//描画
	void Draw(void)override;
	//解放
	void Finalize(void)override;

private:
	aqua::CSprite m_BackSprite;	//背景スプライト

	static const aqua::CVector2 m_back_scale;		//背景拡大率
	static const aqua::CVector2 m_title_name_position;	//タイトルの位置
	static const aqua::CVector2 m_message_position;	//メッセージ位置
	static const std::string m_message;				//メッセージ文字
	static const std::string m_object_name;			//オブジェクトの名前
	aqua::CLabel m_Label;	//デバック用
};