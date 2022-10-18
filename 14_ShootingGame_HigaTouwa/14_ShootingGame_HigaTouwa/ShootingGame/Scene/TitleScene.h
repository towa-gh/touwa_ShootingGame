#pragma once
#include "AbstractScene.h"

class TitleScene : public AbstractScene {
    int	g_MenuNumber;		// メニューカーソル位置
    int g_MenuY;				// メニューカーソルのＹ座標
public:
    virtual ~TitleScene() {};

    virtual AbstractScene* Update() override;

    //描画に関することを実装する
    virtual void Draw() const override;
};