#include "Config.h"
#include "DxLib.h"

Config::Config(ISceneChanger* changer) : Scene(changer) {
}

// ������
void Config::Initialize(){
	// �摜�̃��[�h
	ImageHandle = LoadGraph("./dat/pic/Loading.bmp");
}

// �X�V
void Config::Update(){
	// Esc�L�[��������Ă�����
	if(CheckHitKey(KEY_INPUT_ESCAPE) != 0){
		// �V�[�������j���[�ɕύX
		SceneChanger_p->ChangeScene(SceneMenu);
	}
}

// �`��
void Config::Draw(){
	// �e�N���X�̕`�惁�\�b�h���Ă�
	Scene::Draw();
}
// End Of File