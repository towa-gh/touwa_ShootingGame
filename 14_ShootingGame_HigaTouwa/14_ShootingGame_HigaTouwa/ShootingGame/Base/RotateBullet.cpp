#include "RotateBullet.h"
#include"DxLib.h"

#define _USE_MATH_DEFINES
#include"math.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

RotateBullet::RotateBullet(T_Location location, float speed, int degAngle)
	:BulletsBase(location, 5.f, 1, T_Location{0,0})
{
	int deg = degAngle % 360;
	double rad = (M_PI / 180) * deg;
	float x = (abs(deg) == 90 || abs(deg) == 270) ? 0 : cos(rad);
	float y = sin(rad);

	this->speed = T_Location{speed * x,speed * y };
}
void  RotateBullet::Update()
{
	T_Location newLocation = GetLocation();
	newLocation.x += speed.x;
	newLocation.y += speed.y;
	SetLocation(newLocation);

}
void  RotateBullet::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 255, 0));
}

bool RotateBullet::isScreebOut()
{

	bool ret = (GetLocation().y + GetRadius() <= 0);
	if (ret) 
	{
		return ret;
	}
	ret = (SCREEN_HEIGHT <= (GetLocation().y - GetRadius()));
	if (ret)
	{
		return ret;
	}

	ret = ((GetLocation().x + GetRadius()) <= 0);
	if (ret)
	{
		return ret;
	}
	ret = (SCREEN_WIDTH <= (GetLocation().x - GetRadius()));
	return ret;
}