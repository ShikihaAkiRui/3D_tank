#include "life.h"

const int CLife::m_default_life = 3;
const int CLife::m_min_life = 0;
const int CLife::m_life_width = 85;
const float CLife::m_disappear_time = 1.0f;
const float CLife::m_max_alpha = 255.0f;

//�R���X�g���N�^
CLife::CLife(aqua::IGameObject* parent)
	:IUIComponent(parent,"Life")
	,m_Life(m_default_life)
	,m_ShowLife(m_default_life)
	,m_DisappearFlag(false)
{
}

//������
void CLife::Initialize(const aqua::CVector2& position)
{
	IUIComponent::Initialize(position);

	m_Life = m_ShowLife = m_default_life;

	m_Sprites = AQUA_NEW aqua::CSprite[m_Life];

	for (int i = 0; i < m_Life; ++i)
	{
		m_Sprites[i].Create("data/texture/life.png");
		m_Sprites[i].position = m_Position;
	}

	m_DisappearTimer.Setup(m_disappear_time);
}

//�X�V
void CLife::Update(void)
{
	//�̗͂��\������菭�Ȃ��Ƃ�
	if (m_ShowLife > m_Life && !m_DisappearFlag)
	{
		m_DisappearFlag = true;
	}

	if (m_DisappearFlag)
	{
		m_DisappearTimer.Update();

		m_Sprites[m_ShowLife - 1].color.alpha = m_max_alpha - aqua::easing::OutQuart(m_DisappearTimer.GetTime(), m_DisappearTimer.GetLimit(), 0, m_max_alpha);

		if (m_DisappearTimer.Finished())
		{
			m_DisappearTimer.Reset();
			m_ShowLife = m_Life;
			m_DisappearFlag = false;
		}
	}
}

//�`��
void CLife::Draw(void)
{
	//�ŏ��l���Ⴂ�Ƃ��\�����Ȃ�
	if (m_ShowLife <= m_min_life) return;

	m_Sprites[0].position = m_Position;

	int life_count = 0;

	do
	{
		m_Sprites[life_count].Draw();
		
		//�\���ʒu�����炷
		if (life_count + 1 < m_ShowLife)
			m_Sprites[life_count + 1].position.x = m_Sprites[life_count].position.x - m_life_width;

		life_count++;
	} while (life_count < m_ShowLife);
}

//���
void CLife::Finalize(void)
{
	for (int i = 0; i < m_default_life; ++i)
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
	return m_ShowLife;
}
