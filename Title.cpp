#include "Title.h"
#include "Player.h"
#include "Enemy.h"
#include<Novice.h>

//Novice::Initialize(0,0,0);
//// Novice::Initialize(0,0,0);
//int titleHandle = Novice::LoadTexture("./Resources/Images/title.png");

Title::Title()
{
	//Enemy* enemy = new Enemy;
	player = new Player();

	startButtonPosX_ = 300;
	startButtonPosY_ = 400;
	startButtonWidth_ = 680;
	startButtonHeight_ = 200;
	startButtonColor_ = 0x9acd32ff;
	isPress_ = false;
}
//条件確認はGet　値を仮に変化させるのはSet(Setを通って、引数がprivateにある目標に代入される)
void Title::Update_(char* keys)
{
	player->Update(keys);
	
	if (player->getPosX_() + player->getRadius_() > startButtonPosX_ &&
		player->getPosX_() - player->getRadius_() < startButtonPosX_ + startButtonWidth_)
	{
		isPress_ = true;
	}
}


void Title::Draw_()
{
	player->Draw();
	//Novice::DrawSprite(1280 / 2 - 500, 720 / 2, titleHandle, 1.0f, 1.0f, 0.0f, WHITE);
	Novice::DrawBox(startButtonPosX_, startButtonPosY_, startButtonWidth_, startButtonHeight_, 0.0f, startButtonColor_,kFillModeSolid);
}

void Title::Initialize()
{
	player->initialize();
}

