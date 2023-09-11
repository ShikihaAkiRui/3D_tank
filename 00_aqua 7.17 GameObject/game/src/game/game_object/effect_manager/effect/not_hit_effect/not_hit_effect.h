#pragma once

#include"../effect.h"

//弾が当たらなかったときのエフェクト
class CNotHitEffect : public IEffect
{
public:
	//コンストラクタ
	CNotHitEffect(aqua::IGameObject* parent);
	//デストラクタ
	~CNotHitEffect() = default;

	//初期化
	//位置
	void Initialize(const aqua::CVector3& position)override;

private:
	static const aqua::CVector3 m_scale;	//拡大率
};