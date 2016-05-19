#pragma once
#include"BlockManager.h"
#include"BoardManager.h"
#include"Rectangle.h"
class CGameManager
{
public:
	CGameManager(RECT &clientsize);
	~CGameManager();
private:
	CBoardManager *m_BoardManager;
	CBlockManager *m_BlockManager;
	int m_iSelectBlockIdx;//idx가 0~2까지이기떄문에 초기화를 4로시켜줌.
	int m_iPrevX;//블럭이 안착되지 못할경우 돌아갈 좌표값.
	int m_iPrevY;//
public:
	static int cntMovingBlock;
public:
	void render(HDC hdc);
	void resetBlock();
	void changeBoardType();
	float LengthPts(const float &x1, const float &y1
		, const float &x2, const float &y2);
	BOOL inCircle(const int &x, const int &y);
	void movingBlock(const int &mx,const int &my);
	void CheckInBlock();
	BOOL inCircle(const int &x, const int &y, const int &mx, const int &my);
	BOOL checkInBlock(CRectangle*(*board)[12], CBlock **block, const int &y);
	void checkBlockColor();
};

