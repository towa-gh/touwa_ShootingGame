#include"EndScene.h"
#include"DxLib.h"
#include"../common.h"

AbstractScene* DrawEndScene::Update() {
	//エンディング表示
	if (++g_WaitTime < 600) g_PosY = 300 - g_WaitTime / 2;

	//タイムの加算処理＆終了
	if (++g_WaitTime > 900) g_GameState = GAME_STATE::EXIT;
	return this;
}

void DrawEndScene::Draw() const {
	//エンド画像表示
	DrawGraph(0, 0, g_EndImage, FALSE);

	SetFontSize(24);
	DrawString(100, 170 + g_PosY, "タイトル　　　BreakOut", 0xFFFFFF);
	DrawString(100, 200 + g_PosY, "バージョン　　1.0", 0xFFFFFF);
	DrawString(100, 230 + g_PosY, "最終更新日　　201x年xx月xx日", 0xFFFFFF);
	DrawString(100, 260 + g_PosY, "制作者　　　　国際電子ビジネス専門学校", 0xFFFFFF);
	DrawString(100, 290 + g_PosY, "　　　　　　　ＸＸＸ　ＸＸ", 0xFFFFFF);
	DrawString(100, 310 + g_PosY, "素材利用", 0xFFFFFF);
	DrawString(100, 340 + g_PosY, "　BGM　　　 　ＸＸＸＸ", 0xFFFFFF);
	DrawString(100, 365 + g_PosY, "　SE　　　　　ＸＸＸＸＸＸＸＸ", 0xFFFFFF);

}


