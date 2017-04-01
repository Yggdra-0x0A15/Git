#pragma once
#include "ISceneChanger.h"
#include "Task.h"

class Scene :
	public Task
{
public:
	Scene(ISceneChanger* changer);
	virtual ~Scene(){}
	// 初期化
	virtual void Initialize() override {}
	// 終了
	virtual void Finalize() override;
	// 更新
	virtual void Update() override {}
	// 描画
	virtual void Draw() override;

protected:
	// 画像ハンドル格納用変数
	int Image;
	// フォントハンドル
	int Font;
	// フォントハンドル(日本語)
	int FontJ;
	// クラス所有元にシーン切り替えを伝えるインターフェイス
	ISceneChanger* SceneChanger_p;

};
// End Of File