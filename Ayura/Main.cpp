
#include "Game.h"
#ifndef LINUX
#include <windows.h>
#endif

#define DAS_TIME 120
#define ARR 20
#define FAST_DROP_SPEED 10 // smaller the number the faster
/*
==================
Main
==================
*/
#ifndef LINUX
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)	// Linux users should quit this line
#else
int main()
#endif
// int main ()  // Linux users should use this line instead the previous one
{
	// ----- Vars -----

	// Class for drawing staff, it uses SDL for the rendering. Change the methods of this class
	// in order to use a different renderer
	IO mIO;
	int mScreenHeight = mIO.GetScreenHeight();
	bool held = false;
	int checker = 0;
	// Pieces
	Pieces mPieces;

	// Board
	Board mBoard(&mPieces, mScreenHeight);

	// Game
	Game mGame(&mBoard, &mPieces, &mIO, mScreenHeight);

	// Get the actual clock milliseconds (SDL)
	unsigned long mTime1 = SDL_GetTicks();
	unsigned long mDAS1L = SDL_GetTicks();
	unsigned long mDAS2L;
	unsigned long mDAS1R = SDL_GetTicks();
	unsigned long mDAS2R;

	// ----- Main Loop -----

	while (!mIO.IsKeyDown(SDLK_ESCAPE))
	{
		// ----- Draw -----

		mIO.ClearScreen(); 		// Clear screen
		mGame.DrawScene();			// Draw staff
		mIO.UpdateScreen();		// Put the graphic context in the screen
		// ----- Input -----
		if (mIO.IsKeyDown(SDLK_LEFT))
		{
			mDAS1L = SDL_GetTicks();
			if (mDAS1L - mDAS2L > DAS_TIME) {
				if (mBoard.IsPossibleMovement(mGame.mPosX - 1, mGame.mPosY, mGame.mPiece, mGame.mRotation))
					mGame.mPosX--;
			}
			if (mIO.IsKeyDown(SDLK_RIGHT))
				mDAS2L = SDL_GetTicks();
			SDL_Delay(ARR);

		}
		if (!mIO.IsKeyDown(SDLK_LEFT))
			mDAS2L = SDL_GetTicks();
		if (mIO.IsKeyDown(SDLK_RIGHT))
		{
			mDAS1R = SDL_GetTicks();
			if (mDAS1R - mDAS2R > DAS_TIME) {
				if (mBoard.IsPossibleMovement(mGame.mPosX + 1, mGame.mPosY, mGame.mPiece, mGame.mRotation))
					mGame.mPosX++;
			}
			if (mIO.IsKeyDown(SDLK_LEFT))
				mDAS2R = SDL_GetTicks();
			SDL_Delay(ARR);
		}
		if (!mIO.IsKeyDown(SDLK_RIGHT))
			mDAS2R = SDL_GetTicks();
		if (mIO.IsKeyDown(SDLK_DOWN)) 
		{
			if (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY + 1, mGame.mPiece, mGame.mRotation))
				mGame.mPosY++;
			SDL_Delay(FAST_DROP_SPEED);
		}

		int mKey = mIO.Pollkey();



			switch (mKey)
			{
			case (SDLK_RIGHT):
			{
				if (mBoard.IsPossibleMovement(mGame.mPosX + 1, mGame.mPosY, mGame.mPiece, mGame.mRotation))
					mGame.mPosX++;
				break;
			}

			case (SDLK_LEFT):
			{
				if (mBoard.IsPossibleMovement(mGame.mPosX - 1, mGame.mPosY, mGame.mPiece, mGame.mRotation))
					mGame.mPosX--;

				break;
			}

			case (SDLK_DOWN):
			{
				if (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY + 1, mGame.mPiece, mGame.mRotation))
					mGame.mPosY++;
				break;
			}

			case (SDLK_c):
			{
				// Check collision from up to down
				while (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY, mGame.mPiece, mGame.mRotation)) { mGame.mPosY++; }

				mBoard.StorePiece(mGame.mPosX, mGame.mPosY - 1, mGame.mPiece, mGame.mRotation);

				mBoard.DeletePossibleLines();

				if (mBoard.IsGameOver())
				{
					mIO.Getkey();
					exit(0);
				}

				mGame.CreateNewPiece();
				held = false;

				break;
			}

			case (SDLK_UP):
			{
				if (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY, mGame.mPiece, (mGame.mRotation + 1) % 4))
					mGame.mRotation = (mGame.mRotation + 1) % 4;
				else if (mBoard.IsPossibleMovement(mGame.mPosX + 1, mGame.mPosY, mGame.mPiece, (mGame.mRotation + 1) % 4)) {
					mGame.mRotation = (mGame.mRotation + 1) % 4;
					mGame.mPosX++;
				}
				else if (mBoard.IsPossibleMovement(mGame.mPosX - 1, mGame.mPosY, mGame.mPiece, (mGame.mRotation + 1) % 4)) {
					mGame.mRotation = (mGame.mRotation + 1) % 4;
					mGame.mPosX--;
				}
				else if (mBoard.IsPossibleMovement(mGame.mPosX - 1, mGame.mPosY + 1, mGame.mPiece, (mGame.mRotation + 1) % 4))
				{
					mGame.mPosX--;
					mGame.mPosY++;
					mGame.mRotation = (mGame.mRotation + 1) % 4;
				}
				else if (mBoard.IsPossibleMovement(mGame.mPosX + 1, mGame.mPosY + 1, mGame.mPiece, (mGame.mRotation + 1) % 4))
				{
					mGame.mPosX++;
					mGame.mPosY++;
					mGame.mRotation = (mGame.mRotation + 1) % 4;
				}
				break;
			}
			case (SDLK_a):
			{
				if (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY, mGame.mPiece, (mGame.mRotation + 3) % 4))
					mGame.mRotation = (mGame.mRotation + 3) % 4;
				else if (mBoard.IsPossibleMovement(mGame.mPosX + 1, mGame.mPosY, mGame.mPiece, (mGame.mRotation + 3) % 4)) 
				{
					mGame.mPosX++;
					mGame.mRotation = (mGame.mRotation + 3) % 4;
				}
				else if (mBoard.IsPossibleMovement(mGame.mPosX - 1, mGame.mPosY, mGame.mPiece, (mGame.mRotation + 3) % 4))
				{
					mGame.mPosX--;
					mGame.mRotation = (mGame.mRotation + 3) % 4;
				}
				else if (mBoard.IsPossibleMovement(mGame.mPosX + 1, mGame.mPosY + 1, mGame.mPiece, (mGame.mRotation + 3) % 4)) {
					mGame.mPosX++;
					mGame.mPosY++;
					mGame.mRotation = (mGame.mRotation + 3) % 4;
				}
				else if (mBoard.IsPossibleMovement(mGame.mPosX - 1, mGame.mPosY + 1, mGame.mPiece, (mGame.mRotation + 3) % 4)) {
					mGame.mPosY++;
					mGame.mPosX--;
					mGame.mRotation = (mGame.mRotation + 3) % 4;
				}

				break;
			}
			case (SDLK_s):
			{
				if (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY, mGame.mPiece, (mGame.mRotation + 2) % 4))
					mGame.mRotation = (mGame.mRotation + 2) % 4;

				break;
			}
			case (SDLK_d): // hold a piece.
			{
				if (!held) {
					mGame.NewHoldPiece();
					held = true;
				}

				break;
			}



		}
		// ----- Vertical movement -----

		unsigned long mTime2 = SDL_GetTicks();

		if ((mTime2 - mTime1) > WAIT_TIME)
		{
			if (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY + 1, mGame.mPiece, mGame.mRotation))
			{
				mGame.mPosY++;
			}
			else
			{
				if (checker < 2)
					checker++;

				else if (checker == 2)
				{
					mBoard.StorePiece(mGame.mPosX, mGame.mPosY, mGame.mPiece, mGame.mRotation);
					mBoard.DeletePossibleLines();

					if (mBoard.IsGameOver())
					{
						mIO.Getkey();
						exit(0);
					}

					mGame.CreateNewPiece();
					held = false;
					checker = 0;
				}
			}

			mTime1 = SDL_GetTicks();
		}
	}

	return 0;
}
