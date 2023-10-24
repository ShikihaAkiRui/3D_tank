#pragma once

#include"../ui_component.h"

//体力
class CLife : public IUIComponent
{
public:
	//コンストラクタ
	CLife(aqua::IGameObject* parent);
	//デストラクタ
	~CLife() = default;

	//初期化
	//位置
	void Initialize(const aqua::CVector2& position);
	//更新
	void Update(void)override;
	//描画
	void Draw(void)override;
	//解放
	void Finalize(void)override;

	//体力を減らす
	//減らす数
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
