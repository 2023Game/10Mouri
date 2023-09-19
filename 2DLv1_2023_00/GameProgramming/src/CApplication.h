#pragma once
#include "CRectangle.h"
#include "CTexture.h"
#include "CCharacter.h"
#include "CBullet.h"
#include "CEnemy.h"
#include "CPlayer.h"
#include "CFont.h"
#include "CMiss.h"
#include "CCharacterManager.h"
#include "CGame.h"
#include "CPlayer2.h"
#include "CEnemy2.h"

class CApplication
{
public:
	  //最初に一度だけ実行される処理
	void Start();
	  //毎フレームごとに繰り返し実行される処理
	void Update();
public:
	static CTexture* Texture();
	static CCharacterManager* CharacterManager();
	enum class EState
	{
		ESTART,     //ゲーム開始
		EPLAY,      //ゲーム中
		ECLEAR,     //ゲームクリア
		EOVER,      //ゲームオーバー
	};
private:
	CGame* mpGame;
	   static CCharacterManager mCharacterManager;
	EState mState;
	CInput mInput;
	   CPlayer*mpPlayer;
	   static CTexture mTexture;
	   CEnemy* mpEnemy;
	   CFont mFont;
	   CMiss*mpMiss;
	   CPlayer2* mPlayer2;
	   CEnemy2* mpEnemy2;
};