//#include"GameOverScene.h"
//#include"TitleScene.h"
//#include"DxLib.h"
//#include"../common.h"
//
//AbstractScene* DrawGameOverScene::Update() {
//	// �X�y�[�X�L�[�Ń��j���[�ɖ߂�
//	if (g_KeyFlg & PAD_INPUT_M) return new TitleScene();
//
//	return this;
//}
//
//void DrawGameOverScene::Draw() const {
//	SetFontSize(48);
//	DrawString(200, 200, "Game Over", GetColor(255, 0, 0));
//
//	// �����̕\��(�_��)
//	if (++g_WaitTime < 30) {
//		SetFontSize(24);
//		DrawString(150, 450, "--  Press [SPACE] Key  --", GetColor(255, 0, 0));
//	}
//	else if (g_WaitTime > 60) {
//		g_WaitTime = 0;
//	}
//}

