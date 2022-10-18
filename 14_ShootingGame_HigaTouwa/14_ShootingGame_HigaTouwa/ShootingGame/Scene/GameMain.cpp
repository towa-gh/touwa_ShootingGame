#include"GameMain.h"
#include"GameClearScene.h"
#include"GameOverScene.h"
#include"DxLib.h"
#include"../common.h"

GameMain::GameMain() {
	GameInit();
}
AbstractScene* GameMain::Update() {

	return this;
}

void GameMain::Draw() const {

}

