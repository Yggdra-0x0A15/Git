#pragma once

#include "SceneMgr.h"
#include "DxLib.h"

// メイン関数
int WINAPI WinMain( HINSTANCE, HINSTANCE, LPSTR, int );
// 初期化
int Init();
// ini初期化
void InitializeINIFile(int* mode_p, int* width_p, int* height_p);
// ini読込
int ReadINIFile(int* mode_p, int* width_p, int* height_p);

// FPSカウンタ
long FpsCnt = 0;
// End Of File