#pragma once

#include"aqua.h"

//UI�N���X
class IUIComponent : public aqua::IGameObject
{
public:
	IUIComponent(aqua::IGameObject* parent,const std::string& object_name);
	~IUIComponent() = default;

	virtual void Initialize(void) {};
	//�ʒu
	virtual void Initialize(const aqua::CVector2& position);

protected:
	aqua::CVector2 m_Position;	//�ʒu
	
private:
	static const std::string m_object_category;		//�I�u�W�F�N�g�̃J�e�S���[
};