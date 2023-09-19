#pragma once
#include "CRectangle.h"
#include "CTexture.h"
#define VELOCITY 2.0f //�ړ����x

class CCharacter :public CRectangle 
{
public:
	bool Enabled();
	enum class ETag  //���ʎq
	{
		 EZERO,      //�����l
		 EBULLET,    //�e
		 EENEMY,     //�G
		 EPLAYER,    //�v���C���[
		 ETURN,      //�܂�Ԃ�
		 EBLOCK,     //�u���b�N
	};
	ETag Tag();
	   //�Փˏ���2
	virtual void Collision() {};
	   //�Փˏ���4
	   //Collision(�����̃|�C���^,�Փˑ���̃|�C���^)
	virtual void Collision(CCharacter* m, CCharacter* o) {};
	virtual void Update() = 0;
	enum class EState //���
	{
		 EMOVE,       //�ړ�
		 ESTOP,        //��~
		 EJUMP,       //�W�����v
		 ECRY,        //����
	};
	CCharacter();
	CTexture* Texture();
	void Texture(CTexture* pTexture,
		int left, int right, int bottom, int top);
	virtual void Render();
	void Move();
	EState State();   //��Ԃ��擾����
protected:
	float mVx; //X�����x
	float mVy; //Y�����x
	bool mEnabled; //�L���t���O
	ETag mTag; //���ʎq
	EState mState;
private:
	CTexture* mpTexture;
	int mLeft, mRight, mBottom, mTop;
};