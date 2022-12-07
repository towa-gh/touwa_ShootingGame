#pragma once
#include "BulletsBase.h"
class RotateBullet : public BulletsBase
{
private:
	double Angle;
public:
	RotateBullet(T_Location location, float speed, int degAngle);
public:
	virtual void Update()override;
	virtual void Draw()override;
	virtual bool isScreebOut() override;
};

