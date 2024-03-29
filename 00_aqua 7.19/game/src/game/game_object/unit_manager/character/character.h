#pragma once

#include"../../unit/unit.h"
#include"../unit_id.h"

//キャラクタークラス
class ICharacter : public IUnit
{
public:
	//コンストラクタ
	ICharacter(aqua::IGameObject* parent,const std::string& object_name);
	//デストラクタ
	virtual ~ICharacter() = default;

	//初期化
	//モデルのパス
	virtual void Initialize(const std::string& file_name)override;
	//更新
	virtual void Update(void)override;

	//ユニットのカテゴリーを取得
	UNIT_CATEGORY GetUnitCategory(void);

protected:
	aqua::CVector3 m_Position;			//位置	
	aqua::CVector3 m_GraundRayLength;	//床へのレイ長さ
	aqua::CVector3 m_Velocity;			//速度
	aqua::CVector3 m_Rotation;			//回転
	UNIT_CATEGORY m_UnitCategory;		//ユニットのカテゴリー
	int m_Life;							//体力
	bool m_GraundFlag;					//床についているか


	//移動
	virtual void Move(void);

	//攻撃が当たった
	virtual void HitAttack(void);

	//倒された
	virtual void Dead(void);

	//アイテムが当たった
	virtual void HitItem(void);

	//タイヤの回転
	//回転速度
	virtual void WheelRotation(float rotation_speed);

	//床の判定
	void CheckGround(void);

	//壁の判定
	void CheckWall(void);

	//弾の判定
	bool CheckHitBullet(void);

	//アイテムの判定
	bool CheckHitItem(void);

	static const int m_default_damage;							//デフォルトのダメージ量

private:

	float m_WheelAngle;			//タイヤの角度

	static const aqua::CVector3 m_default_position;				//デフォルトの位置
	static const aqua::CVector3 m_default_graund_ray_length;	//デフォルトの床へのレイの長さ
	static const aqua::CVector3 m_model_right_vector;			//右向きのベクトル
	static const aqua::CVector3 m_tank_wheel_position[];		//タイヤのローカル座標配列
	static const int m_wheel_first_frame;						//一つ目のタイヤのフレーム番号
	static const int m_max_wheel;								//タイヤの数
};