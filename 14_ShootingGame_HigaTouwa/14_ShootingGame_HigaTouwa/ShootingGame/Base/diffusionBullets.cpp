#include "diffusionBullets.h"
#include"DxLib.h"
#define _USE_MATH_DEFINES
#include"math.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

diffusionBullets::diffusionBullets(T_Location location, T_Location speed)
	:BulletsBase(location, 5.f, 1, speed)
{
    //�v���C���[�̈�擾
	px = player->GetLocation().x;
	py = player->GetLocation().y;
    px = enemy->GetLocation().x;
    py = enemy->GetLocation().y;
}
void  diffusionBullets::Update()
{
        //�G�ƃv���C���[�Ƃ̍��W�̍�����t���ڂ����߂�B
        //���񂾂����s
        if (ShotCount == 0)
            trad = atan2(py - ey, px - ex);

    if (ShotCount % 10 == 0 && ShotCount <= 40) {
            for (int i = 0; i < ENEMY_SNUM; ++i) {
                    //�t���O�������ĂȂ��e��T���āA���W�����Z�b�g
                    if (shot[i].flag == false) {
                            shot[i].flag = true;
                            shot[i].x = x;
                            shot[i].y = y;
                            //0�̎��͍����
                            if (num == 0) {
                                    //�G�ƃv���C���[�Ƃ̋t���ڂ���10�x���������W�A������
                                    shot[i].rad = trad - (10 * 3.14 / 180);
                                    //1�̎��̓v���C���[�꒼��
                            }
                            else if (num == 1) {
                                    //�G�ƃv���C���[�Ƃ̋t���ڂ���
                                    shot[i].rad = trad;
                                    //2�̎��͉E���
                            }
                            else if (num == 2) {
                                    //�G�ƃv���C���[�Ƃ̋t���ڂ���10�x���������W�A������
                                    shot[i].rad = trad + (10 * PI / 180);                     
                            }
                            ++num;
                            //3�����˂�����,num��0�ɂ��ă��[�v�𔲂���B
                            if (num == 3) {
                                    num = 0;
                                    break;
                            }
                    }
            }
    }       
}
void  diffusionBullets::Draw()
{
	DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 255, 0));
    DrawFormatString(10, 70, GetColor(255, 255, 255), "px=%f", px);
    DrawFormatString(10, 90, GetColor(255, 255, 255), "py=%f", py);
}

bool diffusionBullets::isScreebOut()
{

	bool ret = (GetLocation().y + GetRadius() <= 0);
	if (ret)
	{
		return ret;
	}
	ret = (SCREEN_HEIGHT <= (GetLocation().y - GetRadius()));
	if (ret)
	{
		return ret;
	}

	ret = ((GetLocation().x + GetRadius()) <= 0);
	if (ret)
	{
		return ret;
	}
	ret = (SCREEN_WIDTH <= (GetLocation().x - GetRadius()));
	return ret;
}