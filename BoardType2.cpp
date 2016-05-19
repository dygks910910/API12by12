#include "BoardType2.h"


CBoardType2::CBoardType2(RECT &clientSize) :CBoard(clientSize)
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (i < 6 && j < 6)
				setBoard(i,j, new CRectangle((clientSize.right / 15 / 2) + (clientSize.right / 15 / 2 / 2 * (j * 2))
				, (clientSize.bottom / 15 / 2 / 2) + (clientSize.right / 15 / 2 / 2 * (i * 2)) + 10, clientSize.right / 15 / 2 / 2));
			else if (i >= 6)
			{
				setBoard(i,j, new CRectangle((clientSize.right / 15 / 2) + (clientSize.right / 15 / 2 / 2 * (j * 2))
					, (clientSize.bottom / 15 / 2 / 2) + (clientSize.right / 15 / 2 / 2 * (i * 2)) + 10, clientSize.right / 15 / 2 / 2));
			}
			else
				setBoard(i,j, nullptr);
		}
	}
}


CBoardType2::~CBoardType2()
{
}

void CBoardType2::render(HDC hdc)
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (getBoard1()[i][j] != nullptr)
				getBoard1()[i][j]->render(hdc);
		}
	}
}