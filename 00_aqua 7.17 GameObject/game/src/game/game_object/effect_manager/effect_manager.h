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
	//エフェクトID,	位置
	void Create(EFFECT_ID id, const aqua::CVector3 position);

private:
	//コンストラクタ
	CEffectManager() = default;
	//コピーコンストラクタ
	CEffectManager(const CEffectManager& rhs);
	//デストラクタ
	~CEffectManager() = default;
	//代入演算子
	CEffectManager& operator=(const CEffectManager& rhs);

	aqua::CEffect3D* m_LoadEffect;	//読み込むエフェクト
	aqua::IGameObject m_GameObject;	//リスト

	static const std::string m_load_file_name[];	//読み込むファイル名
};