#include "DxLib.h"
#include "Ini.h"

// �C���X�^���X�擾
Ini* Ini::GetInstance(){
	// �C���X�^���X
	static Ini Instance;
	return &Instance;
}

// ini�t�@�C��������
void Ini::Initialize(){
	HANDLE retCreate;
	BOOL retVal;
	char errCode[23];
	// ini����
	DeleteFile("./Config.ini");
	retCreate = CreateFile("./Config.ini", GENERIC_ALL, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
	CloseHandle(retCreate);
	// �E�B���h�E���[�h
	retVal = WritePrivateProfileString("Window", "Mode", "0", "./Config.ini");
	if(retVal == FALSE){
		sprintf_s(errCode, "ErrorCode = 0x%X", GetLastError());
		MessageBox(GetMainWindowHandle(), _T(errCode), _T("Error!"), MB_OK);
	}
	Mode = 0;
	// �E�B���h�E��
	retVal = WritePrivateProfileString("Window", "Width", "1600", "./Config.ini");
	if(retVal == FALSE){
		sprintf_s(errCode, "ErrorCode = 0x%X", GetLastError());
		MessageBox(GetMainWindowHandle(), _T(errCode), _T("Error!"), MB_OK);
	}
	Width = 1600;
	// �E�B���h�E��
	retVal = WritePrivateProfileString("Window", "Height", "900", "./Config.ini");
	if(retVal == FALSE){
		sprintf_s(errCode, "ErrorCode = 0x%X", GetLastError());
		MessageBox(GetMainWindowHandle(), _T(errCode), _T("Error!"), MB_OK);
	}
	Height = 900;
	// �\���f�B�X�v���C
	retVal = WritePrivateProfileString("Window", "Display", "0", "./Config.ini");
	if(retVal == FALSE){
		sprintf_s(errCode, "ErrorCode = 0x%X", GetLastError());
		MessageBox(GetMainWindowHandle(), _T(errCode), _T("Error!"), MB_OK);
	}
	Display = 0;
	// FPS�\��
	retVal = WritePrivateProfileString("Window", "FPS", "false", "./Config.ini");
	if(retVal == FALSE){
		sprintf_s(errCode, "ErrorCode = 0x%X", GetLastError());
		MessageBox(GetMainWindowHandle(), _T(errCode), _T("Error!"), MB_OK);
	}
	Display = 0;
}

// ini�Ǎ�
int Ini::Read(){
	int retVal = 1;
	DWORD retRead;
	char mode[1 + 1];
	char width[4 + 1];
	char height[4 + 1];
	char display[1 + 1];
	char fps[5 + 1];
	bool fileBreak = false;

	// �E�B���h�E���[�h�̎擾
	retRead = GetPrivateProfileString("Window", "Mode", "0", mode, sizeof(mode), "./Config.ini");
	if(retRead < 1 && retVal == 1 && fileBreak == false){
		if(MessageBox(GetMainWindowHandle(), _T("Config.ini�t�@�C�����j�����Ă��܂��B\n���������܂����H\n���Ȃ��ꍇ�̓A�v���P�[�V�������I�����܂��B"), _T("�m�F"), MB_YESNO) == IDYES){
			fileBreak = true;
		}
		else{
			retVal = 0;
		}
	}
	else{
		sscanf_s(mode, "%hu", &Mode);
	}
	// �E�B���h�E���̎擾
	retRead = GetPrivateProfileString("Window", "Width", "1600", width, sizeof(width), "./Config.ini");
	if(retRead < 2 && retVal == 1 && fileBreak == false){
		if(MessageBox(GetMainWindowHandle(), _T("Config.ini�t�@�C�����j�����Ă��܂��B\n���������܂����H\n���Ȃ��ꍇ�̓A�v���P�[�V�������I�����܂��B"), _T("�m�F"), MB_YESNO) == IDYES){
			fileBreak = true;
		}
		else{
			retVal = 0;
		}
	}
	else{
		sscanf_s(width, "%d", &Width);
	}
	// �E�B���h�E���̎擾
	retRead = GetPrivateProfileString("Window", "Height", "900", height, sizeof(height), "./Config.ini");
	if(retRead < 2 && retVal == 1 && fileBreak == false){
		if(MessageBox(GetMainWindowHandle(), _T("Config.ini�t�@�C�����j�����Ă��܂��B\n���������܂����H\n���Ȃ��ꍇ�̓A�v���P�[�V�������I�����܂��B"), _T("�m�F"), MB_YESNO) == IDYES){
			fileBreak = true;
		}
		else{
			retVal = 0;
		}
	}
	else{
		sscanf_s(height, "%d", &Height);
	}
	// �\���f�B�X�v���C�̎擾
	retRead = GetPrivateProfileString("Window", "Display", "0", display, sizeof(display), "./Config.ini");
	if(retRead < 1 && retVal == 1 && fileBreak == false){
		if(MessageBox(GetMainWindowHandle(), _T("Config.ini�t�@�C�����j�����Ă��܂��B\n���������܂����H\n���Ȃ��ꍇ�̓A�v���P�[�V�������I�����܂��B"), _T("�m�F"), MB_YESNO) == IDYES){
			fileBreak = true;
		}
		else{
			retVal = 0;
		}
	}
	else{
		sscanf_s(display, "%d", &Display);
	}
	// FPS�\���̎擾
	retRead = GetPrivateProfileString("Window", "FPS", "false", fps, sizeof(fps), "./Config.ini");
	if(retRead < 4 && retVal == 1 && fileBreak == false){
		if(MessageBox(GetMainWindowHandle(), _T("Config.ini�t�@�C�����j�����Ă��܂��B\n���������܂����H\n���Ȃ��ꍇ�̓A�v���P�[�V�������I�����܂��B"), _T("�m�F"), MB_YESNO) == IDYES){
			fileBreak = true;
		}
		else{
			retVal = 0;
		}
	}
	else{
		if(strncmp(fps, "true", 4) == 0){
			Fps = true;
		}
		else{
			Fps = false;
		}

	}
	if(retVal == 1 && fileBreak == true){
		Initialize();
	}
	return retVal;
}

// ini����
void Ini::Write(){
	char mode[1 + 1];
	char width[4 + 1];
	char height[4 + 1];
	char display[1 + 1];
	char fps[5 + 1];
	// �E�B���h�E���[�h
	sprintf_s(mode, "%hu", Mode);
	WritePrivateProfileString("Window", "Mode", mode, "./Config.ini");
	// �E�B���h�E��
	sprintf_s(width, "%d", Width);
	WritePrivateProfileString("Window", "Width", width, "./Config.ini");
	// �E�B���h�E��
	sprintf_s(height, "%d", Height);
	WritePrivateProfileString("Window", "Height", height, "./Config.ini");
	// �\���f�B�X�v���C
	sprintf_s(display, "%d", Display);
	WritePrivateProfileString("Window", "Display", display, "./Config.ini");
	// FPS�\��
	if(Fps == true){
		strcpy_s(fps, "true");
	}
	else{
		strcpy_s(fps, "false");
	}
	WritePrivateProfileString("Window", "FPS", fps, "./Config.ini");
}

// �E�B���h�E���[�h�擾
unsigned short Ini::GetMode(){
	return Mode;
}

// �E�B���h�E���[�h�ݒ�
void Ini::SetMode(int mode){
	Mode = mode;
}

// �E�B���h�E���擾
int Ini::GetWidth(){
	return Width;
}

// �E�B���h�E���ݒ�
void Ini::SetWidth(int width){
	Width = width;
}

// �E�B���h�E���擾
int Ini::GetHeight(){
	return Height;
}

// �E�B���h�E���ݒ�
void Ini::SetHeight(int height){
	Height = height;
}

// �E�B���h�E���擾
unsigned short Ini::GetNumResolution(){
	return NumResolution;
}

// �E�B���h�E���ݒ�
void Ini::SetNumResolution(unsigned short numResolution){
	NumResolution = numResolution;
}

// �\���f�B�X�v���C�擾
int Ini::GetDisplay(){
	return Display;
}

// �\���f�B�X�v���C�ݒ�
void Ini::SetDisplay(int display){
	Display = display;
}

// �f�B�X�v���C���擾
unsigned short Ini::GetNumDisplay(){
	return NumDisplay;
}

// �f�B�X�v���C���ݒ�
void Ini::SetNumDisplay(unsigned short numDisplay){
	NumDisplay = numDisplay;
}

// FPS�\���擾
bool Ini::GetFps(){
	return Fps;
}

// FPS�\���ݒ�
void Ini::SetFps(bool fps){
	Fps = fps;
}
// End Of File