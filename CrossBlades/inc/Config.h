#pragma once
#include "Scene.h"
#include "Ini.h"

//設定画面クラス
class Config : public Scene {

public:
	Config(ISceneChanger* changer);
	//初期化
	void Initialize() override;
	//更新
	void Update() override;
	// 描画
	void Draw() override;

private:
	Ini* Ini_p;
	// ウィンドウモード
	unsigned short Mode;
	// ウィンドウ幅
	int Width;
	// ウィンドウ高
	int Height;
	// 表示ディスプレイ
	int Display;
	// FPS表示
	bool Fps;

	unsigned short Cursor;
	unsigned short Tab;
	unsigned short Button;
	unsigned short IndexResolution;
	unsigned short IndexDisplay;
	bool TabStop;
	bool Setting;
	// 基本画面描画
	void DrawBase(int screenWidth, int screenHeight);
	// 設定適用
	void ApplySetting();
	// Ini設定
	void SetIni();
};
// End Of File