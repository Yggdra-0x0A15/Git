#include "Config.h"
#include "DxLib.h"

Config::Config(ISceneChanger* changer) : Scene(changer) {
	int screenWidth;

	// 画像のロード
	Image = LoadGraph("./dat/pic/Config.bmp");
	// フォント作成
	GetDrawScreenSize(&screenWidth, NULL);
	Font = CreateFontToHandle("Segoe Print", static_cast<int>(static_cast<double>(screenWidth) / 1920.0 * 48), 9, DX_FONTTYPE_ANTIALIASING_EDGE);
	Cursor = 0;
	Tab = 0;
}

// 初期化
void Config::Initialize(){
}

// 更新
void Config::Update(){
	// Escキーが押されていたら
	if(CheckHitKey(KEY_INPUT_ESCAPE) != 0){
		// シーンをメニューに変更
		SceneChanger_p->ChangeScene(SceneMenu);
	}
	if(Cursor == 0){
		if(CheckHitKey(KEY_INPUT_LEFT) != 0){
			if(Tab == 0){
				Tab = 3;
			}
			else{
				Tab--;
			}
		}
		if(CheckHitKey(KEY_INPUT_RIGHT) != 0){
			if(Tab == 3){
				Tab = 0;
			}
			else{
				Tab++;
			}
		}
	}
	if(CheckHitKey(KEY_INPUT_UP) != 0){
		if(Cursor == 0){
			Cursor = 3;
		}
		else{
			Cursor--;
		}
	}
	if(CheckHitKey(KEY_INPUT_DOWN) != 0){
		if(Cursor == 3){
			Cursor = 0;
		}
		else{
			Cursor++;
		}
	}
}

// 描画
void Config::Draw(){
	int fontWidth;
	int screenWidth;
	int screenHeight;
	// 親クラスの描画メソッドを呼ぶ
	Scene::Draw();
	GetWindowSize(&screenWidth, &screenHeight);
	DrawLine(0, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 100), screenWidth, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 100), GetColor(255, 255, 255));
	DrawLine(0, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 200), screenWidth, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 200), GetColor(255, 255, 255));
	switch(Tab){
	case 0:
		fontWidth = GetDrawStringWidthToHandle("Display", sizeof("Display"), Font);
		DrawStringToHandle((screenWidth / 4 - fontWidth) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Display", GetColor(255, 255, 0), Font);
		fontWidth = GetDrawStringWidthToHandle("Graphics", sizeof("Graphics"), Font);
		DrawStringToHandle(((screenWidth / 2 - fontWidth) + screenWidth / 4) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Graphics", GetColor(255, 255, 255), Font);
		fontWidth = GetDrawStringWidthToHandle("Sound", sizeof("Sound"), Font);
		DrawStringToHandle(((screenWidth / 2 + screenWidth / 4) - fontWidth + screenWidth / 2) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Sound", GetColor(255, 255, 255), Font);
		fontWidth = GetDrawStringWidthToHandle("Key Config", sizeof("Key Config"), Font);
		DrawStringToHandle((screenWidth - fontWidth + screenWidth * 3 / 4) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Key Config", GetColor(255, 255, 255), Font);
		break;

	case 1:
		fontWidth = GetDrawStringWidthToHandle("Display", sizeof("Display"), Font);
		DrawStringToHandle((screenWidth / 4 - fontWidth) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Display", GetColor(255, 255, 255), Font);
		fontWidth = GetDrawStringWidthToHandle("Graphics", sizeof("Graphics"), Font);
		DrawStringToHandle(((screenWidth / 2 - fontWidth) + screenWidth / 4) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Graphics", GetColor(255, 255, 0), Font);
		fontWidth = GetDrawStringWidthToHandle("Sound", sizeof("Sound"), Font);
		DrawStringToHandle(((screenWidth / 2 + screenWidth / 4) - fontWidth + screenWidth / 2) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Sound", GetColor(255, 255, 255), Font);
		fontWidth = GetDrawStringWidthToHandle("Key Config", sizeof("Key Config"), Font);
		DrawStringToHandle((screenWidth - fontWidth + screenWidth * 3 / 4) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Key Config", GetColor(255, 255, 255), Font);
		break;

	case 2:
		fontWidth = GetDrawStringWidthToHandle("Display", sizeof("Display"), Font);
		DrawStringToHandle((screenWidth / 4 - fontWidth) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Display", GetColor(255, 255, 255), Font);
		fontWidth = GetDrawStringWidthToHandle("Graphics", sizeof("Graphics"), Font);
		DrawStringToHandle(((screenWidth / 2 - fontWidth) + screenWidth / 4) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Graphics", GetColor(255, 255, 255), Font);
		fontWidth = GetDrawStringWidthToHandle("Sound", sizeof("Sound"), Font);
		DrawStringToHandle(((screenWidth / 2 + screenWidth / 4) - fontWidth + screenWidth / 2) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Sound", GetColor(255, 255, 0), Font);
		fontWidth = GetDrawStringWidthToHandle("Key Config", sizeof("Key Config"), Font);
		DrawStringToHandle((screenWidth - fontWidth + screenWidth * 3 / 4) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Key Config", GetColor(255, 255, 255), Font);
		break;

	case 3:
		fontWidth = GetDrawStringWidthToHandle("Display", sizeof("Display"), Font);
		DrawStringToHandle((screenWidth / 4 - fontWidth) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Display", GetColor(255, 255, 255), Font);
		fontWidth = GetDrawStringWidthToHandle("Graphics", sizeof("Graphics"), Font);
		DrawStringToHandle(((screenWidth / 2 - fontWidth) + screenWidth / 4) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Graphics", GetColor(255, 255, 255), Font);
		fontWidth = GetDrawStringWidthToHandle("Sound", sizeof("Sound"), Font);
		DrawStringToHandle(((screenWidth / 2 + screenWidth / 4) - fontWidth + screenWidth / 2) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Sound", GetColor(255, 255, 255), Font);
		fontWidth = GetDrawStringWidthToHandle("Key Config", sizeof("Key Config"), Font);
		DrawStringToHandle((screenWidth - fontWidth + screenWidth * 3 / 4) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Key Config", GetColor(255, 255, 0), Font);
		break;

	default:
		break;
	}
}
// End Of File