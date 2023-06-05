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

	//中心位置取得
	aqua::CVector3 GetCenterPosition(void);
	//半径取得
	float GetRadius(void);
	//カテゴリー取得
	UNIT_CATEGORY GetCategory(void);

private:
	//敵の当たり判定
	void CheckCharacter(void);

	//床の当たり判定
	void CheckGraund(void);
	
	aqua::CVector3 m_Position;		//位置
	aqua::CVector3 m_Velocity;		//速度
	UNIT_CATEGORY  m_UnitCategory;	//出したユニットのカテゴリー

	static const aqua::CVector3 m_direction;	//動く方向
	static const float m_move_speed;			//移動速度
	static const float m_radius;				//半径
};