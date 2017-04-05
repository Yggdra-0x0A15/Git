#include "Config.h"
#include "DxLib.h"

bool Config::Apply = false;

Config::Config(ISceneChanger* changer) : Scene(changer) {
	// iniインスタンス取得
	Ini_p = Ini::GetInstance();
	// 画像のロード
	Image = LoadGraph("./dat/pic/Config.bmp");
	if(Apply == true){
		Cursor = 4;
	}
	else{
		Cursor = 0;
	}
	Tab = 0;
	Button = 0;
	TabStop = false;
	Setting = false;
	IndexMode = Ini_p->GetMode();
	IndexResolution = 0;
	IndexDisplay = 0;
	// 変更前ウィンドウモード
	PreMode = Ini_p->GetMode();
	// 変更前ウィンドウ幅
	PreWidth = Ini_p->GetWidth();
	// 変更前ウィンドウ高
	PreHeight = Ini_p->GetHeight();
	// 変更前表示ディスプレイ
	PreDisplay = Ini_p->GetDisplay();
	// 変更前FPS表示
	PreFps = Ini_p->GetFps();
}

// 初期化
void Config::Initialize(){
}

// 更新
void Config::Update(){
	if(CheckHitKey(KEY_INPUT_ESCAPE) != 0){
		// シーンをメニューに変更
		SceneChanger_p->ChangeScene(SceneMenu);
	}
	if(CheckHitKey(KEY_INPUT_RETURN) != 0){
		if(Setting == true){
			// 決定
			switch(Tab){
			case 0:
				// ディスプレイ設定
				switch(Cursor){
				case 0:
					// ウィンドウモード
					Ini_p->SetMode(IndexMode);
					Setting = false;
					break;

				case 1:
					// 解像度
					Setting = false;
					break;

				case 2:
					// 表示ディスプレイ
					Setting = false;
					break;

				case 3:
					// FPS表示
					if(Ini_p->GetFps() == true){
						Ini_p->SetFps(false);
					}
					else{
						Ini_p->SetFps(true);
					}
					break;

				default:
					break;

				}
				break;

			case 1:
				// グラフィック設定
				break;

			case 2:
				// サウンド設定
				break;

			case 3:
				// キーコンフィグ設定
				break;

			default:
				break;
			}
		}
		else{
			switch(Tab){
			case 0:
				// ディスプレイ設定
				switch(Cursor){
				case 0:
					// ウィンドウモード
					Setting = true;
					break;

				case 1:
					// 解像度
					Setting = true;
					break;

				case 2:
					// 表示ディスプレイ
					Setting = true;
					break;

				case 3:
					// FPS表示
					if(Ini_p->GetFps() == true){
						Ini_p->SetFps(false);
					}
					else{
						Ini_p->SetFps(true);
					}
					break;

				case 4:
					switch(Button){
					case 0:
						// 保存
						if(Apply == true){
							Apply = false;
						}
						else{
							ApplySetting();
						}
						Ini_p->Write();
						SceneChanger_p->ChangeScene(SceneMenu);
						break;

					case 1:
						// キャンセル
						Cancel();
						ApplySetting();
						SceneChanger_p->ChangeScene(SceneMenu);
						break;

					case 2:
						// 適用
						ApplySetting();
						Apply = true;
						SceneChanger_p->ChangeScene(SceneConfig);
						Scene::Finalize();
						break;

					default:
						break;

					}
					break;

				default:
					break;

				}
				break;

			case 1:
				// グラフィック設定
				break;

			case 2:
				// サウンド設定
				break;

			case 3:
				// キーコンフィグ設定
				break;

			default:
				break;
			}
		}
	}
	if(CheckHitKey(KEY_INPUT_LEFT) != 0){
		if(Setting == false){
			if(TabStop == true){
				// ボタン移動
				if(GetChange() == true){
					if(Button == 0){
						Button = 2;
					}
					else{
						Button--;
					}
				}
				else if(Apply == true){
					if(Button == 0){
						Button = 1;
					}
					else{
						Button--;
					}
				}
			}
			else{
				// タブ移動
				if(Tab == 0){
					Tab = 3;
				}
				else{
					Tab--;
				}
				Cursor = 0;
			}
		}
	}
	if(CheckHitKey(KEY_INPUT_RIGHT) != 0){
		if(Setting == false){
			if(TabStop == true){
				// ボタン移動
				if(GetChange() == true){
					if(Button == 2){
						Button = 0;
					}
					else{
						Button++;
					}
				}
				else if(Apply == true){
					if(Button == 1){
						Button = 0;
					}
					else{
						Button++;
					}
				}
			}
			else{
				// タブ移動
				if(Tab == 3){
					Tab = 0;
				}
				else{
					Tab++;
				}
				Cursor = 0;
			}
		}
	}
	if(CheckHitKey(KEY_INPUT_UP) != 0){
		if(Setting == true){
			// 設定項目選択
			switch(Tab){
			case 0:
				// ディスプレイ設定
				switch(Cursor){
				case 0:
					// ウィンドウモード
					if(IndexMode == 0){
						IndexMode = 2;
					}
					else{
						IndexMode--;
					}
					break;

				case 1:
					// 解像度
					break;

				case 2:
					// 表示ディスプレイ
					break;

				default:
					break;

				}
				break;

			case 1:
				// グラフィック設定
				break;

			case 2:
				// サウンド設定
				break;

			case 3:
				// キーコンフィグ設定
				break;

			default:
				break;

			}
		}
		else{
			// カーソル移動
			if(Cursor == 0){
				Cursor = 4;
			}
			else{
				if(Ini_p->GetMode() == 0 && Cursor == 3){
					Cursor = 1;
				}
				else if(Ini_p->GetMode() == 1 && Cursor == 3){
					Cursor = 0;
				}
				else{
					Cursor--;
				}
			}
			if(GetChange() == true){
				Button = 0;
			}
			else{
				Button = 1;
			}
		}
	}
	if(CheckHitKey(KEY_INPUT_DOWN) != 0){
		if(Setting == true){
			switch(Tab){
			case 0:
				// ディスプレイ設定
				switch(Cursor){
				case 0:
					// ウィンドウモード
					if(IndexMode == 2){
						IndexMode = 0;
					}
					else{
						IndexMode++;
					}
					break;

				case 1:
					// 解像度
					break;

				case 2:
					// 表示ディスプレイ
					break;

				default:
					break;

				}
				break;

			case 1:
				// グラフィック設定
				break;

			case 2:
				// サウンド設定
				break;

			case 3:
				// キーコンフィグ設定
				break;

			default:
				break;

			}
		}
		else{
			// カーソル移動
			if(Cursor == 4){
				Cursor = 0;
			}
			else{
				if(Ini_p->GetMode() == 0 && Cursor == 1){
					Cursor = 3;
				}
				else if(Ini_p->GetMode() == 1 && Cursor == 0){
					Cursor = 3;
				}
				else{
					Cursor++;
				}
			}
			if(GetChange() == true){
				Button = 0;
			}
			else{
				Button = 1;
			}
		}
	}
}

