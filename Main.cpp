#include "Main.h"

using namespace rgf;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//TODO add animation

	HWND hwnd = CreateGameWindow(hInstance, nCmdShow, 800, 600);
	std::shared_ptr<IGame> game(new IGame(hwnd, hInstance));
	IGame::InitInstance(game);
	IGame::GetInstance()->Init();
	IGame::GetInstance()->Run();

	return 0;
}

HWND CreateGameWindow(HINSTANCE hInstance, int nCmdShow, int ScreenWidth, int ScreenHeight)
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = hInstance;

	//Try this to see how the debug function prints out file and line 
	//wc.hInstance = (HINSTANCE)-100; 

	wc.lpfnWndProc = (WNDPROC)WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = (HICON)LoadImage(hInstance, WINDOW_ICON_PATH, IMAGE_ICON, 0, 0, LR_LOADFROMFILE);;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = WINDOW_CLASS_NAME;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);

	HWND hWnd =
		CreateWindow(
			WINDOW_CLASS_NAME,
			WINDOW_TITLE,
			WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX,	//window style (unresizable)
			// WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP,	//window style (resizable)
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			ScreenWidth,
			ScreenHeight,
			NULL,
			NULL,
			hInstance,
			NULL);

	if (!hWnd)
	{
		DWORD ErrCode = GetLastError();
		MessageBox(hWnd, L"Error create window handle", L"Error", MB_OK);
		return 0;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return hWnd;
}


LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
		//if the player close the window
	case WM_DESTROY:
		//tell window to kill this program
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}