#pragma once
#ifndef CCOLLISIONMANAGER_H
#define CCOLLISIONMANAGER_H
#define COLLISIONRANGE 30
//�Փˏ����͈͂�藣��Ă���R���C�_�͏Փˏ������Ȃ�

#include "CTaskManager.h"
#include "CCollider.h"

class CCollisionManager : public CTaskManager
{
public:
	void Collision(CCollider* c, int range);
	//�Փˏ���
	void Collision();
	//�C���X�^���X�̎擾
	static CCollisionManager* Instance();
private:
	//�}�l�[�W���̃C���X�^���X
	static CCollisionManager* mpInstance;
};

#endif