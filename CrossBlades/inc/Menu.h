#pragma once
#include "Scene.h"

// メニュー画面クラス
class Menu : public Scene
{
public:
	Menu(ISceneChanger* changer);
	// 初期化
	void Initialize() override;
	// 更新
	void Update() override;
	// 描画
	void Draw() override;

private:
	unsigned short Cursor;
};
// End Of File