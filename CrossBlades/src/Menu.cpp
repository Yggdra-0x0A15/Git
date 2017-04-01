#include "Menu.h"
#include "DxLib.h"

Menu::Menu(ISceneChanger* changer) : Scene(changer){
	// �摜�̃��[�h
	Image = LoadGraph("./dat/pic/Menu.bmp");
	Cursor = 0;
}

// ������
void Menu::Initialize(){
}

// �X�V
void Menu::Update(){
	if(CheckHitKey(KEY_INPUT_RETURN) != 0){
		switch(Cursor){
		case 0:
			// �L�����N�^�[�G�f�B�b�g
			SceneChanger_p->ChangeScene(SceneLoading);
			break;

		case 1:
			// ���[�h
			SceneChanger_p->ChangeScene(SceneLoading);
			break;

		case 2:
			// �R���t�B�O
			SceneChanger_p->ChangeScene(SceneConfig);
			break;

		case 3:
			// �I��
			Scene::Finalize();
			DxLib_End();
			break;

		default:
			break;
		}
	}

	if(CheckHitKey(KEY_INPUT_UP) != 0){
		if(Cursor == 0){
			Cursor = 3;
		}
		else{
			Cursor--;
		}
	}
	if(CheckHitKey(KEY_INPUT_DOWN) != 0){
		if(Cursor == 3){
			Cursor = 0;
		}
		else{
			Cursor++;
		}
	}
}

// �`��
void Menu::Draw(){
	int fontWidth;
	int screenWidth;
	int screenHeight;
	// �e�N���X�̕`�惁�\�b�h���Ă�
	Scene::Draw();
	GetDrawScreenSize(&screenWidth, &screenHeight);
	switch(Cursor){
	case 0:
		fontWidth = GetDrawStringWidthToHandle("New Game", sizeof("New Game"), Font);
		DrawStringToHandle((screenWidth - fontWidth) / 2, screenHeight - static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 400), "New Game", GetColor(255, 255, 0), Font);
		fontWidth = GetDrawStringWidthToHandle("Continue", sizeof("Continue"), Font);
		DrawStringToHandle((screenWidth - fontWidth) / 2, screenHeight - static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 300), "Continue", GetColor(255, 255, 255), Font);
		fontWidth = GetDrawStringWidthToHandle("Setting", sizeof("Setting"), Font);
		DrawStringToHandle((screenWidth - fontWidth) / 2, screenHeight - static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 200), "Setting", GetColor(255, 255, 255), Font);
		fontWidth = GetDrawStringWidthToHandle("Exit", sizeof("Exit"), Font);
		DrawStringToHandle((screenWidth - fontWidth) / 2, screenHeight - static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 100), "Exit", GetColor(255, 255, 255), Font);
		break;

	case 1:
		fontWidth = GetDrawStringWidthToHandle("New Game", sizeof("New Game"), Font);
		DrawStringToHandle((screenWidth - fontWidth) / 2, screenHeight - static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 400), "New Game", GetColor(255, 255, 255), Font);
		fontWidth = GetDrawStringWidthToHandle("Continue", sizeof("Continue"), Font);
		DrawStringToHandle((screenWidth - fontWidth) / 2, screenHeight - static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 300), "Continue", GetColor(255, 255, 0), Font);
		fontWidth = GetDrawStringWidthToHandle("Setting", sizeof("Setting"), Font);
		DrawStringToHandle((screenWidth - fontWidth) / 2, screenHeight - static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 200), "Setting", GetColor(255, 255, 255), Font);
		fontWidth = GetDrawStringWidthToHandle("Exit", sizeof("Exit"), Font);
		DrawStringToHandle((screenWidth - fontWidth) / 2, screenHeight - static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 100), "Exit", GetColor(255, 255, 255), Font);
		break;

	case 2:
		fontWidth = GetDrawStringWidthToHandle("New Game", sizeof("New Game"), Font);
		DrawStringToHandle((screenWidth - fontWidth) / 2, screenHeight - static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 400), "New Game", GetColor(255, 255, 255), Font);
		fontWidth = GetDrawStringWidthToHandle("Continue", sizeof("Continue"), Font);
		DrawStringToHandle((screenWidth - fontWidth) / 2, screenHeight - static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 300), "Continue", GetColor(255, 255, 255), Font);
		fontWidth = GetDrawStringWidthToHandle("Setting", sizeof("Setting"), Font);
		DrawStringToHandle((screenWidth - fontWidth) / 2, screenHeight - static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 200), "Setting", GetColor(255, 255, 0), Font);
		fontWidth = GetDrawStringWidthToHandle("Exit", sizeof("Exit"), Font);
		DrawStringToHandle((screenWidth - fontWidth) / 2, screenHeight - static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 100), "Exit", GetColor(255, 255, 255), Font);
		break;

	case 3:
		fontWidth = GetDrawStringWidthToHandle("New Game", sizeof("New Game"), Font);
		DrawStringToHandle((screenWidth - fontWidth) / 2, screenHeight - static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 400), "New Game", GetColor(255, 255, 255), Font);
		fontWidth = GetDrawStringWidthToHandle("Continue", sizeof("Continue"), Font);
		DrawStringToHandle((screenWidth - fontWidth) / 2, screenHeight - static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 300), "Continue", GetColor(255, 255, 255), Font);
		fontWidth = GetDrawStringWidthToHandle("Setting", sizeof("Setting"), Font);
		DrawStringToHandle((screenWidth - fontWidth) / 2, screenHeight - static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 200), "Setting", GetColor(255, 255, 255), Font);
		fontWidth = GetDrawStringWidthToHandle("Exit", sizeof("Exit"), Font);
		DrawStringToHandle((screenWidth - fontWidth) / 2, screenHeight - static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 100), "Exit", GetColor(255, 255, 0), Font);
		break;

	default:
		break;
	}
}
// End Of File