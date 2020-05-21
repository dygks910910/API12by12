#include "BlockManager.h"


CBlockManager::CBlockManager(const RECT &clientsize) :m_clientSize(clientsize)
{
	CBlock::setClientRect(&m_clientSize);
	srand(time(NULL));
	for (int i = 0; i < 3; i++)
	{
		m_pBlockArr[i] = nullptr;
	}
	int rand1, rand2, rand3 = 0;
	rand1 = rand() % 7;
	rand2 = rand() % 7;
	rand3 = rand() % 7;
	switch (rand1)
	{
	case BLOCK_TYPE::BLOCK_TYPE1:
		m_pBlockArr[0] = new CBlockType1(10, clientsize.bottom);
		break;
	case BLOCK_TYPE::BLOCK_TYPE2:
		m_pBlockArr[0] = new CBlockType2(10, clientsize.bottom);
		break;
	case BLOCK_TYPE::BLOCK_TYPE3:
		m_pBlockArr[0] = new CBlockType3(10, clientsize.bottom);
		if (m_pBlockArr[0]->getBlockNum() < 3)
		{
			m_pBlockArr[0]->reBuild();
		}
		break;
	case BLOCK_TYPE::BLOCK_TYPE4:
		m_pBlockArr[0] = new CBlockType4(10, clientsize.bottom);
		if (m_pBlockArr[0]->getBlockNum() < 3)
		{
			m_pBlockArr[0]->reBuild();
		}
		break;
	case BLOCK_TYPE::BLOCK_TYPE5:
		m_pBlockArr[0] = new CBlockType5(10, clientsize.bottom);
		if (m_pBlockArr[0]->getBlockNum() < 3)
		{
			m_pBlockArr[0]->reBuild();
		}break;
	case BLOCK_TYPE::BLOCK_TYPE6:
		m_pBlockArr[0] = new CBlockType6(10, clientsize.bottom);
		if (m_pBlockArr[0]->getBlockNum() < 3)
		{
			m_pBlockArr[0]->reBuild();
		}break;
	case BLOCK_TYPE::BLOCK_TYPE7:
		m_pBlockArr[0] = new CBlockType7(10, clientsize.bottom);
		break;
	}
	switch (rand2)
	{
	case BLOCK_TYPE::BLOCK_TYPE1:
		m_pBlockArr[1] = new CBlockType1(clientsize.right / 3, clientsize.bottom);
		break;
	case BLOCK_TYPE::BLOCK_TYPE2:
		m_pBlockArr[1] = new CBlockType2(clientsize.right / 3, clientsize.bottom);
		break;
	case BLOCK_TYPE::BLOCK_TYPE3:
		m_pBlockArr[1] = new CBlockType3(clientsize.right / 3, clientsize.bottom);
		if (m_pBlockArr[1]->getBlockNum() < 3)
		{
			m_pBlockArr[1]->reBuild();
		}break;
	case BLOCK_TYPE::BLOCK_TYPE4:
		m_pBlockArr[1] = new CBlockType4(clientsize.right / 3, clientsize.bottom);
		if (m_pBlockArr[1]->getBlockNum() < 3)
		{
			m_pBlockArr[1]->reBuild();
		}break;
	case BLOCK_TYPE::BLOCK_TYPE5:
		m_pBlockArr[1] = new CBlockType5(clientsize.right / 3, clientsize.bottom);
		if (m_pBlockArr[1]->getBlockNum() < 3)
		{
			m_pBlockArr[1]->reBuild();
		}break;
	case BLOCK_TYPE::BLOCK_TYPE6:
		m_pBlockArr[1] = new CBlockType6(clientsize.right / 3, clientsize.bottom);
		if (m_pBlockArr[1]->getBlockNum() < 3)
		{
			m_pBlockArr[1]->reBuild();
		}break;
	case BLOCK_TYPE::BLOCK_TYPE7:
		m_pBlockArr[1] = new CBlockType7(clientsize.right / 3, clientsize.bottom);
		break;
	}
	switch (rand3)
	{
	case BLOCK_TYPE::BLOCK_TYPE1:
		m_pBlockArr[2] = new CBlockType1(clientsize.right / 3 * 2, clientsize.bottom);
		break;
	case BLOCK_TYPE::BLOCK_TYPE2:
		m_pBlockArr[2] = new CBlockType2(clientsize.right / 3 * 2, clientsize.bottom);
		break;
	case BLOCK_TYPE::BLOCK_TYPE3:
		m_pBlockArr[2] = new CBlockType3(clientsize.right / 3 * 2, clientsize.bottom);
		if (m_pBlockArr[2]->getBlockNum() < 3)
		{
			m_pBlockArr[2]->reBuild();
		}break;
	case BLOCK_TYPE::BLOCK_TYPE4:
		m_pBlockArr[2] = new CBlockType4(clientsize.right / 3 * 2, clientsize.bottom);
		if (m_pBlockArr[2]->getBlockNum() < 3)
		{
			m_pBlockArr[2]->reBuild();
		}break;
	case BLOCK_TYPE::BLOCK_TYPE5:
		m_pBlockArr[2] = new CBlockType5(clientsize.right / 3 * 2, clientsize.bottom);
		if (m_pBlockArr[2]->getBlockNum() < 3)
		{
			m_pBlockArr[2]->reBuild();
		}break;
	case BLOCK_TYPE::BLOCK_TYPE6:
		m_pBlockArr[2] = new CBlockType6(clientsize.right / 3 * 2, clientsize.bottom);
		if (m_pBlockArr[2]->getBlockNum() < 3)
		{
			m_pBlockArr[2]->reBuild();
		}break;
	case BLOCK_TYPE::BLOCK_TYPE7:
		m_pBlockArr[2] = new CBlockType7(clientsize.right / 3 * 2, clientsize.bottom);
		break;
	}
	m_iCntBlock = 3;
}


