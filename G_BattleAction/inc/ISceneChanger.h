#pragma once

typedef enum {
	// メニュー画面
	SceneMenu,
	// ゲーム画面
	SceneGame,
	// 設定画面
	SceneConfig,
	// ロード画面
	SceneLoading,
	// 無し
	SceneNone,
} EnumScene;

class ISceneChanger
{
public:
	virtual ~ISceneChanger() = 0;
	//指定シーンに変更する
	virtual void ChangeScene(EnumScene NextScene) = 0;
};
// End Of File