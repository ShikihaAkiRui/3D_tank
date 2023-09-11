#pragma once

#include"../effect.h"

//爆発エフェクト
class CExplosionEffect : public IEffect
{
public:
	//コンストラクタ
	CExplosionEffect(aqua::IGameObject* parent);
	//デストラクタ
	~CExplosionEffect() = default;

	//初期化
	//位置
	void Initialize(const aqua::CVector3& position)override;

private:

	static const aqua::CVector3 m_scale;	//拡大率
};