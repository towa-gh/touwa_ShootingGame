#pragma once
#include "AbstractScene.h"
class DrawGameClearScene : public AbstractScene {
public:
    virtual ~DrawGameClearScene() {};

    virtual AbstractScene* Update() override;

    //描画に関することを実装する
    virtual void Draw() const override;
};