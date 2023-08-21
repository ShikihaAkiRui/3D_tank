#pragma once

#include"../ui_component.h"

//レーダー
class CRadar : public IUIComponent
{
public:
	CRadar(aqua::IGameObject* parent);
	~CRadar() = default;

	void Initialize(const aqua::CVector2& position)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;

private:

	//エネミーのデータを得る
	void GetEnemyData(void);

	//表示位置を設定
	void SetEnemyPosition(void);

	aqua::CSprite m_AreaSprite;		//画像
	aqua::CSprite m_PlayerSprite;	//プレイヤーの画像
	aqua::CSprite* m_EnemySprites;	//敵の画像
	int m_MaxEnemyCount;			//エネミーの最大数
	int m_AppearEnemyCount;			//出ている敵の数
	aqua::CVector2 m_CenterPosition;//中心位置
	aqua::CVector2* m_EnemyVectors;	//敵のベクトルの配列
	float m_ShowRadius;				//出す半径

	static const std::string m_find_name;	//見つける名前
	static const float m_scale_vector;		//ベクトルを縮小
	static const aqua::CVector2 m_character_scale;	//キャラクターの拡大率
};
