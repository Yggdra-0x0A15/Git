#pragma once

class FPS{
public:
	FPS();
	~FPS();
	// FPS更新
	bool Update();
	// FPS描画
	void Draw();
	// 待機
	void Wait();

private:
	//測定開始時刻
	int StartTime;
	//カウンタ
	int Count;
	//fps
	float Fps;
	//平均を取るサンプル数
	static const int N = 60;
	//設定したFPS
	static const int SettingFPS = 60;

};