#include "effect.h"

const std::string IEffect::m_object_category = "Effect";

//�R���X�g���N�^
IEffect::IEffect(aqua::IGameObject* parent, const std::string& object_name)
	:aqua::IGameObject(parent, object_name, m_object_category)
	, m_Position(aqua::CVector3::ZERO)
	, m_Scale(aqua::CVector3::ZERO)
{
}

//������
void IEffect::Initialize(const std::string& effect_file, const aqua::CVector3& position, const aqua::CVector3& scale)
{
	m_Effect.Create(effect_file);
	m_Position = position;
	m_Scale = scale;

	m_Effect.position = m_Position;
	m_Effect.scale = m_Scale;
	m_Effect.Play();
}

//�X�V
void IEffect::Update(void)
{
	m_Effect.Update();

	//�G�t�F�N�g���I����������
	if (m_Effect.Finished())
		DeleteObject();
}

//�`��
void IEffect::Draw(void)
{
	m_Effect.Draw();
}

//���
void IEffect::Finalize(void)
{
	m_Effect.Delete();
}