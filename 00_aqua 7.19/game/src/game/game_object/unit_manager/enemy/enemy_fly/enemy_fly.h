#pragma once

#include"../enemy.h"
#include"../../player/player.h"

//飛ぶ敵
class CEnemyFly : public IEnemy
{
public:
	//コンストラクタ
	CEnemyFly(aqua::IGameObject* parent);
	//デストラクタ
	~CEnemyFly() = default;

	//初期化
	//位置
	void Initialize(const aqua::CVector3& position)override;
	//更新
	void Update(void)override;

private:
	//移動
	void Move(void)override;

	//弾を撃つ角度を決める
	void ShotAngle(void);

	//プロペラを回転
	void PropellerRotation(void);

	//機体の傾き
	void MoveRotation(void);

	//弾を撃つ
	void Shot(void);

	CPlayer* m_Player;						//プレイヤー
	aqua::CTimer m_ShotTimer;				//撃つ間隔の時間
	aqua::CVector3 m_BulletAngle;			//弾を撃つ角度
	aqua::CVector3 m_PlayerDistance;		//プレイヤーとの距離
	aqua::CTimer m_FlyTimer;				//飛び上がる時間
	float m_DefaultPositionY;				//高さ初期値
	float m_MoveAngle;						//移動時の回転
	bool m_HoveringFlag;					//ホバリングフラグ
	float m_PropellerAngle;					//プロペラの角度

	static const aqua::CVector3 m_scale;			//拡大率
	static const float m_graund_ray_langth;			//床用のレイの長さ
	static const int m_life;						//体力
	static const float m_move_speed;				//移動速度
	static const float m_stop_distance;				//止まる距離
	static const float m_back_distance;				//下がる距離
	static const float m_shot_length;				//撃つ距離
	static const float m_shot_time;					//撃つ感覚の時間
	static const float m_max_fly_height;			//最高高度
	static const float m_fly_speed;					//最高高度までの時間
	static const float m_max_front_angle;			//前方向の最大角度
	static const float m_max_back_angle;			//後ろ方向の最大角度
	static const float m_move_angle_speed;			//回転速度

	static const float m_propeller_angle_speed;		//プロペラの回転速度
	static const float m_main_propeller_angle;		//メインプロペラのx軸の角度
	static const aqua::CVector3 m_main_propeller_position;	//メインプロペラのローカル座標
	static const int m_main_propeller_frame;		//メインプロペラのフレーム番号
	static const aqua::CVector3 m_back_propeller_position;	//後ろのプロペラのローカル座標
	static const int m_back_propeller_frame;		//後ろのプロペラのフレーム番号
};