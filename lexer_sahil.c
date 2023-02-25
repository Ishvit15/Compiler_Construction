#include <stdio.h>
#include <stdlib.h>
#include "lexer_new.h"

TOKEN getNextToken(FILE *fp){
    TOKEN tkn;
    char c;
    int state;

    while(1){
        tkn.line_no = line_no;
        switch(state){
            case 0:
                c = getChar(fp);
                if(c=='.'){
                    state = 8;
                }
                else if(c=="_" || (c>='a' && c<='z')){
                    char t = getChar(fp, 1);
                    if(!(t>='a' && t<='z') && !(t- '0'>=0 && t -'0'<=9) && t!='_'){
                        tkn = getToken();
                        state = 0;
                        beginPtr = fwdPtr;
                        return tkn;
                    }
                    else{
                        state = 1;
                    }
                }
                else if( c- '0'>=0 && c -'0'<=9){
                   char t = getChar(fp, 1);
                   if (t != '.' && !(t- '0'>=0 && t -'0'<=9)){
                    tkn.TK = TK_NUM;
                    tkn.value_if_int = c -'0';
                    beginPtr = fwdPtr;
                    state = 0;
                    return tkn;
                   } else{
                    state = 2;
                   }
                }
                else if(c == ';'){
                    
                    tkn.TK = TK_SEMICOL;
                    strncpy(tkn.lexeme, ";", MAX_LEXEME_LENGTH);
                    beginPtr = fwdPtr;
                    state = 0;
                    return tkn;
                }
                else if(c== ','){
                    tkn.TK = TK_COMMA;
                    strncpy(tkn.lexeme, ",", MAX_LEXEME_LENGTH);
                    beginPtr = fwdPtr;
                    state = 0;
                    return tkn;
                }
                else if( c=='['){
                    tkn = TK_SQBO;
                    strncpy(tkn.lexeme, "[", MAX_LEXEME_LENGTH);
                    beginPtr = fwdPtr;
                    state = 0;
                    return tkn;
                }
                else if(c == ']'){
                    tkn = TK_SQBC;
                    strncpy(tkn.lexeme, "]", MAX_LEXEME_LENGTH);
                    beginPtr = fwdPtr;
                    state  = 0;
                    return tkn;
                }
                else if(c == '('){
                    tkn = TK_BO;
                    strncpy(tkn.lexeme, "(", MAX_LEXEME_LENGTH);
                    beginPtr = fwdPtr;
                    state  = 0;
                    return tkn;
                }
                else if(c== ')'){
                    tkn = TK_SQBC;
                    strncpy(tkn.lexeme, ")", MAX_LEXEME_LENGTH);
                    beginPtr = fwdPtr;
                    state  = 0;
                    return tkn;
                }
                else if(c == EOF){
                    exit(0);
                }
                else if (c== '\t' || c == ' '){
                    state = 17;
                }
                else if (c== '\n'){
                    state = 0;
                    line_no = line_no+1;
                }
                else if(c == '+'){
                    tkn = TK_PLUS;
                    strncpy(tkn.lexeme, "+", MAX_LEXEME_LENGTH);
                    beginPtr = fwdPtr;
                    state  = 0;
                    return tkn;
                }
                else if (c== '-'){
                    tkn = TK_MINUS;
                    strncpy(tkn.lexeme, "-", MAX_LEXEME_LENGTH);
                    beginPtr = fwdPtr;
                    state  = 0;
                    return tkn;
                }
                else if(c== '*'){
                    char t = getChar(fp, 1); /* this getChar only does a lookahead 
                    and returns the file pointer back to its original value */
                    if(t == '*'){
                        state = 22;
                    }
                    else {
                        tkn.TK= TK_MUL;
                        strncpy (tkn.lexeme, "*", MAX_LEXEME_LENGTH);
                        beginPtr = fwdPtr;
                        state = 0;
                        return tkn;
                    }
                }
                else if(c=='/'){
                    tkn = TK_DIV;
                    strncpy(tkn.lexeme, "/", MAX_LEXEME_LENGTH);
                    beginPtr = fwdPtr;
                    state  = 0;
                    return tkn;
                }
                else if( c== '<'){
                    char t = getChar(fp, 1);
                    if(t=='='){
                        tkn.TK= TK_LE;
                        strncpy (tkn.lexeme, "<=", MAX_LEXEME_LENGTH);
                        beginPtr = fwdPtr;
                        state = 0;
                        return tkn;
                    }
                    else if(t == '<'){
                        char t = getChar(fp, 1);
                        if(t=='<'){
                            tkn.TK= TK_DRIVERDEF;
                            strncpy (tkn.lexeme, "<<<", MAX_LEXEME_LENGTH);
                            beginPtr = fwdPtr;
                            state = 0;
                            return tkn;
                        }else{
                            tkn.TK= TK_DEF;
                            strncpy (tkn.lexeme, "<<", MAX_LEXEME_LENGTH);
                            beginPtr = fwdPtr;
                            state = 0;
                            return tkn;
                        }
                    }
                    else{
                        tkn.TK= TK_LT;
                        strncpy (tkn.lexeme, "<", MAX_LEXEME_LENGTH);
                        beginPtr = fwdPtr;
                        state = 0;
                        return tkn;
                    }
                }
                else if(c == '>'){
                    char t = getChar(fp, 1);
                    if(t=='='){
                        tkn.TK= TK_GE;
                        strncpy (tkn.lexeme, ">=", MAX_LEXEME_LENGTH);
                        beginPtr = fwdPtr;
                        state = 0;
                        return tkn;
                    }
                    else if(t == '>'){
                        char t = getChar(fp, 1);
                        if(t=='>'){
                            tkn.TK= TK_DRIVERENDDEF;
                            strncpy (tkn.lexeme, ">>>", MAX_LEXEME_LENGTH);
                            beginPtr = fwdPtr;
                            state = 0;
                            return tkn;
                        }else{
                            tkn.TK= TK_ENDDEF;
                            strncpy (tkn.lexeme, ">>", MAX_LEXEME_LENGTH);
                            beginPtr = fwdPtr;
                            state = 0;
                            return tkn;
                        }
                    }
                    else{
                        tkn.TK= TK_GT;
                        strncpy (tkn.lexeme, ">", MAX_LEXEME_LENGTH);
                        beginPtr = fwdPtr;
                        state = 0;
                        return tkn;
                    }
                }
                else if(c=='='){
                    state = 35;
                }
                else if(c=='!'){
                    state = 37;
                }
                else if(c==':'){
                    char t = getChar(fp, 1);
                    if(t=='='){
                        tkn.TK = TK_ASSIGNOP;
                        strncpy(tkn.lexeme, ":=", MAX_LEXEME_LENGTH);
                        beginPtr = fwdPtr;
                        state = 0;
                        return tkn;
                    }
                    else{
                        tkn.TK = TK_COLON;
                        strncpy(tkn.lexeme, ":", MAX_LEXEME_LENGTH);
                        beginPtr = fwdPtr;
                        state = 0;
                        return tkn;
                    }
                }
            break;

            case 1:
                break;
            
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 22:
                break;
            case 23:
                break;
            case 24:
                break;
            case 35:
                break;
            case 37:
                break;
            default:
                break;
        }
    }
    return tkn;
}