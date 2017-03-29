#pragma once
#include "ISceneChanger.h"
#include "Scene.h"

class SceneMgr : public ISceneChanger, Task {

public:
	SceneMgr();
	// 初期化
	void Initialize() override;
	// 終了
	void Finalize() override;
	// 更新
	void Update() override;
	// 描画
	void Draw() override;

	// nextSceneにシーンを変更
	void ChangeScene(EnumScene nextScene) override;

private:
	// シーン管理変数
	Scene* Scene_p;
	// 次のシーン管理変数
	EnumScene NextScene;

};
// End Of File