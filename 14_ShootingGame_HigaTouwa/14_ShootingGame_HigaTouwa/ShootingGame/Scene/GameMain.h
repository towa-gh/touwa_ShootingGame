#pragma once
#include "AbstractScene.h"
#include"../Base/Player.h"
class GameMainScene : public AbstractScene
{
private:
	Player* player;

public:
	GameMainScene();
	virtual ~GameMainScene()	//�f�X�g���N�^
	{}


public:
	virtual void Update() override;  //�`��ȊO�̍X�V����������
	virtual void Draw() const override;	//�`��Ɋւ��邱�Ƃ���������
	virtual AbstractScene* ChangeScene() override;	//�V�[���̕ύX����
};
