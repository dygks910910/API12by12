#include "BoardType3.h"


CBoardType3::CBoardType3(RECT &clientSize) :CBoard(clientSize)
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (i >= 4 && i <= 7 && j >= 4 && j <= 7)
				setBoard(i,j , nullptr);
			else
				setBoard(i,j, new CRectangle((clientSize.right / 15 / 2) + (clientSize.right / 15 / 2 / 2 * (j * 2))
				, (clientSize.bottom / 15 / 2 / 2) + (clientSize.right / 15 / 2 / 2 * (i * 2)) + 10, clientSize.right / 15 / 2 / 2));
		}
	}
}


CBoardType3::~CBoardType3()
{
}

void CBoardType3::render(HDC hdc)
{

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (getBoard1()[i][j]!= nullptr)
				getBoard1()[i][j]->render(hdc);
		}
	}

}

