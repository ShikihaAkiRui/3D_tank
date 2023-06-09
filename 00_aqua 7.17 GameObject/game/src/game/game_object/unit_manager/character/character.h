#pragma once

#include"../../unit/unit.h"
#include"../unit_id.h"

//キャラクタークラス
class ICharacter : public IUnit
{
public:
	ICharacter(aqua::IGameObject* parent,const std::string& object_name);
	virtual ~ICharacter() = default;

	virtual void Initialize(const std::string& file_name)override;

	virtual void Update(void)override;

	virtual void Draw(void) override;

	//ユニットのカテゴリーを取得
	UNIT_CATEGORY GetUnitCategory(void);

protected:
	aqua::CVector3 m_Position;			//位置	
	aqua::CVector3 m_GraundRayLength;	//床へのレイ長さ
	aqua::CVector3 m_Velocity;			//速度
	aqua::CVector3 m_Rotation;			//回転
	UNIT_CATEGORY m_UnitCategory;		//ユニットのカテゴリー

	//移動
	virtual void Move(void);

	//攻撃が当たった
	virtual void HitAttack(void);

private:
	//床の判定
	void CheckGround(void);

	//弾の判定
	bool CheckHitBullet(void);

	static const aqua::CVector3 m_default_position;				//デフォルトの位置
	static const aqua::CVector3 m_default_graund_ray_length;	//デフォルトの床へのレイの長さ
	static const aqua::CVector3 m_model_right_vector;			//右向きのベクトル
};