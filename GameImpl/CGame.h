#pragma once
#include "IGame.h"

class CGame :
    public rgf::IGame
{
public:
    CGame( HWND hWnd, HINSTANCE hInstance );
    // Inherited via IGame
    virtual void DuringRender() override;

    // Inherited via IGame
    virtual void Update( DWORD dt ) override;
};

