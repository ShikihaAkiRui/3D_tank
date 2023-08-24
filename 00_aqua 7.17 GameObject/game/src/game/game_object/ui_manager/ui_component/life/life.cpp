#include "life.h"

const int CLife::m_default_life = 3;
const int CLife::m_min_life = 0;
const int CLife::m_life_width = 85;
const float CLife::m_disappear_time = 1.0f;
const float CLife::m_max_alpha = 255.0f;

//コンストラクタ
CLife::CLife(aqua::IGameObject* parent)
	:IUIComponent(parent,"Life")
	,m_Life(m_default_life)
	,m_ShowLife(m_default_life)
	,m_DisappearFlag(false)
{
}

//初期化
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

//更新
void CLife::Update(void)
{
	//体力が表示数より少ないとき
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

//描画
void CLife::Draw(void)
{
	//最小値より低いとき表示しない
	if (m_ShowLife <= m_min_life) return;

	m_Sprites[0].position = m_Position;

	int life_count = 0;

	do
	{
		m_Sprites[life_count].Draw();
		
		//表示位置をずらす
		if (life_count + 1 < m_ShowLife)
			m_Sprites[life_count + 1].position.x = m_Sprites[life_count].position.x - m_life_width;

		life_count++;
	} while (life_count < m_ShowLife);
}

//解放
void CLife::Finalize(void)
{
	for (int i = 0; i < m_default_life; ++i)
		m_Sprites[i].Delete();

	AQUA_SAFE_DELETE_ARRAY(m_Sprites);
}

//体力を減らす
void CLife::Reduce(int life)
{
	m_Life -= life;

	//最小値を下回ったら最小値に戻す
	if (m_Life < m_min_life)
		m_Life = m_min_life;
}

//現在の体力を取得
int CLife::GetLife(void)
{
	return m_ShowLife;
}
