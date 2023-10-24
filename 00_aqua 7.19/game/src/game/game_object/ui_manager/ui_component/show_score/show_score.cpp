#include "show_score.h"

const int CShowScore::m_min_score = 0;
const int CShowScore::m_max_score = 99;
const int CShowScore::m_max_digit = 2;
const int CShowScore::m_digit_width = 32;
const int CShowScore::m_digit_height = 32;

//コンストラクタ
CShowScore::CShowScore(aqua::IGameObject* parent)
	:IUIComponent(parent,"ShowScore")
	,m_Score(0)
	,m_Scale(aqua::CVector2::ZERO)
	,m_Color(0xffffffff)
	,m_ShowDigit(0)
{
}

//初期化
void CShowScore::Initialize(const aqua::CVector2& position, int score, float scale, aqua::CColor color)
{

	IUIComponent::Initialize(position);
	m_Scale = aqua::CVector2(scale, scale);
	m_Color = color;
	m_Score = score;

	//桁数を求める
	int digit_score = m_Score;
	//0の時は1
	if (digit_score == 0)
	{
		m_ShowDigit++;
	}
	else
	{
		while (digit_score > m_min_score)
		{

			digit_score /= 10;
			m_ShowDigit++;
		}
	}

	m_Sprites = AQUA_NEW aqua::CSprite[m_ShowDigit];

	for (int i = 0; i < m_ShowDigit; ++i)
	{
		m_Sprites[i].Create("data/texture/number_l.png");
		m_Sprites[i].position = m_Position;
		m_Sprites[i].scale = m_Scale;
		m_Sprites[i].color = m_Color;
	}

	//表示する数値に変更
	int digit_count = 0;
	int show_score = m_Score;

	do
	{
		//表示する数値を求める
		int number = show_score % 10;
		//次の桁の用意
		show_score = show_score / 10;

		//表示する数値にずらす
		m_Sprites[digit_count].rect.left = number * m_digit_width;
		m_Sprites[digit_count].rect.right = m_Sprites[digit_count].rect.left + m_digit_width;
		m_Sprites[digit_count].rect.top = 0;
		m_Sprites[digit_count].rect.bottom = m_Sprites[digit_count].rect.top + m_digit_height;

		//表示位置をずらす
		if (digit_count + 1 < m_ShowDigit)
			m_Sprites[digit_count + 1].position.x = m_Sprites[digit_count].position.x - m_digit_width * m_Scale.x;

		//桁を増やす
		digit_count++;
	} while (show_score > 0 && digit_count < m_ShowDigit);

}

//描画
void CShowScore::Draw(void)
{
	for (int i = 0; i < m_ShowDigit; ++i)
		m_Sprites[i].Draw();

}

//解放
void CShowScore::Finalize(void)
{
	for (int i = 0; i < m_ShowDigit; ++i)
		m_Sprites[i].Delete();

	AQUA_SAFE_DELETE_ARRAY(m_Sprites);
}
