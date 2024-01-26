#include "CEnemy3.h"
#include "CEffect.h"
#include "CCollisionManager.h"

#define OBJ "res\\f16.obj" //���f���̃t�@�C��
#define MTL "res\\f16.mtl" //���f���̃}�e���A���t�@�C��

CModel CEnemy3::sModel;

//�f�t�H���g�R���X�g���N�^
CEnemy3::CEnemy3()
	: CCharacter3(1)
	, mCollider(this,&mMatrix,CVector(0.0f,0.0f,0.0f),0.4f)
{
	//���f���������Ƃ��͓ǂݍ���
	if (sModel.Triangles().size() == 0)
	{
		sModel.Load(OBJ, MTL);
	}
	//���f���̃|�C���^�ݒ�
	mpModel = &sModel;
}

//CEnemy(�ʒu,��],�g�k)
CEnemy3::CEnemy3(const CVector& position
	, const CVector& rotation, const CVector& scale)
	: CEnemy3() ///�f�t�H���g�R���X�g���N�^�����s����
{
	//�ʒu,��],�g�k��ݒ肷��
	mPosition = position; //�ʒu�̐ݒ�
	mRotation = rotation; //��]�̐ݒ�
	mScale = scale; //�g�k��ݒ�
	CTransform::Update(); //�s��̍X�V
}

//�X�V����
void CEnemy3::Update()
{
}

//�Փˏ���
//Collision(�R���C�_1,�R���C�_2)
void CEnemy3::Collision(CCollider* m, CCollider* o)
{
	switch (o->Type())
	{
	case CCollider::EType::ESPHERE:
		if (CCollider::Collision(m, o)) {
			new CEffect(o->Parent()->Position(), 1.0f, 1.0f, "exp.tga", 4, 4, 2);
		}
		break;
	case CCollider::EType::ETRIANGLE:
		CVector adjust;
		if (CCollider::CollisionTriangleSphere(o, m, &adjust))
		{
			mPosition = mPosition + adjust;
		}
		break;
	}
}

void CEnemy3::Collision()
{
	mCollider.ChangePriority();
	CCollisionManager::Instance()->Collision(&mCollider, COLLISIONRANGE);
}