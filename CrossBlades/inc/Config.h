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
	// �ύX�O�E�B���h�E���[�h
	unsigned short PreMode;
	// �ύX�O�E�B���h�E��
	int PreWidth;
	// �ύX�O�E�B���h�E��
	int PreHeight;
	// �ύX�O�\���f�B�X�v���C
	int PreDisplay;
	// �ύX�OFPS�\��
	bool PreFps;

	unsigned short Cursor;
	unsigned short Tab;
	unsigned short Button;
	unsigned short IndexMode;
	unsigned short IndexResolution;
	unsigned short IndexDisplay;
	bool TabStop;
	bool Setting;
	// ��{��ʕ`��
	void DrawBase(int screenWidth, int screenHeight);
	// �ݒ�K�p
	void ApplySetting();
	// �L�����Z��
	void Cancel();
	// �ύX�擾
	bool GetChange();
	// �E�B���h�E�ύX�擾
	bool GetChangeWindow();

	static bool Apply;
};
// End Of File