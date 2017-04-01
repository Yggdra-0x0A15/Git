#include "Loading.h"
#include "DxLib.h"

Loading::Loading(ISceneChanger* changer) : Scene(changer){
	// 画像のロード
	Image = LoadGraph("./dat/pic/Loading.bmp");
	DrawComplete = false;
}

// 初期化
void Loading::Initialize(){
}

// 更新
void Loading::Update(){
	if(DrawComplete == true){
		SceneChanger_p->ChangeScene(SceneGame);
	}
}

// 描画
void Loading::Draw(){
	int fontWidth;
	int screenWidth;
	int screenHeight;

	// 親クラスの描画メソッドを呼ぶ
	Scene::Draw();
	GetDrawScreenSize(&screenWidth, &screenHeight);
	fontWidth = GetDrawStringWidthToHandle("Now Loading ...", sizeof("Now Loading ..."), Font);
	DrawStringToHandle(screenWidth - fontWidth - static_cast<int>(static_cast<double>(screenWidth) / 1920.0 * 10), screenHeight - static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 65), "Now Loading ...", GetColor(255, 255, 255), Font);
	DrawComplete = true;
}
// End Of File