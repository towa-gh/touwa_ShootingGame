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
	static void Update();		//�X�V����
	static bool OnKeyClicked(int Key);	//
	static bool OnKeyReleased(int Key);	//�L�[�𗣂������̏���
	static bool OnKeyPressed(int Key);	//�L�[��������Ă�Ƃ��A�����Ă���Ƃ��̏���

	static bool OnMouseClicked(int Key);	//
	static bool OnMouseReleased(int Key);	//�}�E�X�𗣂������̏���
	static bool OnMousePressed(int Key);	//�}�E�X��������Ă�Ƃ��A�����Ă���Ƃ��̏���

};

