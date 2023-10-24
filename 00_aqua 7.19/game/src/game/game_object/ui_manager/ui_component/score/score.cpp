#include "score.h"

const int CScore::m_max_score = 99;
const int CScore::m_min_score = 0;
const int CScore::m_max_digit = 2;
const int CScore::m_digit_width = 32;
const int CScore::m_digit_height = 32;
const aqua::CVector2 CScore::m_scale = aqua::CVector2(3.0f, 3.0f);

//�R���X�g���N�^
CScore::CScore(aqua::IGameObject* parent)
	:IUIComponent(parent, "Score")
	,m_Score(0)
	,m_CountFlag(true)
{
}

//������
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

//�`��
void CScore::Draw(void)
{
	m_Sprites[0].position = m_Position;

	int digit_count = 0;
	int score = m_Score;

	do
	{
		//�\�����鐔�l�����߂�
		int number = score % 10;
		//���̌��̗p��
		score = score / 10;

		//�\�����鐔�l�ɂ��炷
		m_Sprites[digit_count].rect.left = number * m_digit_width;
		m_Sprites[digit_count].rect.right = m_Sprites[digit_count].rect.left + m_digit_width;
		m_Sprites[digit_count].rect.top = 0;
		m_Sprites[digit_count].rect.bottom = m_Sprites[digit_count].rect.top + m_digit_height;

		//�`��
		m_Sprites[digit_count].Draw();

		//�\���ʒu�����炷
		if (digit_count < m_max_digit)
			m_Sprites[digit_count + 1].position.x = m_Sprites[digit_count].position.x - m_digit_width * m_scale.x;
		
		//���𑝂₷
		digit_count++;
	} while (score > 0 && digit_count < m_max_digit);

}

//���
void CScore::Finalize(void)
{
	for (int i = 0; i < m_max_digit; ++i)
		m_Sprites[i].Delete();

	AQUA_SAFE_DELETE_ARRAY(m_Sprites);
}

//�X�R�A�����Z
void CScore::Add(int score)
{
	if (m_CountFlag)
	{
		m_Score += score;

		//�ő�l�𒴂�����ő�l�ɒ���
		if (m_Score > m_max_score)
			m_Score = m_max_score;
		//�ŏ��l�𒴂�����ŏ��l�ɒ���
		if (m_Score < m_min_score)
			m_Score = m_min_score;
	}
}

//�X�R�A�擾
int CScore::GetScore(void)
{
	return m_Score;
}

//���l��ύX���邩��ݒ�
void CScore::SetCountFlag(bool flag)
{
	m_CountFlag = flag;
}
