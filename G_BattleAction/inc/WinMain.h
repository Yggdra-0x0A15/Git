#pragma once

#include "SceneMgr.h"
#include "DxLib.h"

// ���C���֐�
int WINAPI WinMain( HINSTANCE, HINSTANCE, LPSTR, int );
// ������
int Init();
// ini������
void InitializeINIFile(int* mode_p, int* width_p, int* height_p);
// ini�Ǎ�
int ReadINIFile(int* mode_p, int* width_p, int* height_p);

// FPS�J�E���^
long FpsCnt = 0;
// End Of File