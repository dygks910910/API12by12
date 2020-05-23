#include "BlockType7.h"


CBlockType7::CBlockType7(const int &x, const int &y) :CBlock(x, y)
{
	int idxtemp = 0;
	//if (getBlockNum() == 2 || getBlockNum() == 3 || getBlockNum() == 4)//2일경우 2x2 3일경우 3x3 4일경우 4x4
	switch (getBlockNum())
	{
	case 1:
		for (int i = 0; i < 2; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY(), CBlock::getClientRect()->right / 15 / 2 / 2);
			temp->setColor(getColor());
			setRectArr(i, temp);
			idxtemp = i;
		}
		for (int i = 0; i < 2; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY() + (CBlock::getClientRect()->right / 15 / 2 / 2 * 2), CBlock::getClientRect()->right / 15 / 2 / 2);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);
		}
		setBlockNum(4);
		break;
	case 2:
		for (int i = 0; i < 2; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY(), CBlock::getClientRect()->right / 15 / 2 / 2);
			temp->setColor(getColor());
			setRectArr(i, temp);
			idxtemp = i;
		}
		for (int i = 0; i < 2; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY() + (CBlock::getClientRect()->right / 15 / 2 / 2 * 2), CBlock::getClientRect()->right / 15 / 2 / 2);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);
		}
		setBlockNum(4);

		break;
	case 3:
		for (int i = 0; i < 3; i++)
		{

			CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY(), CBlock::getClientRect()->right / 15 / 2 / 2);
			temp->setColor(getColor());
			setRectArr(i, temp);
			idxtemp = i;
		}
		for (int i = 0; i < 3; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY() + CBlock::getClientRect()->right / 15 / 2 / 2 * 2, CBlock::getClientRect()->right / 15 / 2 / 2);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);

		}
		for (int i = 0; i < 3; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY() + (CBlock::getClientRect()->right / 15 / 2 / 2 * 2) * 2, CBlock::getClientRect()->right / 15 / 2 / 2);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);

		}
		setBlockNum(9);

		break;
	case 4:
		for (int i = 0; i < 4; i++)
		{

			CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY(), CBlock::getClientRect()->right / 15 / 2 / 2);
			temp->setColor(getColor());
			setRectArr(i, temp);
			idxtemp = i;
		}
		for (int i = 0; i < 4; i++)
		{
			CRectangle *temp = new CRectangle(x + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY() + CBlock::getClientRect()->right / 15 / 2 / 2 * 2, CBlock::getClientRect()->right / 15 / 2 / 2);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);

		}
		for (int i = 0; i < 4; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY() + (CBlock::getClientRect()->right / 15 / 2 / 2 * 2) * 2, CBlock::getClientRect()->right / 15 / 2 / 2);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);

		}
		for (int i = 0; i < 4; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY() + (CBlock::getClientRect()->right / 15 / 2 / 2 * 2) * 3, CBlock::getClientRect()->right / 15 / 2 / 2);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);

		}
		setBlockNum(16);

		break;
	case 5:
	{
		for (int i = 0; i < 4; i++)
		{

			CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY(), CBlock::getClientRect()->right / 15 / 2 / 2);
			temp->setColor(getColor());
			setRectArr(i, temp);
			idxtemp = i;
		}
		for (int i = 0; i < 4; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY() + CBlock::getClientRect()->right / 15 / 2 / 2 * 2, CBlock::getClientRect()->right / 15 / 2 / 2);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);

		}
		for (int i = 0; i < 4; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY() + (CBlock::getClientRect()->right / 15 / 2 / 2 * 2) * 2, CBlock::getClientRect()->right / 15 / 2 / 2);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);

		}
		for (int i = 0; i < 4; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY() + (CBlock::getClientRect()->right / 15 / 2 / 2 * 2) * 3, CBlock::getClientRect()->right / 15 / 2 / 2);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);

		}
		setBlockNum(16);

	}	
	break;
	case 6:
		for (int i = 0; i < 2; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY(), CBlock::getClientRect()->right / 15 / 2 / 2);
			temp->setColor(getColor());
			setRectArr(i, temp);
			idxtemp = i;
		}
		for (int i = 0; i < 2; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY() + (CBlock::getClientRect()->right / 15 / 2 / 2 * 2), CBlock::getClientRect()->right / 15 / 2 / 2);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);
		}
		setBlockNum(4);
		break;
	}

}


CBlockType7::~CBlockType7()
{
}

void CBlockType7::render(HDC hdc)
{
	for (int i = 0; i < 20; i++)
	{
		if (getRectArr()[i] != nullptr)
			getRectArr()[i]->render(hdc);
	}
}

