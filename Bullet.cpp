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





void Bullet::SetIsShot_(bool TorF)
{
	isShot_ = TorF;
}

void Bullet::SetPosX_(int x)
{
	posX_ = x;
}

void Bullet::SetPosY_(int y)
{
	posY_ = y;
}

void Bullet::SetRadius_(int radius)
{
	radius_ = radius;
}

void Bullet::SetSpeed_(int speed)
{
	speed_ = speed;
}

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

