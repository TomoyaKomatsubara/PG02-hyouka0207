#pragma once
//#include"Transform.h"
#include"Bullet.h"
class Player
{
public:
	Player();
	//~Player();

	int getPosX_() { return posX_; };
	int getPosY_() { return posY_; };
	int getRadius_() { return radius_; };
	int getSpeed_() { return speed_; };
	int getHp_() { return hp_; };
	bool getIsAlive_() { return isAlive_; };
	int getTransparency_() { return transparency_; };
	bool getIsBlink_() { return isBlink_; };
	int getBlinkingTimer_() { return blinkingTimer_; };
	Bullet *getBullet_() { return bullet_; }

	/*void SetAll(int x, int y, int rad, int speed, int hp, bool isAlive, int transparency, bool isBlink, int blinkingTimer,Bullet *bullet_);*/
	void SetIsBlink(bool TorF);
	void SetHp(int hp);
	void SetIsAlive(bool TorF);

	void Update(char* keys);

	void Draw();

	void initialize();

public:
	Bullet* setBullet_() { return bullet_; };


private:
	//Transform transform_;
	int posX_;
	int posY_;
	int radius_;
	int speed_;
	int hp_;
	bool isAlive_;
	int transparency_;
	bool isBlink_;
	int blinkingTimer_;
	Bullet* bullet_;
};