void CBlockType7::reBuild()
{
	int idxtemp = 0;
	for (int i = 0; i < MAX_ARR_IDX; i++)
	{
		if (getRectArr()[i] != nullptr)
		delete getRectArr()[i];
	}
	//if (getBlockNum() == 2 || getBlockNum() == 3 || getBlockNum() == 4)//2일경우 2x2 3일경우 3x3 4일경우 4x4
	switch (getBlockNum())
	{
	case 1:
		for (int i = 0; i < 2; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY(), CBlock::getClientRect()->right / 15 / 2 / 2);
			temp->setColor(getColor());
			setRectArr(i, temp);
			idxtemp = i;
		}
		for (int i = 0; i < 2; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY() + (CBlock::getClientRect()->right / 15 / 2 / 2 * 2), CBlock::getClientRect()->right / 15 / 2 / 2);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);
		}

		break;
	case 2:
		for (int i = 0; i < 2; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY(), CBlock::getClientRect()->right / 15 / 2 / 2);
			temp->setColor(getColor());
			setRectArr(i, temp);
			idxtemp = i;
		}
		for (int i = 0; i < 2; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY() + (CBlock::getClientRect()->right / 15 / 2 / 2 * 2), CBlock::getClientRect()->right / 15 / 2 / 2);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);
		}
		break;
	case 3:
		for (int i = 0; i < 3; i++)
		{

			CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY(), CBlock::getClientRect()->right / 15 / 2 / 2);
			temp->setColor(getColor());
			setRectArr(i, temp);
			idxtemp = i;
		}
		for (int i = 0; i < 3; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY() + CBlock::getClientRect()->right / 15 / 2 / 2 * 2, CBlock::getClientRect()->right / 15 / 2 / 2);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);

		}
		for (int i = 0; i < 3; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY() + (CBlock::getClientRect()->right / 15 / 2 / 2 * 2) * 2, CBlock::getClientRect()->right / 15 / 2 / 2);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);

		}
		break;
	case 4:
		for (int i = 0; i < 4; i++)
		{

			CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY(), CBlock::getClientRect()->right / 15 / 2 / 2);
			temp->setColor(getColor());
			setRectArr(i, temp);
			idxtemp = i;
		}
		for (int i = 0; i < 4; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY() + CBlock::getClientRect()->right / 15 / 2 / 2 * 2, CBlock::getClientRect()->right / 15 / 2 / 2);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);

		}
		for (int i = 0; i < 4; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY() + (CBlock::getClientRect()->right / 15 / 2 / 2 * 2) * 2, CBlock::getClientRect()->right / 15 / 2 / 2);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);

		}
		for (int i = 0; i < 4; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY() + (CBlock::getClientRect()->right / 15 / 2 / 2 * 2) * 3, CBlock::getClientRect()->right / 15 / 2 / 2);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);

		}

		break;
	case 5:
	{
		for (int i = 0; i < 4; i++)
		{

			CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY(), CBlock::getClientRect()->right / 15 / 2 / 2);
			temp->setColor(getColor());
			setRectArr(i, temp);
			idxtemp = i;
		}
		for (int i = 0; i < 4; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY() + CBlock::getClientRect()->right / 15 / 2 / 2 * 2, CBlock::getClientRect()->right / 15 / 2 / 2);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);

		}
		for (int i = 0; i < 4; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY() + (CBlock::getClientRect()->right / 15 / 2 / 2 * 2) * 2, CBlock::getClientRect()->right / 15 / 2 / 2);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);

		}
		for (int i = 0; i < 4; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY() + (CBlock::getClientRect()->right / 15 / 2 / 2 * 2) * 3, CBlock::getClientRect()->right / 15 / 2 / 2);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);

		}
	}
	break;
	case 6:
		for (int i = 0; i < 2; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY(), CBlock::getClientRect()->right / 15 / 2 / 2);
			temp->setColor(getColor());
			setRectArr(i, temp);
			idxtemp = i;
		}
		for (int i = 0; i < 2; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * CBlock::getClientRect()->right / 15 / 2 / 2), getY() + (CBlock::getClientRect()->right / 15 / 2 / 2 * 2), CBlock::getClientRect()->right / 15 / 2 / 2);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);
		}
	}
}
#include<cmath>
bool CBlockType7::PasteBlock(int (*pCalcBoard)[12], int x, int y)
{
	if (x +  sqrt(getBlockNum())-1 > 12)
		return false;
	if (y + sqrt(getBlockNum()) -1> 12)
		return false;

	for (int i = 0; i <= sqrt(getBlockNum())-1; i++)//x축검사.
	{
		for (int j = 0; j <= sqrt(getBlockNum())-1; j++)//y축검사.
		{
			if (pCalcBoard[x+j][y + i] != 0)
			{
				return false;
			}
		}
	}
	
	for (int i = 0; i <= sqrt(getBlockNum())-1; i++)//x축검사.
	{
		for (int j = 0; j <= sqrt(getBlockNum())-1; j++)//y축검사.
		{
			if (pCalcBoard[x + j][y + i] == 0)
			{
				pCalcBoard[x + j][y + i] = 1;
			}
		}
	}

	return true;
}
