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

// FPS�X�V
bool FPS::Update(){
	if(Count == 0){
		// �������L��
		StartTime = GetNowCount();
	}
	if(Count == N){
		// ���ς��v�Z����
		int t = GetNowCount();
		Fps = 1000.f / ((t - StartTime) / (float)N);
		Count = 0;
		StartTime = t;
	}
	Count++;
	return true;
}

// FPS�`��
void FPS::Draw(){
	int height;

	GetDrawScreenSize(NULL, &height);
	DrawFormatString(0, height - 20, GetColor(255, 255, 255), "%.1f", Fps);
}

// �ҋ@
void FPS::Wait(){
	//������������
	int tookTime = GetNowCount() - StartTime;
	//�҂ׂ�����
	int waitTime = Count * 1000 / SettingFPS - tookTime;
	if(waitTime > 0){
		//�ҋ@
		Sleep(waitTime);
	}
}
