#pragma once

#include"../effect.h"

//プレイヤーに当たったエフェクト
class CHitPlayerEffect : public IEffect
{
public:	
	//コンストラクタ
	CHitPlayerEffect(aqua::IGameObject* parent);
	//デストラクタ
	~CHitPlayerEffect() = default;

	//初期化
	//位置
	void Initialize(const aqua::CVector3& position)override;

private:

	static const aqua::CVector3 m_scale;	//拡大率
};