#pragma once

#include"../ui_component.h"

//終了メッセージ
class CEndMessage : public IUIComponent
{
public:
	//コンストラクタ
	CEndMessage(aqua::IGameObject* parent);
	//デストラクタ
	~CEndMessage() = default;

	//初期化
	void Initialize(void)override;
	//更新
	void Update(void)override;
	//描画
	void Draw(void)override;
	//解放
	void Finalize(void)override;

	//出しているかを取得
	bool GetAppearFlag(void);

private:
	//スタートメッセージの状態
	enum class STATE
	{
		START_IN,	//動かす
		WAIT,		//出し終わる
	};

	aqua::CSprite m_Sprite;			//スプライト
	aqua::CTimer  m_DisplayTimer;	//状態の変更時間
	STATE m_State;					//終了メッセージの状態
	bool m_AppearFlag;				//出しているかのフラグ
	
	static const float m_display_time;		//状態の変更時間
	static const float m_position_height;	//スプライト高さ
	static const aqua::CVector2 m_default_scale;//初期の拡大率
	static const aqua::CVector2 m_max_scale;	//最大拡大率
};
