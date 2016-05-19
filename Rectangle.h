#pragma once
#include<Windows.h>

class CRectangle
{
public:
	CRectangle(const int &x,const int &y,const int &Width);
	~CRectangle();
private:
	int m_iX;
	int m_iY;
	int m_iWidth;
	COLORREF m_color;
	BOOL m_bCheckSelect;
public://setter
	void setWidth(const int &width){ m_iWidth = width; }
	void setX(const int &x){ m_iX = x; }
	void setY(const int &y){ m_iY = y; }
	void setColor(const COLORREF color){ m_color = color; }
	void setCheckSelect(const BOOL b){ m_bCheckSelect = b; }

	//getter
	int getWidth(){ return m_iWidth; }
	int getX(){ return m_iX; }
	int getY(){ return m_iY; }
	COLORREF getColor(){ return m_color; }
	BOOL getCheckSelect(){ return m_bCheckSelect; }
public:
	void render(HDC hdc);
	
};

