#include "BlockType2.h"


CBlockType2::CBlockType2(const int &x, const int &y) :CBlock(x,y)
{
	for (int i = 0; i < getBlockNum(); i++)
	{
		CRectangle *temp = new CRectangle(x, y + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), CBlock::getClientRect()->right / 15 / 2 / 2);
		temp->setColor(getColor());
		setRectArr(i, temp);
	}
}


CBlockType2::~CBlockType2()
{

}

void CBlockType2::render(HDC hdc)
{
	for (int i = 0; i < getBlockNum(); i++)
	{
		getRectArr()[i]->render(hdc);
	}
}

void CBlockType2::reBuild()
{
	for (int i = 0; i < getBlockNum(); i++)
	{
		delete getRectArr()[i];
	}
	setBlockNum(rand() % 3 + 4);
	for (int i = 0; i < getBlockNum(); i++)
	{
		CRectangle *temp = new CRectangle(getX(), getY() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), CBlock::getClientRect()->right / 15 / 2 / 2);
		temp->setColor(getColor());
		setRectArr(i, temp);
	}
}