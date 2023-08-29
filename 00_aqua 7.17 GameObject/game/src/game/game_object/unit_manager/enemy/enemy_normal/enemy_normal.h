#pragma once

#include"../enemy.h"
#include"../../player/player.h"

//普通のエネミー
class CEnemyNormal : public IEnemy
{
public:
	CEnemyNormal(aqua::IGameObject* parent);
	~CEnemyNormal() = default;

	//初期化
	//位置
	void Initialize(const aqua::CVector3& position)override;
	void Update(void)override;

private:
	//移動
	void Move(void)override;

	//弾を撃つ
	void Shot(void);

	CPlayer* m_Player;						//プレイヤー
	aqua::CTimer m_ShotTimer;				//撃つ間隔の時間
	aqua::CVector3 m_PlayerDistance;		//プレイヤーとの距離

	static const aqua::CVector3 m_scale;			//拡大率
	static const float  m_graund_ray_langth;		//床用のレイの長さ
	static const int m_life;						//体力
	static const float m_move_speed;				//移動速度
	static const float m_stop_distance;				//止まる距離
	static const float m_back_distance;				//下がる距離
	static const float m_shot_length;				//撃つ距離
	static const float m_shot_time;					//撃つ感覚の時間

};