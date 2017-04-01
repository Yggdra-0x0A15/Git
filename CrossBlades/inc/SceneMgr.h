#pragma once
#include "ISceneChanger.h"
#include "Scene.h"

class SceneMgr : public ISceneChanger, Task {

public:
	SceneMgr();
	// ������
	void Initialize() override;
	// �I��
	void Finalize() override;
	// �X�V
	void Update() override;
	// �`��
	void Draw() override;

	// nextScene�ɃV�[����ύX
	void ChangeScene(EnumScene nextScene) override;

private:
	// �V�[���Ǘ��ϐ�
	Scene* Scene_p;
	// ���̃V�[���Ǘ��ϐ�
	EnumScene NextScene;

};
// End Of File