// 描画
void Config::Draw(){
	int fontWidth;
	int screenWidth;
	int screenHeight;
	// 親クラスの描画メソッドを呼ぶ
	Scene::Draw();
	GetWindowSize(&screenWidth, &screenHeight);
	DrawBase(screenWidth, screenHeight);
	switch(Tab){
	case 0:
		// ディスプレイ関連設定
		fontWidth = GetDrawStringWidthToHandle("Display", sizeof("Display"), Font);
		DrawStringToHandle((screenWidth / 4 - fontWidth) / 2, static_cast<int>(screenHeight / 1080.0 * 120), "Display", GetColor(255, 255, 0), Font);
		switch(Cursor){
		case 0:
			// ウィンドウモード
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 250), "ウィンドウモード :", GetColor(255, 255, 0), FontJ);
			if(Setting == true){
				// コンボボックス拡張
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1200)
						, static_cast<float>(screenHeight / 1080.0 * 245)
						, static_cast<float>(screenWidth / 1920.0 * 1580)
						, static_cast<float>(screenHeight / 1080.0 * 390)
						, GetColor(255, 255, 255), FALSE);
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1580)
						, static_cast<float>(screenHeight / 1080.0 * 245)
						, static_cast<float>(screenWidth / 1920.0 * 1620)
						, static_cast<float>(screenHeight / 1080.0 * 290)
						, GetColor(255, 255, 255), FALSE);

				switch(IndexMode){
				case 0:
					fontWidth = GetDrawStringWidthToHandle("ウィンドウ", sizeof("ウィンドウ"), FontJ);
					DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
						, static_cast<int>(screenHeight / 1080.0 * 250)
						, "ウィンドウ", GetColor(255, 255, 0), FontJ);
					fontWidth = GetDrawStringWidthToHandle("仮想フルスクリーン", sizeof("仮想フルスクリーン"), FontJ);
					DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
						, static_cast<int>(screenHeight / 1080.0 * 300)
						, "仮想フルスクリーン", GetColor(255, 255, 255), FontJ);
					fontWidth = GetDrawStringWidthToHandle("フルスクリーン", sizeof("フルスクリーン"), FontJ);
					DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
						, static_cast<int>(screenHeight / 1080.0 * 350)
						, "フルスクリーン", GetColor(255, 255, 255), FontJ);
					break;

				case 1:
					fontWidth = GetDrawStringWidthToHandle("ウィンドウ", sizeof("ウィンドウ"), FontJ);
					DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
						, static_cast<int>(screenHeight / 1080.0 * 250)
						, "ウィンドウ", GetColor(255, 255, 255), FontJ);
					fontWidth = GetDrawStringWidthToHandle("仮想フルスクリーン", sizeof("仮想フルスクリーン"), FontJ);
					DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
						, static_cast<int>(screenHeight / 1080.0 * 300)
						, "仮想フルスクリーン", GetColor(255, 255, 0), FontJ);
					fontWidth = GetDrawStringWidthToHandle("フルスクリーン", sizeof("フルスクリーン"), FontJ);
					DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
						, static_cast<int>(screenHeight / 1080.0 * 350)
						, "フルスクリーン", GetColor(255, 255, 255), FontJ);
					break;

				case 2:
					fontWidth = GetDrawStringWidthToHandle("ウィンドウ", sizeof("ウィンドウ"), FontJ);
					DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
						, static_cast<int>(screenHeight / 1080.0 * 250)
						, "ウィンドウ", GetColor(255, 255, 255), FontJ);
					fontWidth = GetDrawStringWidthToHandle("仮想フルスクリーン", sizeof("仮想フルスクリーン"), FontJ);
					DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
						, static_cast<int>(screenHeight / 1080.0 * 300)
						, "仮想フルスクリーン", GetColor(255, 255, 255), FontJ);
					fontWidth = GetDrawStringWidthToHandle("フルスクリーン", sizeof("フルスクリーン"), FontJ);
					DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
						, static_cast<int>(screenHeight / 1080.0 * 350)
						, "フルスクリーン", GetColor(255, 255, 0), FontJ);
					break;

				default:
					break;

				}
			}
			else{
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1200)
						, static_cast<float>(screenHeight / 1080.0 * 245)
						, static_cast<float>(screenWidth / 1920.0 * 1580)
						, static_cast<float>(screenHeight / 1080.0 * 290)
						, GetColor(255, 255, 0), FALSE);
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1580)
						, static_cast<float>(screenHeight / 1080.0 * 245)
						, static_cast<float>(screenWidth / 1920.0 * 1620)
						, static_cast<float>(screenHeight / 1080.0 * 290)
						, GetColor(255, 255, 0), FALSE);
				fontWidth = GetDrawStringWidthToHandle("▼", sizeof("▼"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1620 - (fontWidth + screenWidth / 1920.0 * 1580)) / 2 + screenWidth / 1920.0 * 1580)
								, static_cast<int>(screenHeight / 1080.0 * 250)
								, "▼", GetColor(255, 255, 0), FontJ);
			}
			TabStop = false;
			break;

		case 1:
			// 解像度
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 350), "解像度                :", GetColor(255, 255, 0), FontJ);
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1200)
					, static_cast<float>(screenHeight / 1080.0 * 345)
					, static_cast<float>(screenWidth / 1920.0 * 1580)
					, static_cast<float>(screenHeight / 1080.0 * 390)
					, GetColor(255, 255, 0), FALSE);
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1580)
					, static_cast<float>(screenHeight / 1080.0 * 345)
					, static_cast<float>(screenWidth / 1920.0 * 1620)
					, static_cast<float>(screenHeight / 1080.0 * 390)
					, GetColor(255, 255, 0), FALSE);
			fontWidth = GetDrawStringWidthToHandle("▼", sizeof("▼"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1620 - (fontWidth + screenWidth / 1920.0 * 1580)) / 2 + screenWidth / 1920.0 * 1580)
							, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 350)
							, "▼", GetColor(255, 255, 0), FontJ);
			break;

		case 2:
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 450), "表示ディスプレイ :", GetColor(255, 255, 0), FontJ);
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1200)
				, static_cast<float>(screenHeight / 1080.0 * 445)
				, static_cast<float>(screenWidth / 1920.0 * 1580)
				, static_cast<float>(screenHeight / 1080.0 * 490)
				, GetColor(255, 255, 0), FALSE);
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1580)
				, static_cast<float>(screenHeight / 1080.0 * 445)
				, static_cast<float>(screenWidth / 1920.0 * 1620)
				, static_cast<float>(screenHeight / 1080.0 * 490)
				, GetColor(255, 255, 0), FALSE);
			fontWidth = GetDrawStringWidthToHandle("▼", sizeof("▼"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1620 - (fontWidth + screenWidth / 1920.0 * 1580)) / 2 + screenWidth / 1920.0 * 1580)
				, static_cast<int>(screenHeight / 1080.0 * 450)
				, "▼", GetColor(255, 255, 0), FontJ);
			TabStop = false;
			break;

		case 3:
			// FPS表示
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 550), "FPS表示             :", GetColor(255, 255, 0), FontJ);
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1590)
				, static_cast<float>(screenHeight / 1080.0 * 550)
				, static_cast<float>(screenWidth / 1920.0 * 1620)
				, static_cast<float>(screenHeight / 1080.0 * 580)
				, GetColor(255, 255, 0), FALSE);
			if(Ini_p->GetFps() == true){
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1595)
					, static_cast<float>(screenHeight / 1080.0 * 555)
					, static_cast<float>(screenWidth / 1920.0 * 1615)
					, static_cast<float>(screenHeight / 1080.0 * 575)
					, GetColor(255, 255, 0), TRUE);
			}
			TabStop = false;
			break;

		case 4:
			TabStop = true;
			switch(Button){
			case 0:
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1330), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1480), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 0), FALSE);
				fontWidth = GetDrawStringWidthToHandle("保存", sizeof("保存"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1480 - (fontWidth + screenWidth / 1920.0 * 1330)) / 2 + screenWidth / 1920.0 * 1330), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "保存", GetColor(255, 255, 0), FontJ);
				break;

			case 1:
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1530), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1680), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 0), FALSE);
				fontWidth = GetDrawStringWidthToHandle("ｷｬﾝｾﾙ", sizeof("ｷｬﾝｾﾙ"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1680 - (fontWidth + screenWidth / 1920.0 * 1530)) / 2 + screenWidth / 1920.0 * 1530), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "ｷｬﾝｾﾙ", GetColor(255, 255, 0), FontJ);
				break;

			case 2:
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1730), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1880), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 0), FALSE);
				fontWidth = GetDrawStringWidthToHandle("適用", sizeof("適用"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1880 - (fontWidth + screenWidth / 1920.0 * 1730)) / 2 + screenWidth / 1920.0 * 1730), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "適用", GetColor(255, 255, 0), FontJ);
				break;

			default:
				break;

			}
			break;

		default:
			break;

		}
		break;

	case 1:
		// グラフィック関連設定
		fontWidth = GetDrawStringWidthToHandle("Graphics", sizeof("Graphics"), Font);
		DrawStringToHandle(((screenWidth / 2 - fontWidth) + screenWidth / 4) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Graphics", GetColor(255, 255, 0), Font);
		break;

	case 2:
		// サウンド関連設定
		fontWidth = GetDrawStringWidthToHandle("Sound", sizeof("Sound"), Font);
		DrawStringToHandle(((screenWidth / 2 + screenWidth / 4) - fontWidth + screenWidth / 2) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Sound", GetColor(255, 255, 0), Font);
		break;

	case 3:
		// キーコンフィグ関連設定
		fontWidth = GetDrawStringWidthToHandle("Key Config", sizeof("Key Config"), Font);
		DrawStringToHandle((screenWidth - fontWidth + screenWidth * 3 / 4) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Key Config", GetColor(255, 255, 0), Font);
		break;

	default:
		break;
	}
}

// 基本画面描画
void Config::DrawBase(int screenWidth, int screenHeight){
	int fontWidth;

	DrawLineAA(0.0f
		, static_cast<float>(screenHeight / 1080.0 * 100)
		, static_cast<float>(screenWidth)
		, static_cast<float>(screenHeight / 1080.0 * 100)
		, GetColor(255, 255, 255));
	DrawLineAA(0.0f
		, static_cast<float>(screenHeight / 1080.0 * 200)
		, static_cast<float>(screenWidth)
		, static_cast<float>(screenHeight / 1080.0 * 200)
		, GetColor(255, 255, 255));
	DrawLineAA(0.0f
		, static_cast<float>(screenHeight / 1080.0 * 950)
		, static_cast<float>(screenWidth)
		, static_cast<float>(screenHeight / 1080.0 * 950)
		, GetColor(255, 255, 255));

	fontWidth = GetDrawStringWidthToHandle("Display", sizeof("Display"), Font);
	DrawStringToHandle((screenWidth / 4 - fontWidth) / 2, static_cast<int>(screenHeight / 1080.0 * 120), "Display", GetColor(255, 255, 255), Font);
	fontWidth = GetDrawStringWidthToHandle("Graphics", sizeof("Graphics"), Font);
	DrawStringToHandle(((screenWidth / 2 - fontWidth) + screenWidth / 4) / 2, static_cast<int>(screenHeight / 1080.0 * 120), "Graphics", GetColor(255, 255, 255), Font);
	fontWidth = GetDrawStringWidthToHandle("Sound", sizeof("Sound"), Font);
	DrawStringToHandle(((screenWidth / 2 + screenWidth / 4) - fontWidth + screenWidth / 2) / 2, static_cast<int>(screenHeight / 1080.0 * 120), "Sound", GetColor(255, 255, 255), Font);
	fontWidth = GetDrawStringWidthToHandle("Key Config", sizeof("Key Config"), Font);
	DrawStringToHandle((screenWidth - fontWidth + screenWidth * 3 / 4) / 2, static_cast<int>(screenHeight / 1080.0 * 120), "Key Config", GetColor(255, 255, 255), Font);
	switch(Tab){
	case 0:
		// ディスプレイ
		// ウィンドウモード
		DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 250), "ウィンドウモード :", GetColor(255, 255, 255), FontJ);
		if(Setting == false || Cursor != 0){
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1200)
				, static_cast<float>(screenHeight / 1080.0 * 245)
				, static_cast<float>(screenWidth / 1920.0 * 1580)
				, static_cast<float>(screenHeight / 1080.0 * 290)
				, GetColor(255, 255, 255), FALSE);
		}
		DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1580)
			, static_cast<float>(screenHeight / 1080.0 * 245)
			, static_cast<float>(screenWidth / 1920.0 * 1620)
			, static_cast<float>(screenHeight / 1080.0 * 290)
			, GetColor(255, 255, 255), FALSE);
		fontWidth = GetDrawStringWidthToHandle("▼", sizeof("▼"), FontJ);
		DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1620 - (fontWidth + screenWidth / 1920.0 * 1580)) / 2 + screenWidth / 1920.0 * 1580)
			, static_cast<int>(screenHeight / 1080.0 * 250)
			, "▼", GetColor(255, 255, 255), FontJ);

		if(Setting == false || Cursor != 0){
			switch(Ini_p->GetMode()){
			case 0:
				fontWidth = GetDrawStringWidthToHandle("ウィンドウ", sizeof("ウィンドウ"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
					, static_cast<int>(screenHeight / 1080.0 * 250)
					, "ウィンドウ", GetColor(255, 255, 255), FontJ);
				break;

			case 1:
				fontWidth = GetDrawStringWidthToHandle("仮想フルスクリーン", sizeof("仮想フルスクリーン"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
					, static_cast<int>(screenHeight / 1080.0 * 250)
					, "仮想フルスクリーン", GetColor(255, 255, 255), FontJ);
				break;

			case 2:
				fontWidth = GetDrawStringWidthToHandle("フルスクリーン", sizeof("フルスクリーン"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
					, static_cast<int>(screenHeight / 1080.0 * 250)
					, "フルスクリーン", GetColor(255, 255, 255), FontJ);
				break;

			default:
				break;

			}
		}
		// 解像度
		if(Ini_p->GetMode() != 1){
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 350), "解像度                :", GetColor(255, 255, 255), FontJ);
			if(Setting == false || Cursor != 0){
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1200)
					, static_cast<float>(screenHeight / 1080.0 * 345)
					, static_cast<float>(screenWidth / 1920.0 * 1580)
					, static_cast<float>(screenHeight / 1080.0 * 390)
					, GetColor(255, 255, 255), FALSE);
			}
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1580)
				, static_cast<float>(screenHeight / 1080.0 * 345)
				, static_cast<float>(screenWidth / 1920.0 * 1620)
				, static_cast<float>(screenHeight / 1080.0 * 390)
				, GetColor(255, 255, 255), FALSE);
			fontWidth = GetDrawStringWidthToHandle("▼", sizeof("▼"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1620 - (fontWidth + screenWidth / 1920.0 * 1580)) / 2 + screenWidth / 1920.0 * 1580)
				, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 350)
				, "▼", GetColor(255, 255, 255), FontJ);
		}
		else{
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 350), "解像度                :", GetColor(64, 64, 64), FontJ);
			if(Setting == false || Cursor != 0){
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1200)
					, static_cast<float>(screenHeight / 1080.0 * 345)
					, static_cast<float>(screenWidth / 1920.0 * 1580)
					, static_cast<float>(screenHeight / 1080.0 * 390)
					, GetColor(64, 64, 64), FALSE);
			}
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1580)
				, static_cast<float>(screenHeight / 1080.0 * 345)
				, static_cast<float>(screenWidth / 1920.0 * 1620)
				, static_cast<float>(screenHeight / 1080.0 * 390)
				, GetColor(64, 64, 64), FALSE);
			fontWidth = GetDrawStringWidthToHandle("▼", sizeof("▼"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1620 - (fontWidth + screenWidth / 1920.0 * 1580)) / 2 + screenWidth / 1920.0 * 1580)
				, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 350)
				, "▼", GetColor(64, 64, 64), FontJ);
		}
		// 表示ディスプレイ
		if(Ini_p->GetMode() == 2){
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 450), "表示ディスプレイ :", GetColor(255, 255, 255), FontJ);
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1200)
				, static_cast<float>(screenHeight / 1080.0 * 445)
				, static_cast<float>(screenWidth / 1920.0 * 1580)
				, static_cast<float>(screenHeight / 1080.0 * 490)
				, GetColor(255, 255, 255), FALSE);
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1580)
				, static_cast<float>(screenHeight / 1080.0 * 445)
				, static_cast<float>(screenWidth / 1920.0 * 1620)
				, static_cast<float>(screenHeight / 1080.0 * 490)
				, GetColor(255, 255, 255), FALSE);
			fontWidth = GetDrawStringWidthToHandle("▼", sizeof("▼"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1620 - (fontWidth + screenWidth / 1920.0 * 1580)) / 2 + screenWidth / 1920.0 * 1580)
				, static_cast<int>(screenHeight / 1080.0 * 450)
				, "▼", GetColor(255, 255, 255), FontJ);
		}
		else{
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 450), "表示ディスプレイ :", GetColor(64, 64, 64), FontJ);
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1200)
				, static_cast<float>(screenHeight / 1080.0 * 445)
				, static_cast<float>(screenWidth / 1920.0 * 1580)
				, static_cast<float>(screenHeight / 1080.0 * 490)
				, GetColor(64, 64, 64), FALSE);
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1580)
				, static_cast<float>(screenHeight / 1080.0 * 445)
				, static_cast<float>(screenWidth / 1920.0 * 1620)
				, static_cast<float>(screenHeight / 1080.0 * 490)
				, GetColor(64, 64, 64), FALSE);
			fontWidth = GetDrawStringWidthToHandle("▼", sizeof("▼"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1620 - (fontWidth + screenWidth / 1920.0 * 1580)) / 2 + screenWidth / 1920.0 * 1580)
				, static_cast<int>(screenHeight / 1080.0 * 450)
				, "▼", GetColor(64, 64, 64), FontJ);
		}
		// FPS表示
		DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 550), "FPS表示             :", GetColor(255, 255, 255), FontJ);
		DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1590)
			, static_cast<float>(screenHeight / 1080.0 * 550)
			, static_cast<float>(screenWidth / 1920.0 * 1620)
			, static_cast<float>(screenHeight / 1080.0 * 580)
			, GetColor(255, 255, 255), FALSE);
		if(Ini_p->GetFps() == true){
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1595)
				, static_cast<float>(screenHeight / 1080.0 * 555)
				, static_cast<float>(screenWidth / 1920.0 * 1615)
				, static_cast<float>(screenHeight / 1080.0 * 575)
				, GetColor(255, 255, 255), TRUE);
		}
		break;

	case 1:
		// グラフィック
		break;

	case 2:
		// サウンド
		break;

	case 3:
		// キーコンフィグ
		break;

	default:
		break;
	}
	if(GetChange() == true || Apply == true){
		DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1330), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1480), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 255), FALSE);
		fontWidth = GetDrawStringWidthToHandle("保存", sizeof("保存"), FontJ);
		DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1480 - (fontWidth + screenWidth / 1920.0 * 1330)) / 2 + screenWidth / 1920.0 * 1330), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "保存", GetColor(255, 255, 255), FontJ);
	}
	else{
		DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1330), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1480), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(64, 64, 64), FALSE);
		fontWidth = GetDrawStringWidthToHandle("保存", sizeof("保存"), FontJ);
		DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1480 - (fontWidth + screenWidth / 1920.0 * 1330)) / 2 + screenWidth / 1920.0 * 1330), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "保存", GetColor(64, 64, 64), FontJ);
	}
	DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1530), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1680), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 255), FALSE);
	fontWidth = GetDrawStringWidthToHandle("ｷｬﾝｾﾙ", sizeof("ｷｬﾝｾﾙ"), FontJ);
	DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1680 - (fontWidth + screenWidth / 1920.0 * 1530)) / 2 + screenWidth / 1920.0 * 1530), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "ｷｬﾝｾﾙ", GetColor(255, 255, 255), FontJ);
	if(GetChange() == true){
		DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1730), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1880), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 255), FALSE);
		fontWidth = GetDrawStringWidthToHandle("適用", sizeof("適用"), FontJ);
		DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1880 - (fontWidth + screenWidth / 1920.0 * 1730)) / 2 + screenWidth / 1920.0 * 1730), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "適用", GetColor(255, 255, 255), FontJ);
	}
	else{
		DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1730), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1880), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(64, 64, 64), FALSE);
		fontWidth = GetDrawStringWidthToHandle("適用", sizeof("適用"), FontJ);
		DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1880 - (fontWidth + screenWidth / 1920.0 * 1730)) / 2 + screenWidth / 1920.0 * 1730), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "適用", GetColor(64, 64, 64), FontJ);
	}
}

