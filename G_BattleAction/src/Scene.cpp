#include "Scene.h"
#include "DxLib.h"

Scene::Scene(ISceneChanger* changer) :ImageHandle(0), Font(0){
	SceneChanger_p = changer;
}

void Scene::Finalize(){
	DeleteGraph(ImageHandle);
	DeleteFontToHandle(Font);
}

void Scene::Draw(){
	int width;
	int height;
	GetScreenState(&width, &height, NULL);
	DrawExtendGraph(0, 0, width, height, ImageHandle, TRUE);
}
// End Of File