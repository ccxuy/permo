#include "StdAfx.h"
#include "ProInfo.h"

CProInfo::CProInfo(void)
{
	last_system_time_ = 0;
	last_time_ = 0;
	cpu = 0;
	mem = 0.0;
	netup = 0.0;
	netdown = 0.0;
	bExit = TRUE;
	hIcon = NULL;
}

CProInfo::~CProInfo(void)
{
	if (hIcon)
	{
		DestroyIcon(hIcon);
	}
}
