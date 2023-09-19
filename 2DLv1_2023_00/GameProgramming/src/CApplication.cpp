#include "CApplication.h"
#include "CInput.h"
#include "CRectangle.h"
#include "CEnemy.h"
#include "CEnemy2.h"

void CApplication::Start()
{
}

void CApplication::Update()
{
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