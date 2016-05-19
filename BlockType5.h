#pragma once
#include "Block.h"
class CBlockType5 :
	public CBlock
{
public:
	CBlockType5(const int &x, const int &y);
	virtual ~CBlockType5();
	virtual void render(HDC hdc);
	virtual void reBuild();

};

