#include "BlockType1.h"


CBlockType1::CBlockType1(const int &x, const int &y) :CBlock(x,y)
{
	
	for (int i = 0; i < getBlockNum(); i++)
	{
		CRectangle *temp = new CRectangle(x + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), y, CBlock::getClientRect()->right / 15 / 2 / 2);
		temp->setColor(getColor());
		setRectArr(i, temp);
		
	}
}


CBlockType1::~CBlockType1()
{
}
void CBlockType1::render(HDC hdc)
{
	for (int i = 0; i < getBlockNum(); i++)
	{
		getRectArr()[i]->render(hdc);
	}
}

void CBlockType1::reBuild() 
{
	for (int i = 0; i < getBlockNum(); i++)
	{
		delete getRectArr()[i];
	}
	setBlockNum(rand() % 3 + 4);
	for (int i = 0; i < getBlockNum(); i++)
	{
		CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY(), CBlock::getClientRect()->right / 15 / 2 / 2);
		temp->setColor(getColor());
		setRectArr(i, temp);
	}
}

bool CBlockType1::PasteBlock(int(*pCalcBoard)[12], int x, int y)
{
	//12x12
	if (x + getBlockNum() -1> 12)
		return false;
	//붙여넣기 가능한지 체크.
	for (int i = 0; i < getBlockNum()-1; ++i)
	{
		if (pCalcBoard[x + i][y] != 0)
			return false;
	}
	for (int i = 0; i < getBlockNum(); ++i)
	{
		if (pCalcBoard[x + i][y] == 0)
			pCalcBoard[x+i][y] = 1;
	}
	return true;
}
