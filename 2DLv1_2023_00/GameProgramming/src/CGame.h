#pragma once
//定義の定数
#define TEXTURE "image.png" //テクスチャのファイル名
#define TIPSIZE 20.0f //マップ要素のサイズ
#include "CUi.h"
/*
* CGameクラス
* ゲームのクラス
* ゲームのマップを作成し,
* キャラクタを配置する
*/
class CGame
{
public:
	//ゲームクリア判定
	bool IsClear();
	//ゲームクリア処理
	void Clear();
	//ゲームオーバー判定
	//true:ゲームオーバー
	bool IsOver();
	//ゲームオーバー処理
	void Over();
	//スタート処理
	void Start();
	CGame(); //デフォルトコンストラクタ(初期処理)
	void Update(); //更新処理
private:
	CUi* mpUi; //UIクラスのポインタ
	int mTime; //時間経過
};