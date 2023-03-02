#include <stdlib.h>
#include <stdio.h>
#include "lexerDef.h"
#include "hashDef.h"
#include <string.h>
#include <ctype.h>

// void initLexer (FILE *srcFile) {
//     beginPtr = 0;

//     bufferRounds = 0;
//     fwdPtr = 0;
//     fillBuffer(srcFile); // parameters? ---> Animesh

//     lookupTableRecord* lt;
//     initializeLookupTable(lt);
//     generateLookupTable();

//     // extraChar & num??
// }

void fillEnumToTerminal()
{
    strcpy(enumToTerminal[0], "INTEGER");
    strcpy(enumToTerminal[1], "REAL");
    strcpy(enumToTerminal[2], "BOOLEAN");
    strcpy(enumToTerminal[3], "OF");
    strcpy(enumToTerminal[4], "ARRAY");
    strcpy(enumToTerminal[5], "START");
    strcpy(enumToTerminal[6], "END");
    strcpy(enumToTerminal[7], "DECLARE");
    strcpy(enumToTerminal[8], "MODULE");
    strcpy(enumToTerminal[9], "DRIVER");
    strcpy(enumToTerminal[10], "PROGRAM");
    strcpy(enumToTerminal[11], "GET_VALUE");
    strcpy(enumToTerminal[12], "PRINT");
    strcpy(enumToTerminal[13], "USE");
    strcpy(enumToTerminal[14], "WITH");
    strcpy(enumToTerminal[15], "PARAMETERS");
    strcpy(enumToTerminal[16], "TAKES");
    strcpy(enumToTerminal[17], "INPUT");
    strcpy(enumToTerminal[18], "RETURNS");
    strcpy(enumToTerminal[19], "FOR");
    strcpy(enumToTerminal[20], "IN");
    strcpy(enumToTerminal[21], "SWITCH");
    strcpy(enumToTerminal[22], "CASE");
    strcpy(enumToTerminal[23], "BREAK");
    strcpy(enumToTerminal[24], "DEFAULT");
    strcpy(enumToTerminal[25], "WHILE");
    strcpy(enumToTerminal[26], "ID");
    strcpy(enumToTerminal[27], "NUM");
    strcpy(enumToTerminal[28], "RNUM");
    strcpy(enumToTerminal[29], "AND");
    strcpy(enumToTerminal[30], "OR");
    strcpy(enumToTerminal[31], "TRUE");
    strcpy(enumToTerminal[32], "FALSE");
    strcpy(enumToTerminal[33], "PLUS");
    strcpy(enumToTerminal[34], "MINUS");
    strcpy(enumToTerminal[35], "MUL");
    strcpy(enumToTerminal[36], "DIV");
    strcpy(enumToTerminal[37], "LT");
    strcpy(enumToTerminal[38], "LE");
    strcpy(enumToTerminal[39], "GE");
    strcpy(enumToTerminal[40], "GT");
    strcpy(enumToTerminal[41], "EQ");
    strcpy(enumToTerminal[42], "NE");
    strcpy(enumToTerminal[43], "DEF");
    strcpy(enumToTerminal[44], "ENDDEF");
    strcpy(enumToTerminal[45], "DRIVERDEF");
    strcpy(enumToTerminal[46], "DRIVERENDDEF");
    strcpy(enumToTerminal[47], "COLON");
    strcpy(enumToTerminal[48], "RANGEOP");
    strcpy(enumToTerminal[49], "SEMICOL");
    strcpy(enumToTerminal[50], "COMMA");
    strcpy(enumToTerminal[51], "ASSIGNOP");
    strcpy(enumToTerminal[52], "SQBO");
    strcpy(enumToTerminal[53], "SQBC");
    strcpy(enumToTerminal[54], "BO");
    strcpy(enumToTerminal[55], "BC");
    strcpy(enumToTerminal[56], "COMMENTMARK");
    strcpy(enumToTerminal[57], "END_OF_FILE");
    strcpy(enumToTerminal[58], "LEX_ERROR_1");
    strcpy(enumToTerminal[59], "LEX_ERROR_2");
    strcpy(enumToTerminal[60], "EPSILON");
}
void fillEnumToNonTerminal()
{
    strcpy(enumToNonTerminal[0], "program");
    strcpy(enumToNonTerminal[1], "module_declerations");
    strcpy(enumToNonTerminal[2], "module_decleration");
    strcpy(enumToNonTerminal[3], "other_modules");
    strcpy(enumToNonTerminal[4], "driver_module");
    strcpy(enumToNonTerminal[5], "module");
    strcpy(enumToNonTerminal[6], "ret");
    strcpy(enumToNonTerminal[7], "input_plist");
    strcpy(enumToNonTerminal[8], "n1");
    strcpy(enumToNonTerminal[9], "output_plist");
    strcpy(enumToNonTerminal[10], "n2");
    strcpy(enumToNonTerminal[11], "data_type");
    strcpy(enumToNonTerminal[12], "range_arrays");
    strcpy(enumToNonTerminal[13], "type");
    strcpy(enumToNonTerminal[14], "module_def");
    strcpy(enumToNonTerminal[15], "statements");
    strcpy(enumToNonTerminal[16], "statement");
    strcpy(enumToNonTerminal[17], "io_stmt");
    strcpy(enumToNonTerminal[18], "bool_const");
    strcpy(enumToNonTerminal[19], "n11");
    //strcpy(enumToNonTerminal[20], "actual_para_list");
    strcpy(enumToNonTerminal[20], "var_print");
    strcpy(enumToNonTerminal[21], "p1");
    strcpy(enumToNonTerminal[22], "simple_stmt");
    strcpy(enumToNonTerminal[23], "assignment_stmt");
    strcpy(enumToNonTerminal[24], "which_stmt");
    strcpy(enumToNonTerminal[25], "lvalue_id_stm");
    strcpy(enumToNonTerminal[26], "lvalue_arr_stmt");
    strcpy(enumToNonTerminal[27], "index_arr");
    strcpy(enumToNonTerminal[28], "new_index");
    strcpy(enumToNonTerminal[29], "sign");
    strcpy(enumToNonTerminal[30], "module_reuse_stmt");
    strcpy(enumToNonTerminal[31], "optional");
    strcpy(enumToNonTerminal[32], "id_list");
    strcpy(enumToNonTerminal[33], "n3");
    strcpy(enumToNonTerminal[34], "expression");
    strcpy(enumToNonTerminal[35], "u");
    strcpy(enumToNonTerminal[36], "unary_op");
    strcpy(enumToNonTerminal[37], "new_nt");
    strcpy(enumToNonTerminal[38], "arithmetic_or_boolean_exp");
    strcpy(enumToNonTerminal[39], "n7");
    strcpy(enumToNonTerminal[40], "any_term");
    strcpy(enumToNonTerminal[41], "n8");
    strcpy(enumToNonTerminal[42], "arthmetic_exp");
    strcpy(enumToNonTerminal[43], "n4");
    strcpy(enumToNonTerminal[44], "term");
    strcpy(enumToNonTerminal[45], "n5");
    strcpy(enumToNonTerminal[46], "factor");
    strcpy(enumToNonTerminal[47], "element_index_with_exp");
    strcpy(enumToNonTerminal[48], "arr_exp");
    strcpy(enumToNonTerminal[49], "arr_n4");
    strcpy(enumToNonTerminal[50], "arr_term");
    strcpy(enumToNonTerminal[51], "arr_n5");
    strcpy(enumToNonTerminal[52], "arr_factor");
    strcpy(enumToNonTerminal[53], "op1");
    strcpy(enumToNonTerminal[54], "op2");
    strcpy(enumToNonTerminal[55], "logical_op");
    strcpy(enumToNonTerminal[56], "relational_op");
    strcpy(enumToNonTerminal[57], "declare_stmt");
    strcpy(enumToNonTerminal[58], "conditional_stmt");
    strcpy(enumToNonTerminal[59], "case_stmts");
    strcpy(enumToNonTerminal[60], "n9");
    strcpy(enumToNonTerminal[61], "value");
    strcpy(enumToNonTerminal[62], "default1");
    strcpy(enumToNonTerminal[63], "iterative_stmt");
    strcpy(enumToNonTerminal[64], "range_for_loop");
    strcpy(enumToNonTerminal[65], "index_for_loop");
    strcpy(enumToNonTerminal[66], "new_index_for_loop");
    strcpy(enumToNonTerminal[67], "sign_for_loop");
}

