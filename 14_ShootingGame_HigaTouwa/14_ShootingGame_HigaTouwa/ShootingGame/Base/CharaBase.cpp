#include "CharaBase.h"
CharaBase::CharaBase(T_Location location, float radius, T_Location speed) : SphereCollider(location, radius), speed(speed), image(nullptr), bullets(nullptr)
{

}
BulletsBase** CharaBase::GetBullets()
{
	return bullets;
}
void CharaBase::DeleteBullet(int BulletNum)
{
	delete bullets[BulletNum];
	bullets[BulletNum] = nullptr;

	for (int i = BulletNum + 1; i < 30; i++) {
		if (bullets[i] == nullptr) {
			break;
		}
		bullets[i - 1] = bullets[i];
		bullets[i] = nullptr;
	}
}