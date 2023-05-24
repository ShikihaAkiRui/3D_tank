#pragma once

#include"aqua.h"

//ユニットクラス
class IUnit : public ICollision ,public aqua::IGameObject
{
public:
	IUnit(aqua::IGameObject* parent, const std::string& object_name);
	virtual ~IUnit() = default;

	//初期化
	virtual void Initialize(void) = 0;
	virtual void Initialize(const std::string& file_name);

	//更新
	virtual void Update(void);

	//描画
	virtual void Draw(void);

	//解放
	virtual void Finalize(void);

	//レイを出して判定
	bool CollCheckRay(const aqua::CVector3& start_position,const aqua::CVector3& end_position);

	aqua::CModel* GetModel(void);

protected:
	aqua::CModel* m_Model;	//モデル
	
	static const int m_frame_index;			//フレーム番号
	static const aqua::CVector3 m_divnum;	//分割数
};