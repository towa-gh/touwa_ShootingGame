#pragma once
#include "AbstractScene.h"
class SceneManager :public AbstractScene
{
private:
	AbstractScene* mScene; //���݂̃V�[��

public:
	//�R���X�g���N�^
	SceneManager(AbstractScene* scene)
		:mScene(scene)
	{}

	//�f�X�g���N�^
	~SceneManager()
	{
		delete mScene;
	}

	//�`��ȊO�̍X�V����������
	void Update() override;

	//�`��Ɋւ��邱�Ƃ���������
	void Draw() const override;

	//�V�[���̕ύX����
	virtual AbstractScene* ChangeScene() override;
};
