#pragma once
#ifndef _IO_
#define _IO_

// 覧 Includes 蘭

#ifndef LINUX
#include "SDL/include/SDL.h"
#include "SDL/SDL_GfxPrimitives/SDL_gfxPrimitives.h"
#else
#include <SDL/SDL.h>
#include "SDL/SDL_GfxPrimitives/sdl_gfxprimitives.h"
#endif
#pragma comment (lib, "SDL/lib/SDL.lib")
#pragma comment (lib, "SDL/SDL_GfxPrimitives/SDL_GfxPrimitives_Static.lib")

// 覧 Enums 蘭

enum color { BLACK, RED, GREEN, BLUE, CYAN, MAGENTA, YELLOW, ORANGE, WHITE, GRAY, COLOR_MAX }; // Colors

// 覧覧覧覧覧覧覧覧覧覧覧覧覧�
// IO
// 覧覧覧覧覧覧覧覧覧覧覧覧覧�

class IO
{
public:

	IO();

	void DrawRectangle(int pX1, int pY1, int pX2, int pY2, enum color pC);
	void ClearScreen();
	int GetScreenHeight();
	int InitGraph();
	int Pollkey();
	int Getkey();
	int IsKeyDown(int pKey);
	void UpdateScreen();

};

#endif // _IO_