#include "CXCharacter.h"
#include "CInput.h"
#include "CCollider.h"

class CXPlayer : public CXCharacter {
public:
	CXPlayer();
	void Update();
	void Init(CModelX* model);
private:
	CCollider mColSphereHead; //��
	CCollider mColSphereSword; //��
	//�R���C�_�̐錾
	CCollider mColSphereBody; //��
	CInput mInput;
};