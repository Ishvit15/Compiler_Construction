#ifndef LD_H
#define LD_H

#include <stdio.h>
#include <stdlib.h>
#include "lexerDef.h"
#include "hashDef.h"

char getChar();
TOKEN getToken();
void initLex (FILE *f, int len);
void fillBuffer();
char getChar(int add);
TOKEN getNextToken();
void getStream(FILE *fp);
void fillEnumToTerminal(FILE* fp);
void fillEnumToNonTerminal(FILE* fp);

#endif