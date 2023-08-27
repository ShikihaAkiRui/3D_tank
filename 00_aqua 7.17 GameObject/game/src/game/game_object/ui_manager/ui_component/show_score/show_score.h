#pragma once

#include"../ui_component.h"

//表示用スコアクラス
class CShowScore : public IUIComponent
{
public:
	CShowScore(aqua::IGameObject* parent);
	~CShowScore() = default;

	void Initialize(const aqua::CVector2 position,int score,float scale,unsigned char color);
	void Draw(void)override;
	void Finalize(void)override;

private:
	aqua::CSprite* m_Sprites;	//画像
	int m_Score;				//スコア
	int m_MaxDigit;				//最大桁数
	unsigned char m_Color;		//色
	aqua::CVector2 m_Scale;		//拡大率

	static const int m_min_score;		//最小スコア
	static const int m_digit_width;		//一桁の幅
	static const int m_digit_height;	//一桁の高さ
};