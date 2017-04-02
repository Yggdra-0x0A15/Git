#pragma once

class Ini{
public:
	// �C���X�^���X�擾
	static Ini* GetInstance();
	// ini�t�@�C��������
	void Initialize();
	// ini�Ǎ�
	int Read();
	// ini����
	void Write();
	// �E�B���h�E���[�h�擾
	unsigned short GetMode();
	// �E�B���h�E���[�h�ݒ�
	void SetMode(int mode);
	// �E�B���h�E���擾
	int GetWidth();
	// �E�B���h�E���ݒ�
	void SetWidth(int width);
	// �E�B���h�E���擾
	int GetHeight();
	// �E�B���h�E���ݒ�
	void SetHeight(int height);
	// �\���f�B�X�v���C�擾
	int GetDisplay();
	// �\���f�B�X�v���C�ݒ�
	void SetDisplay(int display);
	// FPS�\���擾
	bool GetFps();
	// FPS�\���ݒ�
	void SetFps(bool fps);

private:
	Ini(){}
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

};
// End Of File