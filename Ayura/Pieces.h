#pragma once
#include <vector>
#ifndef _PIECES_
#define _PIECES_

// 覧覧覧覧覧覧覧覧覧覧覧覧覧�
// Pieces
// 覧覧覧覧覧覧覧覧覧覧覧覧覧�


class Pieces
{
public:
	std::vector<int> pieceBag; 

	int GetBlockType(int pPiece, int pRotation, int pX, int pY);
	int GetXInitialPosition(int pPiece, int pRotation);
	int GetYInitialPosition(int pPiece, int pRotation);
	void generateBag();
	void moveOverOne(int n);
	int bagSize();
	void printBag();
};

#endif // _PIECES_
