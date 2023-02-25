#include "lexerDef.h"

enum nonTerminalNo {

};

typedef struct grammarSymbol {
    bool isTerminal;
    union {
        tokenNo tno;
        nonTerminalNo ntno;
    };
} grammarSymbol;

