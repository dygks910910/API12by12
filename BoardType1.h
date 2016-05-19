#pragma once
#include "Board.h"
class CBoardType1 :
	public CBoard
{
public:
	CBoardType1(RECT &clientsize);
	virtual ~CBoardType1();
	virtual void render(HDC hdc);
};

