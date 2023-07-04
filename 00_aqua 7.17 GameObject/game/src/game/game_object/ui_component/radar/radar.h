#pragma once

#include"../ui_component.h"

//���[�_�[
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
	aqua::CSprite m_AreaSprite;		//�摜
	aqua::CSprite m_PlayerSprite;	//�v���C���[�̉摜
	aqua::CSprite* m_EnemySprites;	//�G�̉摜
	int m_MaxEnemyCount;			//�G�l�~�[�̍ő吔


};
