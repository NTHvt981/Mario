#include "IGame.h"

namespace rgf
{
std::shared_ptr<IGame> IGame::m_instance = NULL;

IGame::IGame(HWND hWnd, HINSTANCE hInstance)
{
	this->m_hWnd = hWnd;
	this->m_hInstance = hInstance;
}

void IGame::LoadResources()
{
}

void IGame::LoadTextures()
{
}

void IGame::LoadSprites()
{
}

void IGame::Update(DWORD dt)
{

}

void IGame::Render()
{
}

void IGame::CleanResources()
{
}

std::shared_ptr<IGame> IGame::GetInstance()
{
	if (IGame::m_instance == NULL)
	{
		throw("Instance of game is null when GetInstance");
	}
	return IGame::m_instance;
}

void IGame::InitInstance(std::shared_ptr<IGame> game)
{
	IGame::m_instance = game;
}

void IGame::Init()
{
}

void IGame::Run()
{
	//Load resource to the game
	LoadResources();

	MSG msg;
	int done = 0;
	DWORD frameStart = GetTickCount64();
	DWORD tickPerFrame = 1000 / m_frameRate;

	try
	{
		while (!done)
		{
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				if (msg.message == WM_QUIT) done = 1;

				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}

			DWORD now = GetTickCount64();

			// dt: the time between (beginning of last frame) and now
			// this frame: the frame we are about to render
			DWORD dt = now - frameStart;

			//Heart of the game
			if (dt >= tickPerFrame)
			{
				frameStart = now;

				Update(dt / 10);
				Render();
			}
			//else
			//	Sleep(tickPerFrame - dt);
		}
	}
	catch (const std::exception& ex)
	{
		rgf::DebugOut(L"[ERROR] Exception in Run method in Game %s\n", ex.what());
		return;
	}

	//Clean the resources
	CleanResources();
}

unsigned int IGame::GetFrameRate()
{
	return m_frameRate;
}

void IGame::SetFrameRate( unsigned int fps )
{
	m_frameRate = fps;
}
}	//namespace rgf
