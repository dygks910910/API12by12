#pragma once
#include "Block.h"
class CBlockType7 :
	public CBlock
{
public:
	CBlockType7(const int &x, const int &y);
	virtual ~CBlockType7();
	virtual void render(HDC hdc);
	virtual void reBuild();

};

