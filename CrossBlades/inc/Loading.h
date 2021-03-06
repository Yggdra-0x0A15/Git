#pragma once

#include "Scene.h"

class Loading : public Scene
{
public:
	Loading(ISceneChanger* changer);
	// 初期化
	void Initialize() override;
	// 更新
	void Update() override;
	// 描画
	void Draw() override;

private:
	bool DrawComplete;
};

