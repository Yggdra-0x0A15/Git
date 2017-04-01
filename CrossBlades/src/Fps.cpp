#include <math.h>
#include "Fps.h"
#include "DxLib.h"

FPS::FPS(){
	StartTime = 0;
	Count = 0;
	Fps = 0;
}

FPS::~FPS(){
}

// FPS更新
bool FPS::Update(){
	if(Count == 0){
		// 時刻を記憶
		StartTime = GetNowCount();
	}
	if(Count == N){
		// 平均を計算する
		int t = GetNowCount();
		Fps = 1000.f / ((t - StartTime) / (float)N);
		Count = 0;
		StartTime = t;
	}
	Count++;
	return true;
}

// FPS描画
void FPS::Draw(){
	int height;

	GetDrawScreenSize(NULL, &height);
	DrawFormatString(0, height - 20, GetColor(255, 255, 255), "%.1f", Fps);
}

// 待機
void FPS::Wait(){
	//かかった時間
	int tookTime = GetNowCount() - StartTime;
	//待つべき時間
	int waitTime = Count * 1000 / SettingFPS - tookTime;
	if(waitTime > 0){
		//待機
		Sleep(waitTime);
	}
}
