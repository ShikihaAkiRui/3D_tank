#pragma once

#include"aqua.h"

//ユニットクラス
class IUnit : public ICollision ,public aqua::IGameObject
{
public:
	//コンストラクタ
	IUnit(aqua::IGameObject* parent, const std::string& object_name);
	//デストラクタ
	virtual ~IUnit() = default;

	//初期化
	virtual void Initialize(void) = 0;
	//モデルのパス
	virtual void Initialize(const std::string& file_name);
	//更新
	virtual void Update(void);
	//描画
	virtual void Draw(void);
	//解放
	virtual void Finalize(void);

	//モデル取得
	aqua::CModel* GetModel(void);

protected:
	aqua::CModel* m_Model;	//モデル
	
	static const aqua::CVector3 m_divnum;	//分割数
};