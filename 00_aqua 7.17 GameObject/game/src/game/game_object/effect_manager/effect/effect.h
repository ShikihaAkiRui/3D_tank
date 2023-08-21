#pragma once

#include"aqua.h"

//�G�t�F�N�g
class IEffect : public aqua::IGameObject
{
public:
	IEffect(aqua::IGameObject* parent, const std::string& object_name);
	~IEffect() = default;

	virtual void Initialize(const aqua::CVector3& position);

protected:
	aqua::CVector3 m_Position;	//�ʒu

private:
	void Initialize(void)override;

	static const std::string m_object_category;	//�J�e�S���[
};