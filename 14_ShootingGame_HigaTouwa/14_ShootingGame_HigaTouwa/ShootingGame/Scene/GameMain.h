#pragma once
#include "AbstractScene.h"
#include"../Base/Player.h"
#include"../Base/Enemy.h"
#include"../Base/ItemBase.h"
class GameMainScene : public AbstractScene
{
private:
	int enemyCount;
	int enemyVolume = 1;
	int enemyDown = 0;
	Player* player;
	Enemy** enemy;
	ItemBase** item;

public:
	GameMainScene();
	virtual ~GameMainScene()	//デストラクタ
	{}


public:
	int EnemyDown();
	virtual void Update() override;  //描画以外の更新を実装する
	virtual void Draw() const override;	//描画に関することを実装する
	virtual AbstractScene* ChangeScene() override;	//シーンの変更処理
};
