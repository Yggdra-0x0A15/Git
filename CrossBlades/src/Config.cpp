#include "Config.h"
#include "DxLib.h"

Config::Config(ISceneChanger* changer) : Scene(changer) {
	// ini�C���X�^���X�擾
	Ini_p = Ini::GetInstance();
	// �摜�̃��[�h
	Image = LoadGraph("./dat/pic/Config.bmp");
	Cursor = 0;
	Tab = 0;
	Button = 0;
	TabStop = false;
	Setting = false;
	IndexMode = Ini_p->GetMode();
	IndexResolution = 0;
	IndexDisplay = Ini_p->GetDisplay();
}

// ������
void Config::Initialize(){
}

// �X�V
void Config::Update(){
	if(CheckHitKey(KEY_INPUT_ESCAPE) != 0){
		// �V�[�������j���[�ɕύX
		SceneChanger_p->ChangeScene(SceneMenu);
	}
	if(CheckHitKey(KEY_INPUT_RETURN) != 0){
		if(Setting == true){
			// ����
			switch(Tab){
			case 0:
				// �f�B�X�v���C�ݒ�
				switch(Cursor){
				case 0:
					// �E�B���h�E���[�h
					Ini_p->SetMode(IndexMode);
					Setting = false;
					break;

				case 1:
					// �𑜓x
					Setting = false;
					break;

				case 2:
					// �\���f�B�X�v���C
					Setting = false;
					break;

				case 3:
					// FPS�\��
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
				// �O���t�B�b�N�ݒ�
				break;

			case 2:
				// �T�E���h�ݒ�
				break;

			case 3:
				// �L�[�R���t�B�O�ݒ�
				break;

			default:
				break;
			}
		}
		else{
			switch(Tab){
			case 0:
				// �f�B�X�v���C�ݒ�
				switch(Cursor){
				case 0:
					// �E�B���h�E���[�h
					Setting = true;
					break;

				case 1:
					// �𑜓x
					Setting = true;
					break;

				case 2:
					// �\���f�B�X�v���C
					Setting = true;
					break;

				case 3:
					// FPS�\��
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
						// �ۑ�
						ApplySetting();
						Ini_p->Write();
						SceneChanger_p->ChangeScene(SceneMenu);
						break;

					case 1:
						// �L�����Z��
						SceneChanger_p->ChangeScene(SceneMenu);
						break;

					case 2:
						// �K�p
						ApplySetting();
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
				// �O���t�B�b�N�ݒ�
				break;

			case 2:
				// �T�E���h�ݒ�
				break;

			case 3:
				// �L�[�R���t�B�O�ݒ�
				break;

			default:
				break;
			}
		}
	}
	if(CheckHitKey(KEY_INPUT_LEFT) != 0){
		if(Setting == false){
			if(TabStop == true){
				// �{�^���ړ�
				if(Button == 0){
					Button = 2;
				}
				else{
					Button--;
				}
			}
			else{
				// �^�u�ړ�
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
				// �{�^���ړ�
				if(Button == 2){
					Button = 0;
				}
				else{
					Button++;
				}
			}
			else{
				// �^�u�ړ�
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
			// �ݒ荀�ڑI��
			switch(Tab){
			case 0:
				// �f�B�X�v���C�ݒ�
				switch(Cursor){
				case 0:
					// �E�B���h�E���[�h
					if(IndexMode == 0){
						IndexMode = 2;
					}
					else{
						IndexMode--;
					}
					break;

				case 1:
					// �𑜓x
					break;

				case 2:
					// �\���f�B�X�v���C
					break;

				default:
					break;

				}
				break;

			case 1:
				// �O���t�B�b�N�ݒ�
				break;

			case 2:
				// �T�E���h�ݒ�
				break;

			case 3:
				// �L�[�R���t�B�O�ݒ�
				break;

			default:
				break;

			}
		}
		else{
			// �J�[�\���ړ�
			if(Cursor == 0){
				Cursor = 4;
			}
			else{
				Cursor--;
			}
			Button = 0;
		}
	}
	if(CheckHitKey(KEY_INPUT_DOWN) != 0){
		if(Setting == true){
			switch(Tab){
			case 0:
				// �f�B�X�v���C�ݒ�
				switch(Cursor){
				case 0:
					// �E�B���h�E���[�h
					if(IndexMode == 2){
						IndexMode = 0;
					}
					else{
						IndexMode++;
					}
					break;

				case 1:
					// �𑜓x
					break;

				case 2:
					// �\���f�B�X�v���C
					break;

				default:
					break;

				}
				break;

			case 1:
				// �O���t�B�b�N�ݒ�
				break;

			case 2:
				// �T�E���h�ݒ�
				break;

			case 3:
				// �L�[�R���t�B�O�ݒ�
				break;

			default:
				break;

			}
		}
		else{
			// �J�[�\���ړ�
			if(Cursor == 4){
				Cursor = 0;
			}
			else{
				Cursor++;
			}
			Button = 0;
		}
	}
}

// �`��
void Config::Draw(){
	int fontWidth;
	int screenWidth;
	int screenHeight;
	// �e�N���X�̕`�惁�\�b�h���Ă�
	Scene::Draw();
	GetWindowSize(&screenWidth, &screenHeight);
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

	switch(Tab){
	case 0:
		// �f�B�X�v���C�֘A�ݒ�
		fontWidth = GetDrawStringWidthToHandle("Display", sizeof("Display"), Font);
		DrawStringToHandle((screenWidth / 4 - fontWidth) / 2, static_cast<int>(screenHeight / 1080.0 * 120), "Display", GetColor(255, 255, 0), Font);
		fontWidth = GetDrawStringWidthToHandle("Graphics", sizeof("Graphics"), Font);
		DrawStringToHandle(((screenWidth / 2 - fontWidth) + screenWidth / 4) / 2, static_cast<int>(screenHeight / 1080.0 * 120), "Graphics", GetColor(255, 255, 255), Font);
		fontWidth = GetDrawStringWidthToHandle("Sound", sizeof("Sound"), Font);
		DrawStringToHandle(((screenWidth / 2 + screenWidth / 4) - fontWidth + screenWidth / 2) / 2, static_cast<int>(screenHeight / 1080.0 * 120), "Sound", GetColor(255, 255, 255), Font);
		fontWidth = GetDrawStringWidthToHandle("Key Config", sizeof("Key Config"), Font);
		DrawStringToHandle((screenWidth - fontWidth + screenWidth * 3 / 4) / 2, static_cast<int>(screenHeight / 1080.0 * 120), "Key Config", GetColor(255, 255, 255), Font);
		switch(Cursor){
		case 0:
			// �E�B���h�E���[�h
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 250), "�E�B���h�E���[�h :", GetColor(255, 255, 0), FontJ);
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 350), "�𑜓x                :", GetColor(255, 255, 255), FontJ);
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 450), "�\���f�B�X�v���C :", GetColor(255, 255, 255), FontJ);
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 550), "FPS�\��             :", GetColor(255, 255, 255), FontJ);
			if(Setting == true){
				// �R���{�{�b�N�X�g��
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
				fontWidth = GetDrawStringWidthToHandle("��", sizeof("��"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1620 - (fontWidth + screenWidth / 1920.0 * 1580)) / 2 + screenWidth / 1920.0 * 1580)
								, static_cast<int>(screenHeight / 1080.0 * 250)
								, "��", GetColor(255, 255, 255), FontJ);

				switch(IndexMode){
				case 0:
					fontWidth = GetDrawStringWidthToHandle("�E�B���h�E", sizeof("�E�B���h�E"), FontJ);
					DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
						, static_cast<int>(screenHeight / 1080.0 * 250)
						, "�E�B���h�E", GetColor(255, 255, 0), FontJ);
					fontWidth = GetDrawStringWidthToHandle("���z�t���X�N���[��", sizeof("���z�t���X�N���[��"), FontJ);
					DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
						, static_cast<int>(screenHeight / 1080.0 * 300)
						, "���z�t���X�N���[��", GetColor(255, 255, 255), FontJ);
					fontWidth = GetDrawStringWidthToHandle("�t���X�N���[��", sizeof("�t���X�N���[��"), FontJ);
					DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
						, static_cast<int>(screenHeight / 1080.0 * 350)
						, "�t���X�N���[��", GetColor(255, 255, 255), FontJ);
					break;

				case 1:
					fontWidth = GetDrawStringWidthToHandle("�E�B���h�E", sizeof("�E�B���h�E"), FontJ);
					DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
						, static_cast<int>(screenHeight / 1080.0 * 250)
						, "�E�B���h�E", GetColor(255, 255, 255), FontJ);
					fontWidth = GetDrawStringWidthToHandle("���z�t���X�N���[��", sizeof("���z�t���X�N���[��"), FontJ);
					DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
						, static_cast<int>(screenHeight / 1080.0 * 300)
						, "���z�t���X�N���[��", GetColor(255, 255, 0), FontJ);
					fontWidth = GetDrawStringWidthToHandle("�t���X�N���[��", sizeof("�t���X�N���[��"), FontJ);
					DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
						, static_cast<int>(screenHeight / 1080.0 * 350)
						, "�t���X�N���[��", GetColor(255, 255, 255), FontJ);
					break;

				case 2:
					fontWidth = GetDrawStringWidthToHandle("�E�B���h�E", sizeof("�E�B���h�E"), FontJ);
					DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
						, static_cast<int>(screenHeight / 1080.0 * 250)
						, "�E�B���h�E", GetColor(255, 255, 255), FontJ);
					fontWidth = GetDrawStringWidthToHandle("���z�t���X�N���[��", sizeof("���z�t���X�N���[��"), FontJ);
					DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
						, static_cast<int>(screenHeight / 1080.0 * 300)
						, "���z�t���X�N���[��", GetColor(255, 255, 255), FontJ);
					fontWidth = GetDrawStringWidthToHandle("�t���X�N���[��", sizeof("�t���X�N���[��"), FontJ);
					DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
						, static_cast<int>(screenHeight / 1080.0 * 350)
						, "�t���X�N���[��", GetColor(255, 255, 0), FontJ);
					break;

				default:
					break;

				}
				// �𑜓x
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1580)
						, static_cast<float>(screenHeight / 1080.0 * 345)
						, static_cast<float>(screenWidth / 1920.0 * 1620)
						, static_cast<float>(screenHeight / 1080.0 * 390)
						, GetColor(255, 255, 255), FALSE);
				fontWidth = GetDrawStringWidthToHandle("��", sizeof("��"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1620 - (fontWidth + screenWidth / 1920.0 * 1580)) / 2 + screenWidth / 1920.0 * 1580)
								, static_cast<int>(screenHeight / 1080.0 * 350)
								, "��", GetColor(255, 255, 255), FontJ);
				// �\���f�B�X�v���C
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
				fontWidth = GetDrawStringWidthToHandle("��", sizeof("��"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1620 - (fontWidth + screenWidth / 1920.0 * 1580)) / 2 + screenWidth / 1920.0 * 1580)
								, static_cast<int>(screenHeight / 1080.0 * 450)
								, "��", GetColor(255, 255, 255), FontJ);
				// FPS�\��
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1590)
						, static_cast<float>(screenHeight / 1080.0 * 550)
						, static_cast<float>(screenWidth / 1920.0 * 1620)
						, static_cast<float>(screenHeight / 1080.0 * 580)
						, GetColor(255, 255, 255), FALSE);
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
				fontWidth = GetDrawStringWidthToHandle("��", sizeof("��"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1620 - (fontWidth + screenWidth / 1920.0 * 1580)) / 2 + screenWidth / 1920.0 * 1580)
								, static_cast<int>(screenHeight / 1080.0 * 250)
								, "��", GetColor(255, 255, 0), FontJ);
				switch(Ini_p->GetMode()){
				case 0:
					fontWidth = GetDrawStringWidthToHandle("�E�B���h�E", sizeof("�E�B���h�E"), FontJ);
					DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
									, static_cast<int>(screenHeight / 1080.0 * 250)
									, "�E�B���h�E", GetColor(255, 255, 255), FontJ);
					break;

				case 1:
					fontWidth = GetDrawStringWidthToHandle("���z�t���X�N���[��", sizeof("���z�t���X�N���[��"), FontJ);
					DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
									, static_cast<int>(screenHeight / 1080.0 * 250)
									, "���z�t���X�N���[��", GetColor(255, 255, 255), FontJ);
					break;

				case 2:
					fontWidth = GetDrawStringWidthToHandle("�t���X�N���[��", sizeof("�t���X�N���[��"), FontJ);
					DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
									, static_cast<int>(screenHeight / 1080.0 * 250)
									, "�t���X�N���[��", GetColor(255, 255, 255), FontJ);
					break;

				default:
					break;

				}
				// �𑜓x
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1200)
						, static_cast<float>(screenHeight / 1080.0 * 345)
						, static_cast<float>(screenWidth / 1920.0 * 1580)
						, static_cast<float>(screenHeight / 1080.0 * 390)
						, GetColor(255, 255, 255), FALSE);
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1580)
						, static_cast<float>(screenHeight / 1080.0 * 345)
						, static_cast<float>(screenWidth / 1920.0 * 1620)
						, static_cast<float>(screenHeight / 1080.0 * 390)
						, GetColor(255, 255, 255), FALSE);
				fontWidth = GetDrawStringWidthToHandle("��", sizeof("��"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1620 - (fontWidth + screenWidth / 1920.0 * 1580)) / 2 + screenWidth / 1920.0 * 1580)
								, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 350)
								, "��", GetColor(255, 255, 255), FontJ);
				// �\���f�B�X�v���C
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
				fontWidth = GetDrawStringWidthToHandle("��", sizeof("��"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1620 - (fontWidth + screenWidth / 1920.0 * 1580)) / 2 + screenWidth / 1920.0 * 1580)
								, static_cast<int>(screenHeight / 1080.0 * 450)
								, "��", GetColor(255, 255, 255), FontJ);
				// FPS�\��
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1590)
						, static_cast<float>(screenHeight / 1080.0 * 550)
						, static_cast<float>(screenWidth / 1920.0 * 1620)
						, static_cast<float>(screenHeight / 1080.0 * 580)
						, GetColor(255, 255, 255), FALSE);
			}
			TabStop = false;
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1330)
					, static_cast<float>(screenHeight / 1080.0 * 980)
					, static_cast<float>(screenWidth / 1920.0 * 1480)
					, static_cast<float>(screenHeight / 1080.0 * 1050)
					, GetColor(255, 255, 255), FALSE);
			fontWidth = GetDrawStringWidthToHandle("�ۑ�", sizeof("�ۑ�"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1480 - (fontWidth + screenWidth / 1920.0 * 1330)) / 2 + screenWidth / 1920.0 * 1330)
							, static_cast<int>(screenHeight / 1080.0 * 999)
							, "�ۑ�", GetColor(255, 255, 255), FontJ);
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1530)
					, static_cast<float>(screenHeight / 1080.0 * 980)
					, static_cast<float>(screenWidth / 1920.0 * 1680)
					, static_cast<float>(screenHeight / 1080.0 * 1050)
					, GetColor(255, 255, 255), FALSE);
			fontWidth = GetDrawStringWidthToHandle("��ݾ�", sizeof("��ݾ�"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1680 - (fontWidth + screenWidth / 1920.0 * 1530)) / 2 + screenWidth / 1920.0 * 1530)
							, static_cast<int>(screenHeight / 1080.0 * 999), "��ݾ�"
							, GetColor(255, 255, 255), FontJ);
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1730)
					, static_cast<float>(screenHeight / 1080.0 * 980)
					, static_cast<float>(screenWidth / 1920.0 * 1880)
					, static_cast<float>(screenHeight / 1080.0 * 1050)
					, GetColor(255, 255, 255), FALSE);
			fontWidth = GetDrawStringWidthToHandle("�K�p", sizeof("�K�p"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1880 - (fontWidth + screenWidth / 1920.0 * 1730)) / 2 + screenWidth / 1920.0 * 1730)
							, static_cast<int>(screenHeight / 1080.0 * 999)
							, "�K�p", GetColor(255, 255, 255), FontJ);
			break;

		case 1:
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 250), "�E�B���h�E���[�h :", GetColor(255, 255, 255), FontJ);
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 350), "�𑜓x                :", GetColor(255, 255, 0), FontJ);
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 450), "�\���f�B�X�v���C :", GetColor(255, 255, 255), FontJ);
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 550), "FPS�\��             :", GetColor(255, 255, 255), FontJ);
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
			fontWidth = GetDrawStringWidthToHandle("��", sizeof("��"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1620 - (fontWidth + screenWidth / 1920.0 * 1580)) / 2 + screenWidth / 1920.0 * 1580)
							, static_cast<int>(screenHeight / 1080.0 * 250)
							, "��", GetColor(255, 255, 0), FontJ);
			switch(Ini_p->GetMode()){
			case 0:
				fontWidth = GetDrawStringWidthToHandle("�E�B���h�E", sizeof("�E�B���h�E"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
								, static_cast<int>(screenHeight / 1080.0 * 250)
								, "�E�B���h�E", GetColor(255, 255, 255), FontJ);
				break;

			case 1:
				fontWidth = GetDrawStringWidthToHandle("���z�t���X�N���[��", sizeof("���z�t���X�N���[��"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
								, static_cast<int>(screenHeight / 1080.0 * 250)
								, "���z�t���X�N���[��", GetColor(255, 255, 255), FontJ);
				break;

			case 2:
				fontWidth = GetDrawStringWidthToHandle("�t���X�N���[��", sizeof("�t���X�N���[��"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
								, static_cast<int>(screenHeight / 1080.0 * 250)
								, "�t���X�N���[��", GetColor(255, 255, 255), FontJ);
				break;

			default:
				break;

			}
			// �𑜓x
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 350), "�𑜓x                :", GetColor(255, 255, 255), FontJ);
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1200)
					, static_cast<float>(screenHeight / 1080.0 * 345)
					, static_cast<float>(screenWidth / 1920.0 * 1580)
					, static_cast<float>(screenHeight / 1080.0 * 390)
					, GetColor(255, 255, 255), FALSE);
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1580)
					, static_cast<float>(screenHeight / 1080.0 * 345)
					, static_cast<float>(screenWidth / 1920.0 * 1620)
					, static_cast<float>(screenHeight / 1080.0 * 390)
					, GetColor(255, 255, 255), FALSE);
			fontWidth = GetDrawStringWidthToHandle("��", sizeof("��"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1620 - (fontWidth + screenWidth / 1920.0 * 1580)) / 2 + screenWidth / 1920.0 * 1580)
							, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 350)
							, "��", GetColor(255, 255, 255), FontJ);
			// �\���f�B�X�v���C
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 450), "�\���f�B�X�v���C :", GetColor(255, 255, 255), FontJ);
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
			fontWidth = GetDrawStringWidthToHandle("��", sizeof("��"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1620 - (fontWidth + screenWidth / 1920.0 * 1580)) / 2 + screenWidth / 1920.0 * 1580)
							, static_cast<int>(screenHeight / 1080.0 * 450)
							, "��", GetColor(255, 255, 255), FontJ);
			// FPS�\��
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 550), "FPS�\��             :", GetColor(255, 255, 255), FontJ);
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1590)
					, static_cast<float>(screenHeight / 1080.0 * 550)
					, static_cast<float>(screenWidth / 1920.0 * 1620)
					, static_cast<float>(screenHeight / 1080.0 * 580)
					, GetColor(255, 255, 255), FALSE);
			TabStop = false;
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1330)
					, static_cast<float>(screenHeight / 1080.0 * 980)
					, static_cast<float>(screenWidth / 1920.0 * 1480)
					, static_cast<float>(screenHeight / 1080.0 * 1050)
					, GetColor(255, 255, 255), FALSE);
			fontWidth = GetDrawStringWidthToHandle("�ۑ�", sizeof("�ۑ�"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1480 - (fontWidth + screenWidth / 1920.0 * 1330)) / 2 + screenWidth / 1920.0 * 1330)
							, static_cast<int>(screenHeight / 1080.0 * 999)
							, "�ۑ�", GetColor(255, 255, 255), FontJ);
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1530)
					, static_cast<float>(screenHeight / 1080.0 * 980)
					, static_cast<float>(screenWidth / 1920.0 * 1680)
					, static_cast<float>(screenHeight / 1080.0 * 1050)
					, GetColor(255, 255, 255), FALSE);
			fontWidth = GetDrawStringWidthToHandle("��ݾ�", sizeof("��ݾ�"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1680 - (fontWidth + screenWidth / 1920.0 * 1530)) / 2 + screenWidth / 1920.0 * 1530)
							, static_cast<int>(screenHeight / 1080.0 * 999), "��ݾ�", GetColor(255, 255, 255), FontJ);
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1730)
					, static_cast<float>(screenHeight / 1080.0 * 980)
					, static_cast<float>(screenWidth / 1920.0 * 1880)
					, static_cast<float>(screenHeight / 1080.0 * 1050)
					, GetColor(255, 255, 255), FALSE);
			fontWidth = GetDrawStringWidthToHandle("�K�p", sizeof("�K�p"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1880 - (fontWidth + screenWidth / 1920.0 * 1730)) / 2 + screenWidth / 1920.0 * 1730)
							, static_cast<int>(screenHeight / 1080.0 * 999)
							, "�K�p", GetColor(255, 255, 255), FontJ);
			break;

		case 2:
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 250), "�E�B���h�E���[�h :", GetColor(255, 255, 255), FontJ);
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 350), "�𑜓x                :", GetColor(255, 255, 255), FontJ);
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 450), "�\���f�B�X�v���C :", GetColor(255, 255, 0), FontJ);
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 550), "FPS�\��             :", GetColor(255, 255, 255), FontJ);
			TabStop = false;
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1330)
					, static_cast<float>(screenHeight / 1080.0 * 980)
					, static_cast<float>(screenWidth / 1920.0 * 1480)
					, static_cast<float>(screenHeight / 1080.0 * 1050)
					, GetColor(255, 255, 255), FALSE);
			fontWidth = GetDrawStringWidthToHandle("�ۑ�", sizeof("�ۑ�"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1480 - (fontWidth + screenWidth / 1920.0 * 1330)) / 2 + screenWidth / 1920.0 * 1330)
							, static_cast<int>(screenHeight / 1080.0 * 999)
							, "�ۑ�", GetColor(255, 255, 255), FontJ);
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1530)
					, static_cast<float>(screenHeight / 1080.0 * 980)
					, static_cast<float>(screenWidth / 1920.0 * 1680)
					, static_cast<float>(screenHeight / 1080.0 * 1050)
					, GetColor(255, 255, 255), FALSE);
			fontWidth = GetDrawStringWidthToHandle("��ݾ�", sizeof("��ݾ�"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1680 - (fontWidth + screenWidth / 1920.0 * 1530)) / 2 + screenWidth / 1920.0 * 1530)
							, static_cast<int>(screenHeight / 1080.0 * 999)
							, "��ݾ�", GetColor(255, 255, 255), FontJ);
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1730)
					, static_cast<float>(screenHeight / 1080.0 * 980)
					, static_cast<float>(screenWidth / 1920.0 * 1880)
					, static_cast<float>(screenHeight / 1080.0 * 1050)
					, GetColor(255, 255, 255), FALSE);
			fontWidth = GetDrawStringWidthToHandle("�K�p", sizeof("�K�p"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1880 - (fontWidth + screenWidth / 1920.0 * 1730)) / 2 + screenWidth / 1920.0 * 1730)
							, static_cast<int>(screenHeight / 1080.0 * 999)
							, "�K�p", GetColor(255, 255, 255), FontJ);
			break;

		case 3:
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 250), "�E�B���h�E���[�h :", GetColor(255, 255, 255), FontJ);
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 350), "�𑜓x                :", GetColor(255, 255, 255), FontJ);
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 450), "�\���f�B�X�v���C :", GetColor(255, 255, 255), FontJ);
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 550), "FPS�\��             :", GetColor(255, 255, 0), FontJ);
			TabStop = false;
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1330), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1480), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 255), FALSE);
			fontWidth = GetDrawStringWidthToHandle("�ۑ�", sizeof("�ۑ�"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1480 - (fontWidth + screenWidth / 1920.0 * 1330)) / 2 + screenWidth / 1920.0 * 1330), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "�ۑ�", GetColor(255, 255, 255), FontJ);
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1530), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1680), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 255), FALSE);
			fontWidth = GetDrawStringWidthToHandle("��ݾ�", sizeof("��ݾ�"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1680 - (fontWidth + screenWidth / 1920.0 * 1530)) / 2 + screenWidth / 1920.0 * 1530), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "��ݾ�", GetColor(255, 255, 255), FontJ);
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1730), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1880), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 255), FALSE);
			fontWidth = GetDrawStringWidthToHandle("�K�p", sizeof("�K�p"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1880 - (fontWidth + screenWidth / 1920.0 * 1730)) / 2 + screenWidth / 1920.0 * 1730), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "�K�p", GetColor(255, 255, 255), FontJ);
			break;

		case 4:
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 250), "�E�B���h�E���[�h :", GetColor(255, 255, 255), FontJ);
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 350), "�𑜓x                :", GetColor(255, 255, 255), FontJ);
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 450), "�\���f�B�X�v���C :", GetColor(255, 255, 255), FontJ);
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 550), "FPS�\��             :", GetColor(255, 255, 255), FontJ);
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1200)
				, static_cast<float>(screenHeight / 1080.0 * 245)
				, static_cast<float>(screenWidth / 1920.0 * 1580)
				, static_cast<float>(screenHeight / 1080.0 * 290)
				, GetColor(255, 255, 255), FALSE);
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1580)
				, static_cast<float>(screenHeight / 1080.0 * 245)
				, static_cast<float>(screenWidth / 1920.0 * 1620)
				, static_cast<float>(screenHeight / 1080.0 * 290)
				, GetColor(255, 255, 255), FALSE);
			fontWidth = GetDrawStringWidthToHandle("��", sizeof("��"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1620 - (fontWidth + screenWidth / 1920.0 * 1580)) / 2 + screenWidth / 1920.0 * 1580)
				, static_cast<int>(screenHeight / 1080.0 * 250)
				, "��", GetColor(255, 255, 255), FontJ);
			switch(Ini_p->GetMode()){
			case 0:
				fontWidth = GetDrawStringWidthToHandle("�E�B���h�E", sizeof("�E�B���h�E"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
					, static_cast<int>(screenHeight / 1080.0 * 250)
					, "�E�B���h�E", GetColor(255, 255, 255), FontJ);
				break;

			case 1:
				fontWidth = GetDrawStringWidthToHandle("���z�t���X�N���[��", sizeof("���z�t���X�N���[��"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
					, static_cast<int>(screenHeight / 1080.0 * 250)
					, "���z�t���X�N���[��", GetColor(255, 255, 255), FontJ);
				break;

			case 2:
				fontWidth = GetDrawStringWidthToHandle("�t���X�N���[��", sizeof("�t���X�N���[��"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
					, static_cast<int>(screenHeight / 1080.0 * 250)
					, "�t���X�N���[��", GetColor(255, 255, 255), FontJ);
				break;

			default:
				break;

			}
			// �𑜓x
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1200)
				, static_cast<float>(screenHeight / 1080.0 * 345)
				, static_cast<float>(screenWidth / 1920.0 * 1580)
				, static_cast<float>(screenHeight / 1080.0 * 390)
				, GetColor(255, 255, 255), FALSE);
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1580)
				, static_cast<float>(screenHeight / 1080.0 * 345)
				, static_cast<float>(screenWidth / 1920.0 * 1620)
				, static_cast<float>(screenHeight / 1080.0 * 390)
				, GetColor(255, 255, 255), FALSE);
			fontWidth = GetDrawStringWidthToHandle("��", sizeof("��"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1620 - (fontWidth + screenWidth / 1920.0 * 1580)) / 2 + screenWidth / 1920.0 * 1580)
				, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 350)
				, "��", GetColor(255, 255, 255), FontJ);
			// �\���f�B�X�v���C
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
			fontWidth = GetDrawStringWidthToHandle("��", sizeof("��"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1620 - (fontWidth + screenWidth / 1920.0 * 1580)) / 2 + screenWidth / 1920.0 * 1580)
				, static_cast<int>(screenHeight / 1080.0 * 450)
				, "��", GetColor(255, 255, 255), FontJ);
			// FPS�\��
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1590)
				, static_cast<float>(screenHeight / 1080.0 * 550)
				, static_cast<float>(screenWidth / 1920.0 * 1620)
				, static_cast<float>(screenHeight / 1080.0 * 580)
				, GetColor(255, 255, 255), FALSE);
			TabStop = true;
			switch(Button){
			case 0:
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1330), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1480), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 0), FALSE);
				fontWidth = GetDrawStringWidthToHandle("�ۑ�", sizeof("�ۑ�"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1480 - (fontWidth + screenWidth / 1920.0 * 1330)) / 2 + screenWidth / 1920.0 * 1330), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "�ۑ�", GetColor(255, 255, 0), FontJ);
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1530), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1680), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 255), FALSE);
				fontWidth = GetDrawStringWidthToHandle("��ݾ�", sizeof("��ݾ�"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1680 - (fontWidth + screenWidth / 1920.0 * 1530)) / 2 + screenWidth / 1920.0 * 1530), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "��ݾ�", GetColor(255, 255, 255), FontJ);
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1730), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1880), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 255), FALSE);
				fontWidth = GetDrawStringWidthToHandle("�K�p", sizeof("�K�p"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1880 - (fontWidth + screenWidth / 1920.0 * 1730)) / 2 + screenWidth / 1920.0 * 1730), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "�K�p", GetColor(255, 255, 255), FontJ);
				break;

			case 1:
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1330), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1480), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 255), FALSE);
				fontWidth = GetDrawStringWidthToHandle("�ۑ�", sizeof("�ۑ�"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1480 - (fontWidth + screenWidth / 1920.0 * 1330)) / 2 + screenWidth / 1920.0 * 1330), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "�ۑ�", GetColor(255, 255, 255), FontJ);
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1530), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1680), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 0), FALSE);
				fontWidth = GetDrawStringWidthToHandle("��ݾ�", sizeof("��ݾ�"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1680 - (fontWidth + screenWidth / 1920.0 * 1530)) / 2 + screenWidth / 1920.0 * 1530), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "��ݾ�", GetColor(255, 255, 0), FontJ);
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1730), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1880), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 255), FALSE);
				fontWidth = GetDrawStringWidthToHandle("�K�p", sizeof("�K�p"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1880 - (fontWidth + screenWidth / 1920.0 * 1730)) / 2 + screenWidth / 1920.0 * 1730), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "�K�p", GetColor(255, 255, 255), FontJ);
				break;

			case 2:
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1330), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1480), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 255), FALSE);
				fontWidth = GetDrawStringWidthToHandle("�ۑ�", sizeof("�ۑ�"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1480 - (fontWidth + screenWidth / 1920.0 * 1330)) / 2 + screenWidth / 1920.0 * 1330), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "�ۑ�", GetColor(255, 255, 255), FontJ);
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1530), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1680), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 255), FALSE);
				fontWidth = GetDrawStringWidthToHandle("��ݾ�", sizeof("��ݾ�"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1680 - (fontWidth + screenWidth / 1920.0 * 1530)) / 2 + screenWidth / 1920.0 * 1530), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "��ݾ�", GetColor(255, 255, 255), FontJ);
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1730), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1880), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 0), FALSE);
				fontWidth = GetDrawStringWidthToHandle("�K�p", sizeof("�K�p"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1880 - (fontWidth + screenWidth / 1920.0 * 1730)) / 2 + screenWidth / 1920.0 * 1730), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "�K�p", GetColor(255, 255, 0), FontJ);
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
		// �O���t�B�b�N�֘A�ݒ�
		fontWidth = GetDrawStringWidthToHandle("Display", sizeof("Display"), Font);
		DrawStringToHandle((screenWidth / 4 - fontWidth) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Display", GetColor(255, 255, 255), Font);
		fontWidth = GetDrawStringWidthToHandle("Graphics", sizeof("Graphics"), Font);
		DrawStringToHandle(((screenWidth / 2 - fontWidth) + screenWidth / 4) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Graphics", GetColor(255, 255, 0), Font);
		fontWidth = GetDrawStringWidthToHandle("Sound", sizeof("Sound"), Font);
		DrawStringToHandle(((screenWidth / 2 + screenWidth / 4) - fontWidth + screenWidth / 2) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Sound", GetColor(255, 255, 255), Font);
		fontWidth = GetDrawStringWidthToHandle("Key Config", sizeof("Key Config"), Font);
		DrawStringToHandle((screenWidth - fontWidth + screenWidth * 3 / 4) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Key Config", GetColor(255, 255, 255), Font);
		break;

	case 2:
		// �T�E���h�֘A�ݒ�
		fontWidth = GetDrawStringWidthToHandle("Display", sizeof("Display"), Font);
		DrawStringToHandle((screenWidth / 4 - fontWidth) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Display", GetColor(255, 255, 255), Font);
		fontWidth = GetDrawStringWidthToHandle("Graphics", sizeof("Graphics"), Font);
		DrawStringToHandle(((screenWidth / 2 - fontWidth) + screenWidth / 4) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Graphics", GetColor(255, 255, 255), Font);
		fontWidth = GetDrawStringWidthToHandle("Sound", sizeof("Sound"), Font);
		DrawStringToHandle(((screenWidth / 2 + screenWidth / 4) - fontWidth + screenWidth / 2) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Sound", GetColor(255, 255, 0), Font);
		fontWidth = GetDrawStringWidthToHandle("Key Config", sizeof("Key Config"), Font);
		DrawStringToHandle((screenWidth - fontWidth + screenWidth * 3 / 4) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Key Config", GetColor(255, 255, 255), Font);
		break;

	case 3:
		// �L�[�R���t�B�O�֘A�ݒ�
		fontWidth = GetDrawStringWidthToHandle("Display", sizeof("Display"), Font);
		DrawStringToHandle((screenWidth / 4 - fontWidth) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Display", GetColor(255, 255, 255), Font);
		fontWidth = GetDrawStringWidthToHandle("Graphics", sizeof("Graphics"), Font);
		DrawStringToHandle(((screenWidth / 2 - fontWidth) + screenWidth / 4) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Graphics", GetColor(255, 255, 255), Font);
		fontWidth = GetDrawStringWidthToHandle("Sound", sizeof("Sound"), Font);
		DrawStringToHandle(((screenWidth / 2 + screenWidth / 4) - fontWidth + screenWidth / 2) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Sound", GetColor(255, 255, 255), Font);
		fontWidth = GetDrawStringWidthToHandle("Key Config", sizeof("Key Config"), Font);
		DrawStringToHandle((screenWidth - fontWidth + screenWidth * 3 / 4) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Key Config", GetColor(255, 255, 0), Font);
		break;

	default:
		break;
	}
}

// �ݒ�K�p
void Config::ApplySetting(){
	int dispWidth;
	int dispHeight;
	int colorBit;

	GetDefaultState(&dispWidth, &dispHeight, &colorBit);
	// �E�B���h�E���[�h�ݒ�
	switch(Ini_p->GetMode()){
	case 0:
		// �E�B���h�E���[�h�ɐݒ�
		if(GetWindowModeFlag() == TRUE){
			ChangeWindowMode(TRUE);
		}
		SetWindowStyleMode(0);
		// �E�B���h�E�ݒ�
		SetGraphMode(Ini_p->GetWidth(), Ini_p->GetHeight(), colorBit);
		SetWindowPosition((dispWidth - Ini_p->GetWidth()) / 2, (dispHeight - Ini_p->GetHeight()) / 2);
		break;

	case 1:
		// ���z�t���X�N���[���ɐݒ�
		if(GetWindowModeFlag() == TRUE){
			ChangeWindowMode(TRUE);
		}
		SetWindowStyleMode(2);
		SetGraphMode(dispWidth, dispHeight, colorBit);
		SetWindowPosition(0, 0);
		break;

	case 2:
		ChangeWindowMode(FALSE);
		// �t���X�N���[���ɐݒ�
		break;

	default:
		break;

	}
	// �}�E�X�J�[�\�����\����
	SetMouseDispFlag(FALSE);
}
// End Of File