#include "score.h"

const int CScore::m_max_score = 99;
const int CScore::m_min_score = 0;
const int CScore::m_max_digit = 2;
const int CScore::m_digit_width = 32;
const int CScore::m_digit_height = 32;
const aqua::CVector2 CScore::m_scale = aqua::CVector2(3.0f, 3.0f);

//コンストラクタ
CScore::CScore(aqua::IGameObject* parent)
	:IUIComponent(parent, "Score")
	,m_Score(0)
	,m_CountFlag(true)
{
}

//初期化
void CScore::Initialize(const aqua::CVector2& position)
{
	IUIComponent::Initialize(position);

	m_Sprites = AQUA_NEW aqua::CSprite[m_max_digit];

	for (int i = 0; i < m_max_digit; ++i)
	{
		m_Sprites[i].Create("data/texture/number_l.png");
		m_Sprites[i].position = m_Position;
		m_Sprites[i].scale = m_scale;
	}

}

//描画
void CScore::Draw(void)
{
	m_Sprites[0].position = m_Position;

	int digit_count = 0;
	int score = m_Score;

	do
	{
		//表示する数値を求める
		int number = score % 10;
		//次の桁の用意
		score = score / 10;

		//表示する数値にずらす
		m_Sprites[digit_count].rect.left = number * m_digit_width;
		m_Sprites[digit_count].rect.right = m_Sprites[digit_count].rect.left + m_digit_width;
		m_Sprites[digit_count].rect.top = 0;
		m_Sprites[digit_count].rect.bottom = m_Sprites[digit_count].rect.top + m_digit_height;

		//描画
		m_Sprites[digit_count].Draw();

		//表示位置をずらす
		if (digit_count < m_max_digit)
			m_Sprites[digit_count + 1].position.x = m_Sprites[digit_count].position.x - m_digit_width * m_scale.x;
		
		//桁を増やす
		digit_count++;
	} while (score > 0 && digit_count < m_max_digit);

}

//解放
void CScore::Finalize(void)
{
	for (int i = 0; i < m_max_digit; ++i)
		m_Sprites[i].Delete();

	AQUA_SAFE_DELETE_ARRAY(m_Sprites);
}

//スコアを加算
void CScore::Add(int score)
{
	if (m_CountFlag)
	{
		m_Score += score;

		//最大値を超えたら最大値に直す
		if (m_Score > m_max_score)
			m_Score = m_max_score;
		//最小値を超えたら最小値に直す
		if (m_Score < m_min_score)
			m_Score = m_min_score;
	}
}

//スコア取得
int CScore::GetScore(void)
{
	return m_Score;
}

//数値を変更するかを設定
void CScore::SetCountFlag(bool flag)
{
	m_CountFlag = flag;
}
