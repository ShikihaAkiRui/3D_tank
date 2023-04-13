#pragma once

#include"../enemy.h"

//•’Ê‚Ì“G
class CNormalEnemy : public IEnemy
{
	CNormalEnemy(aqua::IGameObject* parent);
	~CNormalEnemy() = default;

	void Initialize(void);

private:
	static const std::string m_object_name;
};