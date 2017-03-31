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
		// 更新
		sceneMgr.Update();
		// 描画
		sceneMgr.Draw();
		// FPS更新
		fps.Update();
		// 待機
		fps.Wait();
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
	Ini ini;
	int dispWidth;
	int dispHeight;
	int colorBit;

	// ウィンドウ描画停止
	SetWindowVisibleFlag(FALSE);

	// iniファイルの存在チェック
	retCreate = CreateFile("./Config.ini", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if(retCreate != INVALID_HANDLE_VALUE){
		CloseHandle(retCreate);
		retVal = ini.Read();
	}
	else{
		CloseHandle(retCreate);
		ini.Initialize();
		retVal = ini.Read();
	}
	if(retVal == 1){
		switch(ini.GetMode()){
		case 1:
			// ウィンドウモードに設定
			ChangeWindowMode(TRUE);
			GetDefaultState(&dispWidth, &dispHeight, &colorBit);
			//// ウィンドウ設定
			SetGraphMode(ini.GetWidth(), ini.GetHeight(), colorBit);
			SetWindowInitPosition((dispWidth - ini.GetWidth()) / 2, (dispHeight - ini.GetHeight()) / 2);
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
// End Of File