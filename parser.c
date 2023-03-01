#include "parseDef.h"
//#include "tree.h"
#include "stack.h"
#include "lexer.h"
#include <string.h>
#include <stdlib.h>
#include "lexerDef.h"
#include <stdbool.h>
#include <stdio.h>



// char *gram[TOTAL_RULES] = {
//     "program module_declerations other_modules driver_module other_modules",
//     "module_declerations module_decleration module_declerations ",
//     "module_declerations EPSILON",
//     "module_decleration DECLARE MODULE ID SEMICOL",
//     "other_modules module other_modules",
//     "other_modules EPSILON",
//     "driver_module DRIVERDEF DRIVER PROGRAM DRIVERENDDEF module_def",
//     "module DEF MODULE ID ENDDEF TAKES INPUT SQBO input_plist SQBC SEMICOL ret module_def",
//     "ret RETURNS SQBo output_plist SQBC SEMICOL ",
//     "ret EPSILON",
//     "input_plist ID COLON data_type n1",
//     "n1 COMMA ID COLON data_type n1 ",
//     "n1 EPSILON",
//     "output_plist ID COLON type n2",
//     "n2 comma ID COLON type n2",
//     "n2 EPSILON",
//     "data_type INTEGER ",
//     "data_type REAL",
//     "data_type BOOLEAN",
//     "data_type ARRAY SQBO range_arrays SQBC OF type",
//     "range_arrays index_arr RANGEOP index_arr",
//     "type INTEGER ",
//     "type REAL",
//     "type BOOLEAN",
//     "module_def START statements END",
//     "statements statement statements ",
//     "statements EPSILON",
//     "statement io_stmt ",
//     "statement simple_stmt",
//     "statement declare_stmt",
//     "statement conditional_stmt",
//     "statement iterative_stmt",
//     "io_stmt GET_VALUE BO ID SEMICOL",
//     "io_stmt PRINT BO var_print BC SEMICOL",
//     "bool_const TRUE ",
//     "bool_const FALSE",
//     "var_print ID p1",
//     "var_print NUM",
//     "var_print RNUM ",
//     "var_print book_const",
//     "p1 SQBO new_index SQBC",
//     "p1 EPSILON",
//     "simple_stmt assignment_stmt",
//     "simple_stmt module_reuse_stmt",
//     "assignment_stmt ID which_stmt",
//     "which_stmt lvalue_id_stmt",
//     "which_stmt lvalue_arr_stmt",
//     "lvalue_id_stm ASSIGNOP expression SEMICOL",
//     "lvalue_arr_stmt SQBO element_index_with_exp SQBC ASSIGNOP expression SEMICOL",
//     "index_arr sign new_index",
//     "new_index NUM",
//     "new_index ID",
//     "sign PLUS",
//     "sign MINUS",
//     "sign EPSILON",
//     "module_reuse_stmt optional USE MODULE ID WITH PARAMETERS actual_para_list SEMICOL",
//     "actual_para_list NUM",
//     "actual_para_list RNUM",
//     "actual_para_list bool_const",
//     "actual_para_list ID n11",
//     "n11 SQBO element_index_with_exp SQBC",
//     "n11 EPSILON",
//     "optional SQBO id_list SQBC ASSIGNOP",
//     "optional EPSILON",
//     "id_list ID n3",
//     "n3 COMMA ID n3",
//     "n3 EPSILON",
//     "expression arithmetic_exp_or_boolean_exp",
//     "expression u",
//     "u unary_op new_nt",
//     "unary_op PLUS ",
//     "unary_op MINUS",
//     "new_nt BO arithmetic_exp BC",
//     "new_nt var_id_num ",
//     "var_id_num ID",
//     "var_id_num NUM",
//     "var_id_num RNUM",
//     "arithmetic_or_boolean_exp any_term n7",
//     "n7 logical_op any_term n7",
//     "n7 EPSILON",
//     "any_term arthmetic_exp n8 ",
//     "any_term bool_const n8",
//     "n8 relational_op arthmetic_exp n8",
//     "n8 EPSILON",
//     "arthmetic_exp term n4",
//     "n4 op1 term n4 ",
//     "n4 EPSILON",
//     "term factor n5",
//     "n5 op2 factor n5",
//     "n5 EPSILON",
//     "factor BO arthmetic_exp BC",
//     "factor bool_const",
//     "factor NUM",
//     "factor RNUM",
//     "factor ID n11",
//     "n11 SQBO element_index_with_exp SQBC ",
//     "n11 EPSILON",
//     "element_index_with_exp sign n10",
//     "element_index_with_exp arr_exp ",
//     "n10 new_index ",
//     "n10 BO arr_exp BC",
//     "arr_exp arr_term arr_n4",
//     "arr_n4 op1 arr_term arr_n4",
//     "arr_n4 EPSILON",
//     "arr_term arr_factor arr_n5",
//     "arr_n5 op2 arr_factor arr_n5",
//     "arr_n5 EPSILON",
//     "arr_factor ID",
//     "arr_factor NUM",
//     "arr_factor bool_const",
//     "arr_factor BO arr_exp BC",
//     "op1 PLUS",
//     "op1 MINUS",
//     "op2 MUL",
//     "op2 DIV",
//     "logical_op AND",
//     "logical_op OR",
//     "relational_op LT",
//     "relational_op LE",
//     "relational_op GT ",
//     "relational_op GE",
//     "relational_op EQ",
//     "relational_op NE",
//     "declare_stmt DECLARE id_list COLON data_type SEMICOL",
//     "conditional_stmt SWITCH BO ID BC START case_stmts default1 END",
//     "case_stmts CASE value COLON statements BREAK SEMICOL n9",
//     "n9 CASE value COLON statements BREAK SEMICOL n9",
//     "n9 EPSILON",
//     "value NUM",
//     "value TRUE",
//     "value FALSE",
//     "default1 DEFAULT COLON statements BREAK SEMICOL",
//     "default1 EPSILON",
//     "iterative_stmt FOR BO ID IN range_for_loop BC START statements END",
//     "iterative_stmt WHILE BO arithmetic_or_boolean_exp BC START statements END",
//     "range_for_loop index_for_loop RANGEOP index_for_loop",
//     "index_for_loop sign_for_loop new_index_for_loop",
//     "new_index_for_loop NUM",
//     "sign_for_loop PLUS",
//     "sign_for_loop MINUS",
//     "sign_for_loop EPSILON",
// };


