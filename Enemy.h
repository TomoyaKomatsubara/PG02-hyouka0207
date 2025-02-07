#pragma once
class Enemy
{
public:

	int posX_;
	int posY_;
	int speed_;
	int radius_;
	bool isAlive_;   //staticをつけることで静的メンバ変数になる
	int respawnTimer_;

	Enemy(int posX, int posY);

	void Update();
	void Draw();

};
