#pragma once
#include "Scene.h"

//�ݒ��ʃN���X
class Config : public Scene {

public:
	Config(ISceneChanger* changer);
	//������
	void Initialize() override;
	//�X�V
	void Update() override;
	// �`��
	void Draw() override;

};
// End Of File