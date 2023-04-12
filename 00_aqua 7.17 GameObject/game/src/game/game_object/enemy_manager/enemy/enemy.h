#pragma once

#include"aqua.h"

//エネミーークラス
class IEnemy : public aqua::IGameObject
{
public:
	IEnemy(aqua::IGameObject* parent, const std::string& object_name);
	~IEnemy() = default;

	virtual void Initialize(const std::string& file_name,const aqua::CVector2& position,const aqua::CVector2 velocity,int& life);
	virtual void Update(void)override;
	virtual void Draw(void)override;
	virtual void Finalize(void)override;

protected:
	aqua::CVector2 m_Position;	//位置
	aqua::CVector2 m_Velocity;	//速度
	int m_Life;					//体力

private:
	//状態
	enum class STATE
	{
		WAIT,		//待機
		MOVE,		//移動
		DEAD		//消える
	};

	//移動
	virtual void Move(void);

	//ダメージを受けた
	void Damage(void);

	//消える
	void Dead(void);

	//攻撃
	virtual void Attack(void);

	STATE m_State;					//状態
	aqua::CSprite m_EnemySprite;	//エネミーのスプライト
	aqua::CTimer m_DeleteTimer;		//消すまでの時間

	static const float m_delete_time;	//消すまでの時間

};