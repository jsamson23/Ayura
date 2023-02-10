#ifndef LINUX
#include <windows.h>
#endif
#include "Game.h"


/*
======================================
Init
======================================
*/
Game::Game(Board* pBoard, Pieces* pPieces, IO* pIO, int pScreenHeight)
{
	mScreenHeight = pScreenHeight;

	// Get the pointer to the Board and Pieces classes
	mBoard = pBoard;
	mPieces = pPieces;
	mIO = pIO;

	// Game initialization
	InitGame();
}


/*
======================================
Get a random int between to integers

Parameters:
>> pA: First number
>> pB: Second number
======================================
*/
int Game::GetRand(int pA, int pB)
{
	return rand() % (pB - pA + 1) + pA;
}


/*
======================================
Initial parameters of the game
======================================
*/
void Game::InitGame()
{
	
	holdPiece = -1;
	mPieces->generateBag();
	// Init random numbers
	srand((unsigned int)time(NULL));
	// First piece
	mPiece = mPieces->pieceBag[0];
	mPieces->pieceBag.erase(mPieces->pieceBag.begin() + 0);
	mRotation = 0;
	mPosX = (BOARD_WIDTH / 2) + mPieces->GetXInitialPosition(mPiece, mRotation);
	mPosY = mPieces->GetYInitialPosition(mPiece, mRotation);

	//  Next piece

	mNextPiece = mPieces->pieceBag.back();
	mPieces->pieceBag.pop_back();

	mNextRotation = 0;
	mNextPosX = BOARD_WIDTH + 5;
	mNextPosY = 5;

	mHoldPosX = BOARD_POSITION - 5;
	mHoldPosY = 5;
}


/*
======================================
Create a random piece
======================================
*/
void Game::CreateNewPiece()
{
	// The new piece
	mPiece = mNextPiece;
	mRotation = mNextRotation;
	mPosX = (BOARD_WIDTH / 2) + mPieces->GetXInitialPosition(mPiece, mRotation);
	mPosY = mPieces->GetYInitialPosition(mPiece, mRotation);


	std::printf("%d", mPiece);

	// Random next piece

	mNextPiece = mPieces->pieceBag[0];
	mPieces->pieceBag.erase(mPieces->pieceBag.begin() + 0);
	if (mPieces->bagSize() == 1) 
	{
		mPieces->generateBag();
	}

	mNextRotation = 0;
}


/*
======================================
Draw piece

Parameters:

>> pX:		Horizontal position in blocks
>> pY:		Vertical position in blocks
>> pPiece:	Piece to draw
>> pRotation:	1 of the 4 possible rotations
======================================
*/
void Game::DrawPiece(int pX, int pY, int pPiece, int pRotation)
{
	color mColor;				// Color of the block 

	// Obtain the position in pixel in the screen of the block we want to draw
	int mPixelsX = mBoard->getXPosInPixels(pX);
	int mPixelsY = mBoard->getYPosInPixels(pY);

	// Travel the matrix of blocks of the piece and draw the blocks that are filled
	for (int i = 0; i < PIECE_BLOCKS; i++)
	{
		for (int j = 0; j < PIECE_BLOCKS; j++)
		{
			// Get the type of the block and draw it with the correct color
			switch (pPiece) {
			case 0:
				switch (mPieces->GetBlockType(pPiece, pRotation, j, i))
				{
				case 1: mColor = YELLOW; break;	// For each block of the piece except the pivot
				}
				break;
			case 1:
				switch (mPieces->GetBlockType(pPiece, pRotation, j, i))
				{
				// For each block of the piece except the pivot
				case 2: mColor = CYAN; break;	// For the pivot
				}
				break;
			case 2:
				switch (mPieces->GetBlockType(pPiece, pRotation, j, i))
				{
				case 3: mColor = ORANGE; break;	// For each block of the piece except the pivot
				}
				break;
			case 3:
				switch (mPieces->GetBlockType(pPiece, pRotation, j, i))
				{
				case 4: mColor = BLUE; break;	// For each block of the piece except the pivot
				}
				break;
			case 4: 
				switch (mPieces->GetBlockType(pPiece, pRotation, j, i))
				{
				case 5: mColor = RED; break;	// For each block of the piece except the pivot
				}
				break;
			case 5: 
				switch (mPieces->GetBlockType(pPiece, pRotation, j, i))
				{
				case 6: mColor = GREEN; break;	// For each block of the piece except the pivot
				}
				break;
			case 6:
				switch (mPieces->GetBlockType(pPiece, pRotation, j, i))
				{
				case 7: mColor = MAGENTA; break;	// For each block of the piece except the pivot
				}
				break;
			}

			if (mPieces->GetBlockType(pPiece, pRotation, j, i) != 0)
				mIO->DrawRectangle(mPixelsX + i * BLOCK_SIZE,
					mPixelsY + j * BLOCK_SIZE,
					(mPixelsX + i * BLOCK_SIZE) + BLOCK_SIZE - 1,
					(mPixelsY + j * BLOCK_SIZE) + BLOCK_SIZE - 1,
					mColor);
		}
	}
}


