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
 * �ϐ��̐錾
 ***********************************************/
extern int	g_OldKey;				// �O��̓��̓L�[
extern int	g_NowKey;				// ����̓��̓L�[
extern int	g_KeyFlg;				// ���̓L�[���
extern int g_BlockImage[8];    //�u���b�N�摜�p�ϐ�
extern int	g_TitleImage;			// �摜�p�ϐ�
extern int	g_RankingImage;			// �摜�p�ϐ�
extern int	g_EndImage;				// �摜�p�ϐ�
extern int	g_WaitTime;			// �҂�����
extern int g_PosY;					// �X�N���[�����̂x���W
extern int	g_Score;			// �X�R�A
extern GAME_STATE	g_GameState; // �Q�[���X�e�[�^�X
extern int g_Stage;                //�X�e�[�W�p�ϐ�

void GameInit(void);
