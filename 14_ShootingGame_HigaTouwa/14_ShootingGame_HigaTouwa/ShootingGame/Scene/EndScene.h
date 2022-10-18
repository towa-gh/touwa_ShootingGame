#pragma once
#include "AbstractScene.h"
class DrawEndScene : public AbstractScene {
public:
    virtual ~DrawEndScene() {};

    virtual AbstractScene* Update() override;

    //描画に関することを実装する
    virtual void Draw() const override;
};