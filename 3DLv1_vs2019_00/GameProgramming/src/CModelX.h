#ifndef CMODELX_H //インクルードガード
#define CMODELX_H
#include <vector> //vectorクラスのインクルード(動的配列)
#include "CMatrix.h" //マトリクスのインクルード
class CModelX; //CModelXクラスの宣言
class CModelXFrame; //CModelXFrameクラスの宣言
class CMesh; //CMeshクラスの宣言

#define MODEL_FILE "res\\sample.blend.x" //入力ファイル名

//領域解放をマクロ化
#define SAFE_DELETE_ARRAY(a) {if(a) delete[] a; a = nullptr;}
/*
CModelX
Xファイル形式の3Dモデルデータをプログラムで認識する
*/
class CModelX {
	friend CModelXFrame;
public:
	char* Token();
	~CModelX();
	//ノードの読み飛ばし
	void SkipNode();
	//単語の取り出し
	char* GetToken();
	CModelX();
	//ファイル読み込み
	void Load(char* file);
private:
	std::vector<CModelXFrame*> mFrame; //フレームの配列
	//cが区切り文字ならtrueを返す
	bool IsDelimiter(char c);
	char* mpPointer; //読み込み位置
	char mToken[1024]; //取り出した単語の領域
};
//CModelXFrameクラスの定義
class CModelXFrame {
	friend CModelX;
public:
	//コンストラクタ
	CModelXFrame(CModelX* model);
	//デストラクタ
	~CModelXFrame();
private:
	CMesh* mpMesh; //Meshデータ
	std::vector<CModelXFrame*> mChild; //子フレームの配列
	CMatrix mTransformMatrix; //変換行列
	char* mpName; //フレーム名前
	int mIndex; //フレーム番号
};
//CMeshクラスの定義
class CMesh {
public:
	//コンストラクタ
	CMesh();
	//デストラクタ
	~CMesh();
	//読み込み処理
	void Init(CModelX* model);
private:
	int mNormalNum; //法線数
	CVector* mpNormal;//法線ベクトル
	int mFaceNum; //面数
	int* mpVertexIndex; //面を構成する頂点インデックス
	int mVertexNum; //頂点数
	CVector* mpVertex; //頂点データ
};

#endif