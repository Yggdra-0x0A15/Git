#include <math.h>
#include "Game.h"

Game::Game(ISceneChanger* changer) : Scene(changer){
	Player_p = new Character;
	Enemy_p = new Character;
	// 3Dモデルの読み込み
	Player_p->Model = MV1LoadModel("dat/model/Lat式ミク/Lat式ミクVer2.3_Normal.pmd");
	Enemy_p->Model = MV1LoadModel("dat/model/Lat式ミク/Lat式ミクVer2.3_Whiteエッジ無し専用.pmd");
	Field = MV1LoadModel("dat/stage/ステージ_チェック渦巻き部屋ST32/Stage_ST32/ST32.pmx");
	// 奥行0.1～10000までをカメラの描画範囲とする
	SetCameraNearFar(0.1f, 10000.0f);
	// ３Ｄモデルの座標を初期化
	PlayerPos = VGet(0.0f, 0.0f, -30.0f);
	EnemyPos = VGet(0.0f, 0.0f, 30.0f);
	RelativePos = VGet(PlayerPos.x + 10.0f, 25.0f, PlayerPos.z - 1.0f);
	// ３Ｄモデルの1番目のアニメーションをアタッチする
	AttachIndex = MV1AttachAnim(Player_p->Model, 1, -1, FALSE);
	// アタッチしたアニメーションの総再生時間を取得する
	TotalTime = MV1GetAttachAnimTotalTime(Player_p->Model, AttachIndex);
	// 再生時間の初期化
	PlayTime = 0.0f;
}

// 初期化
void Game::Initialize(){
}

// 更新
void Game::Update(){
	// Escキーが押されていたら
	if(CheckHitKey(KEY_INPUT_ESCAPE) != 0){
		// シーンをメニューに変更
		SceneChanger_p->ChangeScene(SceneMenu);
	}
}

//描画
void Game::Draw(){
	// 親クラスの描画メソッドを呼ぶ
	Scene::Draw();
	// ３Ｄモデル２から３Ｄモデル１に向かうベクトルを算出
	SubVector = VSub(EnemyPos, PlayerPos);
	// atan2 を使用して角度を取得
	PlayerAngle = atan2f(SubVector.x, SubVector.z);
	// atan2 で取得した角度に３Ｄモデルを正面に向かせるための補正値( DX_PI_F )を足した値を３Ｄモデルの Y軸回転値として設定
	MV1SetRotationXYZ(Player_p->Model, VGet(0.0f, PlayerAngle + DX_PI_F, 0.0f));

	// ３Ｄモデル１から３Ｄモデル２に向かうベクトルを算出
	SubVector = VSub(PlayerPos, EnemyPos);
	// atan2 を使用して角度を取得
	EnemyAngle = atan2f(SubVector.x, SubVector.z);
	// atan2 で取得した角度に３Ｄモデルを正面に向かせるための補正値( DX_PI_F )を足した値を３Ｄモデルの Y軸回転値として設定
	MV1SetRotationXYZ(Enemy_p->Model, VGet(0.0f, EnemyAngle + DX_PI_F, 0.0f));

	// 回転行列の作成
	CreateRotationYMatrix(&CycleLine, MV1GetRotationXYZ(Enemy_p->Model).y);
	// 相対座標の回転
	RotPos = VTransformSR(RelativePos, CycleLine);
	// カメラ座標の設定
	CamPos = VGet(PlayerPos.x + RotPos.x, 25.0f, PlayerPos.z + RotPos.z);
	CamTgt = EnemyPos;
	SetCameraPositionAndTarget_UpVecY(CamPos, CamTgt);

	// 指定位置にモデルを配置
	MV1SetPosition(Player_p->Model, PlayerPos);
	MV1SetPosition(Enemy_p->Model, EnemyPos);

	if(CheckHitKey(KEY_INPUT_LEFT) > 0){
		// 敵を軸に左回転
		PlayerPos.x += cosf(-((MV1GetRotationXYZ(Player_p->Model).y))) * 1.0f;
		PlayerPos.z += sinf(-((MV1GetRotationXYZ(Player_p->Model).y))) * 1.0f;
	}
	if(CheckHitKey(KEY_INPUT_RIGHT) > 0){
		// 敵を軸に右回転
		PlayerPos.x += cosf(-(MV1GetRotationXYZ(Player_p->Model).y)) * -1.0f;
		PlayerPos.z += sinf(-(MV1GetRotationXYZ(Player_p->Model).y)) * -1.0f;
	}
	if(CheckHitKey(KEY_INPUT_UP)){
		// 前進
		if(((VSub(EnemyPos, PlayerPos).x > 10.0f) || (VSub(EnemyPos, PlayerPos).x < -10.0f))
			|| ((VSub(EnemyPos, PlayerPos).z > 10.0f) || (VSub(EnemyPos, PlayerPos).z < -10.0f))){
			PlayerPos.x += sinf(MV1GetRotationXYZ(Player_p->Model).y) * -1.0f;
			PlayerPos.z += cosf(MV1GetRotationXYZ(Player_p->Model).y) * -1.0f;
		}
	}
	if(CheckHitKey(KEY_INPUT_DOWN)){
		// 後退
		PlayerPos.x += sinf(MV1GetRotationXYZ(Player_p->Model).y) * 1.0f;
		PlayerPos.z += cosf(MV1GetRotationXYZ(Player_p->Model).y) * 1.0f;
	}
	// 再生時間を進める
	PlayTime += 1.0f;
	// 再生時間がアニメーションの総再生時間に達したら再生時間を０に戻す
	if(PlayTime >= TotalTime) {
		PlayTime = 0.0f;
	}
	// 再生時間をセットする
	MV1SetAttachAnimTime(Player_p->Model, AttachIndex, PlayTime);
	// ３Ｄモデルの描画
	MV1DrawModel(Player_p->Model);
	MV1DrawModel(Enemy_p->Model);
	MV1DrawModel(Field);
}
// End Of File