CBlockManager::~CBlockManager()
{
	for (int i = 0; i < 3; i++)
	{
		if (m_pBlockArr[i] != nullptr)
			delete m_pBlockArr[i];
	}
}

void CBlockManager::render(HDC hdc)
{
	if (m_iCntBlock == 0)
	{
		resetBlock();
		m_iCntBlock = 3;
	}
	for (int i = 0; i < 3; i++)
	{
		if (m_pBlockArr[i] != nullptr)
			m_pBlockArr[i]->render(hdc);
	}
}
void CBlockManager::resetBlock()
{
	for (int i = 0; i < 3; i++)
	{
		delete m_pBlockArr[i];
	}
	srand(time(NULL));
	for (int i = 0; i < 3; i++)
	{
		m_pBlockArr[i] = nullptr;
	}
	int rand1, rand2, rand3 = 0;
	rand1 = rand() % 7;
	rand2 = rand() % 7;
	rand3 = rand() % 7;
	switch (rand1)
	{
	case BLOCK_TYPE::BLOCK_TYPE1:
		m_pBlockArr[0] = new CBlockType1(10, m_clientSize.bottom);
		break;
	case BLOCK_TYPE::BLOCK_TYPE2:
		m_pBlockArr[0] = new CBlockType2(10, m_clientSize.bottom);
		break;
	case BLOCK_TYPE::BLOCK_TYPE3:
		m_pBlockArr[0] = new CBlockType3(10, m_clientSize.bottom);
		if (m_pBlockArr[0]->getBlockNum() < 3)
		{
			m_pBlockArr[0]->reBuild();
		}
		break;
	case BLOCK_TYPE::BLOCK_TYPE4:
		m_pBlockArr[0] = new CBlockType4(10, m_clientSize.bottom);
		if (m_pBlockArr[0]->getBlockNum() < 3)
		{
			m_pBlockArr[0]->reBuild();
		}
		break;
	case BLOCK_TYPE::BLOCK_TYPE5:
		m_pBlockArr[0] = new CBlockType5(10, m_clientSize.bottom);
		if (m_pBlockArr[0]->getBlockNum() < 3)
		{
			m_pBlockArr[0]->reBuild();
		}break;
	case BLOCK_TYPE::BLOCK_TYPE6:
		m_pBlockArr[0] = new CBlockType6(10, m_clientSize.bottom);
		if (m_pBlockArr[0]->getBlockNum() < 3)
		{
			m_pBlockArr[0]->reBuild();
		}break;
	case BLOCK_TYPE::BLOCK_TYPE7:
		m_pBlockArr[0] = new CBlockType7(10, m_clientSize.bottom);
		break;
	}
	switch (rand2)
	{
	case BLOCK_TYPE::BLOCK_TYPE1:
		m_pBlockArr[1] = new CBlockType1(m_clientSize.right / 3, m_clientSize.bottom);
		break;
	case BLOCK_TYPE::BLOCK_TYPE2:
		m_pBlockArr[1] = new CBlockType2(m_clientSize.right / 3, m_clientSize.bottom);
		break;
	case BLOCK_TYPE::BLOCK_TYPE3:
		m_pBlockArr[1] = new CBlockType3(m_clientSize.right / 3, m_clientSize.bottom);
		if (m_pBlockArr[1]->getBlockNum() < 3)
		{
			m_pBlockArr[1]->reBuild();
		}break;
	case BLOCK_TYPE::BLOCK_TYPE4:
		m_pBlockArr[1] = new CBlockType4(m_clientSize.right / 3, m_clientSize.bottom);
		if (m_pBlockArr[1]->getBlockNum() < 3)
		{
			m_pBlockArr[1]->reBuild();
		}break;
	case BLOCK_TYPE::BLOCK_TYPE5:
		m_pBlockArr[1] = new CBlockType5(m_clientSize.right / 3, m_clientSize.bottom);
		if (m_pBlockArr[1]->getBlockNum() < 3)
		{
			m_pBlockArr[1]->reBuild();
		}break;
	case BLOCK_TYPE::BLOCK_TYPE6:
		m_pBlockArr[1] = new CBlockType6(m_clientSize.right / 3, m_clientSize.bottom);
		if (m_pBlockArr[1]->getBlockNum() < 3)
		{
			m_pBlockArr[1]->reBuild();
		}break;
	case BLOCK_TYPE::BLOCK_TYPE7:
		m_pBlockArr[1] = new CBlockType7(m_clientSize.right / 3, m_clientSize.bottom);
		break;
	}
	switch (rand3)
	{
	case BLOCK_TYPE::BLOCK_TYPE1:
		m_pBlockArr[2] = new CBlockType1(m_clientSize.right / 3 * 2, m_clientSize.bottom);
		break;
	case BLOCK_TYPE::BLOCK_TYPE2:
		m_pBlockArr[2] = new CBlockType2(m_clientSize.right / 3 * 2, m_clientSize.bottom);
		break;
	case BLOCK_TYPE::BLOCK_TYPE3:
		m_pBlockArr[2] = new CBlockType3(m_clientSize.right / 3 * 2, m_clientSize.bottom);
		if (m_pBlockArr[2]->getBlockNum() < 3)
		{
			m_pBlockArr[2]->reBuild();
		}break;
	case BLOCK_TYPE::BLOCK_TYPE4:
		m_pBlockArr[2] = new CBlockType4(m_clientSize.right / 3 * 2, m_clientSize.bottom);
		if (m_pBlockArr[2]->getBlockNum() < 3)
		{
			m_pBlockArr[2]->reBuild();
		}break;
	case BLOCK_TYPE::BLOCK_TYPE5:
		m_pBlockArr[2] = new CBlockType5(m_clientSize.right / 3 * 2, m_clientSize.bottom);
		if (m_pBlockArr[2]->getBlockNum() < 3)
		{
			m_pBlockArr[2]->reBuild();
		}break;
	case BLOCK_TYPE::BLOCK_TYPE6:
		m_pBlockArr[2] = new CBlockType6(m_clientSize.right / 3 * 2, m_clientSize.bottom);
		if (m_pBlockArr[2]->getBlockNum() < 3)
		{
			m_pBlockArr[2]->reBuild();
		}break;
	case BLOCK_TYPE::BLOCK_TYPE7:
		m_pBlockArr[2] = new CBlockType7(m_clientSize.right / 3 * 2, m_clientSize.bottom);
		break;
	}
}

void CBlockManager::moveBlock(const int &idxforBlockNum, const int &x, const int &y)
{

	int iDeltaX = x - m_pBlockArr[idxforBlockNum]->getRectArr()[0]->getX();

	int iDeltaY = y- m_pBlockArr[idxforBlockNum]->getRectArr()[0]->getY();

	for (int i = 0; i < 20; i++)
	{
		if (m_pBlockArr[idxforBlockNum]->getRectArr()[i] != nullptr)
		{
			m_pBlockArr[idxforBlockNum]->getRectArr()[i]->setX(m_pBlockArr[idxforBlockNum]->getRectArr()[i]->getX() + iDeltaX);
			m_pBlockArr[idxforBlockNum]->getRectArr()[i]->setY(m_pBlockArr[idxforBlockNum]->getRectArr()[i]->getY() + iDeltaY);

		}
		
	}
}
