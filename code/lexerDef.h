// enum tokenNo {
//     DUMMY = -1,
//     INTEGER,
//     REAL,
//     BOOLEAN,
//     OF,
//     ARRAY,
//     START,
//     END,
//     DECLARE,
//     MODULE,
//     DRIVER,
//     PROGRAM,
//     GET_VALUE,
//     PRINT,
//     USE,
//     WITH,
//     PARAMETERS,
//     TAKES,
//     INPUT,
//     RETURNS,
//     FOR,
//     IN,
//     SWITCH,
//     CASE,
//     BREAK,
//     DEFAULT,
//     WHILE,
//     AND,
//     OR,
//     TRUE,
//     FALSE
// };

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum {
    DUMMY,
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
    AND,
    OR,
    TRUE,
    FALSE,
    END_OF_FILE,
    LEXICAL_ERROR_1,
    LEXICAL_ERROR_2,
    ID,
    NUM,
    RNUM,
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
    COMMENTMARK
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
