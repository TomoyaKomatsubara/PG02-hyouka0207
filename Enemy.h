#pragma once
class Enemy
{
public:

	Enemy(int posX, int posY);

	int getPosX_() { return posX_; };
	int getPosY_() { return posY_; };
	int getSpeed_() { return speed_; };
	int getRadius_() { return radius_; };
	bool getIsAlive_() { return isAlive_; };
	int getRespawnTimer_() { return respawnTimer_; };
	int getToPlayerDamage_() { return toPlayerDamage_; };

	void SetIsAlive(bool TorF);

	void SetRespawnTimer(int remainTimer);
	void SetPosX_(int posX);
	void SetPosY_(int posY);
	void Update();
	void Draw();
	void Initialize(int posX,int posY);

private:
	int posX_;
	int posY_;
	int speed_;
	int radius_;
	bool isAlive_;   //staticをつけることで静的メンバ変数になる
	int respawnTimer_;
	int toPlayerDamage_;



};