// 設定適用
void Config::ApplySetting(){
	int dispWidth;
	int dispHeight;
	int colorBit;

	if(GetChangeWindow() == true){
		GetDefaultState(&dispWidth, &dispHeight, &colorBit);
		// ウィンドウモード設定
		switch(Ini_p->GetMode()){
		case 0:
			// ウィンドウモードに設定
			SetWindowVisibleFlag(FALSE);
			if(GetWindowModeFlag() == FALSE){
				ChangeWindowMode(TRUE);
			}
			SetWindowStyleMode(0);
			// ウィンドウ設定
			SetGraphMode(Ini_p->GetWidth(), Ini_p->GetHeight(), colorBit);
			SetWindowVisibleFlag(TRUE);
			SetWindowPosition((dispWidth - Ini_p->GetWidth()) / 2, (dispHeight - Ini_p->GetHeight()) / 2);
			break;

		case 1:
			// 仮想フルスクリーンに設定
			SetWindowVisibleFlag(FALSE);
			if(GetWindowModeFlag() == FALSE){
				ChangeWindowMode(TRUE);
			}
			SetWindowStyleMode(2);
			SetWindowPosition(0, 0);
			SetGraphMode(dispWidth, dispHeight, colorBit);
			SetWindowVisibleFlag(TRUE);
			break;

		case 2:
			// フルスクリーンに設定
			SetWindowVisibleFlag(FALSE);
			if(GetWindowModeFlag() == TRUE){
				ChangeWindowMode(FALSE);
			}
			SetUseDisplayIndex(Ini_p->GetDisplay());
			SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_MAXIMUM);
			SetGraphMode(Ini_p->GetWidth(), Ini_p->GetHeight(), colorBit);
			SetWindowVisibleFlag(TRUE);
			break;

		default:
			break;

		}
	}
}

