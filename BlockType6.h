#pragma once
#include "Block.h"
class CBlockType6 :
	public CBlock
{
public:
	CBlockType6(const int &x, const int &y);
	virtual ~CBlockType6();
	virtual void render(HDC hdc);
	virtual void reBuild();


};

