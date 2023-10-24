#pragma once

#include"aqua.h"

//アイテム
class CItem : public aqua::IGameObject
{
public:
	//コンストラクタ
	CItem(aqua::IGameObject* parent);
	//デストラクタ
	~CItem() = default;

	//初期化
	//位置
	void Initialize(const aqua::CVector3& position);
	//更新
	void Update(void)override;
	//描画
	void Draw(void)override;
	//解放
	void Finalize(void)override;

	//キャラクターに当たった
	void HitCharacter(void);

	//中心位置取得
	aqua::CVector3 GetCenterPosition(void);

	//半径取得
	float GetRadius(void);

private:
	//重力
	void Gravity(void);

	aqua::CModel m_Model;		//モデル
	aqua::CVector3 m_Position;	//位置
	bool m_GraundFlag;			//地面についているか
	
	static const std::string m_item_file_names[];	//アイテムのファイル名
	static const int m_max_file;				//ファイル数
	static const aqua::CVector3 m_graund_ray;	//床の判定のレイの大きさ
	static const float m_radius;				//半径
};