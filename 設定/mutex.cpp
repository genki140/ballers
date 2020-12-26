#include "stdafx.h"

#include <windows.h>

bool mutexcheck()
{
	HANDLE hMutex;
	hMutex = OpenMutex(MUTEX_ALL_ACCESS, false, "BallerMutex");
	if( hMutex != 0 )
	{
		CloseHandle(hMutex);
		return false;
	}
	hMutex = CreateMutex( NULL, true, "BallerMutex");
	return true;
}
