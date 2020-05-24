#pragma once
#include"BlockManager.h"
#include"BoardManager.h"
#include"Rectangle.h"
#include<string>
class CGameManager
{
public:
	CGameManager(RECT &clientsize);
	~CGameManager();
private:
	CBoardManager *m_BoardManager;
	CBlockManager *m_BlockManager;
	int m_chArrBoardCalculator[12][12];//0�̸� ����� �ִ°� �ƴϸ� ���°�.
	int m_iSelectBlockIdx;//idx�� 0~2�����̱⋚���� �ʱ�ȭ�� 4�ν�����.
	int m_iPrevX;//���� �������� ���Ұ�� ���ư� ��ǥ��.
	int m_iPrevY;//
	int m_iScore;
public:
	static int cntMovingBlock;
public:
	void render(HDC hdc);
	void renderScore(HDC hdc);
	void RenderArrBoardCalcurator(HDC hdc);
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
	bool WriteCalcArr(int x, int y);
	void returnBlock();
	int getScore() { return m_iScore; }
	std::string getScoreStr();
};

