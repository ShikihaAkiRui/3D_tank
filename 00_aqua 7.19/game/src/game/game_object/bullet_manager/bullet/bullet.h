#pragma once
#include"aqua.h"
#include"../../unit_manager/unit_id.h"

//弾クラス
class IBullet : public aqua::IGameObject
{
public:
	//コンストラクタ
	IBullet(aqua::IGameObject* parent,const std::string& object_name);
	//デストラクタ
	~IBullet() = default;

	//初期化
	//ファイル名
	virtual void Initialize(const std::string& file_name);
	//更新
	virtual void Update(void)override;
	//描画
	virtual void Draw(void)override;
	//解放
	virtual void Finalize(void)override;

	//キャラクターに当たった
	virtual void HitCharacter(void);

	//中心位置取得
	aqua::CVector3 GetCenterPosition(void);
	//半径取得
	float GetRadius(void);
	//カテゴリー取得
	UNIT_CATEGORY GetCategory(void);

protected:
	aqua::CModel m_Model;			//モデル
	aqua::CVector3 m_Position;		//位置
	aqua::CVector3 m_Velocity;		//速度
	float m_Radius;					//半径
	UNIT_CATEGORY  m_UnitCategory;	//出したユニットのカテゴリー

private:
	//床の当たり判定
	void CheckGraund(void);

	//表示範囲の判定
	void CheckRange(void);

	static const aqua::CVector3 m_default_direction;//動く方向
	static const aqua::CVector3 m_min_range;		//最小範囲
	static const aqua::CVector3 m_max_range;		//最大範囲

};