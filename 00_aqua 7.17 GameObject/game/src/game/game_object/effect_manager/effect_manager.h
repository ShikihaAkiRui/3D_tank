#pragma once

#include"aqua.h"
#include"effect/effect_id.h"

//�G�t�F�N�g�}�l�[�W���[
class CEffectManager
{
public:
	//�C���X�^���X���擾
	static CEffectManager& GetInstance(void);

	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);

	//����
	void Create(EFFECT_ID id, const aqua::CVector3 position);

private:
	CEffectManager() = default;
	CEffectManager(const CEffectManager& rhs);
	~CEffectManager() = default;
	CEffectManager& operator=(const CEffectManager& rhs);

	aqua::IGameObject m_GameObject;	//���X�g
};