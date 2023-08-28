#pragma once

#include"aqua.h"

//UIクラス
class IUIComponent : public aqua::IGameObject
{
public:
	IUIComponent(aqua::IGameObject* parent,const std::string& object_name);
	~IUIComponent() = default;

	virtual void Initialize(void) {};
	//位置
	virtual void Initialize(const aqua::CVector2& position);

protected:
	aqua::CVector2 m_Position;	//位置
	
private:
	static const std::string m_object_category;		//オブジェクトのカテゴリー
};