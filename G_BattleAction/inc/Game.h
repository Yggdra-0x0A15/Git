#pragma once
#include "Scene.h"
#include "Character.h"
#include "DxLib.h"

// �Q�[����ʃN���X
class Game : public Scene {

public:
	Game(ISceneChanger* changer);
	// ������
	void Initialize() override;
	// �X�V
	void Update() override;
	// �`��
	void Draw() override;

private:
	Character* Player_p;
	Character* Enemy_p;
	int Field;
	VECTOR PlayerPos;
	VECTOR EnemyPos;
	VECTOR CamPos;
	VECTOR CamTgt;
	VECTOR SubVector;
	VECTOR RelativePos;
	VECTOR RotPos;
	MATRIX CycleLine;
	int AttachIndex;
	float TotalTime;
	float PlayTime;
	float PlayerAngle;
	float EnemyAngle;
	long FpsCnt;
	long ThreeReader;
};
// End Of File