void fillBuffer()
{
    if (nxt == buflen)
        nxt = 0;
    int x = fread(buffer + nxt, sizeof(char), buflen / 2, fp);
    nxt += x;
    if (x != buflen / 2)
        buffer[nxt] = EOF;
    // printf("%s\n", buffer);
}

void initLex(FILE *f, int len)
{
    fp = f;
    nxt = 0;
    buflen = 2 * len;
    MAX_BUFFER_SIZE = len;
    lex_ptr = 0;
    lineNum = 1;
    dfaState = 0;
    buffer = malloc(buflen * sizeof(char));
    lexeme = malloc(20 * sizeof(char));
    beginPtr = 0;
    fwdPtr = 0;
    bufferRounds = 0;
    /*
    for (int i = 0; i < LOOKUP_TABLE_SIZE; i++)
    {
        printf("koko\n");
        if (lookupTable[i].token != DUMMY)
            printf("%d@@@%s###%d\n", i, lookupTable[i].lexeme, lookupTable[i].token);
    }
    
    printf("@@%d@@\n", search("integer"));
    printf("@@%d@@\n", search("real"));
    printf("@@%d@@\n", search("boolean"));
    printf("@@%d@@\n", search("of"));
    printf("@@%d@@\n", search("array"));
    printf("@@%d@@\n", search("start"));
    printf("@@%d@@\n", search("end"));
    printf("@@%d@@\n", search("declare"));
    printf("@@%d@@\n", search("module"));
    printf("@@%d@@\n", search("driver"));
    printf("@@%d@@\n", search("program"));
    printf("@@%d@@\n", search("get_value"));
    printf("@@%d@@\n", search("print"));
    printf("@@%d@@\n", search("use"));
    printf("@@%d@@\n", search("with"));
    printf("@@%d@@\n", search("parameters"));
    printf("@@%d@@\n", search("takes"));
    printf("@@%d@@\n", search("input"));
    printf("@@%d@@\n", search("returns"));
    printf("@@%d@@\n", search("for"));
    printf("@@%d@@\n", search("in"));
    printf("@@%d@@\n", search("switch"));
    printf("@@%d@@\n", search("case"));
    printf("@@%d@@\n", search("break"));
    printf("@@%d@@\n", search("default"));
    printf("@@%d@@\n", search("while"));
    printf("@@%d@@\n", search("AND"));
    printf("@@%d@@\n", search("OR"));
    printf("@@%d@@\n", search("true"));
    printf("@@%d@@\n", search("false"));
*/
   

    fillBuffer(fp);

    
    // lookupTableRecord *lt;

    // lt = malloc(sizeof(lookupTableRecord) * LOOKUP_TABLE_SIZE);
    
    initializeLookupTable(lookupTable);
    
    generateLookupTable();
    //printf("Yes\n");
    

    // for(int i = 0; i < 15; i++)
    //     printf("%c\n", getChar(0));
}
// Name stands for token name/type
TOKEN getToken()
{
    //printf("4\n");
    TOKEN _token;
    _token.line_no = lineNum;
    if (beginPtr == MAX_BUFFER_SIZE)
        beginPtr = 0;
    int lexeme_sz = lex_ptr + 1; // Check from Animesh
    if (lexeme_sz > 20)
    {
        _token.TK = LEX_ERROR_1;
        strncpy(_token.lexeme, "lexeme size of ID has exceeded 20\n", MAX_BUFFER_SIZE);

    } // return ERROR TOKEN : Lexeme Length exceeding MAX_LEXEME_LENGTH
    //printf("5\n");
    lexeme[lex_ptr] = '\0'; // Do we really need to do this?

    if (dfaState == 0 || dfaState == 1)
    {
        //printf("%s\n", lexeme);
        Name TK = search(lexeme);
        //printf("Search complete\n");
        
        if (TK == DUMMY){
           // printf("Yes ID\n");
            TK = ID;
        }
        _token.TK = TK;
        //printf("%s\n", TK);
        strcpy(_token.lexeme, lexeme);
        return _token;
    }
    else if (dfaState == 2)
    {
        _token.TK = NUM;
        _token.value_if_int = atoi(lexeme);
        return _token;
    }
    else if (dfaState == 4)
    {
        _token.TK = RNUM;
        _token.value_if_float = atof(lexeme);
        return _token;
    }
    // e.g. parsing 23.5e6
    else if (dfaState == 5 || dfaState == 6 || dfaState == 7)
    {
        _token.TK = RNUM;
        _token.value_if_float = atof(lexeme);
    }
    return _token;
}

