#pragma once
#include "AbstractScene.h"
class DrawGameClearScene : public AbstractScene {
public:
    virtual ~DrawGameClearScene() {};

    virtual AbstractScene* Update() override;

    //�`��Ɋւ��邱�Ƃ���������
    virtual void Draw() const override;
};