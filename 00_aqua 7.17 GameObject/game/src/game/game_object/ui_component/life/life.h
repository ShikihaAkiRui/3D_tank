#pragma once

#include"../ui_component.h"

//�̗�
class CLife : public IUIComponent
{
public:
	CLife(aqua::IGameObject* parent);
	~CLife() = default;

	void Initialize(const aqua::CVector2& position,int life);
	void Draw(void)override;
	void Finalize(void)override;

	//�̗͂����炷
	void Reduce(int life);

	//���݂̗̑͂��擾
	int GetLife(void);

private:
	aqua::CSprite* m_Sprites;	//�摜
	int m_Life;					//�̗͂��擾
	int m_DefaultLife;			//�̗͏����l

	static const int m_min_life;	//�̗͍ŏ��l
	static const int m_life_width;	//���C�t�ЂƂ̕�
};
