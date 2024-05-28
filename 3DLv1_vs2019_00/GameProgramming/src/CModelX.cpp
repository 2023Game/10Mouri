#include <stdio.h>
#include <string.h>
#include "CModelX.h"
#include "glut.h"
#include <ctype.h> //isspace関数の宣言
#include "CVector.h"
#include "CMaterial.h"
/*
IsDelimiter(c)
*cが\t \r \nスペースなどの空白文字
*または,;"などの文字であれば
*区切り文字としてtrueを返す
*/
bool CModelX::IsDelimiter(char c)
{
    //isspace(c)
    //cが空白文字なら0以外を返す
    if (isspace(c) != 0)
        return true;
    /*
    strchr(文字列,文字)
    文字列に文字が含まれていれば,
    見つかった文字へのポインタを返す
    見つからなかったらNULLを返す
    */
    if (strchr(",;\"", c) != NULL)
        return true;
    //区切り文字ではない
    return false;
}

CModelX::CModelX()
    : mpPointer(nullptr)
{
    //mTokenを初期化
    memset(mToken, 0, sizeof(mToken));
}

void CModelX::Load(char* file) {
    //
    //ファイルサイズを取得する
    //
    FILE* fp; //ファイルポインタ変数の作成

    fp = fopen(file, "rb"); //ファイルをオープンする
    if (fp == NULL) {       //エラーチェック
        printf("fopen error:%s\n", file);
        return;
    }
    //ファイルの最後へ移動
    fseek(fp, 0L, SEEK_END);
    //ファイルサイズの取得
    int size = ftell(fp);
    //ファイルサイズ+1バイト分の領域を確保
    char* buf = mpPointer = new char[size + 1];
    //
    //ファイルから3Dモデルのデータを読み込む
    //
    //ファイルの先頭へ移動
    fseek(fp, 0L, SEEK_SET);
    //確保した領域にファイルサイズ分データを読み込む
    fread(buf, size, 1, fp);
    //最後に\0を設定する(文字列の終端)
    buf[size] = '\0';
    fclose(fp); //ファイルをクローズする
    //文字列の最後まで繰り返し
    while (*mpPointer != '\0') {
        GetToken(); //単語の取得
        //単語がFrameの場合
        if (strcmp(mToken, "Frame") == 0) {
            //フレームを作成する
            new CModelXFrame(this);
        }
    }

    SAFE_DELETE_ARRAY(buf); //確保した領域を開放する
}

/*
GetToken
文字列データから,単語を1つ取得する
*/
char* CModelX::GetToken() {
    char* p = mpPointer;
    char* q = mToken;
    //タブ(\t)空白()改行(\n),:"の区切り文字以外になるまで読み飛ばす
    while (*p != '\0' && IsDelimiter(*p))p++;
    if (*p == '{' || *p == '}') {
        //{または}ならmTokenに代入し次の文字へ
        *q++ = *p++;
    }
    else {
        //タブ(\t)空白()改行(\r)(\n),;"の区切り文字
        //または,}の文字になるまでmTokenに代入する
        while (*p != '\0' && !IsDelimiter(*p) && *p != '}')
            *q++ = *p++;
    }

    *q = '\0'; //mTokenの最後に\0を代入
    mpPointer = p; //次の読み込むポイントを更新する

    //もしmTokenが//の場合は,コメントなので改行まで読み飛ばす
    /*
    strcmp(文字列1,文字列2)
    文字列1と文字列2が等しい場合,0を返します。
    文字列1と文字列2が等しくない場合,0以外を返します。
    */
    if (!strcmp("//", mToken)) {
        //改行まで読み飛ばす
        while (*p != '\0' && !strchr("\r\n", *p)) p++;
        //読み込み位置の更新
        mpPointer = p;
        //単語を取得する(再帰呼び出し)
        return GetToken();
    }
    return mToken;
}

CModelXFrame::~CModelXFrame()
{
    //子フレームを全て解放する
    std::vector<CModelXFrame*>::iterator itr;
    for (itr = mChild.begin(); itr != mChild.end(); itr++) {
        delete* itr;
    }
    //名前のエリアを解放する
    SAFE_DELETE_ARRAY(mpName);
    if (mpMesh != nullptr)
    {
        delete mpMesh;
    }
}

CModelX::~CModelX()
{
    if (mFrame.size() > 0)
    {
        delete mFrame[0];
    }
}

