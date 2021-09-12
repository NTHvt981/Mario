#pragma once
#include <memory>
#include <windows.h>

#include "Debug.h"
#include "IEntity.h"
#include "RgfConstants.h"
#include "IGameInfo.h"

namespace rgf
{
/// <summary>
/// [singleton] Heart of the game, init and run in main file
/// </summary>
class IGame
{
public:
	IGame( HWND hWnd, HINSTANCE hInstance );
	static std::shared_ptr<IGame> GetInstance();
	static void InitInstance(std::shared_ptr<IGame> game);

	void Init();
	void Run();
	unsigned int GetFrameRate();
	void SetFrameRate( unsigned int fps );

protected:
	HWND m_hWnd = NULL;									// Window handle
	HINSTANCE m_hInstance = NULL;
	static std::shared_ptr<IGame> m_instance;
	IGameInfo m_info;

	void LoadResources();
	void LoadTextures();
	void LoadSprites();

	virtual void Update(DWORD dt) = 0;
	void Render();
	virtual void DuringRender() = 0;

	void CleanResources();
};

HWND CreateGameWindow( HINSTANCE hInstance, int nCmdShow, int ScreenWidth, int ScreenHeight );
LRESULT CALLBACK WinProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );
}	//namespace rgf

