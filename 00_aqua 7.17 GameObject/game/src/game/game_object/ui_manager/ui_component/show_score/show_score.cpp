#include "show_score.h"

const int CShowScore::m_min_score = 0;
const int CShowScore::m_digit_width = 32;
const int CShowScore::m_digit_height = 32;

//�R���X�g���N�^
CShowScore::CShowScore(aqua::IGameObject* parent)
	:IUIComponent(parent,"ShowScore")
	,m_Score(0)
	,m_MaxDigit(0)
	,m_Scale(aqua::CVector2::ZERO)
	,m_Color(0xffffffff)
{
}

//������
void CShowScore::Initialize(const aqua::CVector2 position, int score, float scale, aqua::CColor color)
{
	IUIComponent::Initialize(position);
	m_Score = score;
	m_Scale = aqua::CVector2(scale, scale);
	m_Color = color;

	//���𐔂���
	while (score != 0)
	{
		score /= 10;
		++m_MaxDigit;
	}

	//0�������Ƃ�1���ɂ���
	if (score == 0)
		m_MaxDigit = 1;

	m_Sprites = AQUA_NEW aqua::CSprite[m_MaxDigit];

	for (int i = 0; i < m_MaxDigit; ++i)
	{
		m_Sprites[i].Create("data/texture/number_l.png");
		m_Sprites[i].position = m_Position;
		m_Sprites[i].scale = m_Scale;
		m_Sprites[i].color = m_Color;
	}

	int digit_count = 0;
	int count_score = m_Score;

	do
	{
		//�\�����鐔�l�����߂�
		int number = count_score % 10;
		//���̌��̗p��
		count_score = count_score / 10;

		//�\�����鐔�l�ɂ��炷
		m_Sprites[digit_count].rect.left = number * m_digit_width;
		m_Sprites[digit_count].rect.right = m_Sprites[digit_count].rect.left + m_digit_width;
		m_Sprites[digit_count].rect.top = 0;
		m_Sprites[digit_count].rect.bottom = m_Sprites[digit_count].rect.top + m_digit_height;

		//�\���ʒu�����炷
		if (digit_count < m_MaxDigit)
			m_Sprites[digit_count + 1].position.x = m_Sprites[digit_count].position.x - m_digit_width * m_Scale.x;

		//���𑝂₷
		digit_count++;
	} while (count_score > 0 && digit_count < m_MaxDigit);

}

//�`��
void CShowScore::Draw(void)
{

	for (int i = 0; i < m_MaxDigit; ++i)
	{
		m_Sprites[i].Draw();
	}

}

//���
void CShowScore::Finalize(void)
{
	for (int i = 0; i < m_MaxDigit; ++i)
	{
		m_Sprites[i].Delete();
	}

	AQUA_SAFE_DELETE_ARRAY(m_Sprites);
}
