#pragma once
#include "Scene.h"

// ���j���[��ʃN���X
class Menu : public Scene
{
public:
	Menu(ISceneChanger* changer);
	// ������
	void Initialize() override;
	// �X�V
	void Update() override;
	// �`��
	void Draw() override;

private:
	unsigned short Cursor;
};
// End Of File