#pragma once
#include "AbstractScene.h"
#include"../Base/Player.h"
#include"../Base/Enemy.h"
#include"../Base/ItemBase.h"
class GameMainScene : public AbstractScene
{
private:
	int enemyCount;
	Player* player;
	Enemy** enemy;
	ItemBase** item;

public:
	GameMainScene();
	virtual ~GameMainScene()	//�f�X�g���N�^
	{}


public:
	virtual void Update() override;  //�`��ȊO�̍X�V����������
	virtual void Draw() const override;	//�`��Ɋւ��邱�Ƃ���������
	virtual AbstractScene* ChangeScene() override;	//�V�[���̕ύX����
};
