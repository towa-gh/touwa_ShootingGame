#include"Enemy.h"
#include"DxLib.h"
#include"KeyManager.h"
//#include"BulletsBase.h"
#include"StraightBullets.h"

Enemy::Enemy(T_Location location) : CharaBase(location, 20.f, T_Location{ 0,0.5 }), hp(10), point(10)
{
	//BulletsBase** bullets;
	bullets = new BulletsBase * [30];
	for (int i = 0; i < 30; i++)
	{
		bullets[i] = nullptr;
	}
}

void Enemy::Update()
{
	T_Location newLocation = GetLocation();
	newLocation.y += speed.y;
	SetLocation(newLocation);

	int bulletCount;
	for (bulletCount = 0; bulletCount < 30; bulletCount++)
	{
		if (bullets[bulletCount] == nullptr)
		{
			break;
		}
		bullets[bulletCount]->Update();


		if (bullets[bulletCount]->isScreebOut())
		{
			DeleteBullet(bulletCount);
			bulletCount--;
		}
	}
	//âÊñ Ç…çsÇ¡ÇΩÇÁíeÇè¡Ç∑


	if (bulletCount < 30 && bullets[bulletCount] == nullptr)
	{
		bullets[bulletCount] = new StraightBullets(GetLocation(),T_Location { 0, 2 });
	}
}
void Enemy::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 0, 0));

	for (int bulletCount = 0; bulletCount < 30; bulletCount++)
	{
		if (bullets[bulletCount] == nullptr)
		{
			break;
		}
		bullets[bulletCount]->Draw();
	}
}
void Enemy::Hit(int damage)
{
	if (0 < damage)
	{
		hp -= damage;
		if (hp < 0)
		{
			hp = 0;
		}
	}
}
bool Enemy::HpCheck()
{
	bool ret = (hp <= 0);
	return ret;
}
int  Enemy::GetPoint()
{
	return point;
}
