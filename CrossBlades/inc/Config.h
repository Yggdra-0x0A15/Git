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
	unsigned short Cursor;
	unsigned short Tab;
	unsigned short Button;
	unsigned short IndexMode;
	unsigned short IndexResolution;
	unsigned short IndexDisplay;
	bool TabStop;
	bool Setting;
	// �ݒ�K�p
	void ApplySetting();
};
// End Of File