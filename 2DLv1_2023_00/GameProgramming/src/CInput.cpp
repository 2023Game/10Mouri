#include "CInput.h"
#include <stdio.h>

CInput::CInput()
{
	printf("�C���X�^���X�����܂�܂���\n");
}

bool CInput::Key(char Key)
{
	return GetAsyncKeyState(Key) < 0;
}