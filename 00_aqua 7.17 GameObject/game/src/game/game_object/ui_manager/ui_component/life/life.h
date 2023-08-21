#pragma once

#include"../ui_component.h"

//体力
class CLife : public IUIComponent
{
public:
	CLife(aqua::IGameObject* parent);
	~CLife() = default;

	void Initialize(const aqua::CVector2& position);
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;

	//体力を減らす
	void Reduce(int life);

	//現在の体力を取得
	int GetLife(void);

private:
	aqua::CSprite* m_Sprites;	//画像
	int m_Life;					//体力を取得
	int m_ShowLife;				//表示する体力
	aqua::CTimer m_DisappearTimer;//消す時間
	bool m_DisappearFlag;		//消すフラグ

	static const int m_default_life;//初期体力
	static const int m_min_life;	//体力最小値
	static const int m_life_width;	//ライフひとつの幅
	static const float m_disappear_time;	//消す時間
	static const float m_max_alpha;	//アルファ値最大
};
