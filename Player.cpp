#include "Player.h"
#include "stdio.h"
#include<Novice.h>
#include"Bullet.h"


Player::Player() {
	posX_ = 1280 / 2;
	posY_ = 720 / 2;
	radius_ = 32;
	speed_ = 5;
	hp_ = 10;
	isAlive_ = true;
	transparency_ = 255;
	isBlink_ = false;
	blinkingTimer_ = 60;

	bullet_ = new Bullet(15, 8);
	bullet_->SetPosX_(posX_);
	bullet_->SetPosY_(posY_);
	bullet_->SetIsShot_(false);
	bullet_->SetRadius_(radius_ / 2);
	bullet_->SetSpeed_(speed_ + 3);


}

//Player::~Player() {
//	delete bullet_;
//}

//
//void Player::SetAll(int x, int y, int rad, int speed, int hp, bool isAlive, int transparency, bool isBlink, int blinkingTimer, Bullet *bullet)
//{
//	posX_ = x;
//	posY_ = y;
//	speed_ = speed;
//	hp_ = hp;
//	isAlive_ = isAlive;
//	transparency_ = transparency;
//	isBlink_ = isBlink;
//	blinkingTimer_ = blinkingTimer;
//
//
//	bullet_->posX_ = bullet->posX_;
//	bullet_->posY_ = bullet->posY_;
//	bullet_->isShot_ = bullet->isShot_;
//	bullet_->radius_ = bullet->radius_;
//	bullet_->speed_ = bullet->speed_;
//
//}
void Player::SetIsBlink(bool TorF)
{
	isBlink_ = TorF;
}
void Player::SetHp(int hp)
{
	hp_ = hp;
}
void Player::SetIsAlive(bool TorF)
{
	isAlive_ = TorF;
}



void Player::Update(char* keys)
{
	if (keys[DIK_A] && posX_ - radius_ >= 0)
	{
		posX_ -= speed_;
	}
	if (keys[DIK_D] && posX_ + radius_ <= 1280)
	{
		posX_ += speed_;
	}
	if (keys[DIK_W] && posY_ - radius_ >= 0)
	{
		posY_ -= speed_;
	}
	if (keys[DIK_S] && posY_ + radius_ <= 720)
	{
		posY_ += speed_;
	}

	if (keys[DIK_SPACE] && !(bullet_->GetIsShot_()))
	{
		bullet_->SetIsShot_(true);
		bullet_->SetPosX_(posX_);
		bullet_->SetPosY_(posY_);
	}
	bullet_->Update();


	/*if (isBlink_)
	{
		if(blinkingTimer_ <= 60 %% blin)
	}*/

}


void Player::Draw()
{
	Novice::DrawEllipse(static_cast<int>(posX_), static_cast<int>(posY_),
		radius_, radius_, 0.0f, 0xffffff00 + transparency_, kFillModeSolid);

	Novice::ScreenPrintf(20, 20, "playerHP = %d", hp_);
	bullet_->Draw();

}


void Player::initialize()
{
	posX_ = 1280 / 2;
	posY_ = 720 / 2;
	radius_ = 32;
	speed_ = 5;
	hp_ = 10;
	isAlive_ = true;
	transparency_ = 255;
	isBlink_ = false;
	blinkingTimer_ = 60;

	//bullet_->SetSpeed_(15);
	bullet_->SetRadius_(8);
	bullet_->SetPosX_(posX_);
	bullet_->SetPosY_(posY_);
	bullet_->SetIsShot_(false);
	bullet_->SetRadius_(radius_ / 2);
	bullet_->SetSpeed_(speed_ + 3);


}