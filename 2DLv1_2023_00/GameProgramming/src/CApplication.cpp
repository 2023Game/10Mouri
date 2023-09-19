#include "CApplication.h"
#include "CInput.h"
#include "CRectangle.h"
#include "CEnemy.h"
#include "CEnemy2.h"

void CApplication::Start()
{
	mFont.Load("FontWhile.png", 1, 64);
	mState = EState::EPLAY;
	mpGame = new CGame();
	//��Ԃ��X�^�[�g�ɂ���
	mState = EState::ESTART;
}

void CApplication::Update()
{
	switch (mState)
	{
	case EState::EPLAY:
		mpGame->Update();
		//�Q�[���I�[�o�[������
		if (mpGame->IsOver())
		{     //��Ԃ��Q�[���I�[�o�[�ɂ���
			mState = EState::EOVER;
		}
		break;
	case EState::ESTART: //��Ԃ��X�^�[�g
		mpGame->Start(); //�X�^�[�g��ʕ\��
		//Enter�L�[�������ꂽ��
		if (mInput.Key(VK_RETURN))
		{     //��Ԃ��v���C���ɂ���
			mState = EState::EPLAY;
		}
		break;
	case EState::EOVER:
		  //�Q�[���I�[�o�[����
		mpGame->Over();
		break;
		//�Q�[���N���A������
		if (mpGame->IsClear())
		{     //��Ԃ��Q�[���N���A�ɂ���
			mState = EState::ECLEAR;
		}
	case EState::ECLEAR:
		  //�Q�[���N���A����
		mpGame->Clear();
		break;
	}
}

CCharacterManager CApplication::mCharacterManager;
CCharacterManager* CApplication::CharacterManager()
{
	return &mCharacterManager;
}

CTexture CApplication::mTexture;
CTexture* CApplication::Texture()
{
	return &mTexture;
}