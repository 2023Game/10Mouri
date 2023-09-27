#include "CVector.h"
//Set(X座標,Y座標,Z座標)
void CVector::Set(float x, float y, float z)
{
	mX = x;
	mY = y;
	mZ = z;
}

float CVector::X() const
{
	return mX;
}

float CVector::Y() const
{
	return mY;
}

float CVector::Z() const
{
	return mZ;
}

CVector::CVector()
	:mX(0.0f)
	,mY(0.0f)
	,mZ(0.0f)
{}


CVector::CVector(float x, float y, float z)
	:mX(x)
	,mY(y)
	,mZ(z)
{}

//+演算子のオーバーロード
//CVector + CVectorの演算結果を返す
CVector CVector::operator+(const CVector& v)const
{
	return CVector(mX + v.mX, mY + v.mY, mZ + v.mZ);
}

//-演算子のオーバーロード
//CVector - CVectorの演算結果を返す
CVector CVector::operator-(const CVector& v)const
{
	return CVector(mX - v.mX, mY - v.mY, mZ - v.mZ);
}