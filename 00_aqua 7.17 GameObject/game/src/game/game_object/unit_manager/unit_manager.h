#pragma once

#include"aqua.h"
#include"../unit/unit.h"
#include"unit_id.h"
#include"player/player.h"


//ユニットマネージャー
class CUnitManager
{
public:
	static CUnitManager& GetInstance(void);

	void Initialzie(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);

	//生成
	IUnit* Create(UNIT_ID id);

	//敵生成
	void CreateEnemy(UNIT_ID id, const aqua::CVector3& position);

	//ユニットの当たり判定
	bool CheckHitUnit(const std::string& object_name, const aqua::CVector3& start_position, const aqua::CVector3& end_position);

	//照準と敵の判定
	aqua::CVector3 CheckHitAim(const aqua::CVector3& start_position, const aqua::CVector3& end_position);

	//プレイヤーと敵の距離取得
	int GetEnemyData(aqua::CVector2* vectors, int max_enemy);

	//全ユニットの状態変更
	void SetGameState(aqua::GAME_OBJECT_STATE state);

	//プレイヤーを取得
	CPlayer* GetPlayer(void);

private:
	//コンストラクタ
	CUnitManager() = default;
	//コピーコンストラクタ
	CUnitManager(const CUnitManager & rhs);
	//デストラクタ
	~CUnitManager() = default;
	//代入演算子
	CUnitManager& operator=(const CUnitManager & rhs);

	aqua::IGameObject m_GameObject;	//ゲームオブジェクト

	static const std::string m_enemy_name;	//当たる対象の名前
	static const std::string m_player_name;	//プレイヤーの名前
};
