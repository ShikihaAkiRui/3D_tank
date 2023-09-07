#pragma once

#include"../character/character.h"

//プレイヤークラス
class CPlayer : public ICharacter
{
public:
	CPlayer(aqua::IGameObject* parent);
	CPlayer() = default;

	void Initialize(void);

	void Update(void);

private:
	//移動
	void Move(void)override;

	//主砲回転
	void GunRotation(void);

	//弾で攻撃
	void Shot(void);

	//敵と衝突した
	void HitEnemyBody(void);

	//攻撃が当たった
	void HitAttack(void)override;

	//倒された
	void Dead(void)override;

	//アイテムに当たった
	void HitItem(void)override;

	//無敵時間のカウント
	void CountDamageInterval(void);

	float m_Angle;				//角度
	aqua::CMatrix m_Matrix;		//行列
	bool m_DamageFlag;			//ダメージのフラグ
	aqua::CTimer m_DamageIntervalTimer;//無敵時間のタイマー
	aqua::CTimer m_ShotBulletTimer;	   //射撃間隔
	bool m_FirstShotFlag;		//最初の攻撃をしたかのフラグ
	aqua::CVector3 m_BodyLine;	//衝突の判定

	static const aqua::CVector3 m_default_position;	//初期位置
	static const aqua::CVector3 m_scale;		//拡大率
	static const int m_life;					//体力
	static const float m_move_speed;			//速度
	static const float m_ray_langth;			//レイ長さ
	static const float m_rotation_speed;		//回転速さ
	static const float m_shot_rotation_speed;	//弾を撃った時の回転速さ
	static const aqua::CVector3 m_graund_ray_langth;	//床用のレイの長さ
	static const float m_damage_interval_time;	//無敵時間
	static const float m_shot_bullet_time;		//射撃間隔
	static const int m_tank_tower_frame;		//戦車の主砲のフレーム番号
	static const aqua::CVector3 m_tank_tower_height;	//戦車の主砲の位置
};