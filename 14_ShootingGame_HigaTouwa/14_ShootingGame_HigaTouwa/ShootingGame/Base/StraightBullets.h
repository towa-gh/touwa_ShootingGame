#pragma once
#include "BulletsBase.h"
class StraightBullets :public BulletsBase
{
public:
	StraightBullets(T_Location location, T_Location speed);
public:
	virtual void Update()override;
	virtual void Draw()override;
	virtual bool isScreebOut() override;
};

