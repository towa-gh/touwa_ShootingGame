#include "GameMain.h"
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
//�`��ȊO�̍X�V����������
void GameMainScene::Update()
{
	player->Update();

	int enemyCount;
	//�G�̍X�V����
	for (enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] == nullptr)
		{
			break;
		}
		enemy[enemyCount]->Update();
	}

	//�A�C�e���X�V����
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
				//�G�l�~�[�Ƀv���C���[�̒e���q�b�g���Ă���
				//�G�l�~�[�Ƀ_���[�W��^���܂�
				
				enemy[enemyCount]->Hit(bullet[bulletCount]->GetDamage());
				//�e���폜���܂�
				player->DeleteBullet(bulletCount);
				bulletCount--;
			
				//�G�l�~�[��HP���O�ȉ���������A�G�l�~�[���폜���܂�
				if (enemy[enemyCount]->HpCheck()) 
				{
					for (int i = 0; i < 10; i++) 
					{
						if (item[i] == nullptr)
						{
							item[i] = new Recovery(enemy[enemyCount]->GetLocation());
							break;
						}
					}

					//�X�R�A�̉��Z
					player->AddScore(enemy[enemyCount]->GetPoint());

					//�G�l�~�[�̍폜
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
				//�G�l�~�[�Ƀv���C���[�̒e���q�b�g���Ă���
				//�G�l�~�[�Ƀ_���[�W��^���܂�

				player->Hit(bullet[bulletCount]->GetDamage());
				//�e���폜���܂�
				enemy[enemyCount]->DeleteBullet(bulletCount);
				bulletCount--;

				//�G�l�~�[��HP���O�ȉ���������A�G�l�~�[���폜���܂�
				if (player->LifeCheck())
				{
					////�G�l�~�[�̍폜
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

			//�񕜏���
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
//�`��Ɋւ��邱�Ƃ���������
void GameMainScene::Draw() const
{
	player->Draw();

	//enemy�`�揈��
	for (int enemyCount = 0; enemyCount < 10; enemyCount++)
	{
		if (enemy[enemyCount] == nullptr)
		{
			break;
		}
		enemy[enemyCount]->Draw();
	}

	//�A�C�e���`�揈��
	for (int i = 0; i < 10; i++)
	{
		if (item[i] == 0)
		{
			break;
		}
		item[i]->Draw();
	}
}
//�V�[���̕ύX����
AbstractScene* GameMainScene::ChangeScene()
{
	return this;
}