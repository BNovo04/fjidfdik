#ifndef _ESTRUTURA_
#define _ESTRUTURA_

#include <stdio.h>
#include <stdlib.h>

struct dominos {
    int side1;
    int side2;
    int stackPosition;
    int pieceState;
};
struct dominos pieces[28];

#endif // _ESTRUTURA_
