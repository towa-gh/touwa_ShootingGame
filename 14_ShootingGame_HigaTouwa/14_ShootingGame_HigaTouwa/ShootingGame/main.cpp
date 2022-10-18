/********************************************************************
**	第４章　ゲームプログラミングの基本
**	　ブロック崩しゲームの作成(2018)
********************************************************************/
#include "DxLib.h"
#include "common.h"
#include"Scene/SceneManager.h"
#include"Scene/TitleScene.h"
#include"Scene/EndScene.h"
#include"Scene/GameClearScene.h"
#include"Scene/GameOverScene.h"
#include"Scene/GameMain.h"


#define  STAGE    5
int	g_OldKey;				// 前回の入力キー
int	g_NowKey;				// 今回の入力キー
int	g_KeyFlg;				// 入力キー情報
int	g_EndImage;				// 画像用変数
int	g_WaitTime;			// 待ち時間
int g_PosY;					// スクロール時のＹ座標
int	g_Score;			// スコア
GAME_STATE	g_GameState = GAME_STATE::GAME_TITLE; // ゲームステータス

int g_Stage;                //ステージ用変数

/***********************************************
 * プログラムの開始
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow) {

	// タイトルを test に変更
	SetMainWindowText("ブロック崩し");

	ChangeWindowMode(TRUE);		// ウィンドウモードで起動

	if (DxLib_Init() == -1) return -1;	// DXライブラリの初期化処理

	//タイトル画像データの読み込み
	if ((g_TitleImage = LoadGraph("images/Title.png")) == -1) return -1;
	//エンド画像データの読み込み
	if ((g_EndImage = LoadGraph("images/End.bmp")) == -1) return -1;

	SetDrawScreen(DX_SCREEN_BACK);	// 描画先画面を裏にする

	SetFontSize(20);		// 文字サイズを設定

	SceneManager sceneMng(new TitleScene());

	// ゲームループ
	while (ProcessMessage() == 0 && g_GameState != GAME_STATE::EXIT && sceneMng.Update() != nullptr) {

		// 入力キー取得
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		g_KeyFlg = g_NowKey & ~g_OldKey;

		ClearDrawScreen();		// 画面の初期化
		sceneMng.Draw();
		ScreenFlip();			// 裏画面の内容を表画面に反映
	}

	DxLib_End();	// DXライブラリ使用の終了処理

	return 0;	// ソフトの終了
}
/***********************************************
 * ゲーム初期処理
 ***********************************************/
void GameInit(void) {
	// 変数の初期設定
	
	//ブロック配列の初期化

	g_GameState = GAME_STATE::GAME_MAIN;	// ゲームメイン処理へ
}



