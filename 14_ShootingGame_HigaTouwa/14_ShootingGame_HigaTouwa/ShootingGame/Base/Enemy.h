#pragma once
#include "CharaBase.h"
#include"DxLib.h"
//�G�̓������p�^�[����
struct MoveInfomation
{
	int pattern;//�p�^�[��
	T_Location targetLocation;//���W
	int next;//���̍��W
	int waitTimeFlame;//�����~�܂鎞��
	int attackPattern;//�U��
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



