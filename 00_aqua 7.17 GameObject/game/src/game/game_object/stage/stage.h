#pragma once

#include"aqua.h"

//�X�e�[�W�N���X
class CStage : public aqua::IGameObject
{
public:
	CStage(aqua::IGameObject* parent);
	~CStage() = default;

	void Initialize(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;

private:

	aqua::CSprite m_BackSprite;		//�w�i

	static const std::string m_object_name;		//�I�u�W�F�N�g�̖��O
};