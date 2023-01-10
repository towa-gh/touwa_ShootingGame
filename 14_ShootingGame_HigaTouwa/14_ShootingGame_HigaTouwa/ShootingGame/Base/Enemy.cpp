#include"Enemy.h"
#include"DxLib.h"
#include"KeyManager.h"
#include"StraightBullets.h"
#include"RotateBullet.h"

//�G�̓������p�^�[����
struct MoveInfomation
{
	T_Location targetLocation;//���W
	int pattern;//�p�^�[��
	int next;//���̍��W
	int waitTimeFlame;//�����~�܂鎞��
	int attackPattern;//�U��
};

MoveInfomation moveInfo[10] = {
	{640,150,0,1,0,0,},
	{640,100,0,2,0,0,},
	{0,0,1,3,180,1},
	{100,100,1,3,0,0,},
	{0,0,0,1,180,1,},
	{240,100,0,2,180,1,},
};
//�ړ�������W
T_Location locations[4] = {
	{640, -20},
	{640,100},
	{1040,100},
	{240,100},
};

int next[4] = {
	1,
	2,
	3,
	2,
};
int current = 0;

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

	move();

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
void Enemy::move()
{
	//���̍��W���擾
	T_Location newLocation = GetLocation();

	//XY�������W�ɂ�����next�̔z������ƂɎ��̍��W�����߂�
	if ((newLocation.y == locations[current].y) &&
		(newLocation.x == locations[current].x))
	{
		current = next[current];
	}
	//XY�̂ǂ��炩�����ǂ蒅���ĂȂ������Ƃ�
	else
	{
		//Y�����ǂ蒅���ĂȂ������ꍇ
		if (newLocation.y != locations[current].y)
		{
			//������Y���W��莟��Y���W���傫���Ƃ�
			if (newLocation.y < locations[current].y)
			{
				newLocation.y += speed.y;
				//�ړ��������ƂɖړI�n���щz�����Ƃ��ړI�n��������
				if ((GetLocation().y <= locations[current].y) && (locations[current].y <= newLocation.y))
				{
					newLocation.y = locations[current].y;
				}
			}
			//������Y���W��莟��Y���W���������Ƃ�
			else {
				newLocation.y -= speed.y;
				//�ړ��������ƂɖړI�n���щz�����Ƃ��ړI�n��������
				if ((newLocation.y <= locations[current].y) && (newLocation.y <= GetLocation().y))
				{
					newLocation.y = locations[current].y;
				}
			}
		}
		//X�����ǂ蒅���ĂȂ������ꍇ
		if (newLocation.x != locations[current].x)
		{
			//������Y���W��莟��Y���W���傫���Ƃ�
			if (newLocation.x < locations[current].x)
			{
				newLocation.x += speed.x;
				//�ړ��������ƂɖړI�n���щz�����Ƃ��ړI�n��������
				if ((GetLocation().x <= locations[current].x) && (locations[current].x <= newLocation.x))
				{
					newLocation.x = locations[current].x;
				}
			}
			//������Y���W��莟��Y���W���������Ƃ�
			else
			{
				newLocation.x -= speed.x;
				//�ړ��������ƂɖړI�n���щz�����Ƃ��ړI�n��������
				if ((GetLocation().x <= locations[current].x) && (locations[current].x <= newLocation.x))
				{
					newLocation.x = locations[current].x;
				}
			}
		}
	}

	//�ړ��̍X�V
	SetLocation(newLocation);
	//if (l < 4) {
	//	//��������W�ƍs���������W�̈ʒu�������Ă����玟�̔z�������
	//	if (GetLocation().x == locations[l].x && GetLocation().y == locations[l].y)
	//	{
	//		l++;
	//	}
	//	else {
	//		//�ŏ��̉�ʊO����o�Ă��鏈��
	//		if (GetLocation().y != locations[l].y)
	//		{
	//			//���ɉ����鏈��
	//			if (GetLocation().y < locations[l].y) {

	//				newLocation.y += speed.y;
	//				SetLocation(newLocation);
	//			}
	//			//��ɏオ�鏈��
	//			else if (GetLocation().y > locations[l].y)
	//			{
	//				newLocation.y -= speed.y;
	//				SetLocation(newLocation);
	//			}
	//		}
	//		//���ړ�����
	//		if (GetLocation().x != locations[l].x)
	//		{
	//			//�E�ɍs������
	//			if (GetLocation().x < locations[l].x) {

	//				newLocation.x += speed.x;
	//				SetLocation(newLocation);
	//			}
	//			//���ɍs������
	//			else if (GetLocation().x > locations[l].x)
	//			{
	//				newLocation.x -= speed.x;
	//				SetLocation(newLocation);
	//			}
	//		}
	//		//�����_������Ă�����ړI�n�̍��WXY�������Ē���
	//			if (GetLocation().x > locations[l].x) {
	//				newLocation.x = locations[l].x;
	//			}
	//		if (GetLocation().y > locations[l].y) {
	//			newLocation.y = locations[l].y;
	//		}
	//	}
	//}
	//else//�R�ɂ�����Q��������
	//{
	//	l = 2;
	//}

}
