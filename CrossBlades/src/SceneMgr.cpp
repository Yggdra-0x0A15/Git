#include "SceneMgr.h"
#include "DxLib.h"
#include "Menu.h"
#include "Loading.h"
#include "Game.h"
#include "Config.h"

SceneMgr::SceneMgr() :
	// 次のシーン管理変数
	NextScene(SceneNone) 
{
	Scene_p = NULL;
	NextScene = SceneMenu;
}

//初期化
void SceneMgr::Initialize(){
	Scene_p->Initialize();
}

//終了処理
void SceneMgr::Finalize(){
	Scene_p->Finalize();
}

//更新
void SceneMgr::Update(){
	if(NextScene != SceneNone){
		// 現在のシーンの終了処理を実行
		if(Scene_p != NULL){
			Scene_p->Finalize();
			delete Scene_p;
		}

		switch(NextScene){
		case SceneMenu:
			// メニュー画面のインスタンスを生成する
			Scene_p = (Scene*) new Menu(this);
			break;
		case SceneGame:
			// ゲーム画面のインスタンスを生成する
			Scene_p = (Scene*) new Game(this);
			break;
		case SceneConfig:
			// 設定画面のインスタンスを生成する
			Scene_p = (Scene*) new Config(this);
			break;
		case SceneLoading:
			// ロード画面のインスタンスを生成する
			Scene_p = (Scene*) new Loading(this);
			break;
		default:
			break;
		}
	}
	// 次のシーン情報をクリア
	NextScene = SceneNone;
	// シーンを初期化
	Scene_p->Initialize();
	// シーンの更新
	Scene_p->Update();
}

//描画
void SceneMgr::Draw(){
	// シーンの描画
	Scene_p->Draw();
}

// nextSceneにシーンを変更
void SceneMgr::ChangeScene(EnumScene nextScene){
	// 次のシーンをセットする
	NextScene = nextScene;
}
// End Of File