#pragma once
#ifndef CMODEL_H
#define CMODEL_H
//vector�̃C���N���[�h
#include <vector>
#include "CTriangle.h"
#include "CMaterial.h"
/*
���f���N���X
���f���f�[�^�̓��͂�\��
*/
class CModel {
private:
	//�}�e���A���|�C���^�̉ϒ��z��
<<<<<<< HEAD
	std::vector<CMaterial*>mpMaterials;
=======
	std::vector<CMaterial*> mpMaterials;
>>>>>>> d164ea01132d274418f6de3275384a3b82bdaf2d
	//�O�p�`�̉ϒ��z��
	std::vector<CTriangle> mTriangles;
public:
	//�`��
	//Render(�s��)
	void Render(const CMatrix& m);
	~CModel();
	//���f���t�@�C���̓���
	//Load(���f���t�@�C����,�}�e���A���t�@�C����)
	void Load(char* obj, char* mtl);
    //�`��
	void Render();
};

#endif