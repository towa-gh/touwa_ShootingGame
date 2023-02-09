#include"GameOverScene.h"
#include"TitleScene.h"
#include"../Base/KeyManager.h"
#include"DxLib.h"
#include"GameMain.h"

GameOverScene::GameOverScene()
{
	BrinkCounter = 0;
}

void GameOverScene::Update()
{
	// 点滅用の変数に 1 を足す
	BrinkCounter++;

	// 点滅用の変数が 60 になっていたら 0 にする
	if (BrinkCounter == 60)
	{
		BrinkCounter = 0;
	}
}

void GameOverScene::Draw() const {

	DrawString(400, 360, "Geme Over", 0x0000ff);
	
	// 点滅用の変数の値が 30 未満のときだけ --- PRESS SPACE KEY --- を描画する
	if (BrinkCounter < 30)
	{
		SetFontSize(60);
		DrawString(400, 460, "Plese SPACE Bar", 0x0000ff);
	}

}

//シーンの変更処理
AbstractScene* GameOverScene::ChangeScene()
{
	//WaitKey();
	if (KeyManager::OnKeyClicked(KEY_INPUT_SPACE)) {
		return new GameTitleScene;
	}
	return this;
}
