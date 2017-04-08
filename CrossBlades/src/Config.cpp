#include "Config.h"
#include "DxLib.h"

bool Config::Apply = false;

Config::Config(ISceneChanger* changer) : Scene(changer) {
	// ini�C���X�^���X�擾
	Ini_p = Ini::GetInstance();
	// �摜�̃��[�h
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
	switch(Ini_p->GetWidth()){
	case 800:
		IndexResolution = 0;
		break;

	case 1280:
		IndexResolution = 1;
		break;

	case 1600:
		IndexResolution = 2;
		break;

	case 1920:
		IndexResolution = 3;
		break;

	case 2880:
		IndexResolution = 4;
		break;

	case 3840:
		IndexResolution = 5;
		break;

	default:
		break;

	}
	IndexDisplay = Ini_p->GetDisplay();
	// �ύX�O�E�B���h�E���[�h
	PreMode = Ini_p->GetMode();
	// �ύX�O�E�B���h�E��
	PreWidth = Ini_p->GetWidth();
	// �ύX�O�E�B���h�E��
	PreHeight = Ini_p->GetHeight();
	// �ύX�O�\���f�B�X�v���C
	PreDisplay = Ini_p->GetDisplay();
	// �ύX�OFPS�\��
	PreFps = Ini_p->GetFps();
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
					switch(IndexResolution){
					case 0:
						Ini_p->SetWidth(800);
						Ini_p->SetHeight(450);
						break;

					case 1:
						Ini_p->SetWidth(1280);
						Ini_p->SetHeight(720);
						break;

					case 2:
						Ini_p->SetWidth(1600);
						Ini_p->SetHeight(900);
						break;

					case 3:
						Ini_p->SetWidth(1920);
						Ini_p->SetHeight(1080);
						break;

					case 4:
						Ini_p->SetWidth(2880);
						Ini_p->SetHeight(1620);
						break;

					case 5:
						Ini_p->SetWidth(3840);
						Ini_p->SetHeight(2160);
						break;

					default:
						break;

					}
					Setting = false;
					break;

				case 2:
					// �\���f�B�X�v���C
					Ini_p->SetDisplay(IndexDisplay);
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
						// �L�����Z��
						Cancel();
						ApplySetting();
						SceneChanger_p->ChangeScene(SceneMenu);
						break;

					case 2:
						// �K�p
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
					if(IndexResolution == 0){
						IndexResolution = Ini_p->GetNumResolution() - 1;
					}
					else{
						IndexResolution--;
					}
					break;

				case 2:
					// �\���f�B�X�v���C
					if(IndexDisplay == 0){
						IndexDisplay = Ini_p->GetNumDisplay() - 1;
					}
					else{
						IndexDisplay--;
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
			// �J�[�\���ړ�
			switch(Tab){
			case 0:
				// �f�B�X�v���C�ݒ�
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
				if(Cursor == 4){
					TabStop = true;
				}
				else{
					TabStop = false;
				}
				break;

			case 1:
				break;

			case 2:
				break;

			case 3:
				break;

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
					if(IndexResolution == Ini_p->GetNumResolution() - 1){
						IndexResolution = 0;
					}
					else{
						IndexResolution++;
					}
					break;

				case 2:
					// �\���f�B�X�v���C
					if(IndexDisplay == Ini_p->GetNumDisplay() - 1){
						IndexDisplay = 0;
					}
					else{
						IndexDisplay++;
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
			// �J�[�\���ړ�
			switch(Tab){
			case 0:
				// �f�B�X�v���C�ݒ�
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
				if(Cursor == 4){
					TabStop = true;
				}
				else{
					TabStop = false;
				}
				break;

			case 1:
				break;

			case 2:
				break;

			case 3:
				break;

			default:
				break;

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

// �`��
void Config::Draw(){
	int fontWidth;
	int screenWidth;
	int screenHeight;

	// �e�N���X�̕`�惁�\�b�h���Ă�
	Scene::Draw();
	GetWindowSize(&screenWidth, &screenHeight);
	DrawBase(screenWidth, screenHeight);
	switch(Tab){
	case 0:
		// �f�B�X�v���C�֘A�ݒ�
		fontWidth = GetDrawStringWidthToHandle("Display", sizeof("Display"), Font);
		DrawStringToHandle((screenWidth / 4 - fontWidth) / 2, static_cast<int>(screenHeight / 1080.0 * 120), "Display", GetColor(255, 255, 0), Font);
		switch(Cursor){
		case 0:
			// �E�B���h�E���[�h
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 250), "�E�B���h�E���[�h :", GetColor(255, 255, 0), FontJ);
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
			}
			break;

		case 1:
			// �𑜓x
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 350), "�𑜓x                :", GetColor(255, 255, 0), FontJ);
			if(Setting == true){
				unsigned short num = 0;
				int dispWidth = 0;
				GetDefaultState(&dispWidth, NULL, NULL);
				if(dispWidth >= 800){
					if(IndexResolution == num){
						fontWidth = GetDrawStringWidthToHandle("800 �~ 450", sizeof("800 �~ 450"), FontJ);
						DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
							, static_cast<int>(screenHeight / 1080.0 * (350 + num * 50))
							, "800 �~ 450", GetColor(255, 255, 0), FontJ);
					}
					else{
						fontWidth = GetDrawStringWidthToHandle("800 �~ 450", sizeof("800 �~ 450"), FontJ);
						DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
							, static_cast<int>(screenHeight / 1080.0 * (350 + num * 50))
							, "800 �~ 450", GetColor(255, 255, 255), FontJ);
					}
					num++;
					if(dispWidth >= 1280){
						if(IndexResolution == num){
							fontWidth = GetDrawStringWidthToHandle("1280 �~ 720", sizeof("1280 �~ 720"), FontJ);
							DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
								, static_cast<int>(screenHeight / 1080.0 * (350 + num * 50))
								, "1280 �~ 720", GetColor(255, 255, 0), FontJ);
						}
						else{
							fontWidth = GetDrawStringWidthToHandle("1280 �~ 720", sizeof("1280 �~ 720"), FontJ);
							DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
								, static_cast<int>(screenHeight / 1080.0 * (350 + num * 50))
								, "1280 �~ 720", GetColor(255, 255, 255), FontJ);
						}
						num++;
						if(dispWidth >= 1600){
							if(IndexResolution == num){
								fontWidth = GetDrawStringWidthToHandle("1600 �~ 900", sizeof("1600 �~ 900"), FontJ);
								DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
									, static_cast<int>(screenHeight / 1080.0 * (350 + num * 50))
									, "1600 �~ 900", GetColor(255, 255, 0), FontJ);
							}
							else{
								fontWidth = GetDrawStringWidthToHandle("1600 �~ 900", sizeof("1600 �~ 900"), FontJ);
								DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
									, static_cast<int>(screenHeight / 1080.0 * (350 + num * 50))
									, "1600 �~ 900", GetColor(255, 255, 255), FontJ);
							}
							num++;
							if(dispWidth >= 1920){
								if(IndexResolution == num){
									fontWidth = GetDrawStringWidthToHandle("1920 �~ 1080", sizeof("1920 �~ 1080"), FontJ);
									DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
										, static_cast<int>(screenHeight / 1080.0 * (350 + num * 50))
										, "1920 �~ 1080", GetColor(255, 255, 0), FontJ);
								}
								else{
									fontWidth = GetDrawStringWidthToHandle("1920 �~ 1080", sizeof("1920 �~ 1080"), FontJ);
									DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
										, static_cast<int>(screenHeight / 1080.0 * (350 + num * 50))
										, "1920 �~ 1080", GetColor(255, 255, 255), FontJ);
								}
								num++;
								if(dispWidth >= 2880){
									if(IndexResolution == num){
										fontWidth = GetDrawStringWidthToHandle("2880 �~ 1620", sizeof("2880 �~ 1620"), FontJ);
										DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
											, static_cast<int>(screenHeight / 1080.0 * (350 + num * 50))
											, "2880 �~ 1620", GetColor(255, 255, 0), FontJ);
									}
									else{
										fontWidth = GetDrawStringWidthToHandle("2880 �~ 1620", sizeof("2880 �~ 1620"), FontJ);
										DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
											, static_cast<int>(screenHeight / 1080.0 * (350 + num * 50))
											, "2880 �~ 1620", GetColor(255, 255, 255), FontJ);
									}
									num++;
									if(dispWidth >= 3840){
										if(IndexResolution == num){
											fontWidth = GetDrawStringWidthToHandle("3840 �~ 2160", sizeof("3840 �~ 2160"), FontJ);
											DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
												, static_cast<int>(screenHeight / 1080.0 * (350 + num * 50))
												, "2880 �~ 1620", GetColor(255, 255, 0), FontJ);
										}
										else{
											fontWidth = GetDrawStringWidthToHandle("3840 �~ 2160", sizeof("3840 �~ 2160"), FontJ);
											DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
												, static_cast<int>(screenHeight / 1080.0 * (350 + num * 50))
												, "3840 �~ 2160", GetColor(255, 255, 255), FontJ);
										}
										num++;
									}
								}
							}
						}
					}
				}
				// �R���{�{�b�N�X�g��
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1200)
					, static_cast<float>(screenHeight / 1080.0 * 345)
					, static_cast<float>(screenWidth / 1920.0 * 1580)
					, static_cast<float>(screenHeight / 1080.0 * (345 + num * 50 - 5))
					, GetColor(255, 255, 255), FALSE);
				Ini_p->SetNumResolution(num);
			}
			else{
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
				fontWidth = GetDrawStringWidthToHandle("��", sizeof("��"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1620 - (fontWidth + screenWidth / 1920.0 * 1580)) / 2 + screenWidth / 1920.0 * 1580)
								, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 350)
								, "��", GetColor(255, 255, 0), FontJ);
			}
			break;

		case 2:
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 450), "�\���f�B�X�v���C :", GetColor(255, 255, 0), FontJ);
			if(Setting == true){
				DISPLAY_DEVICE dd;
				// �R���{�{�b�N�X�g��
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1200)
					, static_cast<float>(screenHeight / 1080.0 * 445)
					, static_cast<float>(screenWidth / 1920.0 * 1580)
					, static_cast<float>(screenHeight / 1080.0 * (445 + Ini_p->GetNumDisplay() * 50 - 5))
					, GetColor(255, 255, 255), FALSE);
				for(unsigned short i = 0; i < Ini_p->GetNumDisplay(); i++){
					memset(&dd, 0x00, sizeof(dd));
					dd.cb = sizeof(dd);
					dd.StateFlags = DISPLAY_DEVICE_ATTACHED;
					EnumDisplayDevices(NULL, i, &dd, false);
					if(i == IndexDisplay){
						fontWidth = GetDrawStringWidthToHandle(dd.DeviceName, sizeof(dd.DeviceName), FontJ);
						DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
							, static_cast<int>(screenHeight / 1080.0 * (450 + i * 50))
							, dd.DeviceName, GetColor(255, 255, 0), FontJ);
					}
					else{
						fontWidth = GetDrawStringWidthToHandle(dd.DeviceName, sizeof(dd.DeviceName), FontJ);
						DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
							, static_cast<int>(screenHeight / 1080.0 * (450 + i * 50))
							, dd.DeviceName, GetColor(255, 255, 255), FontJ);
					}
				}

			}
			else{
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
				fontWidth = GetDrawStringWidthToHandle("��", sizeof("��"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1620 - (fontWidth + screenWidth / 1920.0 * 1580)) / 2 + screenWidth / 1920.0 * 1580)
					, static_cast<int>(screenHeight / 1080.0 * 450)
					, "��", GetColor(255, 255, 0), FontJ);

			}
			break;

		case 3:
			// FPS�\��
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 550), "FPS�\��             :", GetColor(255, 255, 0), FontJ);
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
			break;

		case 4:
			switch(Button){
			case 0:
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1330), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1480), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 0), FALSE);
				fontWidth = GetDrawStringWidthToHandle("�ۑ�", sizeof("�ۑ�"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1480 - (fontWidth + screenWidth / 1920.0 * 1330)) / 2 + screenWidth / 1920.0 * 1330), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "�ۑ�", GetColor(255, 255, 0), FontJ);
				break;

			case 1:
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1530), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1680), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 0), FALSE);
				fontWidth = GetDrawStringWidthToHandle("��ݾ�", sizeof("��ݾ�"), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1680 - (fontWidth + screenWidth / 1920.0 * 1530)) / 2 + screenWidth / 1920.0 * 1530), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "��ݾ�", GetColor(255, 255, 0), FontJ);
				break;

			case 2:
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
		fontWidth = GetDrawStringWidthToHandle("Graphics", sizeof("Graphics"), Font);
		DrawStringToHandle(((screenWidth / 2 - fontWidth) + screenWidth / 4) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Graphics", GetColor(255, 255, 0), Font);
		break;

	case 2:
		// �T�E���h�֘A�ݒ�
		fontWidth = GetDrawStringWidthToHandle("Sound", sizeof("Sound"), Font);
		DrawStringToHandle(((screenWidth / 2 + screenWidth / 4) - fontWidth + screenWidth / 2) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Sound", GetColor(255, 255, 0), Font);
		break;

	case 3:
		// �L�[�R���t�B�O�֘A�ݒ�
		fontWidth = GetDrawStringWidthToHandle("Key Config", sizeof("Key Config"), Font);
		DrawStringToHandle((screenWidth - fontWidth + screenWidth * 3 / 4) / 2, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 120), "Key Config", GetColor(255, 255, 0), Font);
		break;

	default:
		break;
	}
}

