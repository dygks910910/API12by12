#pragma once
#include "Block.h"
class CBlockType2 :
	public CBlock
{
public:
	CBlockType2(const int &x, const int &y);
	virtual ~CBlockType2();
	virtual void render(HDC hdc);
	virtual void reBuild();

};

