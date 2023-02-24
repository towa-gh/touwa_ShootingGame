#pragma once
#include "BulletsBase.h"
#include "Player.h"
class diffusionBullets : public BulletsBase
{
public:
	Player* player;
	int px;
	int py;
	int ShotCount;
	float trad;
public:
	diffusionBullets(T_Location location, T_Location speed = T_Location{ 0,-2 });
public:
	virtual void Update()override;
	virtual void Draw()override;
	virtual bool isScreebOut() override;
};