/*
======================================
Draw board

Draw the two lines that delimit the board
======================================
*/
void Game::DrawBoard()
{
	// Calculate the limits of the board in pixels	
	int mX1 = BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2)) - 1;
	int mX2 = BOARD_POSITION + (BLOCK_SIZE * (BOARD_WIDTH / 2));
	int mY = mScreenHeight - (BLOCK_SIZE * BOARD_HEIGHT);
	color mColor;

	// Check that the vertical margin is not to small
	//assert (mY > MIN_VERTICAL_MARGIN);

	// Rectangles that delimits the board
	mIO->DrawRectangle(mX1 - BOARD_LINE_WIDTH, mY, mX1, mScreenHeight - 1, BLUE);
	mIO->DrawRectangle(mX2, mY, mX2 + BOARD_LINE_WIDTH, mScreenHeight - 1, BLUE);

	for (int i = 0; i < BOARD_HEIGHT; i++) {
		mIO->DrawRectangle(mX1, mScreenHeight - i * BLOCK_SIZE, mX2, mScreenHeight - i * BLOCK_SIZE - 0.25, GRAY);
	}
	for (int i = 0; i < BOARD_WIDTH; i++) {
		mIO->DrawRectangle(mX1 + i * BLOCK_SIZE, mY, mX1 + i * BLOCK_SIZE - 0.25, mScreenHeight - 1, GRAY);
	}
	// Check that the horizontal margin is not to small
	//assert (mX1 > MIN_HORIZONTAL_MARGIN);

	// Drawing the blocks that are already stored in the board
	mX1 += 1;
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		for (int j = 0; j < BOARD_HEIGHT; j++)
		{
			// Check if the block is filled, if so, draw it
			if (!mBoard->IsFreeBlock(i, j)) {
				switch (mBoard->getBlockType(i, j))
				{
				case 1:
					mColor = YELLOW; break;
				case 2: 
					mColor = CYAN; break;
				case 3:
					mColor = ORANGE; break;
				case 4:
					mColor = BLUE; break;
				case 5:
					mColor = RED; break;
				case 6:
					mColor = GREEN; break;
				case 7:
					mColor = MAGENTA; break;
				}

				mIO->DrawRectangle(mX1 + i * BLOCK_SIZE,
					mY + j * BLOCK_SIZE,
					(mX1 + i * BLOCK_SIZE) + BLOCK_SIZE - 1,
					(mY + j * BLOCK_SIZE) + BLOCK_SIZE - 1,
					mColor);
			}
		}
	}
}


/*
======================================
Draw scene

Draw all the objects of the scene
======================================
*/
void Game::DrawScene()
{
	DrawBoard();													// Draw the delimitation lines and blocks stored in the board
	DrawPiece(mPosX, mPosY, mPiece, mRotation);					// Draw the playing piece
	DrawPiece(mNextPosX, mNextPosY, mNextPiece, mNextRotation);	// Draw the next piece
	if (holdPiece != -1)
		DrawPiece(-10, 5, holdPiece, 0); // Draw the hold piece
	DrawShadow(mPosX, mPosY, mPiece, mRotation); // Draw the shadow of the current piece
}

