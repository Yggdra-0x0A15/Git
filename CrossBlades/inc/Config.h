#pragma once
#include "Scene.h"
#include "Ini.h"

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
	Ini* Ini_p;
	unsigned short Cursor;
	unsigned short Tab;
	unsigned short Button;
	unsigned short IndexMode;
	unsigned short IndexResolution;
	unsigned short IndexDisplay;
	bool TabStop;
	bool Setting;
	// 設定適用
	void ApplySetting();
};
// End Of File