#pragma once

#include"../ui_component.h"

//ÉåÅ[É_Å[
class CRadar : public IUIComponent
{
public:
	CRadar(aqua::IGameObject* parent);
	~CRadar() = default;

	void Initialize(const aqua::CVector2& position)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;

private:

};