// ��{��ʕ`��
void Config::DrawBase(int screenWidth, int screenHeight){
	int fontWidth;
	DISPLAY_DEVICE dd;

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
		// �f�B�X�v���C
		// �E�B���h�E���[�h
		DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 250), "�E�B���h�E���[�h :", GetColor(255, 255, 255), FontJ);
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
		fontWidth = GetDrawStringWidthToHandle("��", sizeof("��"), FontJ);
		DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1620 - (fontWidth + screenWidth / 1920.0 * 1580)) / 2 + screenWidth / 1920.0 * 1580)
			, static_cast<int>(screenHeight / 1080.0 * 250)
			, "��", GetColor(255, 255, 255), FontJ);

		if(Setting == false || Cursor != 0){
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
		}
		// �𑜓x
		if(Ini_p->GetMode() != 1){
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 350), "�𑜓x                :", GetColor(255, 255, 255), FontJ);
			if((Setting == false || Cursor != 0) && (Setting == false || Cursor != 1)){
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1200)
					, static_cast<float>(screenHeight / 1080.0 * 345)
					, static_cast<float>(screenWidth / 1920.0 * 1580)
					, static_cast<float>(screenHeight / 1080.0 * 390)
					, GetColor(255, 255, 255), FALSE);
				switch(IndexResolution){
				case 0:
					fontWidth = GetDrawStringWidthToHandle("800 �~ 450", sizeof("800 �~ 450"), FontJ);
					DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
						, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 350)
						, "800 �~ 450", GetColor(255, 255, 255), FontJ);
					break;

				case 1:
					fontWidth = GetDrawStringWidthToHandle("1280 �~ 720", sizeof("1280 �~ 720"), FontJ);
					DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
						, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 350)
						, "1280 �~ 720", GetColor(255, 255, 255), FontJ);
					break;

				case 2:
					fontWidth = GetDrawStringWidthToHandle("1600 �~ 900", sizeof("1600 �~ 900"), FontJ);
					DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
						, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 350)
						, "1600 �~ 900", GetColor(255, 255, 255), FontJ);
					break;

				case 3:
					fontWidth = GetDrawStringWidthToHandle("1920 �~ 1080", sizeof("1920 �~ 1080"), FontJ);
					DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
						, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 350)
						, "1920 �~ 1080", GetColor(255, 255, 255), FontJ);
					break;

				case 4:
					fontWidth = GetDrawStringWidthToHandle("2880 �~ 1620", sizeof("2880 �~ 1620"), FontJ);
					DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
						, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 350)
						, "2880 �~ 1620", GetColor(255, 255, 255), FontJ);
					break;

				case 5:
					fontWidth = GetDrawStringWidthToHandle("3840 �~ 2160", sizeof("3840 �~ 2160"), FontJ);
					DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
						, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 350)
						, "3840 �~ 2160", GetColor(255, 255, 255), FontJ);
					break;

				default:
					break;

				}
			}
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1580)
				, static_cast<float>(screenHeight / 1080.0 * 345)
				, static_cast<float>(screenWidth / 1920.0 * 1620)
				, static_cast<float>(screenHeight / 1080.0 * 390)
				, GetColor(255, 255, 255), FALSE);
			fontWidth = GetDrawStringWidthToHandle("��", sizeof("��"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1620 - (fontWidth + screenWidth / 1920.0 * 1580)) / 2 + screenWidth / 1920.0 * 1580)
				, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 350)
				, "��", GetColor(255, 255, 255), FontJ);
		}
		else{
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 350), "�𑜓x                :", GetColor(64, 64, 64), FontJ);
			if(Setting == false || Cursor != 0){
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1200)
					, static_cast<float>(screenHeight / 1080.0 * 345)
					, static_cast<float>(screenWidth / 1920.0 * 1580)
					, static_cast<float>(screenHeight / 1080.0 * 390)
					, GetColor(64, 64, 64), FALSE);
				switch(IndexResolution){
				case 0:
					fontWidth = GetDrawStringWidthToHandle("800 �~ 450", sizeof("800 �~ 450"), FontJ);
					DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
						, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 350)
						, "800 �~ 450", GetColor(64, 64, 64), FontJ);
					break;

				case 1:
					fontWidth = GetDrawStringWidthToHandle("1280 �~ 720", sizeof("1280 �~ 720"), FontJ);
					DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
						, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 350)
						, "1280 �~ 720", GetColor(64, 64, 64), FontJ);
					break;

				case 2:
					fontWidth = GetDrawStringWidthToHandle("1600 �~ 900", sizeof("1600 �~ 900"), FontJ);
					DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
						, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 350)
						, "1600 �~ 900", GetColor(64, 64, 64), FontJ);
					break;

				case 3:
					fontWidth = GetDrawStringWidthToHandle("1920 �~ 1080", sizeof("1920 �~ 1080"), FontJ);
					DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
						, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 350)
						, "1920 �~ 1080", GetColor(64, 64, 64), FontJ);
					break;

				case 4:
					fontWidth = GetDrawStringWidthToHandle("2880 �~ 1620", sizeof("2880 �~ 1620"), FontJ);
					DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
						, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 350)
						, "2880 �~ 1620", GetColor(64, 64, 64), FontJ);
					break;

				case 5:
					fontWidth = GetDrawStringWidthToHandle("3840 �~ 2160", sizeof("3840 �~ 2160"), FontJ);
					DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
						, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 350)
						, "3840 �~ 2160", GetColor(64, 64, 64), FontJ);
					break;

				default:
					break;

				}
			}
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1580)
				, static_cast<float>(screenHeight / 1080.0 * 345)
				, static_cast<float>(screenWidth / 1920.0 * 1620)
				, static_cast<float>(screenHeight / 1080.0 * 390)
				, GetColor(64, 64, 64), FALSE);
			fontWidth = GetDrawStringWidthToHandle("��", sizeof("��"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1620 - (fontWidth + screenWidth / 1920.0 * 1580)) / 2 + screenWidth / 1920.0 * 1580)
				, static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 350)
				, "��", GetColor(64, 64, 64), FontJ);
		}
		// �\���f�B�X�v���C
		memset(&dd, 0x00, sizeof(dd));
		dd.cb = sizeof(dd);
		dd.StateFlags = DISPLAY_DEVICE_ACTIVE;
		EnumDisplayDevices(NULL, Ini_p->GetDisplay(), &dd, false);
		if(Ini_p->GetMode() == 2){
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 450), "�\���f�B�X�v���C :", GetColor(255, 255, 255), FontJ);
			if((Setting == false || Cursor != 2) && (Setting == false || Cursor != 1)){
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1200)
					, static_cast<float>(screenHeight / 1080.0 * 445)
					, static_cast<float>(screenWidth / 1920.0 * 1580)
					, static_cast<float>(screenHeight / 1080.0 * 490)
					, GetColor(255, 255, 255), FALSE);
				fontWidth = GetDrawStringWidthToHandle(dd.DeviceName, sizeof(dd.DeviceName), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
					, static_cast<int>(screenHeight / 1080.0 * 450)
					, dd.DeviceName, GetColor(255, 255, 255), FontJ);
			}
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1580)
				, static_cast<float>(screenHeight / 1080.0 * 445)
				, static_cast<float>(screenWidth / 1920.0 * 1620)
				, static_cast<float>(screenHeight / 1080.0 * 490)
				, GetColor(255, 255, 255), FALSE);
			fontWidth = GetDrawStringWidthToHandle("��", sizeof("��"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1620 - (fontWidth + screenWidth / 1920.0 * 1580)) / 2 + screenWidth / 1920.0 * 1580)
				, static_cast<int>(screenHeight / 1080.0 * 450)
				, "��", GetColor(255, 255, 255), FontJ);
		}
		else{
			DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 450), "�\���f�B�X�v���C :", GetColor(64, 64, 64), FontJ);
			if(Setting == false || Cursor != 1){
				DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1200)
					, static_cast<float>(screenHeight / 1080.0 * 445)
					, static_cast<float>(screenWidth / 1920.0 * 1580)
					, static_cast<float>(screenHeight / 1080.0 * 490)
					, GetColor(64, 64, 64), FALSE);
				fontWidth = GetDrawStringWidthToHandle(dd.DeviceName, sizeof(dd.DeviceName), FontJ);
				DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1580 - (fontWidth + screenWidth / 1920.0 * 1200)) / 2 + screenWidth / 1920.0 * 1200)
					, static_cast<int>(screenHeight / 1080.0 * 450)
					, dd.DeviceName, GetColor(64, 64, 64), FontJ);
			}
			DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1580)
				, static_cast<float>(screenHeight / 1080.0 * 445)
				, static_cast<float>(screenWidth / 1920.0 * 1620)
				, static_cast<float>(screenHeight / 1080.0 * 490)
				, GetColor(64, 64, 64), FALSE);
			fontWidth = GetDrawStringWidthToHandle("��", sizeof("��"), FontJ);
			DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1620 - (fontWidth + screenWidth / 1920.0 * 1580)) / 2 + screenWidth / 1920.0 * 1580)
				, static_cast<int>(screenHeight / 1080.0 * 450)
				, "��", GetColor(64, 64, 64), FontJ);
		}
		// FPS�\��
		DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 550), "FPS�\��             :", GetColor(255, 255, 255), FontJ);
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
		// �O���t�B�b�N
		break;

	case 2:
		// �T�E���h
		break;

	case 3:
		// �L�[�R���t�B�O
		DrawStringToHandle(static_cast<int>(screenWidth / 1920.0 * 300), static_cast<int>(screenHeight / 1080.0 * 250), "�g�p�f�o�C�X :", GetColor(255, 255, 255), FontJ);
		break;

	default:
		break;
	}
	if(GetChange() == true || Apply == true){
		DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1330), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1480), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 255), FALSE);
		fontWidth = GetDrawStringWidthToHandle("�ۑ�", sizeof("�ۑ�"), FontJ);
		DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1480 - (fontWidth + screenWidth / 1920.0 * 1330)) / 2 + screenWidth / 1920.0 * 1330), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "�ۑ�", GetColor(255, 255, 255), FontJ);
	}
	else{
		DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1330), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1480), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(64, 64, 64), FALSE);
		fontWidth = GetDrawStringWidthToHandle("�ۑ�", sizeof("�ۑ�"), FontJ);
		DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1480 - (fontWidth + screenWidth / 1920.0 * 1330)) / 2 + screenWidth / 1920.0 * 1330), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "�ۑ�", GetColor(64, 64, 64), FontJ);
	}
	DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1530), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1680), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 255), FALSE);
	fontWidth = GetDrawStringWidthToHandle("��ݾ�", sizeof("��ݾ�"), FontJ);
	DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1680 - (fontWidth + screenWidth / 1920.0 * 1530)) / 2 + screenWidth / 1920.0 * 1530), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "��ݾ�", GetColor(255, 255, 255), FontJ);
	if(GetChange() == true){
		DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1730), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1880), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(255, 255, 255), FALSE);
		fontWidth = GetDrawStringWidthToHandle("�K�p", sizeof("�K�p"), FontJ);
		DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1880 - (fontWidth + screenWidth / 1920.0 * 1730)) / 2 + screenWidth / 1920.0 * 1730), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "�K�p", GetColor(255, 255, 255), FontJ);
	}
	else{
		DrawBoxAA(static_cast<float>(screenWidth / 1920.0 * 1730), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 980), static_cast<float>(screenWidth / 1920.0 * 1880), static_cast<float>(static_cast<double>(screenHeight) / 1080.0 * 1050), GetColor(64, 64, 64), FALSE);
		fontWidth = GetDrawStringWidthToHandle("�K�p", sizeof("�K�p"), FontJ);
		DrawStringToHandle(static_cast<int>((screenWidth / 1920.0 * 1880 - (fontWidth + screenWidth / 1920.0 * 1730)) / 2 + screenWidth / 1920.0 * 1730), static_cast<int>(static_cast<double>(screenHeight) / 1080.0 * 999), "�K�p", GetColor(64, 64, 64), FontJ);
	}
}

