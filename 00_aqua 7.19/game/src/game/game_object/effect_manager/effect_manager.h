#pragma once

#include"aqua.h"
#include"effect/effect_id.h"

//エフェクトマネージャー
class CEffectManager
{
public:
	//インスタンスを取得
	static CEffectManager& GetInstance(void);

	//初期化
	void Initialize(void);
	//更新
	void Update(void);
	//描画
	void Draw(void);
	//解放
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