#pragma once
#include "AbstractScene.h"
class DrawGameClearScene : public AbstractScene {
public:
    virtual ~DrawGameClearScene() {};

    virtual AbstractScene* Update() override;

    //•`‰æ‚ÉŠÖ‚·‚é‚±‚Æ‚ðŽÀ‘•‚·‚é
    virtual void Draw() const override;
};