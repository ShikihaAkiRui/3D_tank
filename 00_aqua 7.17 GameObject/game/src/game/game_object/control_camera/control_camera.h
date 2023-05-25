#pragma once

#include"aqua.h"
#include"../unit/unit.h"

//�J��������N���X
class CControlCamera : public aqua::IGameObject
{
public:
	CControlCamera(aqua::IGameObject* parent);
	~CControlCamera() = default;

	void Initialize(void)override;	
	
	void Initialize(aqua::CCamera* camera,IUnit* unit);

	void Update(void)override;

private:
	aqua::CCamera* m_Camera;
	IUnit* m_Unit;

	static const aqua::CVector3 m_camera_length;		//�ΏۂƂ̋���
};