void Game::NewHoldPiece() 
{
	if (holdPiece == -1)
	{
		holdPiece = (int)mPiece;
		mPiece = mNextPiece;
		
		mNextPiece = mPieces->pieceBag[0];
		mPieces->pieceBag.erase(mPieces->pieceBag.begin() + 0);
		if (mPieces->bagSize() == 1)
		{
			mPieces->generateBag();
		}

		mPosX = (BOARD_WIDTH / 2) + mPieces->GetXInitialPosition(mPiece, mRotation);
		mPosY = mPieces->GetYInitialPosition(mPiece, mRotation);
		
		
		mRotation = 0;
		mNextRotation = 0;
	}
	else
	{
		int temp;
		temp = mPiece;
		mPiece = holdPiece;
		holdPiece = temp;
		mPosX = (BOARD_WIDTH / 2) + mPieces->GetXInitialPosition(mPiece, mRotation);
		mPosY = mPieces->GetYInitialPosition(mPiece, mRotation);
		
		mRotation = 0;
		mNextRotation = 0;
	}
}

void Game::DrawShadow(int pX, int pY, int pPiece, int pRotation) {
	color mColor;				// Color of the block 

	// Obtain the position in pixel in the screen of the block we want to draw
	int mPixelsX = mBoard->getXPosInPixels(pX);
	int mPixelsY = mBoard->getYPosInPixels(pY);
	for (int i = pY; i <= BOARD_HEIGHT; i++) // starts from initialization piece position to BOARD_HEIGHT
	{
		if (mBoard->IsPossibleMovement(pX, i, pPiece, pRotation))
		{
			mPixelsY = mBoard->getYPosInPixels(i);
		}
		else
			break; 
	}

	// Travel the matrix of blocks of the piece and draw the blocks that are filled
	for (int i = 0; i < PIECE_BLOCKS; i++)
	{
		for (int j = 0; j < PIECE_BLOCKS; j++)
		{
			// Get the type of the block and draw it with the correct color
			switch (pPiece) {
			case 0:
				switch (mPieces->GetBlockType(pPiece, pRotation, j, i))
				{
				case 1: mColor = YELLOW; break;	// For each block of the piece except the pivot
				}
				break;
			case 1:
				switch (mPieces->GetBlockType(pPiece, pRotation, j, i))
				{
					// For each block of the piece except the pivot
				case 2: mColor = CYAN; break;	// For the pivot
				}
				break;
			case 2:
				switch (mPieces->GetBlockType(pPiece, pRotation, j, i))
				{
				case 3: mColor = ORANGE; break;	// For each block of the piece except the pivot
				}
				break;
			case 3:
				switch (mPieces->GetBlockType(pPiece, pRotation, j, i))
				{
				case 4: mColor = BLUE; break;	// For each block of the piece except the pivot
				}
				break;
			case 4:
				switch (mPieces->GetBlockType(pPiece, pRotation, j, i))
				{
				case 5: mColor = RED; break;	// For each block of the piece except the pivot
				}
				break;
			case 5:
				switch (mPieces->GetBlockType(pPiece, pRotation, j, i))
				{
				case 6: mColor = GREEN; break;	// For each block of the piece except the pivot
				}
				break;
			case 6:
				switch (mPieces->GetBlockType(pPiece, pRotation, j, i))
				{
				case 7: mColor = MAGENTA; break;	// For each block of the piece except the pivot
				}
				break;
			}

			if (mPieces->GetBlockType(pPiece, pRotation, j, i) != 0)
				mIO->DrawRectangle(mPixelsX + i * BLOCK_SIZE,
					mPixelsY + j * BLOCK_SIZE,
					(mPixelsX + i * BLOCK_SIZE) + BLOCK_SIZE - 1,
					(mPixelsY + j * BLOCK_SIZE) + BLOCK_SIZE - 1,
					mColor);
		}
	}

}