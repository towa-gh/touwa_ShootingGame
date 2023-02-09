#pragma once
#include "CharaBase.h"
#include"DxLib.h"
//敵の動きをパターン化
struct MoveInfomation
{
	int pattern;//パターン
	T_Location targetLocation;//座標
	int next;//次の座標
	int waitTimeFlame;//立ち止まる時間
	int attackPattern;//攻撃
};

class Enemy : public CharaBase
{
private:
	int hp;
	int point;
	int shotNum;
	int l = 0;
	int current = 0;
	int WaitTime = 0;
	MoveInfomation moveInfo[5];
public:
	Enemy(T_Location location);
public:
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Hit(int damage) override;
	bool HpCheck();
	void InputCSV();
	int  GetPoint();
	void move();
};



