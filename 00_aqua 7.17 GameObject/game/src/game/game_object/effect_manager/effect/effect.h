#pragma once

#include"aqua.h"

//エフェクト
class IEffect : public aqua::IGameObject
{
public:
	IEffect(aqua::IGameObject* parent, const std::string& object_name);
	~IEffect() = default;

	virtual void Initialize(const aqua::CVector3& position);

protected:
	aqua::CVector3 m_Position;	//位置

private:
	void Initialize(void)override;

	static const std::string m_object_category;	//カテゴリー
};