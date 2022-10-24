#include "KeyManager.h"
#include"DxLib.h"

char KeyManager::oldKey[256];
char KeyManager::nowKey[256];
int KeyManager::oldMouse;
int KeyManager::nowMouse;

void KeyManager::Update()
{
	for (int i = 0; i < 256; i++) 
	{
		oldKey[i] = nowKey[i];
	}
	if (GetHitKeyStateAll(nowKey) == -1)
	{
		throw - 1;
	}
	oldMouse = nowMouse;
	nowMouse = GetMouseInput();
}
bool KeyManager::OnKeyClicked(int Key)	//
{
	bool Kcet = ((nowKey[Key] == 1) && (oldKey[Key] != 1));
	return Kcet;
}
bool  KeyManager::OnKeyReleased(int Key)	//キーを離した瞬間の処理
{
	bool Kret = ((nowKey[Key] == 0) && (oldKey[Key] == 1));
	return Kret;
}
bool  KeyManager::OnKeyPressed(int Key)	//キーを押している間の処理
{
	bool Kpet = (nowKey[Key] == 1);
	return Kpet;
}

bool KeyManager::OnMouseClicked(int Key)		//
{
	bool Mcet = ((nowMouse & Key) && (~oldMouse & Key));
	return Mcet;
}
bool KeyManager::OnMouseReleased(int Key)		//キーを離した時の処理
{
	bool Mcet = ((~nowMouse & Key) && (oldMouse & Key));
	return Mcet;
}
bool KeyManager::OnMousePressed(int Key)		//キーが押されてるとき、押しているときの処理
{
	bool Mcet = (nowKey[Key] == 1);
	return Mcet;
}


