#pragma once
#ifndef CCOLLIDER_H
#define CCOLLIDER_H
//キャラクタクラスのインクルード
#include "CCharacter3.h"
#include "CMatrix.h"

/*
コライダクラス
衝突判定データ
*/
class CCollisionManager;

class CCollider : public CTransform, public CTask {
	friend CCollisionManager;
public:
	void Matrix(CMatrix* m);
	//優先度の変更
	virtual void ChangePriority();
	//優先度の変更
	void ChangePriority(int priority);
	//CollisionTriangleSphere(三角コライダ,球コライダ,調整値)
	//return:true(衝突している)false(衝突していない)
	//調整値:衝突しない位置まで戻す値
	static bool CollisionTriangleSphere(CCollider* triangle, CCollider* sphere, CVector* adjust);
	//CollisionTriangleLine(三角コライダ,調整値)
	//return:true (衝突している) false(衝突していない)
	//調整値:衝突しない位置まで戻す値
	static bool CollisionTriangleLine(CCollider* triangle, CCollider* line, CVector* adjust);
	//コライダタイプ
	enum class EType {
		ESPHERE,//球コライダ
		ETRIANGLE,//三角コライダ
		ELINE,//線分コライダ
	};
	//デフォルトコンストラクタ
	CCollider();
	//衝突判定
	//Collision(コライダ1,コライダ2)
	//return:true(衝突している)false(衝突していない)
	static bool Collision(CCollider* m, CCollider* o);
	~CCollider();
	//コンストラクタ
	//CCollider(親,親行列,位置,半径)
	CCollider(CCharacter3* parent, CMatrix* matrix,
		const CVector& posiiton, float radius);
	//親ポインタの取得
	CCharacter3* Parent();
	//描画
	void Render();
	EType Type();
protected:
	EType mType;//コライダタイプ
	//頂点
	CVector mV[3];
	CCharacter3* mpParent;//親
	CMatrix* mpMatrix;//親行列
	float mRadius; //半径

};
#endif