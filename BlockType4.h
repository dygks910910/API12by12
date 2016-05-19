#pragma once
#include "Block.h"
class CBlockType4 :
	public CBlock
{
public:
	CBlockType4(const int &x, const int &y);
	virtual ~CBlockType4();
	virtual void render(HDC hdc);
	virtual void reBuild();


};

