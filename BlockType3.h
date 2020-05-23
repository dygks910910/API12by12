#pragma once
#include "Block.h"
class CBlockType3 :
	public CBlock
{
	//▨ㅁ
	//   ㅁ
public:
	CBlockType3(const int &x, const int &y);
	virtual ~CBlockType3();
	virtual void render(HDC hdc);
	virtual void reBuild();



	// CBlock을(를) 통해 상속됨
	virtual bool PasteBlock(int (*pCalcBoard)[12], int x, int y) override;

};

