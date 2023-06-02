#include "unit.h"

const int IUnit::m_frame_index = -1;
const aqua::CVector3 IUnit::m_divnum = aqua::CVector3(4.0f, 4.0f, 4.0f);

//コンストラクタ
IUnit::IUnit(aqua::IGameObject* parent, const std::string& object_name)
	:aqua::IGameObject(parent, object_name)
{
}

//初期化
void IUnit::Initialize(const std::string& file_name)
{
	m_Model = AQUA_NEW aqua::CModel;

	m_Model->Load(file_name);

	SetupCollInfo(m_Model, m_frame_index, (int)m_divnum.x, (int)m_divnum.y, (int)m_divnum.z);
}

//更新
void IUnit::Update(void)
{
	RefreshCollInfo(m_frame_index);
}

//描画
void IUnit::Draw(void)
{
	m_Model->Draw();
}

//解放
void IUnit::Finalize(void)
{
	TerminateCollInfo(m_frame_index);
	
	m_Model->Unload();

	AQUA_SAFE_DELETE_ARRAY(m_Model);
	
}

//モデル取得
aqua::CModel* IUnit::GetModel(void)
{
	return m_Model;
}
