#include <Novice.h>
#include"Player.h"
//#include"Bullet.h"
#include"Enemy.h"

const char kWindowTitle[] = "GC1B_04_コマツバラ_トモヤ_タイトル";

//bool Enemy::isAlive_;	//staticとして宣言したものをこの形でmainに書くことで
//同じクラス内で共有される

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Player* player = new Player();
	Enemy* enemy[2];
	enemy[0] = new Enemy(100, 100);
	enemy[1] = new Enemy(250, 300);




	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		player->Update(keys);
		for (int i = 0; i < 2; i++)
		{
			enemy[i]->Update();
			float distX = static_cast<float>(enemy[i]->posX_ - player->bullet_->posX_);
			float distY = static_cast<float>(enemy[i]->posY_ - player->bullet_->posY_);
			float dist = (distX * distX) + (distY * distY);
			int radius = enemy[i]->radius_ + enemy[i]->radius_;
			if (enemy[i]->isAlive_)
			{
				if (dist <= radius * radius) {

					enemy[i]->isAlive_ = false;
					enemy[i]->respawnTimer_ = 60;
				}
			}
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		player->Draw();
		for (int i = 0; i < 2; i++)
		{
			enemy[i]->Draw();
		}


		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete player;//ゲーム終了時
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}