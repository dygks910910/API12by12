#include "BlockType7.h"


CBlockType7::CBlockType7(const int &x, const int &y) :CBlock(x, y)
{
	int idxtemp = 0;
	//if (getBlockNum() == 2 || getBlockNum() == 3 || getBlockNum() == 4)//2老版快 2x2 3老版快 3x3 4老版快 4x4
	switch (getBlockNum())
	{
	case 1:
		for (int i = 0; i < 2; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * 16), getY(), 16);
			temp->setColor(getColor());
			setRectArr(i, temp);
			idxtemp = i;
		}
		for (int i = 0; i < 2; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * 16), getY() + (16 * 2), 16);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);
		}
		setBlockNum(4);
		break;
	case 2:
		for (int i = 0; i < 2; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * 16), getY(), 16);
			temp->setColor(getColor());
			setRectArr(i, temp);
			idxtemp = i;
		}
		for (int i = 0; i < 2; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * 16), getY() + (16 * 2), 16);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);
		}
		setBlockNum(4);

		break;
	case 3:
		for (int i = 0; i < 3; i++)
		{

			CRectangle *temp = new CRectangle(getX() + ((i * 2) * 16), getY(), 16);
			temp->setColor(getColor());
			setRectArr(i, temp);
			idxtemp = i;
		}
		for (int i = 0; i < 3; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * 16), getY() + 16 * 2, 16);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);

		}
		for (int i = 0; i < 3; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * 16), getY() + (16 * 2) * 2, 16);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);

		}
		setBlockNum(9);

		break;
	case 4:
		for (int i = 0; i < 4; i++)
		{

			CRectangle *temp = new CRectangle(getX() + ((i * 2) * 16), getY(), 16);
			temp->setColor(getColor());
			setRectArr(i, temp);
			idxtemp = i;
		}
		for (int i = 0; i < 4; i++)
		{
			CRectangle *temp = new CRectangle(x + ((i * 2) * 16), getY() + 16 * 2, 16);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);

		}
		for (int i = 0; i < 4; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * 16), getY() + (16 * 2) * 2, 16);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);

		}
		for (int i = 0; i < 4; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * 16), getY() + (16 * 2) * 3, 16);
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

			CRectangle *temp = new CRectangle(getX() + ((i * 2) * 16), getY(), 16);
			temp->setColor(getColor());
			setRectArr(i, temp);
			idxtemp = i;
		}
		for (int i = 0; i < 4; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * 16), getY() + 16 * 2, 16);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);

		}
		for (int i = 0; i < 4; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * 16), getY() + (16 * 2) * 2, 16);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);

		}
		for (int i = 0; i < 4; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * 16), getY() + (16 * 2) * 3, 16);
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
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * 16), getY(), 16);
			temp->setColor(getColor());
			setRectArr(i, temp);
			idxtemp = i;
		}
		for (int i = 0; i < 2; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * 16), getY() + (16 * 2), 16);
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
	//if (getBlockNum() == 2 || getBlockNum() == 3 || getBlockNum() == 4)//2老版快 2x2 3老版快 3x3 4老版快 4x4
	switch (getBlockNum())
	{
	case 1:
		for (int i = 0; i < 2; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * 16), getY(), 16);
			temp->setColor(getColor());
			setRectArr(i, temp);
			idxtemp = i;
		}
		for (int i = 0; i < 2; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * 16), getY() + (16 * 2), 16);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);
		}

		break;
	case 2:
		for (int i = 0; i < 2; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * 16), getY(), 16);
			temp->setColor(getColor());
			setRectArr(i, temp);
			idxtemp = i;
		}
		for (int i = 0; i < 2; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * 16), getY() + (16 * 2), 16);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);
		}
		break;
	case 3:
		for (int i = 0; i < 3; i++)
		{

			CRectangle *temp = new CRectangle(getX() + ((i * 2) * 16), getY(), 16);
			temp->setColor(getColor());
			setRectArr(i, temp);
			idxtemp = i;
		}
		for (int i = 0; i < 3; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * 16), getY() + 16 * 2, 16);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);

		}
		for (int i = 0; i < 3; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * 16), getY() + (16 * 2) * 2, 16);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);

		}
		break;
	case 4:
		for (int i = 0; i < 4; i++)
		{

			CRectangle *temp = new CRectangle(getX() + ((i * 2) * 16), getY(), 16);
			temp->setColor(getColor());
			setRectArr(i, temp);
			idxtemp = i;
		}
		for (int i = 0; i < 4; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * 16), getY() + 16 * 2, 16);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);

		}
		for (int i = 0; i < 4; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * 16), getY() + (16 * 2) * 2, 16);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);

		}
		for (int i = 0; i < 4; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * 16), getY() + (16 * 2) * 3, 16);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);

		}

		break;
	case 5:
	{
		for (int i = 0; i < 4; i++)
		{

			CRectangle *temp = new CRectangle(getX() + ((i * 2) * 16), getY(), 16);
			temp->setColor(getColor());
			setRectArr(i, temp);
			idxtemp = i;
		}
		for (int i = 0; i < 4; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * 16), getY() + 16 * 2, 16);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);

		}
		for (int i = 0; i < 4; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * 16), getY() + (16 * 2) * 2, 16);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);

		}
		for (int i = 0; i < 4; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * 16), getY() + (16 * 2) * 3, 16);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);

		}
	}
	break;
	case 6:
		for (int i = 0; i < 2; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * 16), getY(), 16);
			temp->setColor(getColor());
			setRectArr(i, temp);
			idxtemp = i;
		}
		for (int i = 0; i < 2; i++)
		{
			CRectangle *temp = new CRectangle(getX() + ((i * 2) * 16), getY() + (16 * 2), 16);
			temp->setColor(getColor());
			idxtemp += 1;
			setRectArr(idxtemp, temp);
		}
	}
}