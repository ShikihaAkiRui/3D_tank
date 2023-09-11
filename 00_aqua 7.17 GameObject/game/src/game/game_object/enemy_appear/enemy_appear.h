#pragma once

#include"aqua.h"
#include"../unit_manager/unit_id.h"

//エネミーの出現管理クラス
class CEnemyAppear
{
public:
	//インスタンスを取得
	static CEnemyAppear& GetInstance(void);

	//初期化
	void Initialize(void);
	//更新
	void Update(void);

	//エネミーの数を設定
	void SetCountEnemy(int count);

	//エネミーの最大数取得
	int GetMaxCountEnemy(void);

private:
	//コンストラクタ
	CEnemyAppear(void);
	//コピーコンストラクタ
	CEnemyAppear(const CEnemyAppear& rhs);
	//デストラクタ
	~CEnemyAppear() = default;
	//代入演算子
	CEnemyAppear& operator=(const CEnemyAppear& rhs);

	//出す方法を変える
	void ChangeAppear(void);
	//出す方法１
	void FirstAppear(void);
	//出す方法２
	void SecondAppear(void);

	//出現の状態
	enum class APPEAR_STATE
	{
		FIRST,
		SECOND
	};

	aqua::CTimer m_AppearTimer;		//出現の時間
	float m_AppearTime;				//現在の出現時間
	int m_CountEnemy;				//エネミーの出ている数
	int m_TotalCountEnemy;			//全体のエネミー出現数
	APPEAR_STATE m_AppearState;		//出す状態
	UNIT_ID m_UnitID;				//次ぎだすユニットのID
	bool m_FirstAppearFlag;			//最初の出現フラグ


	static const float m_max_ray_height;	//レイの最大高さ
	static const float m_min_ray_height;	//レイの最小高さ
	static const float m_appear_height;		//出す高さ
	static const int m_max_enemy;			//エネミーの最大数
	static const aqua::CVector2 m_min_appear_area;	//最小出現範囲
	static const aqua::CVector2 m_max_appear_area;	//最大出現範囲
	static const float m_first_appear_time;			//最初の出現時間
	static const float m_default_appear_time;		//初期の出現時間
	static const float m_max_appear_time;			//最速の出現時間
	static const float m_acceleration;				//加速率
	static const int m_second_change_count;			//出す方法を切り替えるタイミング
};