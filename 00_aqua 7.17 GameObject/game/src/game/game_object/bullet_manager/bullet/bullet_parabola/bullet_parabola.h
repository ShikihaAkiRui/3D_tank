#pragma once

#include"../bullet.h"

//放物線の弾
class CBulletParabola : public IBullet
{
public:
	//コンストラクタ
	CBulletParabola(aqua::IGameObject* parent);
	//デストラクタ
	~CBulletParabola() = default;

	//初期化
	//ユニットのカテゴリー,	出す位置,　着弾位置
	void Initialize(UNIT_CATEGORY unit_category, const aqua::CVector3& position, const aqua::CVector3& impact_position);
	//更新
	void Update(void)override;

private:
	aqua::CVector3 m_ImpactPosition;	//着弾位置

	static const float m_move_speed;	//初速
	static const float m_fall_speed;	//落ちる速度
	static const float m_max_lenght_angle;	//最大射程になる角度
	static const float m_radius;			//半径

};