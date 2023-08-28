#pragma once

#include"../ui_component.h"

//タイトル名前
class CTitleName : public IUIComponent
{
public:
	CTitleName(aqua::IGameObject* parent);
	~CTitleName() = default;

	//初期化
	//位置
	void Initialize(const aqua::CVector2& position);
	void Draw(void)override;
	void Finalize(void)override;

private:
	aqua::CLabel m_Label;	//タイトル名前

	static const int m_label_size;			//ラベル大きさ
	static const int m_edge_bold;			//端の太さ
	static const aqua::CColor m_label_color;//ラベル色
};