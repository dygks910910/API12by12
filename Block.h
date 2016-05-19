#pragma once
#include"Rectangle.h"
#include<time.h>
const int MAX_ARR_IDX = 20;
class CBlock
{
public:
	CBlock(const int &x, const int &y, const int &blocknum = rand()%6+1
		, const COLORREF color = RGB(rand() % 255, rand() % 255, rand() % 255)
)		:m_iX(x), m_iY(y), m_iBlockNum(blocknum), m_color(color)
	{
		for (int i = 0; i < MAX_ARR_IDX; i++)
		{
			m_pRectArr[i] = nullptr;
		}
		m_bCheckSelect = false;

	};
	virtual ~CBlock()
	{
		for (int i = 0; i < MAX_ARR_IDX; i++)
		{
			delete m_pRectArr[i];
		}
	};
private:
	CRectangle *m_pRectArr[MAX_ARR_IDX];
	int m_iX;//기준점X
	int m_iY;//기준점Y
	int m_iBlockNum;//블럭갯수1~6
	COLORREF m_color;
	BOOL m_bCheckSelect;
public://getter
	BOOL getCheckSelect(){ return m_bCheckSelect; };
	COLORREF getColor(){ return m_color; }
	CRectangle** getRectArr(){ return m_pRectArr; };
	int getX()const{ return m_iX; }
	int getY()const{ return m_iY; }
	int getBlockNum()const{ return m_iBlockNum; };
	//setter
	void setCheckSelect(const BOOL b){ m_bCheckSelect = b; };
	void setColor(const COLORREF color){ m_color = color; };
	void setRectArr(const int &index, CRectangle* prect){ m_pRectArr[index] = prect; };
	void setBlockNum(const int &num){ m_iBlockNum = num; };
	void setX(const int &x){ m_iX = x; };
	void setY(const int &y){ m_iY = y; };
public:
	virtual void render(HDC hdc)PURE;
	virtual void reBuild()PURE;//블럭이 3보다 작을때 리빌드용
};

