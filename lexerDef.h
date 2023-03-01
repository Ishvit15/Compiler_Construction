#ifndef LEXERDEF_H
#define LEXERDEF_H

#include <stdio.h>

#define MAX_LEXEME_LENGTH 20
#define TERMINALS_COUNT 61
#define NON_TERMINALS_COUNT 73 
#define MAX_TERMINAL_NAME_SIZE 15
#define MAX_NON_TERMINAL_NAME_SIZE 30 

typedef enum
{
    DUMMY = -1,
    INTEGER,
    REAL,
    BOOLEAN,
    OF,
    ARRAY,
    START,
    END,
    DECLARE,
    MODULE,
    DRIVER,
    PROGRAM,
    GET_VALUE,
    PRINT,
    USE,
    WITH,
    PARAMETERS,
    TAKES,
    INPUT,
    RETURNS,
    FOR,
    IN,
    SWITCH,
    CASE,
    BREAK,
    DEFAULT,
    WHILE,
    ID,
    NUM,
    RNUM,
    AND,
    OR,
    TRUE,
    FALSE,
    PLUS,
    MINUS,
    MUL,
    DIV,
    LT,
    LE,
    GE,
    GT,
    EQ,
    NE,
    DEF,
    ENDDEF,
    DRIVERDEF,
    DRIVERENDDEF,
    COLON,
    RANGEOP,
    SEMICOL,
    COMMA,
    ASSIGNOP,
    SQBO,
    SQBC,
    BO,
    BC,
    COMMENTMARK,
    END_OF_FILE,
    LEX_ERROR_1,
    LEX_ERROR_2,
    EPSILON
} Name;

typedef struct token
{
    Name TK;
    union
    {
        char lexeme[20];
        int value_if_int;
        float value_if_float;
    };
    int line_no;
} TOKEN;

int beginPtr;
int fwdPtr;
int lineNum;
int dfaState;
int MAX_BUFFER_SIZE;
int buflen;
int nxt;
char *buffer;
int lex_ptr;
char *lexeme;
int bufferRounds;
FILE *fp;

char enumToTerminal[TERMINALS_COUNT][MAX_TERMINAL_NAME_SIZE];
char enumToNonTerminal[NON_TERMINALS_COUNT][MAX_NON_TERMINAL_NAME_SIZE];

#endif