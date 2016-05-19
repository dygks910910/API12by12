#pragma once
#include "Block.h"
class CBlockType1 :
	public CBlock
{
public:
	CBlockType1(const int &x, const int &y);
	virtual ~CBlockType1();
	virtual void render(HDC hdc);
	virtual void reBuild();
};

