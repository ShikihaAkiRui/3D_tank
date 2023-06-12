#pragma once

#include"../character/character.h"
#include"../player/player.h"

//エネミー
class CEnemy : public ICharacter
{
public:
	CEnemy(aqua::IGameObject* parent);
	~CEnemy() = default;

	void Initialize(void) override;
	void Update(void)override;

private:
	//移動
	void Move(void)override;

	//弾を撃つ
	void Shot(void);

	//プレイヤーがいる方向の角度を取得する
	float GetPlayerDirectionAngle(void);

	CPlayer* m_Player;					//プレイヤー
	float m_PlayerDirectionAngle;		//プレイヤーがいる方向の角度
	bool m_ShotFlag;					//攻撃するフラグ
	aqua::CTimer m_ShotTimer;			//撃つ間隔の時間

	static const aqua::CVector3 m_graund_ray_langth;	//床用のレイの長さ
	static const float m_move_speed;					//移動速度
	static const float m_stop_distance;					//止まる距離
	static const float m_shot_time;						//撃つ感覚の時間
};