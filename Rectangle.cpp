#include "Rectangle.h"


CRectangle::CRectangle(const int &x, const int &y, const int &Width)
: m_iX(x), m_iY(y), m_iWidth(Width)
{
	m_color = RGB(255, 255, 255);
	m_bCheckSelect = false;
}


CRectangle::~CRectangle()
{
}
void CRectangle::render(HDC hdc)
{
	HBRUSH mBrush, oldBrush;
	mBrush = CreateSolidBrush(m_color);
	oldBrush = (HBRUSH)SelectObject(hdc, mBrush);
	RoundRect(hdc, m_iX - m_iWidth, m_iY - m_iWidth, m_iX + m_iWidth, m_iY + m_iWidth,10,20);
	SelectObject(hdc, oldBrush);
	DeleteObject(mBrush);
}
