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
	aqua::CSprite m_AreaSprite;		//画像
	aqua::CSprite m_PlayerSprite;	//プレイヤーの画像
	aqua::CSprite* m_EnemySprites;	//敵の画像
	int m_MaxEnemyCount;			//エネミーの最大数


};
