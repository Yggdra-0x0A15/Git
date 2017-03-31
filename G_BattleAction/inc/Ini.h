#pragma once

class Ini{
public:
	// iniファイル初期化
	void Initialize();
	// ini読込
	int Read();
	// ウィンドウモード取得
	int GetMode();
	// ウィンドウモード設定
	void SetMode(int mode);
	// ウィンドウ幅取得
	int GetWidth();
	// ウィンドウ幅設定
	void SetWidth(int width);
	// ウィンドウ高取得
	int GetHeight();
	// ウィンドウ高設定
	void SetHeight(int height);
	// 表示ディスプレイ取得
	int GetDisplay();
	// 表示ディスプレイ設定
	void SetDisplay(int display);

private:
	// ウィンドウモード
	int Mode;
	// ウィンドウ幅
	int Width;
	// ウィンドウ高
	int Height;
	// 表示ディスプレイ
	int Display;

};
// End Of File