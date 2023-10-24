#pragma once

#include"../enemy.h"
#include"../../player/player.h"

//普通のエネミー
class CEnemyParabola : public IEnemy
{
public:
	//コンストラクタ
	CEnemyParabola(aqua::IGameObject* parent);
	//デストラクタ
	~CEnemyParabola() = default;

	//初期化
	//位置
	void Initialize(const aqua::CVector3& position)override;
	//更新
	void Update(void)override;

private:
	//移動
	void Move(void)override;

	//弾を撃つ
	void Shot(void);

	CPlayer* m_Player;						//プレイヤー
	aqua::CVector3 m_Distance;				//プレイヤーとの距離
	aqua::CTimer m_ShotTimer;				//撃つ間隔の時間
	float m_WheelRotationSpeed;				//タイヤの回転速度

	static const aqua::CVector3 m_scale;			//拡大率
	static const float  m_graund_ray_langth;		//床用のレイの長さ
	static const int m_life;						//体力
	static const float m_move_speed;				//移動速度
	static const float m_stop_distance;				//止まる距離
	static const float m_shot_time;					//撃つ感覚の時間
	static const float m_wheel_rotation_speed;		//タイヤの回転速度

};