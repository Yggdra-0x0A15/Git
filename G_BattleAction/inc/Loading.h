#pragma once

#include "Scene.h"

class Loading : public Scene
{
public:
	Loading(ISceneChanger* changer);
	// ‰Šú‰»
	void Initialize() override;
	// XV
	void Update() override;
	// •`‰æ
	void Draw() override;

private:
	bool DrawComplete;
};

