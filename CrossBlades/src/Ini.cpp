#include "DxLib.h"
#include "Ini.h"

// iniファイル初期化
void Ini::Initialize(){
	HANDLE retCreate;
	BOOL retWriteINI;
	char errCode[23];
	// ini書込
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

// ini読込
int Ini::Read(){
	int retVal = 1;
	DWORD retRead;
	char mode[1 + 1];
	char width[4 + 1];
	char height[4 + 1];
	bool fileBreak = false;

	// ウィンドウモードの取得
	retRead = GetPrivateProfileString("Window", "Mode", "1", mode, sizeof(mode), "./Config.ini");
	if(retRead < 1 && retVal == 1 && fileBreak == false){
		if(MessageBox(GetMainWindowHandle(), _T("Config.iniファイルが破損しています。\n初期化しますか？\nしない場合はアプリケーションを終了します。"), _T("確認"), MB_YESNO) == IDYES){
			fileBreak = true;
		}
		else{
			retVal = 0;
		}
	}
	else{
		sscanf_s(mode, "%d", &Mode);
	}
	// ウィンドウ幅の取得
	retRead = GetPrivateProfileString("Window", "Width", "1600", width, sizeof(width), "./Config.ini");
	if(retRead < 2 && retVal == 1 && fileBreak == false){
		if(MessageBox(GetMainWindowHandle(), _T("Config.iniファイルが破損しています。\n初期化しますか？\nしない場合はアプリケーションを終了します。"), _T("確認"), MB_YESNO) == IDYES){
			fileBreak = true;
		}
		else{
			retVal = 0;
		}
	}
	else{
		sscanf_s(width, "%d", &Width);
	}
	// ウィンドウ高の取得
	retRead = GetPrivateProfileString("Window", "Height", "900", height, sizeof(height), "./Config.ini");
	if(retRead < 2 && retVal == 1 && fileBreak == false){
		if(MessageBox(GetMainWindowHandle(), _T("Config.iniファイルが破損しています。\n初期化しますか？\nしない場合はアプリケーションを終了します。"), _T("確認"), MB_YESNO) == IDYES){
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

// ウィンドウモード取得
int Ini::GetMode(){
	return Mode;
}

// ウィンドウモード設定
void Ini::SetMode(int mode){
	Mode = mode;
}

// ウィンドウ幅取得
int Ini::GetWidth(){
	return Width;
}

// ウィンドウ幅設定
void Ini::SetWidth(int width){
	Width = width;
}

// ウィンドウ高取得
int Ini::GetHeight(){
	return Height;
}

// ウィンドウ高設定
void Ini::SetHeight(int height){
	Height = height;
}

// 表示ディスプレイ取得
int Ini::GetDisplay(){
	return Display;
}

// 表示ディスプレイ設定
void Ini::SetDisplay(int display){
	Display = display;
}
// End Of File