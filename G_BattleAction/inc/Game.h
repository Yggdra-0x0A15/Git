#pragma once
#include "Scene.h"
#include "Character.h"
#include "DxLib.h"

// ゲーム画面クラス
class Game : public Scene {

public:
	Game(ISceneChanger* changer);
	// 初期化
	void Initialize() override;
	// 更新
	void Update() override;
	// 描画
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