#ifndef LD_H
#define LD_H

#include <stdio.h>
#include <stdlib.h>
#include "lexerDef.h"
#include "hashDef.h"


TOKEN getToken();
void initLex(FILE *f, int len);
void fillBuffer();
char getChar(int add);
TOKEN getNextToken();
void getStream();
void fillEnumToTerminal();
void fillEnumToNonTerminal();

#endif