grammarSymbol symbolOf(char *c)
{
    grammarSymbol temp;
    temp.isTerminal = true;
    for (int i = 0; i < NON_TERMINALS_COUNT; i++)
    {
        if (strcmp(c, enumToNonTerminal[i]) == 0)
        {
            temp.isTerminal = false;
            temp.ntno = i;
            return temp;
        }
    }
    for (int i = 0; i < TERMINALS_COUNT; i++)
    {
        //HANDLE EPSILON
        if (strcmp(c, enumToTerminal[i]) == 0)
        {
            temp.isTerminal = true;
            temp.tno = i;
            return temp;
        }
    }
    
}

rhsOfGrammarRuleNode *sym_Insert(char arr[])
{
    //printf("%s\n", arr);
    
    //const char z[2] = " \n";
    // also using it for keeping lhs in the head
    rhsOfGrammarRuleNode *head = (rhsOfGrammarRuleNode *)malloc(sizeof(rhsOfGrammarRuleNode));
    rhsOfGrammarRuleNode *temp = head;
    int i = 0, flag = 1;
    //char *y = arr;
    // char brr[220];
    // strcpy(brr, arr);
    char *s = strtok(arr, " \n");
    while (s != NULL)
    {
        //printf("%s\t", s);
        if (flag == 1)
        {
            head->symbol = symbolOf(s);
            flag = 0;

        } // for empty rhs of the rule when getting the first rhs

        else
        {
            rhsOfGrammarRuleNode *node = (rhsOfGrammarRuleNode *)malloc(sizeof(rhsOfGrammarRuleNode));
            node->symbol = symbolOf(s);
            temp->next = node;
            temp = temp->next;
        }
        s = strtok(NULL, " \n");
    }
    printf("\n");
    return head;
}

void printGrammar(rhsOfGrammarRuleNode *n)
{
    rhsOfGrammarRuleNode *temp = n;
    while (temp != NULL)
    {

        if (temp->symbol.isTerminal)
            printf("%s\t", enumToTerminal[temp->symbol.tno]);
        else
            printf("%s\t", enumToNonTerminal[temp->symbol.ntno]);
        temp = temp->next;
    }
    printf("\n");
}

void populateGrammar()
{
    //Creating file pointer for file
    FILE *gr = fopen("grammar.txt", "r");
    if(gr == NULL) printf("Bad\n");
    char c[100];
    int n = 0;
    // fscanf(gr, "%[^\n]", c);
    // printf("%s\n", c);
    // while(c != NULL){
    //     n++;
    //     fscanf(gr, "%[^\n]", c);
    //     printf("%s\n", c);
    // }
    // printf("No of rules = %d\n", n);
    while(fgets(c, 100, gr)){
        //printf("%s\n", c);
        n++;
    }

    //printf("%d\n", n);
    TOTAL_RULES = n;
    rules = malloc(TOTAL_RULES * sizeof(rhsOfGrammarRuleNode*));
    fseek(gr, 0, SEEK_SET);
    int i = 0;
    printf("Start\n");
    while (fgets(c, 100, gr))
    {
        //printf("%d ", i);
        rules[i] = sym_Insert(c);
        //printGrammar(rules[i]);
        i++;
    }
    fclose(gr);

    //printf("1\n");
    // for (int i = 0; i < TOTAL_RULES; ++i)
    // {
    //     //char gramRule[] = gram[i];
    //     rules[i] = sym_Insert(gram[i]);
    // }
}



