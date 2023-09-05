#pragma once

#include"aqua.h"

//エフェクト
class IEffect : public aqua::IGameObject
{
public:
	IEffect(aqua::IGameObject* parent, const std::string& object_name);
	~IEffect() = default;

	//初期化
	//位置
	virtual void Initialize(const aqua::CVector3& position) {};
	//エフェクトファイル名,	位置,	拡大率
	void Initialize(const std::string& effect_file, const aqua::CVector3& position, const aqua::CVector3& scale);
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;

protected:
	aqua::CEffect3D m_Effect;	//エフェクト
	aqua::CVector3 m_Position;	//位置
	aqua::CVector3 m_Scale;		//拡大率

private:
	void Initialize(void)override {};

	static const std::string m_object_category;	//カテゴリー
};