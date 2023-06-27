#pragma once

#include"../ui_component.h"

//Æ€
class CAim : public IUIComponent
{
public:
	CAim(aqua::IGameObject* parent);
	~CAim() = default;

	//‰Šú‰»
	void Initialize(void);

	//XV
	void Update(void)override;

	//•`‰æ
	void Draw(void)override;

	//‰ğ•ú
	void Finalize(void)override;

private:

};