#pragma once

class FPS{
public:
	FPS();
	~FPS();
	// FPS�X�V
	bool Update();
	// FPS�`��
	void Draw();
	// �ҋ@
	void Wait();

private:
	//����J�n����
	int StartTime;
	//�J�E���^
	int Count;
	//fps
	float Fps;
	//���ς����T���v����
	static const int N = 60;
	//�ݒ肵��FPS
	static const int SettingFPS = 60;

};