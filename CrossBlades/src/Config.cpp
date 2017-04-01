#include "Config.h"
#include "DxLib.h"
#include "Ini.h"

Config::Config(ISceneChanger* changer) : Scene(changer) {
	// 画像のロード
	Image = LoadGraph("./dat/pic/Config.bmp");
	Cursor = 0;
	Tab = 0;
	Button = 0;
	TabStop = false;
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
	if(TabStop == true){
		if(CheckHitKey(KEY_INPUT_LEFT) != 0){
			if(Button == 0){
				Button = 2;
			}
			else{
				Button--;
			}
		}
		if(CheckHitKey(KEY_INPUT_RIGHT) != 0){
			if(Button == 2){
				Button = 0;
			}
			else{
				Button++;
			}
		}
	}
	else{
		if(CheckHitKey(KEY_INPUT_LEFT) != 0){
			if(Tab == 0){
				Tab = 3;
			}
			else{
				Tab--;
			}
			Cursor = 0;
		}
		if(CheckHitKey(KEY_INPUT_RIGHT) != 0){
			if(Tab == 3){
				Tab = 0;
			}
			else{
				Tab++;
			}
			Cursor = 0;
		}
	}
	if(CheckHitKey(KEY_INPUT_UP) != 0){
		if(Cursor == 0){
			Cursor = 4;
		}
		else{
			Cursor--;
		}
		Button = 0;
	}
	if(CheckHitKey(KEY_INPUT_DOWN) != 0){
		if(Cursor == 4){
			Cursor = 0;
		}
		else{
			Cursor++;
		}
		Button = 0;
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
	DrawLineAA(0.0f, static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 100), static_cast<float>(screenWidth), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 100), GetColor(255, 255, 255));
	DrawLineAA(0.0f, static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 200), static_cast<float>(screenWidth), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 200), GetColor(255, 255, 255));
	DrawLineAA(0.0f, static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 950), static_cast<float>(screenWidth), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 950), GetColor(255, 255, 255));
	switch(Tab){
	case 0:
		// ディスプレイ関連設定
		fontWidth = GetDrawStringWidthToHandle("Display", sizeof("Display"), Font);
		DrawStringToHandle((screenWidth / 4 - fontWidth) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Display", GetColor(255, 255, 0), Font);
		fontWidth = GetDrawStringWidthToHandle("Graphics", sizeof("Graphics"), Font);
		DrawStringToHandle(((screenWidth / 2 - fontWidth) + screenWidth / 4) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Graphics", GetColor(255, 255, 255), Font);
		fontWidth = GetDrawStringWidthToHandle("Sound", sizeof("Sound"), Font);
		DrawStringToHandle(((screenWidth / 2 + screenWidth / 4) - fontWidth + screenWidth / 2) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Sound", GetColor(255, 255, 255), Font);
		fontWidth = GetDrawStringWidthToHandle("Key Config", sizeof("Key Config"), Font);
		DrawStringToHandle((screenWidth - fontWidth + screenWidth * 3 / 4) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Key Config", GetColor(255, 255, 255), Font);
		switch(Cursor){
		case 0:
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 250), "ウィンドウモード :", GetColor(255, 255, 0), FontJ);
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 350), "解像度                :", GetColor(255, 255, 255), FontJ);
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 450), "表示ディスプレイ :", GetColor(255, 255, 255), FontJ);
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 550), "FPS表示             :", GetColor(255, 255, 255), FontJ);
			TabStop = false;
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1330), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1480), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 255), FALSE);
			fontWidth = GetDrawStringWidthToHandle("保存", sizeof("保存"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1480 - (fontWidth + screenWidth / 1920.0 * 1330)) / 2 + screenWidth / 1920.0 * 1330), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "保存", GetColor(255, 255, 255), FontJ);
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1530), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1680), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 255), FALSE);
			fontWidth = GetDrawStringWidthToHandle("ｷｬﾝｾﾙ", sizeof("ｷｬﾝｾﾙ"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1680 - (fontWidth + screenWidth / 1920.0 * 1530)) / 2 + screenWidth / 1920.0 * 1530), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "ｷｬﾝｾﾙ", GetColor(255, 255, 255), FontJ);
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1730), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1880), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 255), FALSE);
			fontWidth = GetDrawStringWidthToHandle("適用", sizeof("適用"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1880 - (fontWidth + screenWidth / 1920.0 * 1730)) / 2 + screenWidth / 1920.0 * 1730), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "適用", GetColor(255, 255, 255), FontJ);
			break;

		case 1:
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 250), "ウィンドウモード :", GetColor(255, 255, 255), FontJ);
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 350), "解像度                :", GetColor(255, 255, 0), FontJ);
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 450), "表示ディスプレイ :", GetColor(255, 255, 255), FontJ);
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 550), "FPS表示             :", GetColor(255, 255, 255), FontJ);
			TabStop = false;
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1330), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1480), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 255), FALSE);
			fontWidth = GetDrawStringWidthToHandle("保存", sizeof("保存"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1480 - (fontWidth + screenWidth / 1920.0 * 1330)) / 2 + screenWidth / 1920.0 * 1330), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "保存", GetColor(255, 255, 255), FontJ);
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1530), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1680), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 255), FALSE);
			fontWidth = GetDrawStringWidthToHandle("ｷｬﾝｾﾙ", sizeof("ｷｬﾝｾﾙ"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1680 - (fontWidth + screenWidth / 1920.0 * 1530)) / 2 + screenWidth / 1920.0 * 1530), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "ｷｬﾝｾﾙ", GetColor(255, 255, 255), FontJ);
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1730), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1880), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 255), FALSE);
			fontWidth = GetDrawStringWidthToHandle("適用", sizeof("適用"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1880 - (fontWidth + screenWidth / 1920.0 * 1730)) / 2 + screenWidth / 1920.0 * 1730), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "適用", GetColor(255, 255, 255), FontJ);
			break;

		case 2:
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 250), "ウィンドウモード :", GetColor(255, 255, 255), FontJ);
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 350), "解像度                :", GetColor(255, 255, 255), FontJ);
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 450), "表示ディスプレイ :", GetColor(255, 255, 0), FontJ);
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 550), "FPS表示             :", GetColor(255, 255, 255), FontJ);
			TabStop = false;
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1330), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1480), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 255), FALSE);
			fontWidth = GetDrawStringWidthToHandle("保存", sizeof("保存"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1480 - (fontWidth + screenWidth / 1920.0 * 1330)) / 2 + screenWidth / 1920.0 * 1330), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "保存", GetColor(255, 255, 255), FontJ);
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1530), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1680), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 255), FALSE);
			fontWidth = GetDrawStringWidthToHandle("ｷｬﾝｾﾙ", sizeof("ｷｬﾝｾﾙ"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1680 - (fontWidth + screenWidth / 1920.0 * 1530)) / 2 + screenWidth / 1920.0 * 1530), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "ｷｬﾝｾﾙ", GetColor(255, 255, 255), FontJ);
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1730), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1880), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 255), FALSE);
			fontWidth = GetDrawStringWidthToHandle("適用", sizeof("適用"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1880 - (fontWidth + screenWidth / 1920.0 * 1730)) / 2 + screenWidth / 1920.0 * 1730), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "適用", GetColor(255, 255, 255), FontJ);
			break;

		case 3:
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 250), "ウィンドウモード :", GetColor(255, 255, 255), FontJ);
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 350), "解像度                :", GetColor(255, 255, 255), FontJ);
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 450), "表示ディスプレイ :", GetColor(255, 255, 255), FontJ);
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 550), "FPS表示             :", GetColor(255, 255, 0), FontJ);
			TabStop = false;
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1330), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1480), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 255), FALSE);
			fontWidth = GetDrawStringWidthToHandle("保存", sizeof("保存"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1480 - (fontWidth + screenWidth / 1920.0 * 1330)) / 2 + screenWidth / 1920.0 * 1330), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "保存", GetColor(255, 255, 255), FontJ);
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1530), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1680), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 255), FALSE);
			fontWidth = GetDrawStringWidthToHandle("ｷｬﾝｾﾙ", sizeof("ｷｬﾝｾﾙ"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1680 - (fontWidth + screenWidth / 1920.0 * 1530)) / 2 + screenWidth / 1920.0 * 1530), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "ｷｬﾝｾﾙ", GetColor(255, 255, 255), FontJ);
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1730), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1880), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 255), FALSE);
			fontWidth = GetDrawStringWidthToHandle("適用", sizeof("適用"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1880 - (fontWidth + screenWidth / 1920.0 * 1730)) / 2 + screenWidth / 1920.0 * 1730), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "適用", GetColor(255, 255, 255), FontJ);
			break;

		case 4:
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 250), "ウィンドウモード :", GetColor(255, 255, 255), FontJ);
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 350), "解像度                :", GetColor(255, 255, 255), FontJ);
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 450), "表示ディスプレイ :", GetColor(255, 255, 255), FontJ);
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 550), "FPS表示             :", GetColor(255, 255, 255), FontJ);
			TabStop = true;
			switch(Button){
			case 0:
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1330), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1480), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 0), FALSE);
				fontWidth = GetDrawStringWidthToHandle("保存", sizeof("保存"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1480 - (fontWidth + screenWidth / 1920.0 * 1330)) / 2 + screenWidth / 1920.0 * 1330), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "保存", GetColor(255, 255, 0), FontJ);
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1530), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1680), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 255), FALSE);
				fontWidth = GetDrawStringWidthToHandle("ｷｬﾝｾﾙ", sizeof("ｷｬﾝｾﾙ"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1680 - (fontWidth + screenWidth / 1920.0 * 1530)) / 2 + screenWidth / 1920.0 * 1530), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "ｷｬﾝｾﾙ", GetColor(255, 255, 255), FontJ);
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1730), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1880), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 255), FALSE);
				fontWidth = GetDrawStringWidthToHandle("適用", sizeof("適用"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1880 - (fontWidth + screenWidth / 1920.0 * 1730)) / 2 + screenWidth / 1920.0 * 1730), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "適用", GetColor(255, 255, 255), FontJ);
				break;

			case 1:
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1330), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1480), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 255), FALSE);
				fontWidth = GetDrawStringWidthToHandle("保存", sizeof("保存"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1480 - (fontWidth + screenWidth / 1920.0 * 1330)) / 2 + screenWidth / 1920.0 * 1330), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "保存", GetColor(255, 255, 255), FontJ);
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1530), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1680), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 0), FALSE);
				fontWidth = GetDrawStringWidthToHandle("ｷｬﾝｾﾙ", sizeof("ｷｬﾝｾﾙ"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1680 - (fontWidth + screenWidth / 1920.0 * 1530)) / 2 + screenWidth / 1920.0 * 1530), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "ｷｬﾝｾﾙ", GetColor(255, 255, 0), FontJ);
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1730), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1880), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 255), FALSE);
				fontWidth = GetDrawStringWidthToHandle("適用", sizeof("適用"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1880 - (fontWidth + screenWidth / 1920.0 * 1730)) / 2 + screenWidth / 1920.0 * 1730), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "適用", GetColor(255, 255, 255), FontJ);
				break;

			case 2:
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1330), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1480), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 255), FALSE);
				fontWidth = GetDrawStringWidthToHandle("保存", sizeof("保存"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1480 - (fontWidth + screenWidth / 1920.0 * 1330)) / 2 + screenWidth / 1920.0 * 1330), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "保存", GetColor(255, 255, 255), FontJ);
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1530), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1680), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 255), FALSE);
				fontWidth = GetDrawStringWidthToHandle("ｷｬﾝｾﾙ", sizeof("ｷｬﾝｾﾙ"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1680 - (fontWidth + screenWidth / 1920.0 * 1530)) / 2 + screenWidth / 1920.0 * 1530), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "ｷｬﾝｾﾙ", GetColor(255, 255, 255), FontJ);
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1730), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1880), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 0), FALSE);
				fontWidth = GetDrawStringWidthToHandle("適用", sizeof("適用"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1880 - (fontWidth + screenWidth / 1920.0 * 1730)) / 2 + screenWidth / 1920.0 * 1730), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "適用", GetColor(255, 255, 0), FontJ);
				break;

			default:
				break;

			}
			break;

		default:
			break;

		}
		break;

	case 1:
		// グラフィック関連設定
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
		// サウンド関連設定
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
		// キーコンフィグ関連設定
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