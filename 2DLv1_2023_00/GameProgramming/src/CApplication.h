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
	  //�ŏ��Ɉ�x�������s����鏈��
	void Start();
	  //���t���[�����ƂɌJ��Ԃ����s����鏈��
	void Update();
public:
	static CTexture* Texture();
	static CCharacterManager* CharacterManager();
	enum class EState
	{
		ESTART,     //�Q�[���J�n
		EPLAY,      //�Q�[����
		ECLEAR,     //�Q�[���N���A
		EOVER,      //�Q�[���I�[�o�[
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