void computeFirstSets(){

    for(int i= TOTAL_RULES -1; i>=0; i--){
        //printf("4\t");
        rhsOfGrammarRuleNode * curr = rules[i];
        rhsOfGrammarRuleNode * ptr = rules[i]->next;

        printGrammar(curr);
        
        //int i=0;
        while(ptr!=NULL){
            //printf("%d\n", i++);
            printGrammar(ptr);

            bool a[TERMINALS_COUNT];
            initializeSet(&a);

            if(ptr->symbol.isTerminal==TRUE){
                //addToSet(&firstSet[curr->symbol.ntno], ptr->symbol.tno);
                firstSet[curr->symbol.ntno][ptr->symbol.tno] = true;
                break;
            }
            
            else {
                
                // if(findElementInSet(firstSet[ptr->symbol.ntno], 60)!= TRUE){
                if (firstSet[ptr->symbol.ntno][60] != TRUE)
                {
                    deleteFromSet(a, 60);
                    unionOfSets(&a, &a, &firstSet[ptr->symbol.ntno]);
                    unionOfSets(&firstSet[curr->symbol.ntno], &firstSet[curr->symbol.ntno], &a);
                    break;
                }
                else{
                    unionOfSets(&a, &a, &firstSet[ptr->symbol.ntno]);
                    if(ptr->next ==NULL){
                        unionOfSets(&firstSet[curr->symbol.ntno], &firstSet[curr->symbol.ntno], &a);
                        break;
                    }
                    else{
                        ptr = ptr->next;
                    }
                }
            }
        }
        printf("\n");
        
    }

}

void printFirstSets(){
    for (int i=0; i<NON_TERMINALS_COUNT; i++){
        printf("First set of %s is: ", enumToNonTerminal[i]);
        for(int j=0; j<TERMINALS_COUNT; j++){
            if(firstSet[i][j]){
                printf("%s ", enumToTerminal[j]);
            }
        }
        printf("\n");
    }
}

int main(){
    fillEnumToNonTerminal();
    fillEnumToTerminal();
    populateGrammar();
    int rno;
    // printf("Enter rule number\n");
    // scanf("%d", &rno);
    // rhsOfGrammarRuleNode *n = rules[rno];
    // //printf("1\n");
    // while(n != NULL){
    //     if(n->symbol.isTerminal)
    //         printf("%s\n", enumToTerminal[n->symbol.tno]);
    //     else
    //         printf("%s\n", enumToNonTerminal[n->symbol.ntno]);
    //     n=n->next;
    // }

    //computeFirstSets();
    //printFirstSets();

    return 0;

}

/* 
Create Parse Table:
    set of Ts[]
    Create the First, Follow table
    for i in rules:
        If rules[i] is nullable
            Ts[] = Follow(LHS)
        else
            Ts[] = First(LHS)

        for(j in Ts)
            Table[LHS,j] = i      



*/

void createPT(rhsOfGrammarRuleNode *rules )/* First & Follow sets taken from parseDef.h*/
{
    // initializing pt with -1
    for (int i = 0; i < NON_TERMINALS_COUNT; i++) {
        for (int j = 0; j < TERMINALS_COUNT - 1; j++) {
            pt[i][j] = -1;
        }
    }

    // populating pt
    for (int i = 0; i < TOTAL_RULES; i++)
    {
        rhsOfGrammarRuleNode rule = rules[i];
        grammarSymbol lhs = rule.symbol;
        rhsOfGrammarRuleNode *rhs = rule.next;
        grammarSymbol rhsSym = (*rhs).symbol;
        bool epsilonFlag = false;
        bool  tempFollowSet[TERMINALS_COUNT];
        bool tempFirstSet[TERMINALS_COUNT];
        // if rhsSym is epsilon
        if((rhsSym.isTerminal) && (rhsSym.tno == 60))
        { // check if the value is 60 for epsilon
                tempFollowSet[TERMINALS_COUNT]= followSet[lhs.ntno]; //check this
                epsilonFlag = true; 
        }
        // else
        else 
        {
            tempFirstSet[TERMINALS_COUNT] = firstSet[lhs.ntno];
        }         
        if (epsilonFlag) 
        {
            for (int j = 0; j < TERMINALS_COUNT - 1; j++)
            {
                if (tempFollowSet[j]) 
                {
                    pt[lhs.ntno][j] = i;
                }
            }
        }   
        else 
        {
            for (int j = 0; j < TERMINALS_COUNT - 1; j++) 
            {
                if (tempFirstSet[j])
                    pt[lhs.ntno][j] = i;
            }   
        } 

    }
}