// �ݒ�K�p
void Config::ApplySetting(){
	int dispWidth;
	int dispHeight;

	if(GetChangeWindow() == true){
		dispWidth = GetSystemMetrics(SM_CXSCREEN);
		dispHeight = GetSystemMetrics(SM_CYSCREEN);
		// �E�B���h�E���[�h�ݒ�
		switch(Ini_p->GetMode()){
		case 0:
			// �E�B���h�E���[�h�ɐݒ�
			SetWindowVisibleFlag(FALSE);
			if(GetWindowModeFlag() == FALSE){
				ChangeWindowMode(TRUE);
			}
			SetWindowStyleMode(0);
			// �E�B���h�E�ݒ�
			SetGraphMode(Ini_p->GetWidth(), Ini_p->GetHeight(), 32);
			SetWindowPosition((dispWidth - Ini_p->GetWidth()) / 2, (dispHeight - Ini_p->GetHeight()) / 2);
			SetWindowVisibleFlag(TRUE);
			break;

		case 1:
			// ���z�t���X�N���[���ɐݒ�
			SetWindowVisibleFlag(FALSE);
			if(GetWindowModeFlag() == FALSE){
				ChangeWindowMode(TRUE);
			}
			SetWindowStyleMode(2);
			SetGraphMode(dispWidth, dispHeight, 32);
			SetWindowPosition(0, 0);
			SetWindowVisibleFlag(TRUE);
			break;

		case 2:
			// �t���X�N���[���ɐݒ�
			SetWindowVisibleFlag(FALSE);
			SetGraphMode(Ini_p->GetWidth(), Ini_p->GetHeight(), 32);
			SetUseDirectDrawDeviceIndex(Ini_p->GetDisplay());
			if(GetWindowModeFlag() == TRUE){
				ChangeWindowMode(FALSE);
			}
			SetWindowVisibleFlag(TRUE);
			break;

		default:
			break;

		}
	}
}

