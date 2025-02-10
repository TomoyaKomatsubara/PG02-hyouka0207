#include"Player.h"
#include"Enemy.h"
#pragma once
class Scene
{
public:
	Scene();

	int winCount_;
	bool isWin_;
	bool isLose_;
	void Update_(char* keys);
	void Draw_();
	void Initialize();

	Player* player;
	Enemy* enemy[2];
};

