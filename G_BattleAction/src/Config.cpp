#include "Config.h"
#include "DxLib.h"

Config::Config(ISceneChanger* changer) : Scene(changer) {
}

// 初期化
void Config::Initialize(){
	// 画像のロード
	ImageHandle = LoadGraph("./dat/pic/Loading.bmp");
}

// 更新
void Config::Update(){
	// Escキーが押されていたら
	if(CheckHitKey(KEY_INPUT_ESCAPE) != 0){
		// シーンをメニューに変更
		SceneChanger_p->ChangeScene(SceneMenu);
	}
}

// 描画
void Config::Draw(){
	// 親クラスの描画メソッドを呼ぶ
	Scene::Draw();
}
// End Of File