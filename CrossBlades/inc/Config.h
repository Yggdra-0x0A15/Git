#pragma once
#include "Scene.h"
#include "Ini.h"

//�ݒ��ʃN���X
class Config : public Scene {

public:
	Config(ISceneChanger* changer);
	//������
	void Initialize() override;
	//�X�V
	void Update() override;
	// �`��
	void Draw() override;

private:
	Ini* Ini_p;
	// �E�B���h�E���[�h
	unsigned short Mode;
	// �E�B���h�E��
	int Width;
	// �E�B���h�E��
	int Height;
	// �\���f�B�X�v���C
	int Display;
	// FPS�\��
	bool Fps;

	unsigned short Cursor;
	unsigned short Tab;
	unsigned short Button;
	unsigned short IndexResolution;
	unsigned short IndexDisplay;
	bool TabStop;
	bool Setting;
	// ��{��ʕ`��
	void DrawBase(int screenWidth, int screenHeight);
	// �ݒ�K�p
	void ApplySetting();
	// Ini�ݒ�
	void SetIni();
};
// End Of File