#include"Enemy.h"
#include"DxLib.h"
#include"KeyManager.h"
#include"StraightBullets.h"
#include"RotateBullet.h"

//�ړ�������W
T_Location locations[4] = {
	{640, -20},
	{640,100},
	{1040,100},
	{240,100},
};

Enemy::Enemy(T_Location location) : CharaBase(location, 20.f, T_Location{ 1,1 }), hp(10), point(10), shotNum(0)
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
	if (l < 4) {
		//��������W�ƍs���������W�̈ʒu�������Ă����玟�̔z�������
		if (GetLocation().x == locations[l].x && GetLocation().y == locations[l].y)
		{
			l++;
		}
		else {
			//�ŏ��̉�ʊO����o�Ă��鏈��
			if (GetLocation().y != locations[l].y)
			{
				//���ɉ����鏈��
				if (GetLocation().y < locations[l].y) {

					newLocation.y += speed.y;
					SetLocation(newLocation);
				}
				//��ɏオ�鏈��
				else if (GetLocation().y > locations[l].y)
				{
					newLocation.y -= speed.y;
					SetLocation(newLocation);
				}
			}
			//���ړ�����
			if (GetLocation().x != locations[l].x)
			{
				//�E�ɍs������
				if (GetLocation().x < locations[l].x) {

					newLocation.x += speed.x;
					SetLocation(newLocation);
				}
				//���ɍs������
				else if (GetLocation().x > locations[l].x)
				{
					newLocation.x -= speed.x;
					SetLocation(newLocation);
				}
			}
			//�����_������Ă�����ړI�n�̍��WXY�������Ē���
			if (GetLocation().x > locations[l].x) {
				newLocation.x = locations[l].x;
			}
			if (GetLocation().y > locations[l].y) {
				newLocation.y = locations[l].y;
			}
		}
	}
	else//�R�ɂ�����Q��������
	{
		l = 2;
	}
	//T_Location newLocation = GetLocation();
	//newLocation.y += speed.y;
	//SetLocation(newLocation);

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
	//��ʂɍs������e������


	if (bulletCount < 30 && bullets[bulletCount] == nullptr)
	{
		bullets[bulletCount] = new RotateBullet(GetLocation(), 2.f, (20 * shotNum));
		shotNum++;
		//bullets[bulletCount] = new StraightBullets(GetLocation(),T_Location { 0, 2 });
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
