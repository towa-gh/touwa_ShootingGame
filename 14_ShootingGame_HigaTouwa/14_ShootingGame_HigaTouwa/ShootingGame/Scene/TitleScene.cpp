#include"TitleScene.h"
#include"../Base/KeyManager.h"
#include"DxLib.h"
#include"GameMain.h"
#include"EndScene.h"

GameTitleScene::GameTitleScene()
{
	BrinkCounter = 0;
}

void GameTitleScene::Update() 
{
	// �_�ŗp�̕ϐ��� 1 �𑫂�
	BrinkCounter++;

	// �_�ŗp�̕ϐ��� 60 �ɂȂ��Ă����� 0 �ɂ���
	if (BrinkCounter == 60)
	{
		BrinkCounter = 0;
	}
}

void GameTitleScene::Draw() const {

	DrawString(400, 160, "Shooting Game!!", 0x0000ff);

	// �_�ŗp�̕ϐ��̒l�� 30 �����̂Ƃ����� --- PRESS SPACE KEY --- ��`�悷��
	if (BrinkCounter < 30)
	{
		SetFontSize(60);
		DrawString(400, 460, "Plese SPACE Bar", 0x0000ff);
	}

}

//�V�[���̕ύX����
AbstractScene* GameTitleScene::ChangeScene()
{
	//WaitKey();
	if (KeyManager::OnKeyClicked(KEY_INPUT_SPACE)) {
		return new GameMainScene;
	}
	return this;
}
