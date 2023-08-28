#include "radar.h"
#include"../../../enemy_appear/enemy_appear.h"
#include"../../../unit_manager/unit_manager.h"
#include"../../../unit_manager/player/player.h"
#include"../../../control_camera/control_camera.h"

const std::string CRadar::m_find_name = "Enemy";
const float CRadar::m_scale_vector = 0.1f;
const aqua::CVector2 CRadar::m_character_scale = aqua::CVector2(2.0f, 2.0f);

//コンストラクタ
CRadar::CRadar(aqua::IGameObject* parent)
	:IUIComponent(parent,"Radar")
	,m_MaxEnemyCount(0)
	,m_AppearEnemyCount(0)
	,m_CenterPosition(aqua::CVector2::ZERO)
	,m_ShowRadius(0.0f)
{
}

//初期化
void CRadar::Initialize(const aqua::CVector2& position)
{
	IUIComponent::Initialize(position);

	CEnemyAppear* enemy_appear = (CEnemyAppear*)aqua::FindGameObject("EnemyAppear");

	//表示する敵の最大数
	m_MaxEnemyCount = enemy_appear->GetMaxCountEnemy();

	m_AreaSprite.Create("data/texture/radar.png");
	m_AreaSprite.position = m_Position;

	m_CenterPosition = m_Position + aqua::CVector2(m_AreaSprite.GetTextureWidth()/2.0f, m_AreaSprite.GetTextureHeight()/2.0f);

	m_PlayerSprite.Create("data/texture/ball1.png");
	m_PlayerSprite.color = aqua::CColor::BLUE;
	m_PlayerSprite.position = m_CenterPosition - aqua::CVector2(m_PlayerSprite.GetTextureWidth()/2.0f,m_PlayerSprite.GetTextureHeight()/2.0f)* m_character_scale;
	m_PlayerSprite.scale = m_character_scale;

	m_EnemySprites = AQUA_NEW aqua::CSprite[m_MaxEnemyCount];
	m_EnemyVectors = AQUA_NEW aqua::CVector2[m_MaxEnemyCount];

	for (int i = 0; i < m_MaxEnemyCount; ++i)
	{
		m_EnemySprites[i].Create("data/texture/ball1.png");
		m_EnemySprites[i].color = aqua::CColor::RED;
		m_EnemySprites[i].position = m_Position;
		m_EnemySprites[i].scale = m_character_scale;

		m_EnemyVectors[i] = aqua::CVector2::ZERO;
	}
	
}

//更新
void CRadar::Update(void)
{
	//エネミーのデータを得る
	GetEnemyData();

	//表示位置設定
	SetEnemyPosition();

}

//描画
void CRadar::Draw(void)
{
	m_AreaSprite.Draw();
	m_PlayerSprite.Draw();

	//出現数分描画
	for (int i = 0; i < m_AppearEnemyCount; ++i)
		m_EnemySprites[i].Draw();

}

//解放
void CRadar::Finalize(void)
{
	m_AreaSprite.Delete();
	m_PlayerSprite.Delete();

	for (int i = 0; i < m_MaxEnemyCount; ++i)
		m_EnemySprites[i].Delete();

	AQUA_SAFE_DELETE_ARRAY(m_EnemySprites);
	AQUA_SAFE_DELETE_ARRAY(m_EnemyVectors);
}

//エネミーのデータを得る
void CRadar::GetEnemyData(void)
{
	CUnitManager& unit_manager = CUnitManager::GetInstance();

	m_AppearEnemyCount = unit_manager.GetEnemyData(m_EnemyVectors, m_MaxEnemyCount);

}

//表示位置設定
void CRadar::SetEnemyPosition(void)
{
	CControlCamera* camera = (CControlCamera*)aqua::FindGameObject("ControlCamera");
	if (!camera)return;

	aqua::CVector2 vector = aqua::CVector2::ZERO;
	float camera_angle = aqua::DegToRad(-camera->GetAngle().y);

	//表示エリアの半径を求める
	m_ShowRadius = m_AreaSprite.GetTextureWidth() / 2.0f - m_EnemySprites[0].GetTextureWidth()/2.0f;

	//出現している数だけ表示
	for (int i = 0; i < m_AppearEnemyCount; ++i)
	{
		//表示エリアを超えてたら 端に表示
		if (m_EnemyVectors[i].Length() * m_scale_vector > m_ShowRadius)
		{
			float angle = atan2(m_EnemyVectors[i].x, m_EnemyVectors[i].y);

			m_EnemyVectors[i].x = m_ShowRadius * sin(angle);
			m_EnemyVectors[i].y = m_ShowRadius * cos(angle);

			m_EnemyVectors[i] = m_EnemyVectors[i] / m_scale_vector;

		}

		//カメラの方向に合わせる
		vector.x = m_EnemyVectors[i].x * cos(camera_angle) - m_EnemyVectors[i].y * sin(camera_angle);
		vector.y = m_EnemyVectors[i].x * sin(camera_angle) + m_EnemyVectors[i].y * cos(camera_angle);

		//位置設定
		m_EnemySprites[i].position = m_CenterPosition + (vector * m_scale_vector) 
									- aqua::CVector2(m_EnemySprites[i].GetTextureWidth()/2.0f,m_EnemySprites[i].GetTextureHeight()/2.0f) * m_character_scale;
	}
}
