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
	//�G�t�F�N�gID,	�ʒu
	void Create(EFFECT_ID id, const aqua::CVector3 position);

private:
	//�R���X�g���N�^
	CEffectManager() = default;
	//�R�s�[�R���X�g���N�^
	CEffectManager(const CEffectManager& rhs);
	//�f�X�g���N�^
	~CEffectManager() = default;
	//������Z�q
	CEffectManager& operator=(const CEffectManager& rhs);

	aqua::CEffect3D* m_LoadEffect;	//�ǂݍ��ރG�t�F�N�g
	aqua::IGameObject m_GameObject;	//���X�g

	static const std::string m_load_file_name[];	//�ǂݍ��ރt�@�C����
};