#include "SceneMgr.h"
#include "DxLib.h"
#include "Menu.h"
#include "Loading.h"
#include "Game.h"
#include "Config.h"

SceneMgr::SceneMgr() :
	// ���̃V�[���Ǘ��ϐ�
	NextScene(SceneNone) 
{
	Scene_p = NULL;
	NextScene = SceneMenu;
}

//������
void SceneMgr::Initialize(){
	Scene_p->Initialize();
}

//�I������
void SceneMgr::Finalize(){
	Scene_p->Finalize();
}

//�X�V
void SceneMgr::Update(){
	if(NextScene != SceneNone){
		// ���݂̃V�[���̏I�����������s
		if(Scene_p != NULL){
			Scene_p->Finalize();
			delete Scene_p;
		}

		switch(NextScene){
		case SceneMenu:
			// ���j���[��ʂ̃C���X�^���X�𐶐�����
			Scene_p = (Scene*) new Menu(this);
			break;
		case SceneGame:
			// �Q�[����ʂ̃C���X�^���X�𐶐�����
			Scene_p = (Scene*) new Game(this);
			break;
		case SceneConfig:
			// �ݒ��ʂ̃C���X�^���X�𐶐�����
			Scene_p = (Scene*) new Config(this);
			break;
		case SceneLoading:
			// ���[�h��ʂ̃C���X�^���X�𐶐�����
			Scene_p = (Scene*) new Loading(this);
			break;
		default:
			break;
		}
	}
	// ���̃V�[�������N���A
	NextScene = SceneNone;
	// �V�[����������
	Scene_p->Initialize();
	// �V�[���̍X�V
	Scene_p->Update();
}

//�`��
void SceneMgr::Draw(){
	// �V�[���̕`��
	Scene_p->Draw();
}

// nextScene�ɃV�[����ύX
void SceneMgr::ChangeScene(EnumScene nextScene){
	// ���̃V�[�����Z�b�g����
	NextScene = nextScene;
}
// End Of File