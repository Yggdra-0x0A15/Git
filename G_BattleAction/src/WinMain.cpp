#include "WinMain.h"
#include "Fps.h"
#include "Ini.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SceneMgr sceneMgr;
	FPS fps;
	// ������
	if(Init() == 0) {
		// �ُ�I��
		return 0;
	}
	sceneMgr.Initialize();

	// while( ����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A )
	while(ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		// ����{�^���_�C�A���O
		if(GetWindowUserCloseFlag(TRUE)) {
			// �I���m�F�����i�u�͂��v�������ꂽ��I���j
			if(MessageBox(GetMainWindowHandle(), _T("�I�����܂����H"), _T("�m�F"), MB_YESNO) == IDYES) {
				break;
			}
		}
		// FPS�X�V
		fps.Update();
		// �ҋ@
		fps.Wait();
		// �X�V
		sceneMgr.Update();
		// �`��
		sceneMgr.Draw();
		// FPS�`��
		fps.Draw();
	}
	sceneMgr.Finalize();
	// DX���C�u�����I������
	DxLib_End();
	// �I��
	return 0;
}

// ������
int Init(){

	int retVal = 1;
	HANDLE retCreate;
	int dispWidth;
	int dispHeight;
	int colorBit;

	// �E�B���h�E�`���~
	SetWindowVisibleFlag(FALSE);

	// ini�t�@�C���̑��݃`�F�b�N
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
			// �E�B���h�E���[�h�ɐݒ�
			ChangeWindowMode(TRUE);
			GetDefaultState(&dispWidth, &dispHeight, &colorBit);
			//// �E�B���h�E�ݒ�
			SetGraphMode(Width, Height, colorBit);
			SetWindowInitPosition((dispWidth - Width) / 2, (dispHeight - Height) / 2);
			break;
		case 2:
			// ���z�t���X�N���[���ɐݒ�
			ChangeWindowMode(TRUE);
			SetWindowStyleMode(2);
			GetDefaultState(&dispWidth, &dispHeight, &colorBit);
			SetGraphMode(dispWidth, dispHeight, colorBit);
			SetWindowInitPosition(0, 0);
			break;
		case 3:
			// �t���X�N���[���ɐݒ�
			break;
		default:
			break;
		}
		// DX���C�u��������������
		if(DxLib_Init() != 0) {
			// �ُ�I��
			retVal = 0;
		}
		// �E�B���h�E�`��J�n
		SetWindowVisibleFlag(TRUE);
		SetAlwaysRunFlag(TRUE);
		// �`���𗠉�ʂɐݒ�
		SetDrawScreen(DX_SCREEN_BACK);
		// ���[�U�[���~�{�^���������Ă������I�ɏI�����Ȃ��悤�ɂ���
		SetWindowUserCloseEnableFlag(FALSE);
	}
	return retVal;
}

// ini�t�@�C��������
void InitializeINIFile(int* mode_p, int* width_p, int* height_p){
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
	ReadINIFile(mode_p, width_p, height_p);
}

// ini�Ǎ�
int ReadINIFile(int* mode_p, int* width_p, int* height_p){
	int retVal = 1;
	DWORD retReadINI;
	char mode[1 + 1];
	char width[4 + 1];
	char height[4 + 1];
	bool breakflg = false;

	// �E�B���h�E���[�h�̎擾
	retReadINI = GetPrivateProfileString("Window", "Mode", "1", mode, sizeof(mode), "./Config.ini");
	if(retReadINI < 1 && retVal == 1 && breakflg == false){
		if(MessageBox(GetMainWindowHandle(), _T("Config.ini�t�@�C�����j�����Ă��܂��B\n���������܂����H\n���Ȃ��ꍇ�̓A�v���P�[�V�������I�����܂��B"), _T("�m�F"), MB_YESNO) == IDYES){
			breakflg = true;
		}
		else{
			retVal = 0;
		}
	}
	else{
		sscanf_s(mode, "%d", mode_p);
	}
	// �E�B���h�E���̎擾
	retReadINI = GetPrivateProfileString("Window", "Width", "1600", width, sizeof(width), "./Config.ini");
	if(retReadINI < 2 && retVal == 1 && breakflg == false){
		if(MessageBox(GetMainWindowHandle(), _T("Config.ini�t�@�C�����j�����Ă��܂��B\n���������܂����H\n���Ȃ��ꍇ�̓A�v���P�[�V�������I�����܂��B"), _T("�m�F"), MB_YESNO) == IDYES){
			breakflg = true;
		}
		else{
			retVal = 0;
		}
	}
	else{
		sscanf_s(width, "%d", width_p);
	}
	// �E�B���h�E���̎擾
	retReadINI = GetPrivateProfileString("Window", "Height", "900", height, sizeof(height), "./Config.ini");
	if(retReadINI < 2 && retVal == 1 && breakflg == false){
		if(MessageBox(GetMainWindowHandle(), _T("Config.ini�t�@�C�����j�����Ă��܂��B\n���������܂����H\n���Ȃ��ꍇ�̓A�v���P�[�V�������I�����܂��B"), _T("�m�F"), MB_YESNO) == IDYES){
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