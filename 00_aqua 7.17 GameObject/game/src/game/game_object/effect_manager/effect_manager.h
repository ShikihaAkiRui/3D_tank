#pragma once

#include"aqua.h"
#include"effect/effect_id.h"

//エフェクトマネージャー
class CEffectManager
{
public:
	//インスタンスを取得
	static CEffectManager& GetInstance(void);

	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);

	//生成
	void Create(EFFECT_ID id, const aqua::CVector3 position);

private:
	CEffectManager() = default;
	CEffectManager(const CEffectManager& rhs);
	~CEffectManager() = default;
	CEffectManager& operator=(const CEffectManager& rhs);

	aqua::IGameObject m_GameObject;	//リスト
};