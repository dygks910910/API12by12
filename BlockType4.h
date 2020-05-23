#pragma once
#include "Block.h"
class CBlockType4 :
	public CBlock
{
	/*▨ㅁㅁ
	    ㅁ
	    ㅁ*/
public:
	CBlockType4(const int &x, const int &y);
	virtual ~CBlockType4();
	virtual void render(HDC hdc);
	virtual void reBuild();



	// CBlock을(를) 통해 상속됨
	virtual bool PasteBlock(int (*pCalcBoard)[12], int x, int y) override;

};

