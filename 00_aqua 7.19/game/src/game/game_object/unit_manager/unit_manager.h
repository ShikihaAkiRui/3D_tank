#pragma once

#include"aqua.h"
#include"../unit/unit.h"
#include"unit_id.h"
#include"player/player.h"


//ユニットマネージャー
class CUnitManager
{
public:
	//インスタンスを取得
	static CUnitManager& GetInstance(void);

	//初期化
	void Initialzie(void);
	//更新
	void Update(void);
	//描画
	void Draw(void);
	//解放
	void Finalize(void);

	//生成
	//ユニットID
	IUnit* Create(UNIT_ID id);

	//敵生成
	//ユニット,	位置
	void CreateEnemy(UNIT_ID id, const aqua::CVector3& position);

	//ユニットの当たり判定
	//オブジェクトの名前,	線の初めの位置,	線の終わりの位置
	bool CheckHitUnit(const std::string& object_name, const aqua::CVector3& start_position, const aqua::CVector3& end_position);

	//照準と敵の判定
	//線の初めの位置,	線の終わりの位置
	aqua::CVector3 CheckHitAim(const aqua::CVector3& start_position, const aqua::CVector3& end_position);

	//プレイヤーと敵の距離取得
	//情報を取得する配列,	敵の最大出現数
	int GetEnemyData(aqua::CVector2* vectors, int max_enemy);

	//全ユニットの状態変更
	//変更する状態
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

	aqua::CModel* m_LoadModel;		//あらかじめ読み込むモデル

	static const std::string m_enemy_name;	//当たる対象の名前
	static const std::string m_player_name;	//プレイヤーの名前
	static const int m_load_model_count;	//読み込むモデルの数
};
