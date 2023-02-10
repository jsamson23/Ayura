#pragma once
#ifndef _BOARD_
#define _BOARD_

#include "Pieces.h"

#define BOARD_LINE_WIDTH 6 //width of each of the two lines that delimit the board
#define BLOCK_SIZE 16 // width and height of each block
#define BOARD_POSITION 320 //center position of the board from the left of screen
#define BOARD_WIDTH 10 //board width in blocks
#define BOARD_HEIGHT 20 //board height in blocks
#define MIN_VERTICAL_MARGIN 20 //min vertical margin for the board limit
#define MIN_HORIZONTAL_MARGIN 20 //minimum horizonal margin for the board limit
#define PIECE_BLOCKS 5 //number of horizontal and vertical blocks of a matrix piece

class Board
{
public: 

	Board(Pieces* pPieces, int pScreenheight);
	int getXPosInPixels(int pPos);
	int getYPosInPixels(int pPos);
	bool IsFreeBlock(int pX, int pY);
	bool IsPossibleMovement(int pX, int pY, int pPiece, int pRotation);
	void StorePiece(int pX, int pY, int pPiece, int pRotation);
	int getBlockType(int pX, int pY);
	void DeletePossibleLines();
	bool IsGameOver();

private:
	enum { POS_FREE, POS_FILLED };// POS_FREE free position of board
	Pieces* mPieces;
	int mScreenHeight;
	int mBoard[BOARD_WIDTH][BOARD_HEIGHT];

	void initBoard();
	void DeleteLine(int pY);
};

#endif // _BOARD_
