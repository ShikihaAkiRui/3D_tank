#pragma once

#include"../ui_component.h"

//クリックメッセージフラグ
class CClickMessage : public IUIComponent
{
public:
	//コンストラクタ
	CClickMessage(aqua::IGameObject* parent);
	//デストラクタ
	~CClickMessage() = default;

	//初期化
	//位置,	文字
	void Initialize(const aqua::CVector2& position, const std::string word);
	//更新
	void Update(void)override;
	//描画
	void Draw(void)override;
	//解放
	void Finalize(void)override;

private:
	aqua::CLabel m_Label;	    //メッセージ
	float m_AlphaAngle;			//アルファ値アングル

	static const float m_label_angle_speed;	//アルファ値の速度
	static const float m_max_alpha;			//アルファ値最大
	static const int m_size;				//大きさ
	static const int m_edge_size;			//端大きさ

};