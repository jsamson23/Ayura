#include "Pieces.h"
#include <ctime>
#include <cstdlib>

// Pieces definition
char mPieces[7 /*kind */][4 /* rotation */][5 /* horizontal blocks */][5 /* vertical blocks */] =
{
    // Square
      {
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0}
        }
       },

    // I
      {
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 2, 2, 2},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 2, 0},
        {0, 0, 0, 2, 0},
        {0, 0, 0, 2, 0},
        {0, 0, 0, 2, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 2, 2, 2},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 2, 0, 0},
        {0, 0, 2, 0, 0},
        {0, 0, 2, 0, 0},
        {0, 0, 2, 0, 0}
        }
       }
      ,
    // L
      {
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 3, 0},
        {0, 3, 3, 3, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
       },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 3, 0, 0},
        {0, 0, 3, 0, 0},
        {0, 0, 3, 3, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 3, 3, 3, 0},
        {0, 3, 0, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 3, 3, 0, 0},
        {0, 0, 3, 0, 0},
        {0, 0, 3, 0, 0},
        {0, 0, 0, 0, 0}
        }
       },
    // L mirrored
      {
       {
        {0, 0, 0, 0, 0},
        {0, 4, 0, 0, 0},
        {0, 4, 4, 4, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 4, 4, 0},
        {0, 0, 4, 0, 0},
        {0, 0, 4, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 4, 4, 4, 0},
        {0, 0, 0, 4, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 4, 0, 0},
        {0, 0, 4, 0, 0},
        {0, 4, 4, 0, 0},
        {0, 0, 0, 0, 0}
        }
       },
    // N
      {
       {
        {0, 0, 0, 0, 0},
        {0, 5, 5, 0, 0},
        {0, 0, 5, 5, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 5, 0},
        {0, 0, 5, 5, 0},
        {0, 0, 5, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 5, 5, 0, 0},
        {0, 0, 5, 5, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 5, 0, 0},
        {0, 5, 5, 0, 0},
        {0, 5, 0, 0, 0},
        {0, 0, 0, 0, 0}
        }
       },
    // N mirrored
      {
       {
        {0, 0, 0, 0, 0},
        {0, 0, 6, 6, 0},
        {0, 6, 6, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 6, 0, 0},
        {0, 0, 6, 6, 0},
        {0, 0, 0, 6, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 6, 6, 0},
        {0, 6, 6, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 6, 0, 0, 0},
        {0, 6, 6, 0, 0},
        {0, 0, 6, 0, 0},
        {0, 0, 0, 0, 0}
        }
       },
    // T
      {
       {
        {0, 0, 0, 0, 0},
        {0, 0, 7, 0, 0},
        {0, 7, 7, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 7, 0, 0},
        {0, 0, 7, 7, 0},
        {0, 0, 7, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 7, 7, 7, 0},
        {0, 0, 7, 0, 0},
        {0, 0, 0, 0, 0}
        },
       {
        {0, 0, 0, 0, 0},
        {0, 0, 7, 0, 0},
        {0, 7, 7, 0, 0},
        {0, 0, 7, 0, 0},
        {0, 0, 0, 0, 0}
        }
       }
};


// Displacement of the piece to the position where it is first drawn in the board when it is created
int mPiecesInitialPosition[7 /*kind */][4 /* rotation */][2 /* position */] =
{
    /* Square */
      {
        {-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -3}
       },
    /* I */
      {
        {-2, -2},
        {-2, -3},
        {-2, -2},
        {-2, -3}
       },
    /* L */
      {
        {-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -2}
       },
    /* L mirrored */
      {
        {-2, -3},
        {-2, -2},
        {-2, -3},
        {-2, -3}
       },
    /* N */
      {
        {-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -2}
       },
    /* N mirrored */
      {
        {-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -2}
       },
    /* T */
      {
        {-2, -3},
        {-2, -3},
        {-2, -3},
        {-2, -2}
       },
};


/*
======================================
Return the type of a block (0 = no-block, 1 = normal block, 2 = pivot block)

Parameters:

>> pPiece:		Piece to draw
>> pRotation:	1 of the 4 possible rotations
>> pX:			Horizontal position in blocks
>> pY:			Vertical position in blocks
======================================
*/
int Pieces::GetBlockType(int pPiece, int pRotation, int pX, int pY)
{
    return mPieces[pPiece][pRotation][pX][pY];
}


/*
======================================
Returns the horizontal displacement of the piece that has to be applied in order to create it in the
correct position.

Parameters:

>> pPiece:	Piece to draw
>> pRotation:	1 of the 4 possible rotations
======================================
*/
int Pieces::GetXInitialPosition(int pPiece, int pRotation)
{
    return mPiecesInitialPosition[pPiece][pRotation][0] - 1;
}


/*
======================================
Returns the vertical displacement of the piece that has to be applied in order to create it in the
correct position.

Parameters:

>> pPiece:	Piece to draw
>> pRotation:	1 of the 4 possible rotations
======================================
*/
int Pieces::GetYInitialPosition(int pPiece, int pRotation)
{
    return mPiecesInitialPosition[pPiece][pRotation][1];
}

void Pieces::generateBag() 
{
    srand(time(0));
    int choice;
    if (pieceBag.empty()) {
        for (int i = 0; i < 7; i++) {
            choice = rand() % (2);
            switch (choice) {
            case 0:
                pieceBag.push_back(i);
                break;
            case 1:
                moveOverOne(0);
                pieceBag[0] = i;
                break;
            }
        }
    }
    else
    {
        for (int i = 0; i < 7; i++) {
            choice = rand() % (2);
            switch (choice) {
            case 0:
                pieceBag.push_back(i);
                break;
            case 1:
                moveOverOne(1);
                pieceBag[1] = i;
                break;
            }
        }
    }
}

void Pieces::moveOverOne(int n)
{
    pieceBag.push_back(0);
    for (int i = pieceBag.size()-2; i >= n; i--) 
    {
        pieceBag[i + 1] = pieceBag[i];
    }
}

int Pieces::bagSize() {
    return pieceBag.size();
}

void Pieces::printBag() {
    for (int i = 0; i < pieceBag.size(); i++) {
        std::printf("%d", pieceBag[i]);
    }
}