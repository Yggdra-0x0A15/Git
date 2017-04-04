#include "WinMain.h"
#include "Fps.h"
#include "ini.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SceneMgr sceneMgr;
	FPS fps;
	Ini* ini_p = Ini::GetInstance();
	// ������
	if(Init() == 0) {
		// �ُ�I��
		return 0;
	}
	// while( ����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A )
	while(ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		// ����{�^���_�C�A���O
		if(GetWindowUserCloseFlag(TRUE)) {
			// �I���m�F�����i�u�͂��v�������ꂽ��I���j
			if(MessageBox(GetMainWindowHandle(), _T("�I�����܂����H"), _T("�m�F"), MB_YESNO) == IDYES) {
				break;
			}
		}
		// �X�V
		sceneMgr.Update();
		// �`��
		sceneMgr.Draw();
		// FPS�X�V
		fps.Update();
		// �ҋ@
		fps.Wait();
		if(ini_p->GetFps() == true){
			// FPS�`��
			fps.Draw();
		}
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
	Ini* ini_p = Ini::GetInstance();
	int dispWidth;
	int dispHeight;
	int colorBit;

	// �E�B���h�E�`���~
	SetWindowVisibleFlag(FALSE);

	// ini�t�@�C���̑��݃`�F�b�N
	retCreate = CreateFile("./Config.ini", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if(retCreate != INVALID_HANDLE_VALUE){
		CloseHandle(retCreate);
		retVal = ini_p->Read();
	}
	else{
		CloseHandle(retCreate);
		ini_p->Initialize();
		retVal = ini_p->Read();
	}
	if(retVal == 1){
		GetDefaultState(&dispWidth, &dispHeight, &colorBit);
		switch(ini_p->GetMode()){
		case 0:
			// �E�B���h�E���[�h�ɐݒ�
			ChangeWindowMode(TRUE);
			//// �E�B���h�E�ݒ�
			SetGraphMode(ini_p->GetWidth(), ini_p->GetHeight(), colorBit);
			SetWindowInitPosition((dispWidth - ini_p->GetWidth()) / 2, (dispHeight - ini_p->GetHeight()) / 2);
			break;

		case 1:
			// ���z�t���X�N���[���ɐݒ�
			ChangeWindowMode(TRUE);
			SetWindowStyleMode(2);
			SetGraphMode(dispWidth, dispHeight, colorBit);
			SetWindowInitPosition(0, 0);
			break;

		case 2:
			// �t���X�N���[���ɐݒ�
			if(GetWindowModeFlag() == TRUE){
				ChangeWindowMode(FALSE);
			}
			SetUseDirectDrawDeviceIndex(ini_p->GetDisplay());
			SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_MAXIMUM);
			SetGraphMode(ini_p->GetWidth(), ini_p->GetHeight(), colorBit);
			break;
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
		// �}�E�X�J�[�\�����\����
		SetMouseDispFlag(FALSE);
	}
	return retVal;
}
// End Of File