#pragma once
#include"CCharacter.h"

class CBullet : public CCharacter
{
public:
      //�Փˏ���2
    void Collision();
      //�Փˏ���4
      //Collision(�����̃|�C���^,�Փˑ���̃|�C���^)
    void Collision(CCharacter* m, CCharacter* o);
       //CBullet(X���W,Y���W,��,����,�摜�E,�摜��,�摜��,�摜��,�e�N�X�`���̃|�C���^)
    CBullet(float x, float y, float w, float h, float l, float r, float b, float t, CTexture* pt);
    CBullet();
    void Update();
      bool Collision(CRectangle* rect);
};