#pragma once

#include"../effect.h"

//爆発エフェクト
class CGraundHitBulletEffect : public IEffect
{
public:
	CGraundHitBulletEffect(aqua::IGameObject* parent);
	~CGraundHitBulletEffect() = default;

	void Initialize(const aqua::CVector3& position)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;

private:
	aqua::CEffect3D m_Effect;	//エフェクト

	static const aqua::CVector3 m_scale;	//拡大率
};