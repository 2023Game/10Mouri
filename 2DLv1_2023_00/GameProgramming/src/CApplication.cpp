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
	//状態をスタートにする
	mState = EState::ESTART;
}

void CApplication::Update()
{
	switch (mState)
	{
	case EState::EPLAY:
		mpGame->Update();
		//ゲームオーバーか判定
		if (mpGame->IsOver())
		{     //状態をゲームオーバーにする
			mState = EState::EOVER;
		}
		break;
	case EState::ESTART: //状態がスタート
		mpGame->Start(); //スタート画面表示
		//Enterキーが押されたら
		if (mInput.Key(VK_RETURN))
		{     //状態をプレイ中にする
			mState = EState::EPLAY;
		}
		break;
	case EState::EOVER:
		  //ゲームオーバー処理
		mpGame->Over();
		break;
		//ゲームクリアか判定
		if (mpGame->IsClear())
		{     //状態をゲームクリアにする
			mState = EState::ECLEAR;
		}
	case EState::ECLEAR:
		  //ゲームクリア処理
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