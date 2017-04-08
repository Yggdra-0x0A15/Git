#include "DxLib.h"
#include "Ini.h"

// インスタンス取得
Ini* Ini::GetInstance(){
	// インスタンス
	static Ini Instance;
	return &Instance;
}

// iniファイル初期化
void Ini::Initialize(){
	HANDLE retCreate;
	BOOL retVal;
	char errCode[23];
	// ini書込
	DeleteFile("./Config.ini");
	retCreate = CreateFile("./Config.ini", GENERIC_ALL, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
	CloseHandle(retCreate);
	// ウィンドウモード
	retVal = WritePrivateProfileString("Window", "Mode", "0", "./Config.ini");
	if(retVal == FALSE){
		sprintf_s(errCode, "ErrorCode = 0x%X", GetLastError());
		MessageBox(GetMainWindowHandle(), _T(errCode), _T("Error!"), MB_OK);
	}
	Mode = 0;
	// ウィンドウ幅
	retVal = WritePrivateProfileString("Window", "Width", "1600", "./Config.ini");
	if(retVal == FALSE){
		sprintf_s(errCode, "ErrorCode = 0x%X", GetLastError());
		MessageBox(GetMainWindowHandle(), _T(errCode), _T("Error!"), MB_OK);
	}
	Width = 1600;
	// ウィンドウ高
	retVal = WritePrivateProfileString("Window", "Height", "900", "./Config.ini");
	if(retVal == FALSE){
		sprintf_s(errCode, "ErrorCode = 0x%X", GetLastError());
		MessageBox(GetMainWindowHandle(), _T(errCode), _T("Error!"), MB_OK);
	}
	Height = 900;
	// 表示ディスプレイ
	retVal = WritePrivateProfileString("Window", "Display", "0", "./Config.ini");
	if(retVal == FALSE){
		sprintf_s(errCode, "ErrorCode = 0x%X", GetLastError());
		MessageBox(GetMainWindowHandle(), _T(errCode), _T("Error!"), MB_OK);
	}
	Display = 0;
	// FPS表示
	retVal = WritePrivateProfileString("Window", "FPS", "false", "./Config.ini");
	if(retVal == FALSE){
		sprintf_s(errCode, "ErrorCode = 0x%X", GetLastError());
		MessageBox(GetMainWindowHandle(), _T(errCode), _T("Error!"), MB_OK);
	}
	Display = 0;
}

// ini読込
int Ini::Read(){
	int retVal = 1;
	DWORD retRead;
	char mode[1 + 1];
	char width[4 + 1];
	char height[4 + 1];
	char display[1 + 1];
	char fps[5 + 1];
	bool fileBreak = false;

	// ウィンドウモードの取得
	retRead = GetPrivateProfileString("Window", "Mode", "0", mode, sizeof(mode), "./Config.ini");
	if(retRead < 1 && retVal == 1 && fileBreak == false){
		if(MessageBox(GetMainWindowHandle(), _T("Config.iniファイルが破損しています。\n初期化しますか？\nしない場合はアプリケーションを終了します。"), _T("確認"), MB_YESNO) == IDYES){
			fileBreak = true;
		}
		else{
			retVal = 0;
		}
	}
	else{
		sscanf_s(mode, "%hu", &Mode);
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
	// 表示ディスプレイの取得
	retRead = GetPrivateProfileString("Window", "Display", "0", display, sizeof(display), "./Config.ini");
	if(retRead < 1 && retVal == 1 && fileBreak == false){
		if(MessageBox(GetMainWindowHandle(), _T("Config.iniファイルが破損しています。\n初期化しますか？\nしない場合はアプリケーションを終了します。"), _T("確認"), MB_YESNO) == IDYES){
			fileBreak = true;
		}
		else{
			retVal = 0;
		}
	}
	else{
		sscanf_s(display, "%d", &Display);
	}
	// FPS表示の取得
	retRead = GetPrivateProfileString("Window", "FPS", "false", fps, sizeof(fps), "./Config.ini");
	if(retRead < 4 && retVal == 1 && fileBreak == false){
		if(MessageBox(GetMainWindowHandle(), _T("Config.iniファイルが破損しています。\n初期化しますか？\nしない場合はアプリケーションを終了します。"), _T("確認"), MB_YESNO) == IDYES){
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

// ini書込
void Ini::Write(){
	char mode[1 + 1];
	char width[4 + 1];
	char height[4 + 1];
	char display[1 + 1];
	char fps[5 + 1];
	// ウィンドウモード
	sprintf_s(mode, "%hu", Mode);
	WritePrivateProfileString("Window", "Mode", mode, "./Config.ini");
	// ウィンドウ幅
	sprintf_s(width, "%d", Width);
	WritePrivateProfileString("Window", "Width", width, "./Config.ini");
	// ウィンドウ高
	sprintf_s(height, "%d", Height);
	WritePrivateProfileString("Window", "Height", height, "./Config.ini");
	// 表示ディスプレイ
	sprintf_s(display, "%d", Display);
	WritePrivateProfileString("Window", "Display", display, "./Config.ini");
	// FPS表示
	if(Fps == true){
		strcpy_s(fps, "true");
	}
	else{
		strcpy_s(fps, "false");
	}
	WritePrivateProfileString("Window", "FPS", fps, "./Config.ini");
}

// ウィンドウモード取得
unsigned short Ini::GetMode(){
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

// ウィンドウ高取得
unsigned short Ini::GetNumResolution(){
	return NumResolution;
}

// ウィンドウ高設定
void Ini::SetNumResolution(unsigned short numResolution){
	NumResolution = numResolution;
}

// 表示ディスプレイ取得
int Ini::GetDisplay(){
	return Display;
}

// 表示ディスプレイ設定
void Ini::SetDisplay(int display){
	Display = display;
}

// ディスプレイ数取得
unsigned short Ini::GetNumDisplay(){
	return NumDisplay;
}

// ディスプレイ数設定
void Ini::SetNumDisplay(unsigned short numDisplay){
	NumDisplay = numDisplay;
}

// FPS表示取得
bool Ini::GetFps(){
	return Fps;
}

// FPS表示設定
void Ini::SetFps(bool fps){
	Fps = fps;
}
// End Of File