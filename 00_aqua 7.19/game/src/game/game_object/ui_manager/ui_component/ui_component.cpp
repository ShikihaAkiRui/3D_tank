#include "ui_component.h"

const std::string IUIComponent::m_object_category = "UIComponent";

//コンストラクタ
IUIComponent::IUIComponent(aqua::IGameObject* parent,const std::string& object_name)
	:aqua::IGameObject(parent,object_name,m_object_category)
	,m_Position(aqua::CVector2::ZERO)
{
}

//初期化
void IUIComponent::Initialize(const aqua::CVector2& position)
{
	m_Position = position;
}
