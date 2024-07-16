#include "CXCharacter.h"
#include "CInput.h"
#include "CCollider.h"

class CXPlayer : public CXCharacter {
public:
	CXPlayer();
	void Update();
	void Init(CModelX* model);
private:
	CCollider mColSphereHead; //頭
	CCollider mColSphereSword; //剣
	//コライダの宣言
	CCollider mColSphereBody; //体
	CInput mInput;
};