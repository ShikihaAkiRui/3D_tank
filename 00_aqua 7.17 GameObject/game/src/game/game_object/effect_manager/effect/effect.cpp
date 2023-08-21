#include "effect.h"

const std::string IEffect::m_object_category = "Effect";

//コンストラクタ
IEffect::IEffect(aqua::IGameObject* parent, const std::string& object_name)
	:aqua::IGameObject(parent, object_name, m_object_category)
	, m_Position(aqua::CVector3::ZERO)
{
}

//初期化
void IEffect::Initialize(const aqua::CVector3& position)
{
	m_Position = position;
}

//初期化
void IEffect::Initialize(void)
{
}
