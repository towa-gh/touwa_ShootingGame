#include"Enemy.h"
#include"DxLib.h"
#include"KeyManager.h"
#include"StraightBullets.h"
#include"RotateBullet.h"

//�G�̓������p�^�[����
struct MoveInfomation
{
	int pattern;//�p�^�[��
	T_Location targetLocation;//���W
	int next;//���̍��W
	int waitTimeFlame;//�����~�܂鎞��
	int attackPattern;//�U��
};

MoveInfomation moveInfo[5] = {
	//{ 0,    640, 150, 1,   0, 0},
	//{ 0, 1200.4, 150, 2,   0, 2},
	//{ 1,      0,   0, 3, 300, 1},
	//{ 0,   80.2, 150, 4,   0, 2},
	//{ 1,      0,   0, 1, 300, 1},
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
int WaitTime = 0;

void InputCSV()
{
	FILE* fp;//FILE�^�\����
	errno_t error;//fopen_s�̃G���[�m�F

	error = fopen_s(&fp, "ShootingGame/Enemy/MoveEnemy.csv", "r");
	if (error != 0)
	{
		//�G���[����
		return;
	}
	else
	{
		//�t�@�C�����J����
		char line[100];
		for (int i = 0; fgets(line, 100, fp) != NULL; i++)
		{
			sscanf_s(line, "%d, %f, %f, %d, %d, %d",
				&moveInfo[i].pattern,
				&moveInfo[i].targetLocation.x,
				&moveInfo[i].targetLocation.y,
				&moveInfo[i].next,
				&moveInfo[i].waitTimeFlame,
				&moveInfo[i].attackPattern);
		}
		return;
	}
	fclose(fp);//�t�@�C�������
}

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
	InputCSV();
	switch (moveInfo[current].pattern)
	{
	case 0:
		move();
		break;

	case 1:
		WaitTime++;
		if (moveInfo[current].waitTimeFlame <= WaitTime)
		{
			WaitTime = 0;
			current = moveInfo[current].next;
		}
		break;

	default:
		break;
	}

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

	if (moveInfo[current].attackPattern != 0)
	{
		if (bulletCount < 30 && bullets[bulletCount] == nullptr)
		{
			if (moveInfo[current].attackPattern == 1)
			{
				bullets[bulletCount] = new StraightBullets(GetLocation(), T_Location{ 0,2 });
			}
			else if (moveInfo[current].attackPattern == 2)
			{
				shotNum++;
				bullets[bulletCount] = new RotateBullet(GetLocation(), 2.f, (20 * shotNum));
			}
		}
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
	if ((newLocation.x == moveInfo[current].targetLocation.x) &&
		(newLocation.y == moveInfo[current].targetLocation.y))
	{
		current = moveInfo[current].next;
	}
	//XY�̂ǂ��炩�����ǂ蒅���ĂȂ������Ƃ�
	else
	{
		//Y�����ǂ蒅���ĂȂ������ꍇ
		if (newLocation.y != moveInfo[current].targetLocation.y)
		{
			//������Y���W��莟��Y���W���傫���Ƃ�
			if (newLocation.y < moveInfo[current].targetLocation.y)
			{
				newLocation.y += speed.y;
				//�ړ��������ƂɖړI�n���щz�����Ƃ��ړI�n��������
				if ((GetLocation().y <= moveInfo[current].targetLocation.y) && (moveInfo[current].targetLocation.y <= newLocation.y))
				{
					newLocation.y = moveInfo[current].targetLocation.y;
				}
			}
			//������Y���W��莟��Y���W���������Ƃ�
			else {
				newLocation.y -= speed.y;
				//�ړ��������ƂɖړI�n���щz�����Ƃ��ړI�n��������
				if ((newLocation.y <= moveInfo[current].targetLocation.y) && (newLocation.y <= GetLocation().y))
				{
					newLocation.y = moveInfo[current].targetLocation.y;
				}
			}
		}
		//X�����ǂ蒅���ĂȂ������ꍇ
		if (newLocation.x != moveInfo[current].targetLocation.x)
		{
			//������Y���W��莟��Y���W���傫���Ƃ�
			if (newLocation.x < moveInfo[current].targetLocation.x)
			{
				newLocation.x += speed.x;
				//�ړ��������ƂɖړI�n���щz�����Ƃ��ړI�n��������
				if ((GetLocation().x <= moveInfo[current].targetLocation.x) && (moveInfo[current].targetLocation.x <= newLocation.x))
				{
					newLocation.x = moveInfo[current].targetLocation.x;
				}
			}
			//������Y���W��莟��Y���W���������Ƃ�
			else
			{
				newLocation.x -= speed.x;
				//�ړ��������ƂɖړI�n���щz�����Ƃ��ړI�n��������
				if ((GetLocation().x <= moveInfo[current].targetLocation.x) && (moveInfo[current].targetLocation.x <= newLocation.x))
				{
					newLocation.x = moveInfo[current].targetLocation.x;
				}
			}
		}
	}

	//�ړ��̍X�V
	SetLocation(newLocation);

}
