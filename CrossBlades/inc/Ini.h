#pragma once

class Ini{
public:
	// インスタンス取得
	static Ini* GetInstance();
	// iniファイル初期化
	void Initialize();
	// ini読込
	int Read();
	// ini書込
	void Write();
	// ウィンドウモード取得
	unsigned short GetMode();
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
	// 解像度数取得
	unsigned short GetNumResolution();
	// 解像度数設定
	void SetNumResolution(unsigned short numResolution);
	// 表示ディスプレイ取得
	int GetDisplay();
	// 表示ディスプレイ設定
	void SetDisplay(int display);
	// 表示ディスプレイ取得
	unsigned short GetNumDisplay();
	// 表示ディスプレイ設定
	void SetNumDisplay(unsigned short numDisplay);
	// FPS表示取得
	bool GetFps();
	// FPS表示設定
	void SetFps(bool fps);

private:
	Ini(){}
	// ウィンドウモード
	unsigned short Mode;
	// ウィンドウ幅
	int Width;
	// ウィンドウ高
	int Height;
	// 解像度数
	unsigned short NumResolution;
	// 表示ディスプレイ
	int Display;
	// ディスプレイ数
	unsigned short NumDisplay;
	// FPS表示
	bool Fps;

};
// End Of File