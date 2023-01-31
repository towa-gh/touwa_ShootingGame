#include"Enemy.h"
#include"DxLib.h"
#include"KeyManager.h"
#include"StraightBullets.h"
#include"RotateBullet.h"

//敵の動きをパターン化
struct MoveInfomation
{
	int pattern;//パターン
	T_Location targetLocation;//座標
	int next;//次の座標
	int waitTimeFlame;//立ち止まる時間
	int attackPattern;//攻撃
};

MoveInfomation moveInfo[5] = {
	{ 0,    640, 150, 1,   0, 0},
	{ 0, 1200.4, 150, 2,   0, 2},
	{ 1,      0,   0, 3, 300, 1},
	{ 0,   80.2, 150, 4,   0, 2},
	{ 1,      0,   0, 1, 300, 1},
};
//移動する座標
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
	//画面に行ったら弾を消す

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
	//今の座標を取得
	T_Location newLocation = GetLocation();

	//XY同じ座標にいたらnextの配列をもとに次の座標を決める
	if ((newLocation.x == moveInfo[current].targetLocation.x) &&
		(newLocation.y == moveInfo[current].targetLocation.y))
	{
		current = moveInfo[current].next;
	}
	//XYのどちらかがたどり着いてなかったとき
	else
	{
		//Yがたどり着いてなかった場合
		if (newLocation.y != moveInfo[current].targetLocation.y)
		{
			//今いるY座標より次のY座標が大きいとき
			if (newLocation.y < moveInfo[current].targetLocation.y)
			{
				newLocation.y += speed.y;
				//移動したあとに目的地を飛び越したとき目的地を代入する
				if ((GetLocation().y <= moveInfo[current].targetLocation.y) && (moveInfo[current].targetLocation.y <= newLocation.y))
				{
					newLocation.y = moveInfo[current].targetLocation.y;
				}
			}
			//今いるY座標より次のY座標が小さいとき
			else {
				newLocation.y -= speed.y;
				//移動したあとに目的地を飛び越したとき目的地を代入する
				if ((newLocation.y <= moveInfo[current].targetLocation.y) && (newLocation.y <= GetLocation().y))
				{
					newLocation.y = moveInfo[current].targetLocation.y;
				}
			}
		}
		//Xがたどり着いてなかった場合
		if (newLocation.x != moveInfo[current].targetLocation.x)
		{
			//今いるY座標より次のY座標が大きいとき
			if (newLocation.x < moveInfo[current].targetLocation.x)
			{
				newLocation.x += speed.x;
				//移動したあとに目的地を飛び越したとき目的地を代入する
				if ((GetLocation().x <= moveInfo[current].targetLocation.x) && (moveInfo[current].targetLocation.x <= newLocation.x))
				{
					newLocation.x = moveInfo[current].targetLocation.x;
				}
			}
			//今いるY座標より次のY座標が小さいとき
			else
			{
				newLocation.x -= speed.x;
				//移動したあとに目的地を飛び越したとき目的地を代入する
				if ((GetLocation().x <= moveInfo[current].targetLocation.x) && (moveInfo[current].targetLocation.x <= newLocation.x))
				{
					newLocation.x = moveInfo[current].targetLocation.x;
				}
			}
		}
	}

	//移動の更新
	SetLocation(newLocation);

}
//if (l < 4) {
//	//今いる座標と行きたい座標の位置があっていたら次の配列を見る
//	if (GetLocation().x == locations[l].x && GetLocation().y == locations[l].y)
//	{
//		l++;
//	}
//	else {
//		//最初の画面外から出てくる処理
//		if (GetLocation().y != locations[l].y)
//		{
//			//下に下がる処理
//			if (GetLocation().y < locations[l].y) {

//				newLocation.y += speed.y;
//				SetLocation(newLocation);
//			}
//			//上に上がる処理
//			else if (GetLocation().y > locations[l].y)
//			{
//				newLocation.y -= speed.y;
//				SetLocation(newLocation);
//			}
//		}
//		//横移動処理
//		if (GetLocation().x != locations[l].x)
//		{
//			//右に行く処理
//			if (GetLocation().x < locations[l].x) {

//				newLocation.x += speed.x;
//				SetLocation(newLocation);
//			}
//			//左に行く処理
//			else if (GetLocation().x > locations[l].x)
//			{
//				newLocation.x -= speed.x;
//				SetLocation(newLocation);
//			}
//		}
//		//小数点がずれていたら目的地の座標XYを代入して直す
//			if (GetLocation().x > locations[l].x) {
//				newLocation.x = locations[l].x;
//			}
//		if (GetLocation().y > locations[l].y) {
//			newLocation.y = locations[l].y;
//		}
//	}
//}
//else//３についたら２を代入する
//{
//	l = 2;
//}