#pragma once
#include "AbstractScene.h"

class GameTitleScene : public AbstractScene
{
private:
	static int BrinkCounter;
public:
	GameTitleScene();
	virtual ~GameTitleScene()	//�f�X�g���N�^
	{}

public:
	virtual void Update() override;  //�`��ȊO�̍X�V����������
	virtual void Draw() const override;	//�`��Ɋւ��邱�Ƃ���������
	virtual AbstractScene* ChangeScene() override;	//�V�[���̕ύX����
};
