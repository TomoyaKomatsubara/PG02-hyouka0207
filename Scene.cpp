#include "Scene.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include<math.h>
#include<Novice.h>


Scene::Scene()
{
	winCount_ = 0;
	isWin_ = false;
	isLose_ = false;
	//Enemy* enemy = new Enemy;
	player = new Player();
	enemy[0] = new Enemy(100, 100);
	enemy[1] = new Enemy(250, 300);
}
	//条件確認はGet　値を仮に変化させるのはSet(Setを通って、引数がprivateにある目標に代入される)
void Scene::Update_(char* keys)
{
	player->Update(keys);
	for (int i = 0; i < 2; i++)
	{
		enemy[i]->Update();
		float distX = static_cast<float>(enemy[i]->getPosX_() - player->getBullet_()->GetPosX_());//enemyToBullet
		float distY = static_cast<float>(enemy[i]->getPosY_() - player->getBullet_()->GetPosY_());
		float dist = sqrtf((distX * distX) + (distY * distY));
		int radius = enemy[i]->getRadius_() + player->getBullet_()->GetRadius_();
		if (enemy[i]->getIsAlive_())
		{
			if (dist <= radius) {
				enemy[i]->SetIsAlive(false);
				enemy[i]->SetRespawnTimer(60);
				winCount_++;
			}
		}

		float playerToEnemyX = static_cast<float>(enemy[i]->getPosX_() - player->getPosX_());//enemyToPlayer
		float playerToEnemyY = static_cast<float>(enemy[i]->getPosY_() - player->getPosY_());
		float playerToEnemy = sqrtf((playerToEnemyX * playerToEnemyX) + (playerToEnemyY * playerToEnemyY));
		int addPlayerEnemyRadius = enemy[i]->getRadius_() + player->getRadius_();
		if (enemy[i]->getIsAlive_())
		{
			if (playerToEnemy <= addPlayerEnemyRadius) {

				enemy[i]->SetIsAlive(false);	//まずenemyのisAlive_をfalseにする
				winCount_++;
				if (!player->getIsBlink_())
				{
					player->SetIsBlink(true);
				}
				if (player->getHp_() - enemy[i]->getToPlayerDamage_() <= 0)//	引いたときHP０以下ならplayerは倒れた
				{
					player->SetHp(0);
					player->SetIsAlive(false);


				} 
				else//それ以外の場合playerのHPを削る
				{
					player->SetHp(player->getHp_() - enemy[i]->getToPlayerDamage_());

				}
				enemy[i]->SetRespawnTimer(60);
			}
		}
	}

	if (player->getHp_() <= 0)
	{
		isLose_ = true;
	}
	else if (winCount_ >= 10)
	{
		isWin_ = true;
	}


}


void Scene::Draw_()
{
	player->Draw();
	for (int i = 0; i < 2; i++)
	{
		enemy[i]->Draw();
	}
	Novice::ScreenPrintf(20, 50, "winCount = %d", winCount_);

}

void Scene::Initialize()
{
	winCount_ = 0;
	isWin_ = false;
	isLose_ = false;
	player->initialize();
	enemy[0]->Initialize(100,100);
	enemy[1]->Initialize(250,300);
	
}

