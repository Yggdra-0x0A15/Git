#include "Scene.h"
#include "DxLib.h"

Scene::Scene(ISceneChanger* changer) :Image(0), Font(0){
	int screenWidth;

	SceneChanger_p = changer;
	// フォント作成
	GetDrawScreenSize(&screenWidth, NULL);
	Font = CreateFontToHandle("Segoe Print", static_cast<int>(screenWidth / 1920.0 * 48), DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
	FontJ = CreateFontToHandle("メイリオ", static_cast<int>(screenWidth / 1920.0 * 36), DX_FONTTYPE_ANTIALIASING_4X4);
}

void Scene::Finalize(){
	DeleteGraph(Image);
	DeleteFontToHandle(Font);
	DeleteFontToHandle(FontJ);
}

void Scene::Draw(){
	int width;
	int height;
	GetScreenState(&width, &height, NULL);
	DrawExtendGraph(0, 0, width, height, Image, TRUE);
}
// End Of File