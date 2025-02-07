#include<Novice.h>
#include"Bullet.h"

Bullet::Bullet(int speed, int radius)
{
	posX_ = 0;
	posY_ = 0;
	isShot_ = false;
	speed_ = speed;
	radius_ = radius;
}

//Bullet::~Bullet()
//{
//
//}

void Bullet::Update()
{
	if (isShot_)
	{
		posY_ -= speed_;
		if (posY_ + radius_ < 0)
		{
			isShot_ = false;
		}

	}
}

void Bullet::Draw()
{
	if (isShot_)
	{
		Novice::DrawEllipse(static_cast<int>(posX_), static_cast<int>(posY_),
			radius_, radius_, 0.0f, RED, kFillModeSolid);
	}
}