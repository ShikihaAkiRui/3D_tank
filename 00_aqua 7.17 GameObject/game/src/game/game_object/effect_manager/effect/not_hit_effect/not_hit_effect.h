#pragma once

#include"../effect.h"

//弾が当たらなかったときのエフェクト
class CNotHitEffect : public IEffect
{
public:
	CNotHitEffect(aqua::IGameObject* parent);
	~CNotHitEffect() = default;

	//初期化
	//位置
	void Initialize(const aqua::CVector3& position)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;

private:
	static const aqua::CVector3 m_scale;	//拡大率
};