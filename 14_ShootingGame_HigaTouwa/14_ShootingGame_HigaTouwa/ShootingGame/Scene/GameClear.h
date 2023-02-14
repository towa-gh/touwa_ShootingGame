#pragma once
#include "AbstractScene.h"

class GameClearScene : public AbstractScene
{
private:
	int BrinkCounter;	// �_�ŗp�̕ϐ�
public:
	GameClearScene();
	virtual ~GameClearScene()	//�f�X�g���N�^
	{}

public:
	virtual void Update() override;  //�`��ȊO�̍X�V����������
	virtual void Draw() const override;	//�`��Ɋւ��邱�Ƃ���������
	virtual AbstractScene* ChangeScene() override;	//�V�[���̕ύX����
};
