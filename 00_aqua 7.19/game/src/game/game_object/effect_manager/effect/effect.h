#pragma once

#include"aqua.h"

//�G�t�F�N�g
class IEffect : public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	IEffect(aqua::IGameObject* parent, const std::string& object_name);
	//�f�X�g���N�^
	~IEffect() = default;

	//������
	//�ʒu
	virtual void Initialize(const aqua::CVector3& position) {};
	//�G�t�F�N�g�t�@�C����,	�ʒu,	�g�嗦
	void Initialize(const std::string& effect_file, const aqua::CVector3& position, const aqua::CVector3& scale);
	//�X�V
	void Update(void)override;
	//�`��
	void Draw(void)override;
	//���
	void Finalize(void)override;

protected:
	aqua::CEffect3D m_Effect;	//�G�t�F�N�g
	aqua::CVector3 m_Position;	//�ʒu
	aqua::CVector3 m_Scale;		//�g�嗦

private:
	void Initialize(void)override {};

	static const std::string m_object_category;	//�J�e�S���[
};