char getChar(int add)
{
    if (fwdPtr == 0 || fwdPtr == buflen / 2)
        fillBuffer();
    char c = buffer[fwdPtr];

    if (add == 0)
    {
        lexeme[lex_ptr++] = c;
        fwdPtr = (fwdPtr + 1) % buflen;
    }

    if(add == 2)
        fwdPtr = (fwdPtr + 1) % buflen;
    return c;
}

TOKEN getNextToken()
{
    TOKEN tkn;
    char c;
    char t;
    int flag = 0;

    while (1)
    {
        tkn.line_no = lineNum;
        switch (dfaState)
        {
        case 0:
            c = getChar(0);

            //printf("\nChar = %c\n",c);
            
            if (c == '.')
            {
                dfaState = 8;
            }

            //printf("c\n");
            
            else if (c == '_' || isalpha(c))
            {
                //printf("c\n");
                t = getChar(1);
                //printf("Char is %c\n", t);
                if (!isalpha(c) && !isdigit(c) && t != '_')
                {
                    tkn = getToken();
                    dfaState = 0;
                    beginPtr = fwdPtr;
                    return tkn;
                }
                else
                {
                    dfaState = 1;
                }
            }
            else if (isdigit(c))
            {
                t = getChar(1);
                if (t != '.' && !isdigit(t))
                {
                    tkn.TK = NUM;
                    tkn.value_if_int = c - '0';
                    //printf("%d\n", tkn.value_if_int);
                    beginPtr = fwdPtr;
                    dfaState = 0;
                    return tkn;
                }
                else
                {
                    dfaState = 2;
                }
            }
            else if (c == ';')
            {

                tkn.TK = SEMICOL;
                strncpy(tkn.lexeme, ";", MAX_LEXEME_LENGTH);
                beginPtr = fwdPtr;
                dfaState = 0;
                return tkn;
            }
            else if (c == ',')
            {
                tkn.TK = COMMA;
                strncpy(tkn.lexeme, ",", MAX_LEXEME_LENGTH);
                beginPtr = fwdPtr;
                dfaState = 0;
                return tkn;
            }
            else if (c == '[')
            {
                tkn.TK = SQBO;
                strncpy(tkn.lexeme, "[", MAX_LEXEME_LENGTH);
                beginPtr = fwdPtr;
                dfaState = 0;
                return tkn;
            }
            else if (c == ']')
            {
                tkn.TK = SQBC;
                strncpy(tkn.lexeme, "]", MAX_LEXEME_LENGTH);
                beginPtr = fwdPtr;
                dfaState = 0;
                return tkn;
            }
            else if (c == '(')
            {
                tkn.TK = BO;
                strncpy(tkn.lexeme, "(", MAX_LEXEME_LENGTH);
                beginPtr = fwdPtr;
                dfaState = 0;
                return tkn;
            }
            else if (c == ')')
            {
                tkn.TK = BC;
                strncpy(tkn.lexeme, ")", MAX_LEXEME_LENGTH);
                beginPtr = fwdPtr;
                dfaState = 0;
                return tkn;
            }
            else if (c == EOF)
            {
                
                tkn.TK = END_OF_FILE;
                strncpy(tkn.lexeme, "EOF", MAX_LEXEME_LENGTH);
                
                beginPtr = fwdPtr;
                dfaState = 0;
                //exit(0);
                return tkn;
            }
            else if (c == '\t' || c == ' ')
            {
                memset(lexeme, '\0', sizeof(lexeme));
                lex_ptr = 0;
                // printf("a\n");
                while(getChar(1)==' ' || getChar(1)=='\t'){
                    // printf("b\n");
                    getChar(2);
                }
                dfaState = 0;
            }
            else if (c == '\n')
            {
                memset(lexeme, '\0', sizeof(lexeme));
                lex_ptr = 0;
                lineNum = lineNum + 1;
                // printf("a\n");
                while (getChar(1) == '\n')
                {
                    // printf("b\n");
                    getChar(2);
                    lineNum = lineNum + 1;
                }
                dfaState = 0;
                
            }
            else if (c == '+')
            {
                tkn.TK = PLUS;
                strncpy(tkn.lexeme, "+", MAX_LEXEME_LENGTH);
                beginPtr = fwdPtr;
                dfaState = 0;
                return tkn;
            }
            else if (c == '-')
            {
                tkn.TK = MINUS;
                strncpy(tkn.lexeme, "-", MAX_LEXEME_LENGTH);
                beginPtr = fwdPtr;
                dfaState = 0;
                return tkn;
            }
            else if (c == '*')
            {
                t = getChar(1); /* this getChar only does a lookahead
                and returns the file pointer back to its original value */
                if (t == '*')
                {
                    dfaState = 22;
                }
                else
                {
                    tkn.TK = MUL;
                    strncpy(tkn.lexeme, "*", MAX_LEXEME_LENGTH);
                    beginPtr = fwdPtr;
                    dfaState = 0;
                    return tkn;
                }
            }
            else if (c == '/')
            {
                tkn.TK = DIV;
                strncpy(tkn.lexeme, "/", MAX_LEXEME_LENGTH);
                beginPtr = fwdPtr;
                dfaState = 0;
                return tkn;
            }
            else if (c == '<')
            {
                t = getChar(1);
                if (t == '=')
                {   getChar(0);
                    tkn.TK = LE;
                    strncpy(tkn.lexeme, "<=", MAX_LEXEME_LENGTH);
                    beginPtr = fwdPtr;
                    dfaState = 0;
                    return tkn;
                }
                else if (t == '<')
                {   getChar(0);
                    t = getChar(1);
                    if (t == '<')
                    {   getChar(0);
                        tkn.TK = DRIVERDEF;
                        strncpy(tkn.lexeme, "<<<", MAX_LEXEME_LENGTH);
                        beginPtr = fwdPtr;
                        dfaState = 0;
                        return tkn;
                    }
                    else
                    {
                        tkn.TK = DEF;
                        strncpy(tkn.lexeme, "<<", MAX_LEXEME_LENGTH);
                        beginPtr = fwdPtr;
                        dfaState = 0;
                        return tkn;
                    }
                }
                else
                {
                    tkn.TK = LT;
                    strncpy(tkn.lexeme, "<", MAX_LEXEME_LENGTH);
                    beginPtr = fwdPtr;
                    dfaState = 0;
                    return tkn;
                }
            }
            else if (c == '>')
            {
                t = getChar(1);
                if (t == '=')
                {
                    getChar(0);
                    tkn.TK = GE;
                    strncpy(tkn.lexeme, ">=", MAX_LEXEME_LENGTH);
                    beginPtr = fwdPtr;
                    dfaState = 0;
                    return tkn;
                }
                else if (t == '>')
                {
                    getChar(0);
                    t = getChar(1);
                    if (t == '>')
                    {
                        getChar(0);
                        tkn.TK = DRIVERENDDEF;
                        strncpy(tkn.lexeme, ">>>", MAX_LEXEME_LENGTH);
                        beginPtr = fwdPtr;
                        dfaState = 0;
                        return tkn;
                    }
                    else
                    {
                        tkn.TK = ENDDEF;
                        strncpy(tkn.lexeme, ">>", MAX_LEXEME_LENGTH);
                        beginPtr = fwdPtr;
                        dfaState = 0;
                        return tkn;
                    }
                }
                else
                {
                    tkn.TK = GT;
                    strncpy(tkn.lexeme, ">", MAX_LEXEME_LENGTH);
                    beginPtr = fwdPtr;
                    dfaState = 0;
                    return tkn;
                }
            }
            else if (c == '=')
            {
                dfaState = 35;
            }
            else if (c == '!')
            {
                dfaState = 37;
            }
            else if (c == ':')
            {
                t = getChar(1);
                if (t == '=')
                {
                    getChar(0);
                    tkn.TK = ASSIGNOP;
                    strncpy(tkn.lexeme, ":=", MAX_LEXEME_LENGTH);
                    beginPtr = fwdPtr;
                    dfaState = 0;
                    return tkn;
                }
                else
                {
                    tkn.TK = COLON;
                    strncpy(tkn.lexeme, ":", MAX_LEXEME_LENGTH);
                    beginPtr = fwdPtr;
                    dfaState = 0;
                    return tkn;
                }
            }
            break;

        case 1:
            t = getChar(1);
            
            // fwdPtr = fwdPtr -1;
            if (isalpha(t) || isdigit(t) || t == '_')
            {
                //printf("Char = %c\n", t);
                getChar(0);
                dfaState = 1;
            }
            else
            {
                //printf("Reach\n");
                tkn = getToken();
                //printf("Token: %s %d\n", tkn.lexeme, tkn.TK);
                beginPtr = fwdPtr;
                dfaState = 0;
                return tkn;
            }
            break;

        case 2:
            if (flag == 1)
            {
                tkn = getToken();
                beginPtr = fwdPtr;
                dfaState = 0;
                flag = 0;
                return tkn;
            }
            else
            {
                getChar(0);//By ME$
                t = getChar(1);
                // fwdPtr = fwdPtr -1;
                if (isdigit(t))
                {
                    c = getChar(0);
                    dfaState = 2;
                }
                else if (t == '.')
                {
                    // c = getChar(0);
                    dfaState = 3;
                }
                else
                {
                    tkn = getToken();
                    beginPtr = fwdPtr;
                    dfaState = 0;
                    return tkn;
                }
            }
            break;
        case 3:
            t = getChar(1);
            if (t == '.')
            {
                flag = 1;
                fwdPtr = fwdPtr -1;
                lex_ptr = lex_ptr -1;
                lexeme[lex_ptr] = '\0';
                dfaState = 2;
            }
            else if (isdigit(t))
            {
                c = getChar(0);
                dfaState = 4;
            }
            else
            {
                dfaState = 38; // trap dfaState
            }
            break;
        case 4:
            t = getChar(1);
            // fwdPtr = fwdPtr -1;
            if (isdigit(t))
            {
                t = getChar(0);
                dfaState = 4;
            }
            else if (t == 'E' || t == 'e')
            {
                t = getChar(0);
                dfaState = 5;
            }
            else
            {
                tkn = getToken();
                beginPtr = fwdPtr;
                dfaState = 0;
                return tkn;
            }
            break;
        case 5:
            t = getChar(1);
            if (t == '+' || t == '-')
            {
                c = getChar(0);
                dfaState = 6;
            }
            else if (isdigit(t))
            {
                c = getChar(0);
                t = getChar(1);
                if (isdigit(t))
                {
                    dfaState = 7;
                }
                else
                {
                    tkn = getToken();
                    beginPtr = fwdPtr;
                    dfaState = 0;
                    return tkn;
                }
            }
            else
            {
                dfaState = 38; // trap dfaState
            }
            break;
        case 6:
            t = getChar(1);
            if (isdigit(t))
            {
                c = getChar(0);
                t = getChar(1);
                // fwdPtr= fwdPtr -1;
                if (isdigit(t))
                {
                    dfaState = 7;
                }
                else
                {
                    tkn = getToken();
                    beginPtr = fwdPtr;
                    dfaState = 0;
                    return tkn;
                }
            }
            else
            {
                dfaState = 38; // trap dfaState
            }
            break;
        case 7:
            c = getChar(0);
            t = getChar(1);
            if (isdigit(t))
            {
                dfaState = 7;
            }
            else
            {
                tkn = getToken();
                beginPtr = fwdPtr;
                dfaState = 0;
                return tkn;
            }
            break;
        
        case 8:
            t = getChar(1);
            if(t=='.'){
                getChar(0);
                tkn.TK = RANGEOP;
                strncpy(tkn.lexeme, "..", MAX_LEXEME_LENGTH);
                beginPtr = fwdPtr;
                dfaState = 0;
                return tkn;
            }
            else{
                dfaState = 38;
            }
        
        case 22:
            c = getChar(0);
            if (c == '*')
            {
                dfaState = 23;
            }
            else if (c == '\n')
            {
                dfaState = 24;
            }
            else
            {
                dfaState = 22;
            }
            break;
        case 23:
            c = getChar(0);
            if (c == '\n')
            {
                dfaState = 24;
            }
            else if (c == '*')
            {
                dfaState = 0;
            }
            else
            {
                dfaState = 22;
            }
            break;
        case 24:
            c = getChar(0);
            lineNum = lineNum + 1;
            if (c == '*')
            {
                dfaState = 23;
            }
            else if (c == '\n')
            {
                dfaState = 24;
            }
            else
            {
                dfaState = 22;
            }
            break;
        case 35:
            t = getChar(1);
            if (t == '=')
            {
                c = getChar(0);
                tkn.TK = EQ;
                strncpy(tkn.lexeme, "==", MAX_LEXEME_LENGTH);
                beginPtr = fwdPtr;
                dfaState = 0;
                return tkn;
            }
            else
            {
                dfaState = 38; // trap dfaState
            }
            break;
        case 37:
            t = getChar(1);
            if (t == '=')
            {
                c = getChar(0);
                tkn.TK = NE;
                strncpy(tkn.lexeme, "!=", MAX_LEXEME_LENGTH);
                beginPtr = fwdPtr;
                dfaState = 0;
                return tkn;
            }
            else
            {
                dfaState = 38; // trap dfaState
            }
            break;
        case 38:
            tkn.TK = LEX_ERROR_2;
            strncpy(tkn.lexeme, "transition not possible\n", MAX_LEXEME_LENGTH);
            beginPtr = fwdPtr;
            dfaState = 0;
            return tkn;
            // trap dfaState
        default:
            break;
        }
    }
    return tkn;
}
void getStream()
{
    //printf("1\n");
    TOKEN token;
    while (1)
    {
        token = getNextToken(fp);
        //printf("Getstream Token: %s %d\n", token.lexeme, token.TK);
        //printf("2\n");
        //printf("%s\n", enumToTerminal[token.TK]);
        if (token.TK == END_OF_FILE){
            //printf("Token- %s, Lexeme- %s (Line No. - %d)\n", enumToTerminal[token.TK], token.lexeme, token.line_no);
            break;
        }
        else if (token.TK == LEX_ERROR_1)
            printf("Identifier length is greater than 20 (Line No. - %d)\n", token.line_no);
        else if (token.TK == LEX_ERROR_2)
            printf("Unidentified token found :- %s (Line No. - %d)\n", token.lexeme, token.line_no);
        else
        {
            if (token.TK == NUM)
                printf("Token- %s, Lexeme- %d (Line No. - %d)\n", enumToTerminal[token.TK], token.value_if_int, token.line_no);
            else if (token.TK == RNUM)
                printf("Token- %s, Lexeme- %f (Line No. - %d)\n", enumToTerminal[token.TK], token.value_if_float, token.line_no);
            else
                printf("Token- %s, Lexeme- %s (Line No. - %d)\n", enumToTerminal[token.TK], token.lexeme, token.line_no);
        }

        memset(lexeme, '\0', sizeof(lexeme));
        lex_ptr = 0;
    }
}
