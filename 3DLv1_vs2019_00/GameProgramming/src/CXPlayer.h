#include "CXCharacter.h"
#include "CInput.h"
#include "CCollider.h"

class CXPlayer : public CXCharacter {
public:
	CXPlayer();
	void Update();
	void Init(CModelX* model);
private:
	CCollider mColSphereHead; //“ª
	CCollider mColSphereSword; //Œ•
	//ƒRƒ‰ƒCƒ_‚ÌéŒ¾
	CCollider mColSphereBody; //‘Ì
	CInput mInput;
};