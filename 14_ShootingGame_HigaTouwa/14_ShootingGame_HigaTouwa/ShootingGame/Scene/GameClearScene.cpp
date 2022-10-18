#include"GameClearScene.h"
#include"GameMain.h"
#include"DxLib.h"
#include"../common.h"


AbstractScene* DrawGameClearScene::Update() {
	//�X�y�[�X�L�[�łm�d�w�s�X�e�[�W��
	if (g_KeyFlg & PAD_INPUT_M) {
		return new GameMain();
	}
	return this;
}

void DrawGameClearScene::Draw() const {
	SetFontSize(48);
	DrawString(120, 200, "Congratulations!!", 0x700f0);
	//�����̕\��(�_��)
	if (++g_WaitTime < 30) {
		SetFontSize(24);
		DrawString(150, 450, "-- Press [SPASE] Key --", 0xFF0000);
	}
	else if (g_WaitTime > 60) {
		g_WaitTime = 0;
	}

}
