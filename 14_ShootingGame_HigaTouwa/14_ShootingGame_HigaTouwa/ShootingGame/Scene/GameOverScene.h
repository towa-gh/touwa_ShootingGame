#pragma once
#include "AbstractScene.h"

class GameOverScene : public AbstractScene
{
private:
	int BrinkCounter;	// �_�ŗp�̕ϐ�
public:
	GameOverScene();
	virtual ~GameOverScene()	//�f�X�g���N�^
	{}

public:
	virtual void Update() override;  //�`��ȊO�̍X�V����������
	virtual void Draw() const override;	//�`��Ɋւ��邱�Ƃ���������
	virtual AbstractScene* ChangeScene() override;	//�V�[���̕ύX����
};
