#pragma once
#include "Scene.h"

//設定画面クラス
class Config : public Scene {

public:
	Config(ISceneChanger* changer);
	//初期化
	void Initialize() override;
	//更新
	void Update() override;
	// 描画
	void Draw() override;

private:
	unsigned short Cursor;
	unsigned short Tab;
	unsigned short Button;
	bool TabStop;
};
// End Of File