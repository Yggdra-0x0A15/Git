#include "WinMain.h"
#include "Fps.h"
#include "Ini.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SceneMgr sceneMgr;
	FPS fps;
	// 初期化
	if(Init() == 0) {
		// 異常終了
		return 0;
	}
	sceneMgr.Initialize();

	// while( 裏画面を表画面に反映, メッセージ処理, 画面クリア )
	while(ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		// 閉じるボタンダイアログ
		if(GetWindowUserCloseFlag(TRUE)) {
			// 終了確認処理（「はい」が押されたら終了）
			if(MessageBox(GetMainWindowHandle(), _T("終了しますか？"), _T("確認"), MB_YESNO) == IDYES) {
				break;
			}
		}
		// FPS更新
		fps.Update();
		// 待機
		fps.Wait();
		// 更新
		sceneMgr.Update();
		// 描画
		sceneMgr.Draw();
		// FPS描画
		fps.Draw();
	}
	sceneMgr.Finalize();
	// DXライブラリ終了処理
	DxLib_End();
	// 終了
	return 0;
}

// 初期化
int Init(){

	int retVal = 1;
	HANDLE retCreate;
	int dispWidth;
	int dispHeight;
	int colorBit;

	// ウィンドウ描画停止
	SetWindowVisibleFlag(FALSE);

	// iniファイルの存在チェック
	retCreate = CreateFile("./Config.ini", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if(retCreate != INVALID_HANDLE_VALUE){
		CloseHandle(retCreate);
		retVal = ReadINIFile(&Mode, &Width, &Height);
	}
	else{
		CloseHandle(retCreate);
		InitializeINIFile(&Mode, &Width, &Height);
	}
	if(retVal == 1){
		switch(Mode){
		case 1:
			// ウィンドウモードに設定
			ChangeWindowMode(TRUE);
			GetDefaultState(&dispWidth, &dispHeight, &colorBit);
			//// ウィンドウ設定
			SetGraphMode(Width, Height, colorBit);
			SetWindowInitPosition((dispWidth - Width) / 2, (dispHeight - Height) / 2);
			break;
		case 2:
			// 仮想フルスクリーンに設定
			ChangeWindowMode(TRUE);
			SetWindowStyleMode(2);
			GetDefaultState(&dispWidth, &dispHeight, &colorBit);
			SetGraphMode(dispWidth, dispHeight, colorBit);
			SetWindowInitPosition(0, 0);
			break;
		case 3:
			// フルスクリーンに設定
			break;
		default:
			break;
		}
		// DXライブラリ初期化処理
		if(DxLib_Init() != 0) {
			// 異常終了
			retVal = 0;
		}
		// ウィンドウ描画開始
		SetWindowVisibleFlag(TRUE);
		SetAlwaysRunFlag(TRUE);
		// 描画先を裏画面に設定
		SetDrawScreen(DX_SCREEN_BACK);
		// ユーザーが×ボタンを押しても自動的に終了しないようにする
		SetWindowUserCloseEnableFlag(FALSE);
	}
	return retVal;
}

// iniファイル初期化
void InitializeINIFile(int* mode_p, int* width_p, int* height_p){
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
	ReadINIFile(mode_p, width_p, height_p);
}

// ini読込
int ReadINIFile(int* mode_p, int* width_p, int* height_p){
	int retVal = 1;
	DWORD retReadINI;
	char mode[1 + 1];
	char width[4 + 1];
	char height[4 + 1];
	bool breakflg = false;

	// ウィンドウモードの取得
	retReadINI = GetPrivateProfileString("Window", "Mode", "1", mode, sizeof(mode), "./Config.ini");
	if(retReadINI < 1 && retVal == 1 && breakflg == false){
		if(MessageBox(GetMainWindowHandle(), _T("Config.iniファイルが破損しています。\n初期化しますか？\nしない場合はアプリケーションを終了します。"), _T("確認"), MB_YESNO) == IDYES){
			breakflg = true;
		}
		else{
			retVal = 0;
		}
	}
	else{
		sscanf_s(mode, "%d", mode_p);
	}
	// ウィンドウ幅の取得
	retReadINI = GetPrivateProfileString("Window", "Width", "1600", width, sizeof(width), "./Config.ini");
	if(retReadINI < 2 && retVal == 1 && breakflg == false){
		if(MessageBox(GetMainWindowHandle(), _T("Config.iniファイルが破損しています。\n初期化しますか？\nしない場合はアプリケーションを終了します。"), _T("確認"), MB_YESNO) == IDYES){
			breakflg = true;
		}
		else{
			retVal = 0;
		}
	}
	else{
		sscanf_s(width, "%d", width_p);
	}
	// ウィンドウ高の取得
	retReadINI = GetPrivateProfileString("Window", "Height", "900", height, sizeof(height), "./Config.ini");
	if(retReadINI < 2 && retVal == 1 && breakflg == false){
		if(MessageBox(GetMainWindowHandle(), _T("Config.iniファイルが破損しています。\n初期化しますか？\nしない場合はアプリケーションを終了します。"), _T("確認"), MB_YESNO) == IDYES){
			breakflg = true;
		}
		else{
			retVal = 0;
		}
	}
	else{
		sscanf_s(height, "%d", height_p);
	}
	if(retVal == 1 && breakflg == true){
		InitializeINIFile(mode_p, width_p, height_p);
	}
	return retVal;
}
// End Of File