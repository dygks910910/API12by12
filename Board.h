#pragma once
#include"Rectangle.h"
#include"enum.h"
class CBoard
{
public:
	CBoard(RECT &clientSize) :m_clientSize(clientSize){};
	virtual ~CBoard()
	{
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				delete m_BoardType1[i][j];
			}
		}
	};
private:
	CRectangle *m_BoardType1[12][12];
	RECT m_clientSize;
public://getter
	CRectangle* (*getBoard1(void))[12]{ return m_BoardType1; };
		//setter
	void setBoard(const int &y,const int &x, CRectangle* add){ m_BoardType1[y][x] = add; }
public:
	virtual void render(HDC hdc)PURE;


};

