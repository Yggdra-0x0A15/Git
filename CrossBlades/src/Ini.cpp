#include "DxLib.h"
#include "Ini.h"

// ini�t�@�C��������
void Ini::Initialize(){
	HANDLE retCreate;
	BOOL retWriteINI;
	char errCode[23];
	// ini����
	DeleteFile("./Config.ini");
	retCreate = CreateFile("./Config.ini", GENERIC_ALL, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
	CloseHandle(retCreate);
	retWriteINI = WritePrivateProfileString("Window", "Mode", "1", "./Config.ini");
	if(retWriteINI == FALSE){
		sprintf_s(errCode, "ErrorCode = 0x%X", GetLastError());
		MessageBox(GetMainWindowHandle(), _T(errCode), _T("Error!"), MB_OK);
	}
	retWriteINI = WritePrivateProfileString("Window", "Width", "1600", "./Config.ini");
	if(retWriteINI == FALSE){
		sprintf_s(errCode, "ErrorCode = 0x%X", GetLastError());
		MessageBox(GetMainWindowHandle(), _T(errCode), _T("Error!"), MB_OK);
	}
	retWriteINI = WritePrivateProfileString("Window", "Height", "900", "./Config.ini");
	if(retWriteINI == FALSE){
		sprintf_s(errCode, "ErrorCode = 0x%X", GetLastError());
		MessageBox(GetMainWindowHandle(), _T(errCode), _T("Error!"), MB_OK);
	}
}

// ini�Ǎ�
int Ini::Read(){
	int retVal = 1;
	DWORD retRead;
	char mode[1 + 1];
	char width[4 + 1];
	char height[4 + 1];
	bool fileBreak = false;

	// �E�B���h�E���[�h�̎擾
	retRead = GetPrivateProfileString("Window", "Mode", "1", mode, sizeof(mode), "./Config.ini");
	if(retRead < 1 && retVal == 1 && fileBreak == false){
		if(MessageBox(GetMainWindowHandle(), _T("Config.ini�t�@�C�����j�����Ă��܂��B\n���������܂����H\n���Ȃ��ꍇ�̓A�v���P�[�V�������I�����܂��B"), _T("�m�F"), MB_YESNO) == IDYES){
			fileBreak = true;
		}
		else{
			retVal = 0;
		}
	}
	else{
		sscanf_s(mode, "%d", &Mode);
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
	if(retVal == 1 && fileBreak == true){
		Initialize();
	}
	return retVal;
}

// �E�B���h�E���[�h�擾
int Ini::GetMode(){
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

// �\���f�B�X�v���C�擾
int Ini::GetDisplay(){
	return Display;
}

// �\���f�B�X�v���C�ݒ�
void Ini::SetDisplay(int display){
	Display = display;
}
// End Of File