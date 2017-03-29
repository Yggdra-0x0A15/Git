#pragma once

typedef enum {
	// ���j���[���
	SceneMenu,
	// �Q�[�����
	SceneGame,
	// �ݒ���
	SceneConfig,
	// ���[�h���
	SceneLoading,
	// ����
	SceneNone,
} EnumScene;

class ISceneChanger
{
public:
	virtual ~ISceneChanger() = 0;
	//�w��V�[���ɕύX����
	virtual void ChangeScene(EnumScene NextScene) = 0;
};
// End Of File