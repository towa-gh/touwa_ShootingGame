#include"GameClear.h"
#include"TitleScene.h"
#include"../Base/KeyManager.h"
#include"DxLib.h"
#include"GameMain.h"

GameClearScene::GameClearScene()
{
	BrinkCounter = 0;
}

void GameClearScene::Update()
{
	// �_�ŗp�̕ϐ��� 1 �𑫂�
	BrinkCounter++;

	// �_�ŗp�̕ϐ��� 60 �ɂȂ��Ă����� 0 �ɂ���
	if (BrinkCounter == 60)
	{
		BrinkCounter = 0;
	}
}

void GameClearScene::Draw() const {

	DrawString(400, 360, "Geme Clear", 0x0000ff);

	// �_�ŗp�̕ϐ��̒l�� 30 �����̂Ƃ����� --- PRESS SPACE KEY --- ��`�悷��
	if (BrinkCounter < 30)
	{
		SetFontSize(60);
		DrawString(400, 460, "Plese SPACE Bar", 0x0000ff);
	}

}

//�V�[���̕ύX����
AbstractScene* GameClearScene::ChangeScene()
{
	//WaitKey();
	if (KeyManager::OnKeyClicked(KEY_INPUT_SPACE)) {
		return new GameTitleScene;
	}
	return this;
}
