#pragma once
#include "CharaBase.h"
class Enemy : public CharaBase
{
private:
	int hp;
	int point;
	int shotNum;
	int l = 0;
public:
	Enemy(T_Location location);

public:
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Hit(int damage) override;
	bool HpCheck();
	int  GetPoint();
	void move();

};

