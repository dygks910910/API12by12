#pragma once
#include"Block.h"
#include"BlockType1.h"
#include"BlockType2.h"
#include"BlockType3.h"
#include"BlockType4.h"
#include"BlockType5.h"
#include"BlockType6.h"
#include"BlockType7.h"
#include<time.h>
#include"enum.h"
#include<math.h>
class CBlockManager
{
public:
	CBlockManager(const RECT &clientsize);
	~CBlockManager();
private:
	RECT m_clientSize;
	int m_iCntBlock;
	CBlock *m_pBlockArr[3];
public://getter
	CBlock** getBlockArr(){ return m_pBlockArr; };
	int getCntBlock(){ return m_iCntBlock; }
	//setter
	void setCntBlock(const int &cnt){ m_iCntBlock = cnt; };
	void setBlockArr(int idx, CBlock* pblock){ m_pBlockArr[idx] = pblock; }
public:
	void render(HDC hdc);
	void resetBlock();
	void moveBlock(const int &idxforBlockNum,const int &x,const int &y);
	BOOL inCircle(const int &x, const int &y, const int &mx, const int &my);

};

