#include "lexerDef.h"
// #include "driver.h"
#include "set.h"
#include <stdio.h>
#include <stdbool.h>
#define NO_MATCH -1

int TOTAL_RULES;

typedef enum
{
    program,
    module_declerations,
    module_decleration,
    other_modules,
    driver_module,
    module,
    ret,
    input_plist,
    n1,
    output_plist,
    n2,
    data_type,
    range_arrays,
    type,
    module_def,
    statements,
    statement,
    io_stmt,
    bool_const,
    n11,
    // id_num_rnum,
    // array_element_for_print,
    var_print,
    p1,
    simple_stmt,
    assignment_stmt,
    which_stmt,
    lvalue_id_stm,
    lvalue_arr_stmt,
    index_arr,
    new_index,
    sign,
    module_reuse_stmt,
    optional,
    id_list,
    n3,
    expression,
    u,
    unary_op,
    new_nt,
    arithmetic_or_boolean_exp,
    n7,
    any_term,
    n8,
    arthmetic_exp,
    n4,
    term,
    n5,
    factor,
    element_index_with_exp,
    arr_exp,
    arr_n4,
    arr_term,
    arr_n5,
    arr_factor,
    op1,
    op2,
    logical_op,
    relational_op,
    declare_stmt,
    conditional_stmt,
    case_stmts,
    n9,
    value,
    default1,
    iterative_stmt,
    range_for_loop,
    index_for_loop,
    new_index_for_loop,
    sign_for_loop
} nonTerminalNo;

typedef struct grammarSymbol
{
    bool isTerminal;
    union
    {
        Name tno;
        nonTerminalNo ntno;
    };
} grammarSymbol;

// typedef struct
// {
//     /*nonTerminalNo lhsSymbol;*/
//     rhsOfGrammarRuleNode *head;
//     /*rhsOfGrammarRuleNode* tail;*/
// } grammarRule;

typedef struct rhsOfGrammarRuleNode
{
    grammarSymbol symbol;
    struct rhsOfGrammarRuleNode *next;
} rhsOfGrammarRuleNode;


//     grammarRule grammar[TOTAL_RULES];

// int parseTable[NON_TERMINALS_COUNT][TERMINALS_COUNT];

bool firstSet[NON_TERMINALS_COUNT][TERMINALS_COUNT];
Set followSet[NON_TERMINALS_COUNT];

rhsOfGrammarRuleNode **rules;

int pt[NON_TERMINALS_COUNT][TERMINALS_COUNT-1]; // Not considering $ & EPSILON

void populateGrammar();