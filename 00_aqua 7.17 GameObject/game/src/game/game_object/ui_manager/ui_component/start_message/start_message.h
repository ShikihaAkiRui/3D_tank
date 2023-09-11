#pragma once

#include"../ui_component.h"

//開始メッセージ
class CStartMessage : public IUIComponent
{
public:
	//コンストラクタ
	CStartMessage(aqua::IGameObject* parent);
	//デストラクタ
	~CStartMessage() = default;

	//初期化
	void Initialize(void)override;
	//更新
	void Update(void)override;
	//描画
	void Draw(void)override;
	//解放
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
	static const aqua::CVector2 m_default_scale;//初期の拡大率
	static const aqua::CVector2 m_max_scale;	//最大拡大率
	static const float m_max_alpha;				//アルファ値最大
	static const float m_min_alpha;				//アルファ値最小
};