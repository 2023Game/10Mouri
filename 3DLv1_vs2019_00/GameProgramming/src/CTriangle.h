#pragma once
#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include "CVector.h"
#include "CMatrix.h"
/*
�O�p�`�̃N���X
*/
class CTriangle {
public:
	//�`��
	//Render(�s��)
	void Render(const CMatrix& m);
	//UV�ݒ�
	void UV(const CVector& v0, const CVector& v1, const CVector& v2);
	//�}�e���A���ԍ��̎擾
	int MaterialIdx();
	//�}�e���A���ԍ��̐ݒ�
<<<<<<< HEAD
	//Material(�}�e���A���ԍ�)
=======
	//Material(�}�e���A���Í�)]
>>>>>>> d164ea01132d274418f6de3275384a3b82bdaf2d
	void MaterialIdx(int idx);
	//���_���W�ݒ�
	//Vertex(���_1,���_2,���_3)
	void Vertex(const CVector&v0, const CVector&v1, const CVector&v2);
	//�@���ݒ�
	//Normal(�@���x�N�g��)
	void Normal(const CVector& n);
	//�`��
	void Render();
	//Normal(�@���x�N�g��1,�@���x�N�g��2,�@���x�N�g��3)
	void Normal(const CVector& v0, const CVector& v1, const CVector& v2);
private:
<<<<<<< HEAD
	CVector mUv[3]; //�e�N�X�`���}�b�s���O
	int mMaterialIdx; //�}�e���A���ԍ�
=======
	CVector mUv[3];//�e�N�X�`���}�b�s���O
	int mMaterialIdx;//�}�e���A���ԍ�
>>>>>>> d164ea01132d274418f6de3275384a3b82bdaf2d
	CVector mV[3];//���_���W
	CVector mN[3];//�@��
};
#endif