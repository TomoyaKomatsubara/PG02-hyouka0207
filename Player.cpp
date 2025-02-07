#include "Player.h"
#include "stdio.h"
#include<Novice.h>
#include"Bullet.h"


Player::Player() {
	posX_ = 1280 / 2;
	posY_ = 720 / 2;
	radius_ = 32;
	speed_ = 5;

	bullet_ = new Bullet(15, 8);
	bullet_->posX_ = posX_;
	bullet_->posY_ = posY_;
	bullet_->isShot_ = false;
	bullet_->radius_ = radius_ / 2;
	bullet_->speed_ = speed_ + 3;


}

//Player::~Player() {
//	delete bullet_;
//}

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

	if (keys[DIK_SPACE] && !(bullet_->isShot_))
	{
		bullet_->isShot_ = true;
		bullet_->posX_ = posX_;
		bullet_->posY_ = posY_;
	}
	bullet_->Update();


}


void Player::Draw()
{
	Novice::DrawEllipse(static_cast<int>(posX_), static_cast<int>(posY_),
		radius_, radius_, 0.0f, WHITE, kFillModeSolid);


	bullet_->Draw();

}
