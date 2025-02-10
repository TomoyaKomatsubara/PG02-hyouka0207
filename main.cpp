#include <Novice.h>
#include <Math.h>
#include"Player.h"
//#include"Bullet.h"
#include"Enemy.h"
#include"Title.h"
#include"Scene.h"
#include"WinScene.h"
#include"LoseScene.h"

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

	int nowScene = 0;

	/*Player* player = new Player();
	Enemy* enemy[2];
	enemy[0] = new Enemy(100, 100);
	enemy[1] = new Enemy(250, 300);*/

	Title *title = new Title();
	Scene *scene = new Scene();
	WinScene *winScene = new WinScene();
	LoseScene *loseScene = new LoseScene();


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

		if (keys[DIK_0] && !preKeys[DIK_0])
		{
			nowScene = 0;
			title->Initialize();
			scene->Initialize();
		}
		if (keys[DIK_1] && !preKeys[DIK_1])
		{
			nowScene = 1;
			title->Initialize();
			scene->Initialize();
		}


		if (nowScene == 0)
		{
			title->Update_(keys);
		}
		else if (nowScene == 1)
		{
			scene->Update_(keys);
		}

		if (scene->isWin_)
		{
			nowScene = 3;
		}
		else if (scene->isLose_)
		{
			nowScene = 4;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		/*player->Draw();
		for (int i = 0; i < 2; i++)
		{
			enemy[i]->Draw();
		}*/
		if (nowScene == 0)
		{
			title->Draw_();
		}
		else if (nowScene == 1)
		{
			scene->Draw_();
		}
		else if (nowScene == 3)
		{
			winScene->Draw_();
		}
		else if (nowScene == 4)
		{
			loseScene->Draw_();
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

	//delete player;//ゲーム終了時
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}