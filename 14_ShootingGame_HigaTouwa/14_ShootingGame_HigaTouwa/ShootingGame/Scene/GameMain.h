#pragma once
#include "AbstractScene.h"
class GameMain : public AbstractScene {
public:
    GameMain();
    virtual ~GameMain() {};

    virtual AbstractScene* Update() override;

    //�`��Ɋւ��邱�Ƃ���������
    virtual void Draw() const override;
};