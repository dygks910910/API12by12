#include "GameManager.h"

int CGameManager::cntMovingBlock = 0;
CGameManager::CGameManager(RECT &clientsize):
	m_iScore(0)
{
	m_BoardManager = new CBoardManager(clientsize);
	m_BlockManager = new CBlockManager(clientsize);
	m_iSelectBlockIdx = 4;
	m_iPrevX = 0;
	m_iPrevY = 0;
	for (int i = 0; i < 12; ++i)
	{
		for (int j = 0; j < 12; ++j)//0이면 블록이 없는곳.1이면 있는곳.
			m_chArrBoardCalculator[i][j] = 0;
	}
}


CGameManager::~CGameManager()
{
	delete m_BoardManager;
	delete m_BlockManager;
}

void CGameManager::render(HDC hdc)
{
	m_BoardManager->render(hdc);
	m_BlockManager->render(hdc);
	RenderArrBoardCalcurator(hdc);
	renderScore(hdc);
}

void CGameManager::renderScore(HDC hdc)
{
	
	RECT scoreRt{ 300, 100, 600, 200 };
	std::string strScore = getScoreStr();
	DrawText(hdc, strScore.c_str(), strScore.size(), &scoreRt, DT_CENTER);
}

void CGameManager::RenderArrBoardCalcurator(HDC hdc)
{
	RECT textArea;
	
	for (int y = 0; y < 12; ++y)
	{
		for (int x = 0; x < 12; ++x)
		{
			textArea.left = 500 + x * 10;
			textArea.top = 50 + y * 20;
			textArea.right = textArea.left + 10;
			textArea.bottom = textArea.top + 20;

			char a[2];
			itoa(m_chArrBoardCalculator[x][y], a, 10);
			DrawText(hdc, a, -1, &textArea, DT_CENTER);

		}
	}
}


void CGameManager::resetBlock()
{
	m_BlockManager->resetBlock();
}

void CGameManager::changeBoardType()
{
	m_BoardManager->setBoardType(m_BoardManager->getBoardType() + 1);
	if (m_BoardManager->getBoardType() > BOARD_TYPE::BOARD_TYPE3)
	{
		m_BoardManager->setBoardType(BOARD_TYPE::BOARD_TYPE1);
	}
	m_BoardManager->reCreateBoard();
}


float CGameManager::LengthPts(const float &x1, const float &y1
	, const float &x2, const float &y2)
{
	return (sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1)));
}

BOOL CGameManager::inCircle(const int &x, const int &y)
{

	int tempi, tempj = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (m_BlockManager->getBlockArr()[i] != nullptr)
				if (m_BlockManager->getBlockArr()[i]->getRectArr()[j] != nullptr)
					if (LengthPts(m_BlockManager->getBlockArr()[i]->getRectArr()[j]->getX(), m_BlockManager->getBlockArr()[i]->getRectArr()[j]->getY(), x, y) < CBlock::getClientRect()->right / 15 / 2 / 2)
					{
						m_iSelectBlockIdx = i;
						if (m_BlockManager->getBlockArr()[m_iSelectBlockIdx] != nullptr)
						{
							m_iPrevX = m_BlockManager->getBlockArr()[m_iSelectBlockIdx]->getX();
							m_iPrevY = m_BlockManager->getBlockArr()[m_iSelectBlockIdx]->getY();
						}
						m_BlockManager->getBlockArr()[i]->getRectArr()[j]->setCheckSelect(true);
						return true;
						break;
					}
		}
	}
	return false;
}

BOOL CGameManager::inCircle(const int &x, const int &y, const int &mx, const int &my)
{

	if (LengthPts(mx, my, x, y) < CBlock::getClientRect()->right / 15 / 2 / 2)
	{

		return true;
	}
	return false;
}

void CGameManager::movingBlock(const int &mx, const int &my)
{
	if (m_iSelectBlockIdx != 4)
	{
		m_BlockManager->moveBlock(m_iSelectBlockIdx, mx, my);
	}


}

