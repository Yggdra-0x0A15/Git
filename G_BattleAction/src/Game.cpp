#include <math.h>
#include "Game.h"

Game::Game(ISceneChanger* changer) : Scene(changer){
	Player_p = new Character;
	Enemy_p = new Character;
	// 3D���f���̓ǂݍ���
	Player_p->Model = MV1LoadModel("dat/model/Lat���~�N/Lat���~�NVer2.3_Normal.pmd");
	Enemy_p->Model = MV1LoadModel("dat/model/Lat���~�N/Lat���~�NVer2.3_White�G�b�W������p.pmd");
	Field = MV1LoadModel("dat/stage/�X�e�[�W_�`�F�b�N�Q��������ST32/Stage_ST32/ST32.pmx");
	// ���s0.1�`10000�܂ł��J�����̕`��͈͂Ƃ���
	SetCameraNearFar(0.1f, 10000.0f);
	// �R�c���f���̍��W��������
	PlayerPos = VGet(0.0f, 0.0f, -30.0f);
	EnemyPos = VGet(0.0f, 0.0f, 30.0f);
	RelativePos = VGet(PlayerPos.x + 10.0f, 25.0f, PlayerPos.z - 1.0f);
	// �R�c���f����1�Ԗڂ̃A�j���[�V�������A�^�b�`����
	AttachIndex = MV1AttachAnim(Player_p->Model, 1, -1, FALSE);
	// �A�^�b�`�����A�j���[�V�����̑��Đ����Ԃ��擾����
	TotalTime = MV1GetAttachAnimTotalTime(Player_p->Model, AttachIndex);
	// �Đ����Ԃ̏�����
	PlayTime = 0.0f;
}

// ������
void Game::Initialize(){
}

// �X�V
void Game::Update(){
	// Esc�L�[��������Ă�����
	if(CheckHitKey(KEY_INPUT_ESCAPE) != 0){
		// �V�[�������j���[�ɕύX
		SceneChanger_p->ChangeScene(SceneMenu);
	}
}

//�`��
void Game::Draw(){
	// �e�N���X�̕`�惁�\�b�h���Ă�
	Scene::Draw();
	// �R�c���f���Q����R�c���f���P�Ɍ������x�N�g�����Z�o
	SubVector = VSub(EnemyPos, PlayerPos);
	// atan2 ���g�p���Ċp�x���擾
	PlayerAngle = atan2f(SubVector.x, SubVector.z);
	// atan2 �Ŏ擾�����p�x�ɂR�c���f���𐳖ʂɌ������邽�߂̕␳�l( DX_PI_F )�𑫂����l���R�c���f���� Y����]�l�Ƃ��Đݒ�
	MV1SetRotationXYZ(Player_p->Model, VGet(0.0f, PlayerAngle + DX_PI_F, 0.0f));

	// �R�c���f���P����R�c���f���Q�Ɍ������x�N�g�����Z�o
	SubVector = VSub(PlayerPos, EnemyPos);
	// atan2 ���g�p���Ċp�x���擾
	EnemyAngle = atan2f(SubVector.x, SubVector.z);
	// atan2 �Ŏ擾�����p�x�ɂR�c���f���𐳖ʂɌ������邽�߂̕␳�l( DX_PI_F )�𑫂����l���R�c���f���� Y����]�l�Ƃ��Đݒ�
	MV1SetRotationXYZ(Enemy_p->Model, VGet(0.0f, EnemyAngle + DX_PI_F, 0.0f));

	// ��]�s��̍쐬
	CreateRotationYMatrix(&CycleLine, MV1GetRotationXYZ(Enemy_p->Model).y);
	// ���΍��W�̉�]
	RotPos = VTransformSR(RelativePos, CycleLine);
	// �J�������W�̐ݒ�
	CamPos = VGet(PlayerPos.x + RotPos.x, 25.0f, PlayerPos.z + RotPos.z);
	CamTgt = EnemyPos;
	SetCameraPositionAndTarget_UpVecY(CamPos, CamTgt);

	// �w��ʒu�Ƀ��f����z�u
	MV1SetPosition(Player_p->Model, PlayerPos);
	MV1SetPosition(Enemy_p->Model, EnemyPos);

	if(CheckHitKey(KEY_INPUT_LEFT) > 0){
		// �G�����ɍ���]
		PlayerPos.x += cosf(-((MV1GetRotationXYZ(Player_p->Model).y))) * 1.0f;
		PlayerPos.z += sinf(-((MV1GetRotationXYZ(Player_p->Model).y))) * 1.0f;
	}
	if(CheckHitKey(KEY_INPUT_RIGHT) > 0){
		// �G�����ɉE��]
		PlayerPos.x += cosf(-(MV1GetRotationXYZ(Player_p->Model).y)) * -1.0f;
		PlayerPos.z += sinf(-(MV1GetRotationXYZ(Player_p->Model).y)) * -1.0f;
	}
	if(CheckHitKey(KEY_INPUT_UP)){
		// �O�i
		if(((VSub(EnemyPos, PlayerPos).x > 10.0f) || (VSub(EnemyPos, PlayerPos).x < -10.0f))
			|| ((VSub(EnemyPos, PlayerPos).z > 10.0f) || (VSub(EnemyPos, PlayerPos).z < -10.0f))){
			PlayerPos.x += sinf(MV1GetRotationXYZ(Player_p->Model).y) * -1.0f;
			PlayerPos.z += cosf(MV1GetRotationXYZ(Player_p->Model).y) * -1.0f;
		}
	}
	if(CheckHitKey(KEY_INPUT_DOWN)){
		// ���
		PlayerPos.x += sinf(MV1GetRotationXYZ(Player_p->Model).y) * 1.0f;
		PlayerPos.z += cosf(MV1GetRotationXYZ(Player_p->Model).y) * 1.0f;
	}
	// �Đ����Ԃ�i�߂�
	PlayTime += 1.0f;
	// �Đ����Ԃ��A�j���[�V�����̑��Đ����ԂɒB������Đ����Ԃ��O�ɖ߂�
	if(PlayTime >= TotalTime) {
		PlayTime = 0.0f;
	}
	// �Đ����Ԃ��Z�b�g����
	MV1SetAttachAnimTime(Player_p->Model, AttachIndex, PlayTime);
	// �R�c���f���̕`��
	MV1DrawModel(Player_p->Model);
	MV1DrawModel(Enemy_p->Model);
	MV1DrawModel(Field);
}
// End Of File