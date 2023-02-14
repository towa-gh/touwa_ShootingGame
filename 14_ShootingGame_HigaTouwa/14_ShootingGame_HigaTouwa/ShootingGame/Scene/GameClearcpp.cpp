#include"GameClear.h"
#include"TitleScene.h"
#include"../Base/KeyManager.h"
#include"DxLib.h"
#include"GameMain.h"

GameClearScene::GameClearScene()
{
	BrinkCounter = 0;
}

void GameClearScene::Update()
{
	// 点滅用の変数に 1 を足す
	BrinkCounter++;

	// 点滅用の変数が 60 になっていたら 0 にする
	if (BrinkCounter == 60)
	{
		BrinkCounter = 0;
	}
}

void GameClearScene::Draw() const {

	DrawString(400, 360, "Geme Clear", 0x0000ff);

	// 点滅用の変数の値が 30 未満のときだけ --- PRESS SPACE KEY --- を描画する
	if (BrinkCounter < 30)
	{
		SetFontSize(60);
		DrawString(400, 460, "Plese SPACE Bar", 0x0000ff);
	}

}

//シーンの変更処理
AbstractScene* GameClearScene::ChangeScene()
{
	//WaitKey();
	if (KeyManager::OnKeyClicked(KEY_INPUT_SPACE)) {
		return new GameTitleScene;
	}
	return this;
}
