#include "lexerDef.h"
#include "driver.h"
#include "lexer.h"
void getStream(FILE* fp) {
    TOKEN token = getNextToken(fp);
    while(true) {
        if(token.TK == END_OF_FILE)
            break;
        else if(token.TK == LEXICAL_ERROR_1)
            printf("Identifier length is greater than 20 (Line No. - %d)\n", token.line_no);
        else if(token.TK == LEXICAL_ERROR_2)
            printf("Unidentified token found :- %s (Line No. - %d)", token.lexeme, token.line_no);
        else {
            if(token.TK == INTEGER)
                printf("Token- %s, Lexeme- %d (Line No. - %d)", enumToTerminal[token.TK], token.value_if_int, token.line_no);
            else if(token.TK == REAL)
                printf("Token- %s, Lexeme- %f (Line No. - %d)", enumToTerminal[token.TK], token.value_if_float, token.line_no);
            else
                printf("Token- %s, Lexeme- %s (Line No. - %d)", enumToTerminal[token.TK], token.lexeme, token.line_no);
        }
    }
}