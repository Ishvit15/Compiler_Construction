#include <stdio.h>
#include <stdlib.h>
#include "test1.h"

int buflen;
int nxt;
char *buffer;
int lex_ptr;
char *lexeme;
int begin;
int forward;
FILE *fp;

void fillBuffer(){
    if(nxt == buflen)
        nxt = 0;
    int x = fread(buffer + nxt, sizeof(char), buflen/2, fp);
    nxt += x;
    if(x != buflen/2)
        buffer[nxt] = EOF;
    printf("%s\n", buffer);
}

char getChar(int add)
{
    if (forward == 0 || forward == buflen / 2)
        fillBuffer();
    char c = buffer[forward];

    if (add == 0)
    {
        lexeme[lex_ptr++] = c;
        forward = (forward + 1) % buflen;
    }
    return c;
}

void initLex(FILE *f, int len){
    fp = f;
    nxt = 0;
    buflen = 2*len;
    lex_ptr = 0;
    buffer = malloc(buflen*sizeof(char));
    lexeme = malloc(20*sizeof(char));
    begin = 0;
    forward = 0;
    //fillBuffer(fp);
    // for(int i = 0; i < 15; i++)
    //     printf("%c\n", getChar(0));
    
}





