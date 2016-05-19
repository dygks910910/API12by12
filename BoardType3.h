#pragma once
#include "Board.h"
class CBoardType3 :
	public CBoard
{
public:
	CBoardType3(RECT &clientSize);
	virtual ~CBoardType3();
	virtual void render(HDC hdc);
};

