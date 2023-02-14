#pragma once
#include "AbstractScene.h"

class GameClearScene : public AbstractScene
{
private:
	int BrinkCounter;	// 点滅用の変数
public:
	GameClearScene();
	virtual ~GameClearScene()	//デストラクタ
	{}

public:
	virtual void Update() override;  //描画以外の更新を実装する
	virtual void Draw() const override;	//描画に関することを実装する
	virtual AbstractScene* ChangeScene() override;	//シーンの変更処理
};
