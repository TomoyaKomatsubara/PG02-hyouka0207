#pragma once
#include"Player.h"
class Title
{
public:
	Title();

	bool isTabUp;
	void Update_(char* keys);
	void Draw_();
	void Initialize();
	Player* player;

	int titleHandle;
	int pressSpaceHandle;
	int startButtonPosX_;
	int startButtonPosY_;
	int startButtonWidth_;
	int startButtonHeight_;
	int startButtonColor_;
	bool isPress_;
	
};


