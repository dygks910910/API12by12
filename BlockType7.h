#pragma once
#include "Block.h"
class CBlockType7 :
	public CBlock
{
public:
	/*
	�ɤ�
	����
	*/
	CBlockType7(const int &x, const int &y);
	virtual ~CBlockType7();
	virtual void render(HDC hdc);
	virtual void reBuild();


	// CBlock��(��) ���� ��ӵ�
	virtual bool PasteBlock(int (*pCalcBoard)[12], int x, int y) override;

};

