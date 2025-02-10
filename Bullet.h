#pragma once
//#include<Transform.h>
class Bullet
{
public:

	Bullet(int speed, int radius);
	//~Bullet();

	//Transform transform_;
	int GetPosX_() { return posX_; };
	int GetPosY_() { return posY_; };
	int GetRadius_() { return radius_; };
	int GetSpeed_() { return speed_; };
	bool GetIsShot_() { return isShot_; };
  
	void SetIsShot_(bool TorF);
	void SetPosX_(int x);
	void SetPosY_(int y);
	void SetRadius_(int radius);
	void SetSpeed_(int speed);

	//void Move(char* keys);

	void Update();

	void Draw();

private:
	int posX_;
	int posY_;
	int radius_;
	int speed_;
	bool isShot_;
};



