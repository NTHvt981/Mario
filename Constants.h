#pragma once

#include <memory>

#define WINDOW_CLASS_NAME L"NGUYEN TRUNG HIEU'S WINDOW"
#define WINDOW_TITLE L"MARIO"
#define WINDOW_ICON_PATH L"Mario.ico"
#define D3DCOLOR_WHITE D3DCOLOR_XRGB(255, 255, 255)

#define FULLSCREEN true

#define BACKGROUND_COLOR D3DCOLOR_XRGB(0, 0, 0)
//width and height of the camera
#define CAMERA_WIDTH 256
#define CAMERA_HEIGHT 256
#define CAMERA_SCALE 2

//width and height when shown
//#define WINDOW_WIDTH 640
//#define WINDOW_HEIGHT 480
#define WINDOW_WIDTH 480
#define WINDOW_HEIGHT 480

//width and height of the whole level
//#define GAME_WIDTH 2048
//#define GAME_HEIGHT 2048
#define GAME_WIDTH 3072
#define GAME_HEIGHT 3072

//#define GRID_WIDTH 64
//#define GRID_HEIGHT 64
#define GRID_WIDTH 128
#define GRID_HEIGHT 128

//#define MAX_FRAME_RATE 120
#define MAX_FRAME_RATE 60

#define ENEMIES_TEXTURE_PATH L"./Resources/Texture/enemies.png"

#define TEX_BBOX_PATH L"./Resources/Texture/bbox.png"
#define ID_TEX_BBOX 999		// special texture to draw object bounding box

#define POSITION_START_X 10
#define POSITION_START_Y 10
