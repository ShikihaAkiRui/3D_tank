#pragma once

#include"aqua.h"

//エネミーークラス
class IEnemy : public aqua::IGameObject
{
public:
	IEnemy(aqua::IGameObject* parent, const std::string& object_name);
	~IEnemy() = default;

	virtual void Initialize(std::string file_name);
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

};