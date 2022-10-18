#include"EndScene.h"
#include"DxLib.h"
#include"../common.h"

AbstractScene* DrawEndScene::Update() {
	//�G���f�B���O�\��
	if (++g_WaitTime < 600) g_PosY = 300 - g_WaitTime / 2;

	//�^�C���̉��Z�������I��
	if (++g_WaitTime > 900) g_GameState = GAME_STATE::EXIT;
	return this;
}

void DrawEndScene::Draw() const {
	//�G���h�摜�\��
	DrawGraph(0, 0, g_EndImage, FALSE);

	SetFontSize(24);
	DrawString(100, 170 + g_PosY, "�^�C�g���@�@�@BreakOut", 0xFFFFFF);
	DrawString(100, 200 + g_PosY, "�o�[�W�����@�@1.0", 0xFFFFFF);
	DrawString(100, 230 + g_PosY, "�ŏI�X�V���@�@201x�Nxx��xx��", 0xFFFFFF);
	DrawString(100, 260 + g_PosY, "����ҁ@�@�@�@���ۓd�q�r�W�l�X���w�Z", 0xFFFFFF);
	DrawString(100, 290 + g_PosY, "�@�@�@�@�@�@�@�w�w�w�@�w�w", 0xFFFFFF);
	DrawString(100, 310 + g_PosY, "�f�ޗ��p", 0xFFFFFF);
	DrawString(100, 340 + g_PosY, "�@BGM�@�@�@ �@�w�w�w�w", 0xFFFFFF);
	DrawString(100, 365 + g_PosY, "�@SE�@�@�@�@�@�w�w�w�w�w�w�w�w", 0xFFFFFF);

}


