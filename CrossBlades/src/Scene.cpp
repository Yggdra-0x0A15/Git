#include "Scene.h"
#include "DxLib.h"

Scene::Scene(ISceneChanger* changer) :Image(0), Font(0){
	SceneChanger_p = changer;
}

void Scene::Finalize(){
	DeleteGraph(Image);
	DeleteFontToHandle(Font);
}

void Scene::Draw(){
	int width;
	int height;
	GetScreenState(&width, &height, NULL);
	DrawExtendGraph(0, 0, width, height, Image, TRUE);
}
// End Of File