#pragma once

#include"../enemy.h"
#include"../../player/player.h"

//飛ぶ敵
class CEnemyFlight : public IEnemy
{
public:
	CEnemyFlight(aqua::IGameObject* parent);
	~CEnemyFlight() = default;

	void Initialize(const aqua::CVector3 & position)override;

	void Update(void)override;

private:
	//移動
	void Move(void)override;

	//弾を撃つ
	void Shot(void);

	CPlayer* m_Player;						//プレイヤー
	bool m_ShotFlag;						//攻撃するフラグ
	aqua::CTimer m_ShotTimer;				//撃つ間隔の時間

	static const float  m_graund_ray_langth;		//床用のレイの長さ
	static const int m_life;						//体力
	static const float m_move_speed;				//移動速度
	static const float m_homing_angle;				//変える角度
	static const float m_shot_time;					//撃つ感覚の時間
};