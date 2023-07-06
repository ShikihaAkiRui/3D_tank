#include "life.h"

const int CLife::m_min_life = 0;
const int CLife::m_life_width = 48;

//�R���X�g���N�^
CLife::CLife(aqua::IGameObject* parent)
	:IUIComponent(parent,"Life")
	,m_Life(0)
	,m_DefaultLife(0)
{
}

//������
void CLife::Initialize(const aqua::CVector2& position, int life)
{
	IUIComponent::Initialize(position);

	m_Life =  m_DefaultLife =life;

	m_Sprites = AQUA_NEW aqua::CSprite[m_Life];

	for (int i = 0; i < m_Life; ++i)
	{
		m_Sprites[i].Create("data/ball.png");
		m_Sprites[i].position = m_Position;
	}
}

//�`��
void CLife::Draw(void)
{
	//�ŏ��l���Ⴂ�Ƃ��\�����Ȃ�
	if (m_Life <= m_min_life) return;

	m_Sprites[0].position = m_Position;

	int life_count = 0;

	do
	{
		m_Sprites[life_count].Draw();
		
		//�\���ʒu�����炷
		if (life_count + 1 < m_Life)
			m_Sprites[life_count + 1].position.x = m_Sprites[life_count].position.x - m_life_width;

		life_count++;
	} while (life_count < m_Life);
}

//���
void CLife::Finalize(void)
{
	for (int i = 0; i < m_DefaultLife; ++i)
		m_Sprites[i].Delete();

	AQUA_SAFE_DELETE_ARRAY(m_Sprites);
}

//�̗͂����炷
void CLife::Reduce(int life)
{
	m_Life -= life;

	//�ŏ��l�����������ŏ��l�ɖ߂�
	if (m_Life < m_min_life)
		m_Life = m_min_life;
}

//���݂̗̑͂��擾
int CLife::GetLife(void)
{
	return m_Life;
}
