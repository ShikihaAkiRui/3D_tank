#pragma once

#include"../ui_component.h"

//スコア
class CScore : public IUIComponent
{
public:
	CScore(aqua::IGameObject* parent);
	~CScore() = default;

	void Initialize(const aqua::CVector2& position)override;

	void Draw(void)override;
	void Finalize(void)override;

	//スコアを加算
	void Add(int score);

private:
	aqua::CSprite* m_Sprites;	//画像
	int m_Score;				//スコア

	static const int m_max_score;		//最大スコア
	static const int m_min_score;		//最小スコア
	static const int m_max_dight;		//最大桁数
	static const int m_digit_width;		//一桁の幅
	static const int m_digit_height;	//一桁の高さ
};