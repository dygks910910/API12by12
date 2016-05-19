#include "BlockType1.h"


CBlockType1::CBlockType1(const int &x, const int &y) :CBlock(x,y)
{
	for (int i = 0; i < getBlockNum(); i++)
	{
		CRectangle *temp = new CRectangle(x + ((i * 2) * 16), y, 16);
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
		CRectangle *temp = new CRectangle(getX() + ((i * 2) * 16), getY(), 16);
		temp->setColor(getColor());
		setRectArr(i, temp);
	}
}
