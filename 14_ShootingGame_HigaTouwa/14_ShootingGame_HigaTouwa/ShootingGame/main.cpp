/********************************************************************
**	��S�́@�Q�[���v���O���~���O�̊�{
**	�@�u���b�N�����Q�[���̍쐬(2018)
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
int	g_OldKey;				// �O��̓��̓L�[
int	g_NowKey;				// ����̓��̓L�[
int	g_KeyFlg;				// ���̓L�[���
int	g_EndImage;				// �摜�p�ϐ�
int	g_WaitTime;			// �҂�����
int g_PosY;					// �X�N���[�����̂x���W
int	g_Score;			// �X�R�A
GAME_STATE	g_GameState = GAME_STATE::GAME_TITLE; // �Q�[���X�e�[�^�X

int g_Stage;                //�X�e�[�W�p�ϐ�

/***********************************************
 * �v���O�����̊J�n
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow) {

	// �^�C�g���� test �ɕύX
	SetMainWindowText("�u���b�N����");

	ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ŋN��

	if (DxLib_Init() == -1) return -1;	// DX���C�u�����̏���������

	//�^�C�g���摜�f�[�^�̓ǂݍ���
	if ((g_TitleImage = LoadGraph("images/Title.png")) == -1) return -1;
	//�G���h�摜�f�[�^�̓ǂݍ���
	if ((g_EndImage = LoadGraph("images/End.bmp")) == -1) return -1;

	SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���

	SetFontSize(20);		// �����T�C�Y��ݒ�

	SceneManager sceneMng(new TitleScene());

	// �Q�[�����[�v
	while (ProcessMessage() == 0 && g_GameState != GAME_STATE::EXIT && sceneMng.Update() != nullptr) {

		// ���̓L�[�擾
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		g_KeyFlg = g_NowKey & ~g_OldKey;

		ClearDrawScreen();		// ��ʂ̏�����
		sceneMng.Draw();
		ScreenFlip();			// ����ʂ̓��e��\��ʂɔ��f
	}

	DxLib_End();	// DX���C�u�����g�p�̏I������

	return 0;	// �\�t�g�̏I��
}
/***********************************************
 * �Q�[����������
 ***********************************************/
void GameInit(void) {
	// �ϐ��̏����ݒ�
	
	//�u���b�N�z��̏�����

	g_GameState = GAME_STATE::GAME_MAIN;	// �Q�[�����C��������
}