bool CModelX::EOT()
{
    return *mpPointer == '\0';
}
/*
SkipNode
ノードを読み飛ばす
*/
void CModelX::SkipNode() {
    //文字が終わったら終了
    while (*mpPointer != '\0') {
        GetToken(); //次の単語取得
        //{が見つかったらループ終了
        if (strchr(mToken, '{')) break;
    }
    int count = 1;
    //文字が終わるか,カウントが0になったら終了
    while (*mpPointer != '\0' && count > 0) {
        GetToken(); //次の単語取得
        //{を見つけるとカウントアップ
        if (strchr(mToken, '{')) count++;
        //}を見つけるとカウントダウン
        else if (strchr(mToken, '}')) count--;
    }
}

char* CModelX::Token()
{
    return mToken;
}
//コンストラクタ
CMesh::CMesh()
    : mVertexNum(0)
    , mpVertex(nullptr)
    , mFaceNum(0)
    , mpVertexIndex(nullptr)
    , mNormalNum(0)
    , mpNormal(nullptr)
    , mMaterialNum(0)
    , mMaterialIndexNum(0)
    , mpMaterialIndex(nullptr)
{}
//デストラクタ
CMesh::~CMesh() {
    SAFE_DELETE_ARRAY(mpVertex);
    SAFE_DELETE_ARRAY(mpVertexIndex);
    SAFE_DELETE_ARRAY(mpNormal);
    SAFE_DELETE_ARRAY(mpMaterialIndex);
}
/*
Init
Meshのデータを取り込む
*/
void CMesh::Init(CModelX* model) {
    model->GetToken();// {or 名前
    if (!strchr(model->Token(), '{')) {
        //名前の場合,次が{
        model->GetToken(); // {
    }

    //頂点数の取得
    mVertexNum = atoi(model->GetToken());
    //頂点数分エリア確保
    mpVertex = new CVector[mVertexNum];
    //頂点数分データを取り込む
    for (int i = 0; i < mVertexNum; i++) {
        mpVertex[i].X(atof(model->GetToken()));
        mpVertex[i].Y(atof(model->GetToken()));
        mpVertex[i].Z(atof(model->GetToken()));
    }
    //面数読み込み
    mFaceNum = atoi(model->GetToken());
    //頂点数は1面に3頂点
    mpVertexIndex = new int[mFaceNum * 3];
    for (int i = 0; i < mFaceNum * 3; i += 3) {
        model->GetToken(); //頂点数読み飛ばし
        mpVertexIndex[i] = atoi(model->GetToken());
        mpVertexIndex[i + 1] = atoi(model->GetToken());
        mpVertexIndex[i + 2] = atoi(model->GetToken());
    }
    //単語がある間繰り返し
    while (!model->EOT()) {
        model->GetToken(); //MeshNormals
        //}かっこの場合は終了
        if (strchr(model->Token(), '}'))
            break;
        if (strcmp(model->Token(), "MeshNormals") == 0) {
            model->GetToken(); // {
            //法線データ数を取得
            mNormalNum = atoi(model->GetToken());
            //法線のデータを配列に取り込む
            CVector* pNormal = new CVector[mNormalNum];
            for (int i = 0; i < mNormalNum; i++) {
                pNormal[i].X(atof(model->GetToken()));
                pNormal[i].Y(atof(model->GetToken()));
                pNormal[i].Z(atof(model->GetToken()));
            }
            //法線数=面数×3
            mNormalNum = atoi(model->GetToken()) * 3; //FaceNum
            int ni;
            //頂点毎に法線データを設定する
            mpNormal = new CVector[mNormalNum];
            for (int i = 0; i < mNormalNum; i += 3) {
                model->GetToken(); //3
                ni = atoi(model->GetToken());
                mpNormal[i] = pNormal[ni];

                ni = atoi(model->GetToken());
                mpNormal[i + 1] = pNormal[ni];

                ni = atoi(model->GetToken());
                mpNormal[i + 2] = pNormal[ni];
            }
            delete[] pNormal;
            model->GetToken(); //}
        } // End of MeshNormals
        //MeshMaterialListのとき
        else if (strcmp(model->Token(), "MeshMaterialList") == 0)
            model->GetToken(); // {
        //Materialの数
        mMaterialNum = atoi(model->GetToken());
        //FaceNum
        mMaterialIndexNum = atoi(model->GetToken());
        //マテリアルインデックスの作成
        mpMaterialIndex = new int[mMaterialIndexNum];
        for (int i = 0; i < mMaterialIndexNum; i++) {
            mpMaterialIndex[i] = atoi(model->GetToken());
        }
        //マテリアルデータの作成
        for (int i = 0; i < mMaterialNum; i++) {
            model->GetToken(); //Material
            if (strcmp(model->Token(), "Material") == 0) {
                mMaterial.push_back(new CMaterial(model));
            }
        }
        model->GetToken(); // } //End of MeshMaterialList
    } //End of MeshMaterialList
    printf("VertexNum:%d\n", mVertexNum);
    for (int i = 0; i < mVertexNum; i++) {
        printf("%10f", mpVertex[i].X());
        printf("%10f", mpVertex[i].Y());
        printf("%10f\n", mpVertex[i].Z());
    }
#ifdef _DEBUG
    printf("FaceNum:%d\n", mFaceNum);
    for(int i = 0; i < mFaceNum * 3; i += 3) {
        printf("%10d", mpVertexIndex[i]);
        printf("%10d", mpVertexIndex[i + 1]);
        printf("%10d\n", mpVertexIndex[i + 2]);
    }
#endif
#ifdef _DEBUG
    printf("NormalNum:%d\n", mNormalNum);
    for (int i = 0; i < mNormalNum; i++) {
        printf("%10f", mpNormal[i].X());
        printf("%10f", mpNormal[i].Y());
        printf("%10f\n", mpNormal[i].Z());
    }
#endif
}
/*
Render
画面に描画する
*/
void CMesh::Render() {
    /* 頂点データ,法線データの配列を有効にする */
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);

    /* 頂点データ,法線データの場所を指定する */
    glVertexPointer(3, GL_FLOAT, 0, mpVertex);
    glNormalPointer(GL_FLOAT, 0, mpNormal);

    /* 頂点のインデックスの場所を指定して図形を描画する */
    for (int i = 0; i < mFaceNum; i++) {
        //マテリアルを適用する
        mMaterial[mpMaterialIndex[i]]->Enabled();
        glDrawElements(GL_TRIANGLES, 3,
            GL_UNSIGNED_INT, (mpVertexIndex + 1 * 3));
    }

    /* 頂点データ,法線データの配列を無効にする */
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
}
/*
Render
メッシュが存在すれば描画する
*/
void CModelXFrame::Render() {
    if (mpMesh != nullptr)
        mpMesh->Render();
}
/*
Render
全てのフレームの描画処理を呼び出す
*/
void CModelX::Render() {
    for (size_t i = 0; i < mFrame.size(); i++) {
        mFrame[i]->Render();
    }
}
/*
CModelXFrame
model:CModelXインスタンスへのポインタ
フレームを作成する
読み込み中にFrameが見つかれば,フレームを作成し,
子フレームに追加する
*/
CModelXFrame::CModelXFrame(CModelX* model)
    : mpName(nullptr)
    , mIndex(0)
    , mpMesh(nullptr)
{
    //現在のフレーム配列の要素数を取得し設定する
    mIndex = model->mFrame.size();
    //CModelXのフレーム配列に追加する
    model->mFrame.push_back(this);
    //変数行列を単位行列にする
    mTransformMatrix.Identity();
    //次の単語(フレーム名の予定)を取得する
    model->GetToken(); // frame name
    //フレーム名分エリアを確保する
    mpName = new char[strlen(model->mToken) + 1];
    //フレーム名をコピーする
    strcpy(mpName, model->mToken);
    //次の単語({の予定)を取得する
    model->GetToken(); // {
    //文字が無くなったら終わり
    while (*model->mpPointer != '\0') {
        //次の単語取得
        model->GetToken(); // Frame
        //}かっこの場合は終了
        if (strchr(model->mToken, '}')) break;
        //新なフレームの場合は,子フレームに追加
        if (strcmp(model->mToken,"Frame") == 0) {
            //フレームを作成し,子フレームに追加
            mChild.push_back(
                new CModelXFrame(model));
        }
        else if (strcmp(model->mToken,"FrameTransformMatrix") == 0) {
            model->GetToken(); // {
            for (int i = 0; i < mTransformMatrix.Size(); i++) {
                mTransformMatrix.M()[i] = atof(model->GetToken());
            }
            model->GetToken(); // }
        }
        else if (strcmp(model->mToken, "Mesh") == 0) {
            mpMesh = new CMesh();
            mpMesh->Init(model);
        }
        else {
            //上記以外の要素は読み飛ばす
            model->SkipNode();
        }
    }
//デバッグバージョンのみ有効
#ifdef _DEBUG
    printf("%s\n", mpName);
    mTransformMatrix.Print();
#endif
}