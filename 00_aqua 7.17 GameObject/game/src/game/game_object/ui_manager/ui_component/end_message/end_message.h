#pragma once

#include"../ui_component.h"

//終了メッセージ
class CEndMessage : public IUIComponent
{
public:
	CEndMessage(aqua::IGameObject* parent);
	~CEndMessage() = default;

	void Initialize(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;

	//出しているかを取得
	bool GetAppearFlag(void);

private:
	//スタートメッセージの状態
	enum class STATE
	{
		START_IN,
		WAIT,
	};

	aqua::CSprite m_Sprite;			//スプライト
	aqua::CTimer  m_DisplayTimer;	//状態の変更時間
	STATE m_State;					//終了メッセージの状態
	bool m_AppearFlag;				//出しているかのフラグ

	static const float m_display_time;	//状態の変更時間
	static const float m_position_height;	//スプライト高さ
	static const float m_max_scale;		//最大拡大率
};
