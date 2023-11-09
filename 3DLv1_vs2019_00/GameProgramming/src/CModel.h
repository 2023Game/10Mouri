#pragma once
#ifndef CMODEL_H
#define CMODEL_H
//vectorのインクルード
#include <vector>
#include "CTriangle.h"
#include "CMaterial.h"
/*
モデルクラス
モデルデータの入力や表示
*/
class CModel {
private:
	//マテリアルポインタの可変長配列
	std::vector<CMaterial*>mpMaterials;
	//三角形の可変長配列
	std::vector<CTriangle> mTriangles;
public:
	//描画
	//Render(行列)
	void Render(const CMatrix& m);
	~CModel();
	//モデルファイルの入力
	//Load(モデルファイル名,マテリアルファイル名)
	void Load(char* obj, char* mtl);
    //描画
	void Render();
};

#endif