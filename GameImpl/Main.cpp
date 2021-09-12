#include "Main.h"
#include "CGame.h"

using namespace rgf;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//TODO add animation

	HWND hwnd = rgf::CreateGameWindow(hInstance, nCmdShow, 800, 600);
	std::shared_ptr<CGame> game(new CGame(hwnd, hInstance));
	IGame::InitInstance(game);
	IGame::GetInstance()->Init();
	IGame::GetInstance()->Run();

	return 0;
}
