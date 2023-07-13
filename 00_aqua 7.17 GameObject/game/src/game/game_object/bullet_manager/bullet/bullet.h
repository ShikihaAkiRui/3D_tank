#pragma once

#include"../../unit/unit.h"
#include"../../unit_manager/unit_id.h"

//弾クラス
class CBullet : public IUnit
{
public:
	CBullet(aqua::IGameObject* parent);
	~CBullet() = default;

	void Initialize(void)override {};
	void Initialize(UNIT_CATEGORY unit_category, const aqua::CVector3& position, const aqua::CVector3& rotation);
	void Update(void)override;

	//キャラクターに当たった
	void HitCharacter(void);

	//中心位置取得
	aqua::CVector3 GetCenterPosition(void);
	//半径取得
	float GetRadius(void);
	//カテゴリー取得
	UNIT_CATEGORY GetCategory(void);

private:

	//床の当たり判定
	void CheckGraund(void);

	//表示範囲の判定
	void CheckRange(void);
	
	aqua::CVector3 m_Position;		//位置
	aqua::CVector3 m_Velocity;		//速度
	UNIT_CATEGORY  m_UnitCategory;	//出したユニットのカテゴリー

	static const aqua::CVector3 m_direction;	//動く方向
	static const float m_move_speed;			//移動速度
	static const float m_radius;				//半径
	static const aqua::CVector3 m_min_range;	//最小範囲
	static const aqua::CVector3 m_max_range;	//最大範囲

};