#pragma once
#include "CRectangle.h"
#include "CTexture.h"
#include "CCharacter.h"
#include "CBullet.h"
#include "CEnemy.h"
#include "CPlayer.h"
#include "CInput.h"
#include "CFont.h"
#include "CMiss.h"
#include <vector>
#include "CCharacterManager.h"
#include "CGame.h"
#include "CSound.h"
#include "CModel.h"
#include "CCharacter3.h"
#include "CTaskManager.h"
#include "CColliderTriangle.h"
#include "CColliderMesh.h"

class CApplication
{
private:
	//���f������R���C�_�𐶐�
	CColliderMesh mColliderMesh;
	//�O�p�R���C�_�̍쐬
	//�폜CColliderTriangle mColliderTriangle;
	//�O�p�R���C�_2�̍쐬
	//�폜CColliderTriangle mColliderTriangle2;
	//���f���r���[�̋t�s��
	static CMatrix mModelViewInverse;
	//C5���f��
	CModel mModelC5;
	static CCharacterManager mCharacterManager;
	CPlayer mPlayer;
	CModel mBackGround; //�w�i���f��
	//���f���N���X�̃C���X�^���X�쐬
	CVector mEye;
	CModel mModel;
	CSound mSoundBgm;	//BGM
	CSound mSoundOver;	//�Q�[���I�[�o�[
	CGame* mpGame;
	enum class EState
	{
		ESTART,	//�Q�[���J�n
		EPLAY,	//�Q�[����
		ECLEAR,	//�Q�[���N���A
		EOVER,	//�Q�[���I�[�o�[
	};
	EState mState;
//	CCharacter mRectangle;
	CPlayer* mpPlayer;
	static CTexture mTexture;
	CEnemy* mpEnemy;
//	CBullet* mpBullet;
	CInput mInput;
	CFont mFont;
	CMiss* mpMiss;
	//CCharacter�̃|�C���^�̉ϒ��z��
	std::vector<CCharacter*> mCharacters;
public:
	//���f���r���[�s��̎擾
	static const CMatrix& ModelViewInverse();
	static CCharacterManager* CharacterManager();
	static CTexture* Texture();
	//�ŏ��Ɉ�x�������s����v���O����
	void Start();
	//�J��Ԃ����s����v���O����
	void Update();
};