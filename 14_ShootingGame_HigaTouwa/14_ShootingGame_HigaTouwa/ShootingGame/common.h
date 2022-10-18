#pragma once

#define SCREEN_SIZE_X 640
#define SCREEN_SIZE_Y 480

#define  HEIGHT  10
#define  WIDTH   16

enum class GAME_STATE {
    GAME_TITLE = 0,
    GAME_INIT,
    DRAW_RANKING,
    DRAW_END,
    GAME_MAIN,
    DRAW_GAME_OVER,
    DRAW_GAME_CLEAR,
    INPUT_RANKING,

    EXIT = 99
};
/***********************************************
 * 変数の宣言
 ***********************************************/
extern int	g_OldKey;				// 前回の入力キー
extern int	g_NowKey;				// 今回の入力キー
extern int	g_KeyFlg;				// 入力キー情報
extern int g_BlockImage[8];    //ブロック画像用変数
extern int	g_TitleImage;			// 画像用変数
extern int	g_RankingImage;			// 画像用変数
extern int	g_EndImage;				// 画像用変数
extern int	g_WaitTime;			// 待ち時間
extern int g_PosY;					// スクロール時のＹ座標
extern int	g_Score;			// スコア
extern GAME_STATE	g_GameState; // ゲームステータス
extern int g_Stage;                //ステージ用変数

void GameInit(void);
