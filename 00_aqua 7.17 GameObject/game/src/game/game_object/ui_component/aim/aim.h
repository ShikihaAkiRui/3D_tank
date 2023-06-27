#pragma once

#include"../ui_component.h"

//照準
class CAim : public IUIComponent
{
public:
	CAim(aqua::IGameObject* parent);
	~CAim() = default;

	//初期化
	void Initialize(void);

	//更新
	void Update(void)override;

	//描画
	void Draw(void)override;

	//解放
	void Finalize(void)override;

private:

};