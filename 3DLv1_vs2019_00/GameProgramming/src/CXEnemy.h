#include "CXCharacter.h"
#include "CCollider.h"

class CXEnemy :public CXCharacter {
public:
	//�Փˏ���
	void Collision(CCollider* m, CCollider* o);
	void Init(CModelX* model);
	CXEnemy();
private:
	//�R���C�_�̐錾
	CCollider mColSphereBody; //��
	CCollider mColSphereHead; //��
	CCollider mColSphereSword; //��
};