#pragma once

#include"../unit/unit.h"

//ステージ
class CStage : public IUnit
{
public:
	CStage(aqua::IGameObject* parent);
	~CStage() = default;

	//初期化
	void Initialize(void)override;
	void Draw(void)override;

	//弾と床の判定
	//弾の中心位置,	弾の半径
	bool GetHitBulletGroundFlag(const aqua::CVector3& center_position,float radius);

	//重力取得
	float GetGravity(void);

	//床の高さを取得
	//線の下の位置,	線の上の位置
	float GetGraundHeight(const aqua::CVector3& min_height_position, const aqua::CVector3& max_height_position);

	//照準と床の判定
	//線の始まりの位置,	線の終わりの位置
	aqua::CVector3 CheckHitAim(const aqua::CVector3& start_position, const aqua::CVector3& end_position);

	//壁の判定
	//位置
	bool GetHitWall(const aqua::CVector3& position);

private:

	aqua::CBoxPrimitive m_BackgroundPanel;	//背景

	static const aqua::CVector3 m_position;	//位置
	static const aqua::CVector3 m_scale;	//拡大率
	static const float m_gravity;			//重力
	static const float m_not_hit_height;	//当たらなかったときに返す値
	static const aqua::CVector3 m_min_wall_position;	//最小の壁の位置
	static const aqua::CVector3 m_max_wall_position;	//最大の壁の位置
	static const aqua::CColor m_background_color;		//背景

};