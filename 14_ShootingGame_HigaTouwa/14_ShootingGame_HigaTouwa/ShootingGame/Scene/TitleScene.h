#pragma once
#include "AbstractScene.h"

class TitleScene : public AbstractScene {
    int	g_MenuNumber;		// ���j���[�J�[�\���ʒu
    int g_MenuY;				// ���j���[�J�[�\���̂x���W
public:
    virtual ~TitleScene() {};

    virtual AbstractScene* Update() override;

    //�`��Ɋւ��邱�Ƃ���������
    virtual void Draw() const override;
};