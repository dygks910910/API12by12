#include "BlockType6.h"


CBlockType6::CBlockType6(const int &x, const int &y) :CBlock(x,y)
{
	int idxtemp = 0;
	for (int i = 0; i < getBlockNum() / 2; i++)//3보다 클경우에만들어와야함.
	{
		CRectangle *temp = new CRectangle(x + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), y, CBlock::getClientRect()->right / 15 / 2 / 2);
		temp->setColor(getColor());
		setRectArr(i, temp);
		idxtemp = i;
	}
	for (int i = 1; i < getBlockNum() / 2; i++)
	{
		CRectangle *temp2 = new CRectangle(getRectArr()[idxtemp]->getX(), getRectArr()[idxtemp]->getY() - ((2 * CBlock::getClientRect()->right / 15 / 2 / 2)), CBlock::getClientRect()->right / 15 / 2 / 2);
		temp2->setColor(getColor());
		idxtemp++;
		setRectArr(idxtemp, temp2);
	}
	if (getBlockNum() == 4 || getBlockNum() == 5)
	{
		setBlockNum(3);
	}
	else if (getBlockNum() == 3)
	{
		setBlockNum(1);
	}
	else if (getBlockNum() == 6)
	{
		setBlockNum(5);
	}
}


CBlockType6::~CBlockType6()
{
}

void CBlockType6::render(HDC hdc)
{
	for (int i = 0; i < getBlockNum(); i++)
	{
		if (getRectArr()[i] != nullptr)
			getRectArr()[i]->render(hdc);
	}
}

void CBlockType6::reBuild()
{
	for (int i = 0; i < getBlockNum(); i++)
	{
		delete getRectArr()[i];
	}
	setBlockNum(rand() % 3 + 4);
	int idxtemp = 0;
	for (int i = 0; i < getBlockNum() / 2; i++)//3보다 클경우에만들어와야함.
	{
		CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY(), CBlock::getClientRect()->right / 15 / 2 / 2);
		temp->setColor(getColor());
		setRectArr(i, temp);
		idxtemp = i;
	}
	for (int i = 1; i < getBlockNum() / 2; i++)
	{
		CRectangle *temp2 = new CRectangle(getRectArr()[idxtemp]->getX(), getRectArr()[idxtemp]->getY() - ((2 * CBlock::getClientRect()->right / 15 / 2 / 2)), CBlock::getClientRect()->right / 15 / 2 / 2);
		temp2->setColor(getColor());
		idxtemp++;
		setRectArr(idxtemp, temp2);
	}
	if (getBlockNum() == 4 || getBlockNum() == 5)
	{
		setBlockNum(3);
	}
	else if (getBlockNum() == 3)
	{
		setBlockNum(1);
	}
	else if (getBlockNum() == 6)
	{
		setBlockNum(5);
	}
}

bool CBlockType6::PasteBlock(int(*pCalcBoard)[12], int x, int y)
{
	if ((x + getBlockNum() - 1) / 2 > 12)
		return false;
	if (y - (getBlockNum() - 1) / 2 > 12)
		return false;
	for (int i = 0; i <= (getBlockNum() - 1) / 2; i++)//x축검사.
	{
		if (pCalcBoard[x + i][y] != 0)
		{
			return false;
		}
	}
	for (int i = 0; i <= (getBlockNum() - 1) / 2; i++)//y축검사.
	{
		if (pCalcBoard[x + ((getBlockNum() - 1) / 2)][y - i] != 0)
		{
			return false;
		}
	}

	for (int i = 0; i <= (getBlockNum() - 1) / 2; i++)//x축검사.
	{
		if (pCalcBoard[x + i][y] == 0)
		{
			pCalcBoard[x + i][y] = 1;
		}
	}
	for (int i = 0; i <= (getBlockNum() - 1) / 2; i++)//y축검사.
	{
		if (pCalcBoard[x + ((getBlockNum() - 1) / 2)][y-i] == 0)
		{
			pCalcBoard[x + ((getBlockNum() - 1) / 2)][y-i] = 1;
		}
	}
	return true;
}