void CGameManager::CheckInBlock()
{
	BOOL check = false;
	int cntBlock = 0;//색입힌 블럭갯수카운트.
	if (m_iSelectBlockIdx != 4)
	{
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				if (m_BoardManager->getBoard()->getBoard1()[i][j] != nullptr)
				{
					if (m_BlockManager->getBlockArr()[m_iSelectBlockIdx] != nullptr
						&& m_BoardManager->getBoard()->getBoard1()[i][j] != nullptr)
						for (int k = 0; k < m_BlockManager->getBlockArr()[m_iSelectBlockIdx]->getBlockNum() + 1; k++)
						{
							if (m_BlockManager->getBlockArr()[m_iSelectBlockIdx]->getRectArr()[k] != nullptr)
								if (inCircle(m_BoardManager->getBoard()->getBoard1()[i][j]->getX()//보드좌표와 블럭좌표를 비교후 같은자리에 색입히기
									, m_BoardManager->getBoard()->getBoard1()[i][j]->getY()
									, m_BlockManager->getBlockArr()[m_iSelectBlockIdx]->getRectArr()[k]->getX()
									, m_BlockManager->getBlockArr()[m_iSelectBlockIdx]->getRectArr()[k]->getY()))
								{
									if (m_BoardManager->getBoard()->getBoard1()[i][j]->getCheckSelect() == false) // false면 색붙이고 아니면 말고.
									{
										cntBlock++;
										if (m_BlockManager->getBlockArr()[m_iSelectBlockIdx]->getColor() != NULL)
										{
											m_BoardManager->getBoard()->getBoard1()[i][j]->setColor(m_BlockManager->getBlockArr()[m_iSelectBlockIdx]->getColor());
										}
									}
								}
						}
				}
			}
		}
		if (cntBlock == m_BlockManager->getBlockArr()[m_iSelectBlockIdx]->getBlockNum())
		{
			m_BlockManager->setCntBlock(m_BlockManager->getCntBlock() - 1);
			delete m_BlockManager->getBlockArr()[m_iSelectBlockIdx];
			m_BlockManager->setBlockArr(m_iSelectBlockIdx, nullptr);
			m_iSelectBlockIdx = 4;
			cntMovingBlock++;
		}
		else
		{
			movingBlock(m_iPrevX, m_iPrevY);
		}

	}

}
void CGameManager::checkBlockColor()
{
	int itempX = 0;
	int itempY = 0;
	if (m_BoardManager->getBoardType() == BOARD_TYPE::BOARD_TYPE1)
	{
		itempX = 0;
		itempY = 0;
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				if (m_BoardManager->getBoard()->getBoard1()[i][j] != nullptr)
				{
					if (m_BoardManager->getBoard()->getBoard1()[i][j]->getColor() != RGB(255, 255, 255))
					{
						itempX++;
						if (itempX >= 12)
						{
							for (int k = 0; k < 12; k++)
							{
								m_BoardManager->getBoard()->getBoard1()[i][k]->setColor(RGB(255, 255, 255));
								m_chArrBoardCalculator[k][i] = 0;
								m_iScore += 1;
							}
						}
					}
				}

			}
			itempX = 0;

		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				if (m_BoardManager->getBoard()->getBoard1()[j][i] != nullptr)
				{
					if (m_BoardManager->getBoard()->getBoard1()[j][i]->getColor() != RGB(255, 255, 255))
					{
						itempY++;
						if (itempY >= 12)
						{
							for (int k = 0; k < 12; k++)
							{
								m_BoardManager->getBoard()->getBoard1()[k][i]->setColor(RGB(255, 255, 255));
								m_chArrBoardCalculator[i][k] = 0;
								m_iScore += 1;
							}
						}
					}
				}

			}
			itempY = 0;

		}
	}
	else if (m_BoardManager->getBoardType() == BOARD_TYPE::BOARD_TYPE2)
	{
		itempX = 0;
		itempY = 0;
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				if (m_BoardManager->getBoard()->getBoard1()[i][j] != nullptr)
				{
					if (m_BoardManager->getBoard()->getBoard1()[i][j]->getColor() != RGB(255, 255, 255))
					{
						itempX++;
						if (i < 6 && itempX >= 6)
						{
							for (int k = 0; k < 6; k++)
							{
								m_BoardManager->getBoard()->getBoard1()[i][k]->setColor(RGB(255, 255, 255));
							}
						}
						if (itempX >= 12)
						{
							for (int k = 0; k < 12; k++)
							{
								m_BoardManager->getBoard()->getBoard1()[i][k]->setColor(RGB(255, 255, 255));
							}
						}
					}
				}

			}
			itempX = 0;

		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				if (m_BoardManager->getBoard()->getBoard1()[j][i] != nullptr)
				{
					if (m_BoardManager->getBoard()->getBoard1()[j][i]->getColor() != RGB(255, 255, 255))
					{
						itempY++;
						if (i > 6 && itempY >= 6)
						{
							for (int k = 0; k < 12; k++)
							{
								m_BoardManager->getBoard()->getBoard1()[k][i]->setColor(RGB(255, 255, 255));
							}
						}
						if (itempY >= 12)
						{
							for (int k = 0; k < 12; k++)
							{
								m_BoardManager->getBoard()->getBoard1()[k][i]->setColor(RGB(255, 255, 255));
							}
						}
					}
				}

			}
			itempY = 0;

		}
	}
	else if (m_BoardManager->getBoardType() == BOARD_TYPE::BOARD_TYPE3)
	{
		itempX = 0;
		itempY = 0;
	}

	if (cntMovingBlock > 100)
	{
		PostQuitMessage(0);
	}
}

bool CGameManager::WriteCalcArr(int x, int y)
{
	if (m_iSelectBlockIdx == 4)
		return false;
	CBlock* selectedBlock = m_BlockManager->getBlockArr()[m_iSelectBlockIdx];
	if (selectedBlock == nullptr)
	{
		//movingBlock(m_iPrevX, m_iPrevY);
		return false;
	}
	int iBoardX = -1;
	int iBoardY = -1;

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (m_BoardManager->getBoard()->getBoard1()[i][j] != nullptr)
			{
				if (m_BlockManager->getBlockArr()[m_iSelectBlockIdx] != nullptr
					&& m_BoardManager->getBoard()->getBoard1()[i][j] != nullptr)
					for (int k = 0; k < m_BlockManager->getBlockArr()[m_iSelectBlockIdx]->getBlockNum() + 1; k++)
					{
						if (m_BlockManager->getBlockArr()[m_iSelectBlockIdx]->getRectArr()[k] != nullptr)
							if (inCircle(m_BoardManager->getBoard()->getBoard1()[i][j]->getX()//보드좌표와 블럭좌표를 비교후 같은자리에 색입히기
								, m_BoardManager->getBoard()->getBoard1()[i][j]->getY()
								, x
								, y))
							{
								iBoardY = i;
								iBoardX = j; 

							}
					}
			}
		}
	}
	if (iBoardX == -1 && iBoardY == -1)
		return false;
	return selectedBlock->PasteBlock(m_chArrBoardCalculator, iBoardX, iBoardY);
	
}

void CGameManager::returnBlock()
{
	movingBlock(m_iPrevX, m_iPrevY);
}

std::string CGameManager::getScoreStr()
{
	char tmp[10];
	itoa(m_iScore, tmp, 10);
	char scoreTxt[20] = "Score : ";
	strcat(scoreTxt, tmp);
	std::string rv = scoreTxt;
	return rv;
}
