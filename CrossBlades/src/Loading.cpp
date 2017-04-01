#include "Loading.h"
#include "DxLib.h"

Loading::Loading(ISceneChanger* changer) : Scene(changer){
	int screenWidth;

	// �摜�̃��[�h
	Image = LoadGraph("./dat/pic/Loading.bmp");
	// �t�H���g�쐬
	GetDrawScreenSize(&screenWidth, NULL);
	Font = CreateFontToHandle("Segoe Print", static_cast<int>(static_cast<double>(screenWidth) / 1920.0 * 48), 9, DX_FONTTYPE_ANTIALIASING_EDGE);
	DrawComplete = false;
}

// ������
void Loading::Initialize(){
}

// �X�V
void Loading::Update(){
	if(DrawComplete == true){
		SceneChanger_p->ChangeScene(SceneGame);
	}
}

// �`��
void Loading::Draw(){
	int fontWidth;
	int screenWidth;
	int screenHeight;

	// �e�N���X�̕`�惁�\�b�h���Ă�
	Scene::Draw();
	GetDrawScreenSize(&screenWidth, &screenHeight);
	fontWidth = GetDrawStringWidthToHandle("Now Loading ...", sizeof("Now Loading ..."), Font);
	DrawStringToHandle(screenWidth - fontWidth - static_cast<int>(static_cast<double>(screenWidth) / 1920.0 * 10), screenHeight - static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 65), "Now Loading ...", GetColor(255, 255, 255), Font);
	DrawComplete = true;
	DeleteFontToHandle(Font);
}
// End Of File