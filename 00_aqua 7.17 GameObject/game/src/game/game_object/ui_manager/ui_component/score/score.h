#pragma once

#include"../ui_component.h"

//スコア
class CScore : public IUIComponent
{
public:
	CScore(aqua::IGameObject* parent);
	~CScore() = default;

	//初期化
	//位置
	void Initialize(const aqua::CVector2& position)override;
	void Draw(void)override;
	void Finalize(void)override;

	//スコアを加算
	void Add(int score);

	//スコア取得
	int GetScore(void);

	//数値を変更するかを設定
	void SetCountFlag(bool flag);

private:
	aqua::CSprite* m_Sprites;	//画像
	int m_Score;				//スコア
	bool m_CountFlag;			//数値を増加させるかのフラグ

	static const int m_max_score;		//最大スコア
	static const int m_min_score;		//最小スコア
	static const int m_max_digit;		//最大桁数
	static const int m_digit_width;		//一桁の幅
	static const int m_digit_height;	//一桁の高さ
	static const aqua::CVector2 m_scale;//拡大率
};