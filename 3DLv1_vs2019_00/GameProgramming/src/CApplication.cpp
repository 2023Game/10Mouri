#include "CApplication.h"
//OpenGL
#include "glut.h"
#include "CRectangle.h"
#include "CVector.h"
#include "CTriangle.h"
//���f���f�[�^�̎w��
#define MODEL_OBJ "res\\f14.obj","res\\f14.mtl"
//�w�i���f���f�[�^�̎w��
#define MODEL_BACKGROUND "res\\sky.obj","res\\sky.mtl"
//�N���X��static�ϐ�
CTexture CApplication::mTexture;
#define SOUND_BGM "res\\mario.wav" //BGM�����t�@�C��
#define SOUND_OVER "res\\mdai.wav" //�Q�[���I�[�o�[�����t�@�C��
#include "CMatrix.h"
#include "CTransform.h"

CTexture* CApplication::Texture()
{
	return &mTexture;
}

void CApplication::Start()
{
	mPlayer.Model(&mModel);
	mPlayer.Scale(CVector(0.1f, 0.1f, 0.1f));
	mPlayer.Position(CVector(0.0f, 0.0f, -3.0f));
	mPlayer.Rotation(CVector(0.0f, 180.0f, 0.0f));
	CMatrix matrix;
	matrix.Print();
	mBackGround.Load(MODEL_BACKGROUND);
	mEye = CVector(1.0f, 2.0f, 3.0f);
	//���f���t�@�C���̓���
	mModel.Load(MODEL_OBJ);
}

void CApplication::Update()
{
	//�^�X�N�}�l�[�W���̍X�V
	mTaskManager.Update();
	//���_1,���_2,���_3,�@���f�[�^�̍쐬
	CVector v0, v1, v2, n;
	//�@����������Őݒ肷��
	n.Set(0.0f, 1.0f, 0.0f);
	//���_1�̍��W��ݒ肷��
	v0.Set(0.0f, 0.0f, 0.5f);
	//���_2�̍��W��ݒ肷��
	v1.Set(1.0f, 0.0f, 0.0f);
	//���_3�̍��W��ݒ肷��
	v2.Set(0.0f, 0.0f, -0.5f);

	if (mInput.Key('J'))
	{
		mEye = mEye - CVector(0.1f, 0.0f, 0.0f);
	}
	if (mInput.Key('L'))
	{
		mEye = mEye + CVector(0.1f, 0.0f, 0.0f);
	}
	if (mInput.Key('I'))
	{
		mEye = mEye - CVector(0.0f, 0.0f, 0.1f);
	}
	if (mInput.Key('K'))
	{
		mEye = mEye + CVector(0.0f, 0.0f, 0.1f);
	}
	if (mInput.Key('M'))
	{
		mEye = mEye - CVector(0.0f, 0.1f, 0.0f);
	}
	if (mInput.Key('O'))
	{
		mEye = mEye + CVector(0.0f, 0.1f, 0.0f);
	}

	//�J�����̃p�����[�^���쐬����
	CVector e, c, u;//���_,�����_,�����
	//���_�����߂�
	e = mPlayer.Position() + CVector(0.0f, 1.0f, -3.0f) * mPlayer.MatrixRotate();
	//�����_�����߂�
	c = mPlayer.Position();
	//����������߂�
	u = CVector(0.0f, 1.0f, 0.0f) * mPlayer.MatrixRotate();
	//�J�����̐ݒ�
	gluLookAt(e.X(), e.Y(), e.Z(), c.X(), c.Y(), c.Z(), u.X(), u.Y(), u.Z());
	mBackGround.Render();
	//�^�X�N���X�g�̍폜
	mTaskManager.Delete();
	//�^�X�N�}�l�[�W���̕`��
	mTaskManager.Render();
}

CCharacterManager CApplication::mCharacterManager;
CCharacterManager* CApplication::CharacterManager()
{
	return &mCharacterManager;
}

CTaskManager CApplication::mTaskManager;
CTaskManager* CApplication::TaskManager()
{
	return &mTaskManager;
}