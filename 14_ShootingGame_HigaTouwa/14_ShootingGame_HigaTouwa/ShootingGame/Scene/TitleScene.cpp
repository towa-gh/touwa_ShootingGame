#include"TitleScene.h"
#include"DxLib.h"
#include"GameMain.h"
#include"EndScene.h"
#include"../common.h"

AbstractScene* TitleScene::Update() {
	//���j���[�J�[�\���ړ�����
	if (g_KeyFlg & PAD_INPUT_DOWN) {
		if (++g_MenuNumber > 1) g_MenuNumber = 0;
	}
	if (g_KeyFlg & PAD_INPUT_UP) {
		if (--g_MenuNumber < 0) g_MenuNumber = 1;
	}

	// �y�L�[�Ń��j���[�I��
	if (g_KeyFlg & PAD_INPUT_A) {/*g_GameState = static_cast<GAME_STATE>(g_MenuNumber + 1);*/
		if (g_MenuNumber == 0) return new GameMain();
		if (g_MenuNumber == 1) return new DrawEndScene();
	}
	//���j���[�J�[�\���i�O�p�`�j�̕\��
	g_MenuY = g_MenuNumber * 52;

	return this;
}

void TitleScene::Draw() const {
	//�^�C�g���摜�\��
	DrawGraph(0, 0, g_TitleImage, FALSE);
	DrawTriangle(240, 255 + g_MenuY, 260, 270 + g_MenuY, 240, 285 + g_MenuY, GetColor(255, 0, 0), TRUE);
}
