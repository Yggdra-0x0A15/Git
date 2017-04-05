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
	// 変更前ウィンドウモード
	unsigned short PreMode;
	// 変更前ウィンドウ幅
	int PreWidth;
	// 変更前ウィンドウ高
	int PreHeight;
	// 変更前表示ディスプレイ
	int PreDisplay;
	// 変更前FPS表示
	bool PreFps;

	unsigned short Cursor;
	unsigned short Tab;
	unsigned short Button;
	unsigned short IndexMode;
	unsigned short IndexResolution;
	unsigned short IndexDisplay;
	bool TabStop;
	bool Setting;
	// 基本画面描画
	void DrawBase(int screenWidth, int screenHeight);
	// 設定適用
	void ApplySetting();
	// キャンセル
	void Cancel();
	// 変更取得
	bool GetChange();
	// ウィンドウ変更取得
	bool GetChangeWindow();

	static bool Apply;
};
// End Of File