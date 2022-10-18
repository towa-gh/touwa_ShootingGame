#pragma once
#include "AbstractScene.h"
class GameMain : public AbstractScene {
public:
    GameMain();
    virtual ~GameMain() {};

    virtual AbstractScene* Update() override;

    //•`‰æ‚ÉŠÖ‚·‚é‚±‚Æ‚ðŽÀ‘•‚·‚é
    virtual void Draw() const override;
};