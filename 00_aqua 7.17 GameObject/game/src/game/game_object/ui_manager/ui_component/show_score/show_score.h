#pragma once

#include"../ui_component.h"

//表示用スコア
class CShowScore : public IUIComponent
{
public:
	CShowScore(aqua::IGameObject* parent);
	~CShowScore() = default;

	//初期化
	//位置,	スコア,	拡大率,	色
	void Initialize(const aqua::CVector2& position, int score, float scale, aqua::CColor color);
	void Draw(void)override;
	void Finalize(void)override;

private:
	aqua::CSprite* m_Sprites;	//スプライト
	int m_Score;				//表示するスコア
	aqua::CVector2 m_Scale;		//拡大率
	aqua::CColor m_Color;		//色
	int m_ShowDigit;			//表示桁数

	static const int m_min_score;	//最小スコア
	static const int m_max_score;	//最大スコア
	static const int m_max_digit;	//最大桁数
	static const int m_digit_width;	//一桁の幅
	static const int m_digit_height;//一桁の高さ

};