#pragma once
#include"Board.h"
#include"BoardType1.h"
#include"BoardType2.h"
#include"BoardType3.h"

class CBoardManager
{
public:
	CBoardManager(RECT &clientSIze);
	~CBoardManager();
private:
	CBoard *m_pBoard;
	int m_iBoardType;
	RECT m_clientSize;
public:
	void render(HDC hdc);
public://getter
	CBoard* getBoard(){ return m_pBoard; };
	int getBoardType(){ return m_iBoardType; }
	//setter
	void setBoardType(const int &type);
	void reCreateBoard();
};

