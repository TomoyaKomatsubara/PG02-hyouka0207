#include "Enemy.h"
#include <Novice.h>

Enemy::Enemy(int posX, int posY)
{

	posX_ = posX;
	posY_ = posY;
	speed_ = 10;
	radius_ = 20;
	isAlive_ = true;
	toPlayerDamage_ = 2;
}


void Enemy::SetIsAlive(bool TorF)
{
	isAlive_ = TorF;
}
void Enemy::SetRespawnTimer(int remainTimer)
{
	respawnTimer_ = remainTimer;
}
void Enemy::SetPosX_(int posX)
{
	posX_ = posX;
}
void Enemy::SetPosY_(int posY)
{
	posY_ = posY;
}


void Enemy::Update()
{
	if (isAlive_ == true)
	{
		posX_ += speed_;
		if (posX_ <= 0 + radius_ || posX_ >= 1280 - radius_)
		{
			speed_ *= -1;
		}
	}
	else if (isAlive_ == false)
	{
		respawnTimer_--;
		if (respawnTimer_ <= 0)
		{
			isAlive_ = true;
		}
	}

}



void Enemy::Draw()
{
	if (isAlive_ == true)
	{
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, 0xff6347ff, kFillModeSolid);
	}
}

void Enemy::Initialize(int posX,int posY)
{
	posX_ = posX;
	posY_ = posY;
	speed_ = 10;
	radius_ = 20;
	isAlive_ = true;
	toPlayerDamage_ = 2;
}
