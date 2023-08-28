#pragma once

#include"../ui_component.h"

//開始メッセージ
class CStartMessage : public IUIComponent
{
public:
	CStartMessage(aqua::IGameObject* parent);
	~CStartMessage() = default;

	void Initialize(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;

private:
	//メッセージの状態
	enum class STATE
	{
		START_IN,	//動かす
		WAIT,		//出し終わる
	};

	aqua::CSprite m_StartSprite;		//開始のスプライト
	aqua::CTimer  m_StartDisplayTimer;	//状態の変更時間
	STATE m_State;						//開始メッセージの状態

	static const float m_start_display_time;	//状態の変更時間
	static const float m_max_scale;				//最大拡大率
};