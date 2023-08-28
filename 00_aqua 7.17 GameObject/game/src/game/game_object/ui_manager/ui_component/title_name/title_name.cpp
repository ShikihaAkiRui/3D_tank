#include "title_name.h"

const int CTitleName::m_label_size = 80;
const int CTitleName::m_edge_bold = 2;
const aqua::CColor CTitleName::m_label_color = 0xffffffff;

//コンストラクタ
CTitleName::CTitleName(aqua::IGameObject* parent)
	:IUIComponent(parent,"TitleName")
{
}

//初期化
void CTitleName::Initialize(const aqua::CVector2& position)
{
	m_Label.Create(m_label_size,m_edge_bold);
	m_Label.text = "タイトル";
	m_Label.color = m_label_color;
}

//描画
void CTitleName::Draw(void)
{
	m_Label.Draw();
}

//解放
void CTitleName::Finalize(void)
{
	m_Label.Delete();
}