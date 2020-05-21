#include "BlockType4.h"


CBlockType4::CBlockType4(const int &x, const int &y) :CBlock(x, y)
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
		CRectangle *temp2 = new CRectangle(getRectArr()[0]->getX(), getRectArr()[0]->getY() + ((2 *i)* CBlock::getClientRect()->right / 15 / 2 / 2), CBlock::getClientRect()->right / 15 / 2 / 2);
		temp2->setColor(getColor());
		idxtemp++;
		setRectArr(idxtemp, temp2);
	}
	if (getBlockNum() == 4||getBlockNum() == 5 )
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


CBlockType4::~CBlockType4()
{
}

void CBlockType4::render(HDC hdc)
{
	for (int i = 0; i < getBlockNum(); i++)
	{
		if (getRectArr()[i] != nullptr)
		getRectArr()[i]->render(hdc);
	}
}

void CBlockType4::reBuild()
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
		CRectangle *temp2 = new CRectangle(getRectArr()[0]->getX(), getRectArr()[0]->getY() + ((2 * i) * CBlock::getClientRect()->right / 15 / 2 / 2), CBlock::getClientRect()->right / 15 / 2 / 2);
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