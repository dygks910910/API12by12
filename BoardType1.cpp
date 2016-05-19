#include "BoardType1.h"


CBoardType1::CBoardType1(RECT &clientsize) :CBoard(clientsize)
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			setBoard(i,j, new CRectangle((clientsize.right / 15 / 2) + (clientsize.right / 15 / 2 / 2 * (j * 2))
				, (clientsize.bottom / 15 / 2 / 2) + (clientsize.right / 15 / 2 / 2 * (i * 2)) + 10, clientsize.right / 15 / 2 / 2));
		}
	}
}


CBoardType1::~CBoardType1()
{
}

void CBoardType1::render(HDC hdc)
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			getBoard1()[i][j]->render(hdc);
		}
	}
}