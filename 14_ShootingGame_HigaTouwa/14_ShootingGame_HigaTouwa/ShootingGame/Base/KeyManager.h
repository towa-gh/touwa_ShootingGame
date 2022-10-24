#pragma once
class KeyManager
{
private:
	static char oldKey[256];
	static char nowKey[256];
	static int oldMouse;
	static int nowMouse;


private:
	KeyManager() = default;

public:
	static void Update();		//更新処理
	static bool OnKeyClicked(int Key);	//
	static bool OnKeyReleased(int Key);	//キーを離した時の処理
	static bool OnKeyPressed(int Key);	//キーが押されてるとき、押しているときの処理

	static bool OnMouseClicked(int Key);	//
	static bool OnMouseReleased(int Key);	//マウスを離した時の処理
	static bool OnMousePressed(int Key);	//マウスが押されてるとき、押しているときの処理

};

