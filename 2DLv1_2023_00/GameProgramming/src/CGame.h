#pragma once
//��`�̒萔
#define TEXTURE "image.png" //�e�N�X�`���̃t�@�C����
#define TIPSIZE 20.0f //�}�b�v�v�f�̃T�C�Y
#include "CUi.h"
/*
* CGame�N���X
* �Q�[���̃N���X
* �Q�[���̃}�b�v���쐬��,
* �L�����N�^��z�u����
*/
class CGame
{
public:
	//�Q�[���N���A����
	bool IsClear();
	//�Q�[���N���A����
	void Clear();
	//�Q�[���I�[�o�[����
	//true:�Q�[���I�[�o�[
	bool IsOver();
	//�Q�[���I�[�o�[����
	void Over();
	//�X�^�[�g����
	void Start();
	CGame(); //�f�t�H���g�R���X�g���N�^(��������)
	void Update(); //�X�V����
private:
	CUi* mpUi; //UI�N���X�̃|�C���^
	int mTime; //���Ԍo��
};