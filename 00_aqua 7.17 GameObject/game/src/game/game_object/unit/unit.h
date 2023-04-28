#pragma once

#include"aqua.h"

//ユニットクラス
class IUnit : public ICollision ,public aqua::IGameObject
{
public:
	IUnit(aqua::IGameObject* parent,const std::string& object_name);
	virtual ~IUnit() = default;

	//初期化
	virtual void Initialize(const std::string& file_name);

	//更新
	virtual void Update(void);

	//描画
	virtual void Draw(void);

	//解放
	virtual void Finalize(void);

protected:
	aqua::CModel* m_Model;	//モデル
};