// キャンセル
void Config::Cancel(){
	Ini_p->SetMode(PreMode);
	Ini_p->SetWidth(PreWidth);
	Ini_p->SetHeight(PreHeight);
	Ini_p->SetDisplay(PreDisplay);
	Ini_p->SetFps(PreFps);
}

// 変更取得
bool Config::GetChange(){
	bool retVal = false;

	// 変更前ウィンドウモード
	if(PreMode != Ini_p->GetMode()){
		retVal = true;
	}
	// 変更前ウィンドウ幅
	if(PreWidth != Ini_p->GetWidth()){
		retVal = true;
	}
	// 変更前ウィンドウ高
	if(PreHeight != Ini_p->GetHeight()){
		retVal = true;
	}
	// 変更前表示ディスプレイ
	if(PreDisplay != Ini_p->GetDisplay()){
		retVal = true;
	}
	// 変更前FPS表示
	if(PreFps != Ini_p->GetFps()){
		retVal = true;
	}

	return retVal;
}

// ウィンドウ変更取得
bool Config::GetChangeWindow(){
	bool retVal = false;

	// 変更前ウィンドウモード
	if(PreMode != Ini_p->GetMode()){
		retVal = true;
	}
	// 変更前ウィンドウ幅
	if(PreWidth != Ini_p->GetWidth()){
		retVal = true;
	}
	// 変更前ウィンドウ高
	if(PreHeight != Ini_p->GetHeight()){
		retVal = true;
	}
	// 変更前表示ディスプレイ
	if(PreDisplay != Ini_p->GetDisplay()){
		retVal = true;
	}

	return retVal;
}
// End Of File