#pragma once
#include "Block.h"
class CBlockType3 :
	public CBlock
{
	//�ɤ�
	//   ��
public:
	CBlockType3(const int &x, const int &y);
	virtual ~CBlockType3();
	virtual void render(HDC hdc);
	virtual void reBuild();



	// CBlock��(��) ���� ��ӵ�
	virtual bool PasteBlock(int (*pCalcBoard)[12], int x, int y) override;

};

