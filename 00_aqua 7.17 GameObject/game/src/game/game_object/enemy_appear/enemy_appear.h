#pragma once

#include"aqua.h"

//エネミーの出現管理クラス
class CEnemyAppear : public aqua::IGameObject
{
public:
	CEnemyAppear(aqua::IGameObject* parent);
	~CEnemyAppear() = default;

	void Initialize(void)override;
	void Update(void)override;

	//エネミーの数を設定
	void SetCountEnemy(int count);

	//エネミーの最大数取得
	int GetMaxCountEnemy(void);

private:
	aqua::CTimer m_AppearTimer;		//出現の時間
	int m_CountEnemy;				//エネミーの出ている数

	static const float m_max_ray_height;	//レイの最大高さ
	static const float m_min_ray_height;	//レイの最小高さ
	static const float m_appear_time;		//出現間隔
	static const float m_appear_height;		//出す高さ
	static const int m_max_enemy;			//エネミーの最大数
};