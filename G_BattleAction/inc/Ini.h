#pragma once

class Ini{
public:
	// ini�t�@�C��������
	void Initialize();
	// ini�Ǎ�
	int Read();
	// �E�B���h�E���[�h�擾
	int GetMode();
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

private:
	// �E�B���h�E���[�h
	int Mode;
	// �E�B���h�E��
	int Width;
	// �E�B���h�E��
	int Height;
	// �\���f�B�X�v���C
	int Display;

};
// End Of File