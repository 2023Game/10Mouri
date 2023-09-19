#include "CPlayer.h"
#include "CApplication.h"

void CPlayer::Update()
{
	if (mInput.Key(VK_SPACE))
	{
		CApplication::CharacterManager()->Add(
			new CBullet(X(), Y() + H() + 10.0f
				, 3.0f, 10.0f, 1396, 1420, 750, 592
				, CApplication::Texture()));
	}
	if (mInput.Key('A'))
	{
		float x = X() - 4.0f;
		X(x);
	}
	if (mInput.Key('D'))
	{
		float x = X() + 4.0f;
		X(x);
	}
}