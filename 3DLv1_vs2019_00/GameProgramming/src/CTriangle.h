#pragma once
#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include "CVector.h"
#include "CMatrix.h"
/*
三角形のクラス
*/
class CTriangle {
public:
	//描画
	//Render(行列)
	void Render(const CMatrix& m);
	//UV設定
	void UV(const CVector& v0, const CVector& v1, const CVector& v2);
	//マテリアル番号の取得
	int MaterialIdx();
	//マテリアル番号の設定
<<<<<<< HEAD
	//Material(マテリアル番号)
=======
	//Material(マテリアル暗号)]
>>>>>>> d164ea01132d274418f6de3275384a3b82bdaf2d
	void MaterialIdx(int idx);
	//頂点座標設定
	//Vertex(頂点1,頂点2,頂点3)
	void Vertex(const CVector&v0, const CVector&v1, const CVector&v2);
	//法線設定
	//Normal(法線ベクトル)
	void Normal(const CVector& n);
	//描画
	void Render();
	//Normal(法線ベクトル1,法線ベクトル2,法線ベクトル3)
	void Normal(const CVector& v0, const CVector& v1, const CVector& v2);
private:
<<<<<<< HEAD
	CVector mUv[3]; //テクスチャマッピング
	int mMaterialIdx; //マテリアル番号
=======
	CVector mUv[3];//テクスチャマッピング
	int mMaterialIdx;//マテリアル番号
>>>>>>> d164ea01132d274418f6de3275384a3b82bdaf2d
	CVector mV[3];//頂点座標
	CVector mN[3];//法線
};
#endif