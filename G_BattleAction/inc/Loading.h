#pragma once

#include "Scene.h"

class Loading : public Scene
{
public:
	Loading(ISceneChanger* changer);
	// ������
	void Initialize() override;
	// �X�V
	void Update() override;
	// �`��
	void Draw() override;

private:
	bool DrawComplete;
};

