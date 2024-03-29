#include "GameMain.h"
#include"GameOverScene.h"
#include"GameClear.h"
#include"../Base/Recovery.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

GameMainScene::GameMainScene()
{
	T_Location location = T_Location{ 20,100 };
	player = new Player(location);
	
	enemy = new Enemy * [10];
	for (int i = 0; i < 10; i++) 
	{
		enemy[i] = nullptr;
	}
	enemy[0] = new Enemy(T_Location{ 640, -20 });

	item = new ItemBase * [10];
	for (int i = 0; i < 10; i++) 
	{
		item[i] = nullptr;
	}
}
//描画以外の更新を実装する
void GameMainScene::Update()
{
	player->Update();

	//敵の更新処理
	for (enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] == nullptr)
		{
			break;
		}
		enemy[enemyCount]->Update();
	}

	//アイテム更新処理
	for (int i = 0; i < 10; i++)
	{
		if (item[i] == 0)
		{
			break;
		}
		item[i]->Update();
	}

	BulletsBase** bullet = player->GetBullets();
	for (enemyCount = 0; enemyCount < 10; enemyCount++) 
	{
		if (enemy[enemyCount] == nullptr)
		{
			break;
		}
		for (int bulletCount = 0; bulletCount < 30; bulletCount++)
		{
			if (bullet[bulletCount] == nullptr)
			{
				break;
			}
			if (enemy[enemyCount]->HitSphere(bullet[bulletCount]))
			{
				//エネミーにプレイヤーの弾がヒットしたら
				//エネミーにダメージを与える
				
				enemy[enemyCount]->Hit(bullet[bulletCount]->GetDamage());
				//弾を削除
				player->DeleteBullet(bulletCount);
				bulletCount--;
			
				//エネミーのHPが０以下だったら、エネミーを削除
				if (enemy[enemyCount]->HpCheck()) 
				{
					EnemyDown();
					for (int i = 0; i < 10; i++) 
					{
						if (item[i] == nullptr)
						{
							item[i] = new Recovery(enemy[enemyCount]->GetLocation());
							break;
						}
					}

					//スコアの加算
					player->AddScore(enemy[enemyCount]->GetPoint());

					//エネミーの削除
					delete enemy[enemyCount];
					enemy[enemyCount] = nullptr;

					for (int i = enemyCount + 1; i < 10; i++) 
					{
						if (enemy[i] == nullptr) 
						{
							break;
						}
						enemy[i - 1] = enemy[i];
						enemy[i] = nullptr;
					}
					enemyCount--;
					break;
				}
			}
		}
	}

	
	for (enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] == nullptr)
		{
			break;
		}

		BulletsBase** bullet = enemy[enemyCount]->GetBullets();

		for (int bulletCount = 0; bulletCount < 30; bulletCount++)
		{
			if (bullet[bulletCount] == nullptr)
			{
				break;
			}
			if (player->HitSphere(bullet[bulletCount]))
			{
				//プレイヤーにエネミーの弾がヒットしている
				//プレイヤーにダメージを与えます

				player->Hit(bullet[bulletCount]->GetDamage());
				//弾を削除します
				enemy[enemyCount]->DeleteBullet(bulletCount);
				bulletCount--;

				//プレイヤーのHPが０以下だったら、プレイヤーを削除します
				if (player->LifeCheck())
				{
					////エネミーの削除
					//delete enemy[enemyCount];
					//enemy[enemyCount] = nullptr;

					//for (int i = enemyCount + 1; i < 10; i++)
					//{
					//	if (enemy[i] == nullptr)
					//	{
					//		break;
					//	}
					//	enemy[i - 1] = enemy[i];
					//	enemy[i] = nullptr;
					//}
					//enemyCount--;
					//break;
				}
			}
		}
	}

	for (int itemcount = 0; itemcount < 10; itemcount++)
	{
		if (item[itemcount] == nullptr)
		{
			break;
		}
		if (item[itemcount]->HitSphere(player)==true)
		{

			//回復処理
			player->Hit(item[itemcount]);

			delete item[itemcount];
			item[itemcount] = nullptr;

			//
			for (int i = itemcount + 1; i < 10; i++)
			{
				if (item[i] == nullptr)
				{
					break;
				}
				item[i - 1] = item[i];
				item[i] = nullptr;
			}
			itemcount--;
		}
	}
}
//描画に関することを実装する
void GameMainScene::Draw() const
{
	player->Draw();

	//enemy描画処理
	for (int enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] == nullptr)
		{
			break;
		}
		enemy[enemyCount]->Draw();
	}

	//アイテム描画処理
	for (int i = 0; i < 10; i++)
	{
		if (item[i] == 0)
		{
			break;
		}
		item[i]->Draw();
	}
}
int GameMainScene::EnemyDown() 
{
	enemyDown++;
	return enemyDown;
}

//シーンの変更処理
AbstractScene* GameMainScene::ChangeScene()
{
	if (player->LifeCheck())
	{
		return new GameOverScene;
	}

	if (enemyVolume == enemyDown)
	{
		return new GameClearScene;
	}

	return this;
}