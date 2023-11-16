#pragma once
#ifndef CMATERIAL_H
#define CMATERIAL_H
#define MATERIAL_NAME_LEN 64 //名前の長さ
#include "CTexture.h"

/*
マテリアルクラス
アテリアルのデータを扱う
*/
class CMaterial {
public:
	//頂点数の設定
	//VertexNum(頂点数)
	void VertexNum(int num);
	//頂点数の獲得
	int VertexNum();
	//行列値の取得
	//M(行,列)
	//mM[行][列]を取得
	float M(int r, int c)const;
	//テクスチャの取得
	CTexture* Texture();
	//マテリアルを無効にする
	void Disabled();
	//デフォルトコンストラクタ
	CMaterial();
	//マテリアルを有効にする
	void Enabled();
	//マテリアルの名前を取得
	char* Name();
	//マテリアルの名前を設定する
	//Name(マテリアルの名前)
	void Name(char* name);
	//mDiffuse配列の取得
	float* Diffuse();
private:
	//マテリアル毎の頂点数
	int mVertexNum;
	//テクスチャ
	CTexture mTexture;
	//マテリアル名
	char mName[MATERIAL_NAME_LEN + 1];
	//拡散光の色RGBA
	float mDiffuse[4];
};

#endif