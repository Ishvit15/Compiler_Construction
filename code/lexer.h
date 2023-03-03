/* 
GROUP NO. 19
ID: 2019B3A70545P  Name: ANIMESH BHARGAVA 
ID: 2019B5A70226P  Name: ISHVIT BHASIN 
ID: 2019B2A70878P  Name: RITIK THAKUR 
ID: 2019B3A70154P  Name: SAHIL GUPTA
ID: 2019B4A70704P  Name: UTKARSH YASHVARDHAN
*/

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
void getStream();
void fillEnumToTerminal(FILE* fp);
void fillEnumToNonTerminal(FILE* fp);
void removeComment(char* testcasefile, char* cleanFile);

#endif
