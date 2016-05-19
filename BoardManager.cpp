#include "BoardManager.h"


CBoardManager::CBoardManager(RECT &clientSIze)
{
	m_pBoard = new CBoardType1(clientSIze);
	m_iBoardType = BOARD_TYPE::BOARD_TYPE1;
	m_clientSize = clientSIze;
}



CBoardManager::~CBoardManager()
{
}

void CBoardManager::render(HDC hdc)
{
	m_pBoard->render(hdc);
}

void CBoardManager::setBoardType(const int &type)
{
	m_iBoardType = type;
	
}

void CBoardManager::reCreateBoard()
{
	delete m_pBoard;
	switch (m_iBoardType)
	{
	case BOARD_TYPE::BOARD_TYPE1:
		m_pBoard = new CBoardType1(m_clientSize);
		break;
	case BOARD_TYPE::BOARD_TYPE2:
		m_pBoard = new CBoardType2(m_clientSize);
		break;
	case BOARD_TYPE::BOARD_TYPE3:
		m_pBoard = new CBoardType3(m_clientSize);
		break;
	}
}
