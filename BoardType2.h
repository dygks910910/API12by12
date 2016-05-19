#pragma once
#include "Board.h"
class CBoardType2 :
	public CBoard
{
public:
	CBoardType2(RECT &clientSize);
	virtual ~CBoardType2();
	virtual void render(HDC hdc);
};