// �L�����Z��
void Config::Cancel(){
	Ini_p->SetMode(PreMode);
	Ini_p->SetWidth(PreWidth);
	Ini_p->SetHeight(PreHeight);
	Ini_p->SetDisplay(PreDisplay);
	Ini_p->SetFps(PreFps);
}

// �ύX�擾
bool Config::GetChange(){
	bool retVal = false;

	// �ύX�O�E�B���h�E���[�h
	if(PreMode != Ini_p->GetMode()){
		retVal = true;
	}
	// �ύX�O�E�B���h�E��
	if(PreWidth != Ini_p->GetWidth()){
		retVal = true;
	}
	// �ύX�O�E�B���h�E��
	if(PreHeight != Ini_p->GetHeight()){
		retVal = true;
	}
	// �ύX�O�\���f�B�X�v���C
	if(PreDisplay != Ini_p->GetDisplay()){
		retVal = true;
	}
	// �ύX�OFPS�\��
	if(PreFps != Ini_p->GetFps()){
		retVal = true;
	}

	return retVal;
}

// �E�B���h�E�ύX�擾
bool Config::GetChangeWindow(){
	bool retVal = false;

	// �ύX�O�E�B���h�E���[�h
	if(PreMode != Ini_p->GetMode()){
		retVal = true;
	}
	// �ύX�O�E�B���h�E��
	if(PreWidth != Ini_p->GetWidth()){
		retVal = true;
	}
	// �ύX�O�E�B���h�E��
	if(PreHeight != Ini_p->GetHeight()){
		retVal = true;
	}
	// �ύX�O�\���f�B�X�v���C
	if(PreDisplay != Ini_p->GetDisplay()){
		retVal = true;
	}

	return retVal;
}
// End Of File