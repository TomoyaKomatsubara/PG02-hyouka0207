#pragma once
//#include<Transform.h>
class Bullet
{
public:

	Bullet(int speed, int radius);
	//~Bullet();

	//Transform transform_;
	int posX_;
	int posY_;
	int radius_;
	int speed_;
	bool isShot_;



	//void Move(char* keys);

	void Update();

	void Draw();

};



