#pragma once
#include "ISceneChanger.h"
#include "Task.h"

class Scene :
	public Task
{
public:
	Scene(ISceneChanger* changer);
	virtual ~Scene(){}
	// ������
	virtual void Initialize() override {}
	// �I��
	virtual void Finalize() override;
	// �X�V
	virtual void Update() override {}
	// �`��
	virtual void Draw() override;

protected:
	// �摜�n���h���i�[�p�ϐ�
	int Image;
	// �t�H���g�n���h��
	int Font;
	// �t�H���g�n���h��(���{��)
	int FontJ;
	// �N���X���L���ɃV�[���؂�ւ���`����C���^�[�t�F�C�X
	ISceneChanger* SceneChanger_p;

};
// End Of File