#pragma once
#include <memory>
#include <windows.h>

#include "Debug.h"
#include "IEntity.h"

namespace rgf
{
/// <summary>
/// [singleton] Heart of the game, init and run in main file
/// </summary>
class IGame
{
public:
	IGame(HWND hWnd, HINSTANCE hInstance);
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
	unsigned int m_frameRate = 60;

	void LoadResources();
	void LoadTextures();
	void LoadSprites();

	void Update(DWORD dt);

	void Render();

	void CleanResources();
};

}	//namespace rgf

