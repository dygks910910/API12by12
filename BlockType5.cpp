#include "BlockType5.h"


CBlockType5::CBlockType5(const int &x, const int &y) :CBlock(x,y)
{
	int idxtemp = 0;
	for (int i = 0; i < getBlockNum() / 2; i++)//3보다 클경우에만들어와야함.
	{
		CRectangle *temp = new CRectangle(x, y + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), CBlock::getClientRect()->right / 15 / 2 / 2);
		temp->setColor(getColor());
		setRectArr(i, temp);
		idxtemp = i;
	}
	for (int i = 1; i < getBlockNum() / 2; i++)
	{
		CRectangle *temp2 = new CRectangle(getRectArr()[idxtemp]->getX() + ((2  * CBlock::getClientRect()->right / 15 / 2 / 2)), getRectArr()[idxtemp]->getY(), CBlock::getClientRect()->right / 15 / 2 / 2);
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


CBlockType5::~CBlockType5()
{
}

void CBlockType5::render(HDC hdc)
{
	for (int i = 0; i < getBlockNum(); i++)
	{
		if (getRectArr()[i] != nullptr)
			getRectArr()[i]->render(hdc);
	}
}

void CBlockType5::reBuild()
{
	for (int i = 0; i < getBlockNum(); i++)
	{
		delete getRectArr()[i];
	}
	setBlockNum(rand() % 3 + 4);
	int idxtemp = 0;
	for (int i = 0; i < getBlockNum() / 2; i++)//3보다 클경우에만들어와야함.
	{
		CRectangle *temp = new CRectangle(getX(), getY() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), CBlock::getClientRect()->right / 15 / 2 / 2);
		temp->setColor(getColor());
		setRectArr(i, temp);
		idxtemp = i;
	}
	for (int i = 1; i < getBlockNum() / 2; i++)
	{
		CRectangle *temp2 = new CRectangle(getRectArr()[idxtemp]->getX() + ((2 * CBlock::getClientRect()->right / 15 / 2 / 2)), getRectArr()[idxtemp]->getY(), CBlock::getClientRect()->right / 15 / 2 / 2);
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