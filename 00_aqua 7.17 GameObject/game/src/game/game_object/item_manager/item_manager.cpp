#include "item_manager.h"
#include"item/item.h"

//�C���X�^���X���擾
CItemManager& CItemManager::GetInstance(void)
{
	static CItemManager instance;

	return instance;
}

//������
void CItemManager::Initialize(void)
{
	m_GameObject.Initialize();
}

//�X�V
void CItemManager::Update(void)
{
	m_GameObject.Update();
}

//�`��
void CItemManager::Draw(void)
{
	m_GameObject.Draw();
}

//���
void CItemManager::Finalize(void)
{
	m_GameObject.Finalize();
}

//����
void CItemManager::Create(aqua::CVector3& position)
{
	CItem* item = aqua::CreateGameObject<CItem>(&m_GameObject);

	if (!item)
		return;

	item->Initialize(position);
}

//�A�C�e���ƃL�����N�^�[�̓����蔻��
bool CItemManager::CheckHitCharacter(ICollision* collision, UNIT_CATEGORY unit_category)
{
	bool hit_flag = false;

	auto it = m_GameObject.GetChildList()->begin();

	while (it != m_GameObject.GetChildList()->end())
	{
		CItem* item = (CItem*)(*it);

		{
			hit_flag = collision->CollCheckSphere(item->GetCenterPosition(), item->GetRadius());

			//����������true
			if (hit_flag && unit_category == UNIT_CATEGORY::PLAYER)
			{
				item->HitCharacter();
				return hit_flag;
			}

		}

		it++;
	}

	//�������ĂȂ��Ȃ�
	return hit_flag;

}

//�R�s�[�R���X�g���N�^
CItemManager::CItemManager(const CItemManager& rhs)
{
	(void)rhs;
}

//������Z�q
CItemManager& CItemManager::operator=(const CItemManager& rhs)
{
	(void)rhs;

	return *this;
}
