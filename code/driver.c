#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "hashtable.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
        exit(1);
    FILE *fp = fopen(argv[1], "r");
    int len = atoi(argv[2]);

    

    fillEnumToNonTerminal();
    fillEnumToTerminal();

    initLex(fp, len);
    // for(int i = 0; i < TERMINALS_COUNT; i++)
    //      printf("%s\n", enumToTerminal[i]);
    getStream();
}