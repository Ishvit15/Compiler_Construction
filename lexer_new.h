#include <stdio.h>
#include <stdlib.h>

typedef enum {
    #include "token_names.txt"
} Name;

#define MAX_LEXEME_LENGTH 20

int beginPtr;
int fwdPtr;
int line_no;

char getChar();
TOKEN getToken();


typedef struct token{
    Name TK;
    union{
        char lexeme[20];
        int value_if_int;
        float value_if_float;
    };
    int line_no;
} TOKEN;
