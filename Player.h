#pragma once
//#include"Transform.h"
#include"Bullet.h"
class Player
{
public:
	Player();
	//~Player();

	void Update(char* keys);

	void Draw();

public:
	Bullet* bullet_;


public:
	//Transform transform_;
	int posX_;
	int posY_;
	int radius_;
	int speed_;
};
