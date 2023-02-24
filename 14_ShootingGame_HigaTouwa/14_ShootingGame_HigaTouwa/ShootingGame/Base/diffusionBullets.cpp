#include "diffusionBullets.h"
#include"DxLib.h"
#define _USE_MATH_DEFINES
#include"math.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

diffusionBullets::diffusionBullets(T_Location location, T_Location speed)
	:BulletsBase(location, 5.f, 1, speed)
{
	px = player->GetLocation().x;
	py = player->GetLocation().y;
}
void  diffusionBullets::Update()
{
	trad = atan2(py - GetLocation().y, px - GetLocation().x);
}
void  diffusionBullets::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 255, 0));

}

bool diffusionBullets::isScreebOut()
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