#pragma once
#include "AbstractScene.h"
class GameMain : public AbstractScene {
public:
    GameMain();
    virtual ~GameMain() {};

    virtual AbstractScene* Update() override;

    //描画に関することを実装する
    virtual void Draw() const override;
};