#pragma once

#include"../ui_component.h"

//体力
class CLife : public IUIComponent
{
public:
	CLife(aqua::IGameObject* parent);
	~CLife() = default;

	void Initialize(const aqua::CVector2& position,int life);
	void Draw(void)override;
	void Finalize(void)override;

	//体力を減らす
	void Reduce(int life);

	//現在の体力を取得
	int GetLife(void);

private:
	aqua::CSprite* m_Sprites;	//画像
	int m_Life;					//体力を取得
	int m_DefaultLife;			//体力初期値

	static const int m_min_life;	//体力最小値
	static const int m_life_width;	//ライフひとつの幅
};
