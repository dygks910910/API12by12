#include <windows.h>
#include"GameManager.h"
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPSTR lpszClass = "12x12";
PAINTSTRUCT ps;
HDC hdc;
RECT clientSize;
CGameManager *gameManager;
BOOL drag = false;
static int mx, my = 0;
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
	, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = (WNDPROC)WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, 0, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage) {
	case WM_CREATE:
		GetClientRect(hWnd, &clientSize);
		gameManager = new CGameManager(clientSize);
		SetTimer(hWnd, 1, 100000, nullptr);
		break;
	case WM_TIMER:
		if (wParam == 1)
		{
			MessageBox(hWnd, "타임오버", "타임오버", MB_OK);
			PostQuitMessage(0);
		}
		break;
	case WM_KEYDOWN:
		if (wParam == VK_LEFT)
		{
			gameManager->resetBlock();
			InvalidateRect(hWnd, nullptr, true);
		}
		if (wParam == VK_ADD)
		{
			gameManager->changeBoardType();
			InvalidateRect(hWnd, nullptr, true);
		}
		break;
	case WM_LBUTTONDOWN:
		mx = LOWORD(lParam);
		my = HIWORD(lParam);
		if (gameManager->inCircle(mx, my))
		{
			drag = true;
		}
		break;
	case WM_LBUTTONUP:
		drag = false;
		gameManager->CheckInBlock();
		gameManager->checkBlockColor();
		InvalidateRect(hWnd, nullptr, true);
		break;
	case WM_MOUSEMOVE:
		if (drag)
		{
			mx = LOWORD(lParam);
			my = HIWORD(lParam);
			if (gameManager->inCircle(mx,my))
			{
				gameManager->movingBlock(mx, my);
				InvalidateRect(hWnd, nullptr, true);

			}
		}
		break;
	case WM_PAINT:
	{
		HDC backMemDC;
		HBITMAP backBitmap;
		RECT rt;
		GetClientRect(hWnd, &rt); 
		//static HBITMAP backBitmap = NULL;
		HBITMAP   hOldBitmap;


		hdc = BeginPaint(hWnd, &ps);

		backMemDC = CreateCompatibleDC(hdc);
		backBitmap = CreateCompatibleBitmap(hdc, rt.right, rt.bottom); //도화지 준비!
		hOldBitmap = (HBITMAP)SelectObject(backMemDC, backBitmap);
		FillRect(backMemDC, &rt, (HBRUSH)GetStockObject(WHITE_BRUSH)); //도화지 색 변경


		gameManager->render(backMemDC);

		BitBlt(hdc, 0, 0, rt.right, rt.bottom, backMemDC, 0, 0, SRCCOPY);
		
		DeleteObject(SelectObject(backMemDC, hOldBitmap));
		DeleteDC(backMemDC);
		EndPaint(hWnd, &ps);
	}
		break;
	case WM_DESTROY:
		delete gameManager;
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}